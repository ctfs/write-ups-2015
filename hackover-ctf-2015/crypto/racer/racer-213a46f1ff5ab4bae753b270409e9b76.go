package main

import (
	"archive/tar"
	"compress/gzip"
	"crypto/rand"
	"crypto/rc4"
	"encoding/base32"
	"encoding/json"
	"fmt"
	"html/template"
	"io"
	"log"
	"net/http"
	"strings"
	"sync"
	"time"
)

const NUM_STAGES = 40
const NUM_CHEMICALS = 2048
const FLAG = "flag{XXXXXXXXXXXXXXXXXXXXX}"
var HINT = []byte("I see red for your cipher, Ron!")

var CHEMICAL_PREFIX = []string{"Meth", "Eth", "Prop", "But", "Pent", "Hex", "Oct", "Non"}
var CHEMICAL_SUFFIX = []string{"an", "en", "in", "anol"}
var CHEMICALS [NUM_CHEMICALS]string

var validStates = make(map[string]*State)
var validStateMutex = new(sync.Mutex)
var tmpl *template.Template

type JsonResponse struct {
	Action string `json:"action"`
	Text   string `json:"text"`
}

type State struct {
	Code       string
	Stage      uint8
	Pills      []byte
	ValidUntil time.Time
}

func (s *State) GetColor() string {
	numBit := s.Stage % 8
	pillsPos := s.Stage / 8
	if (s.Pills[pillsPos]>>numBit)&0x1 == 0 {
		return "red"
	} else {
		return "blue"
	}
}

func (s *State) Activity() {
	s.ValidUntil = time.Now().Add(15 * time.Minute)
}

func (s *State) Burn() {
	validStateMutex.Lock()
	defer validStateMutex.Unlock()
	delete(validStates, s.Code)
}

func (s *State) EncodeCode() string {
	return base32.StdEncoding.EncodeToString([]byte(s.Code))
}

func (s *State) IsExpired() bool {
	return s.ValidUntil.Before(time.Now())
}

func NewState() *State {
	code := make([]byte, 20)
	if _, err := io.ReadFull(rand.Reader, code); err != nil {
		log.Fatal("Oh no! Out of randomness for state code")
	}
	pills := make([]byte, NUM_STAGES/8+1)
	if _, err := io.ReadFull(rand.Reader, pills); err != nil {
		log.Fatal("Oh no! Out of randomness for pills")
	}
	s := &State{Code: string(code), Stage: 0, Pills: pills}
	s.Activity()
	validStateMutex.Lock()
	defer validStateMutex.Unlock()
	validStates[s.Code] = s
	return s
}

func getState(codeBase32 string) *State {
	code, err := base32.StdEncoding.DecodeString(codeBase32)
	if err != nil {
		return nil
	}
	s := validStates[string(code)]
	if s == nil {
		return nil
	}
	if s.IsExpired() {
		return nil
	}
	s.Activity()
	return s
}

func main() {
	var err error
	tmpl, err = template.ParseFiles("racer.html")
	if err != nil {
		log.Fatal("Could not load template", err)
	}

	for i := 0; i < NUM_CHEMICALS; i++ {
		CHEMICALS[i] = getChemical(i)
	}
	CHEMICALS[42] = "4R-Cyclopropenylidene"

	go cleaner()
	http.HandleFunc("/", handleIndex)
	http.HandleFunc("/race", handleRace)
	http.HandleFunc("/take", handleTakePill)
	http.HandleFunc("/pills.tar.gz", handleExaminePill)
	http.Handle("/static/", http.StripPrefix("/static/", http.FileServer(http.Dir("./static"))))

	log.Fatal(http.ListenAndServe(":8202", nil))
}

func handleIndex(w http.ResponseWriter, r *http.Request) {
	s := NewState()
	http.Redirect(w, r, "/race?driver_license="+s.EncodeCode(), http.StatusFound)
}

func handleRace(w http.ResponseWriter, r *http.Request) {
	s := getState(r.FormValue("driver_license"))
	if s == nil {
		http.Redirect(w, r, "/", http.StatusFound)
		return
	}
	err := tmpl.ExecuteTemplate(w, "racer.html", struct {
		DriverLicense string
		NumStages     int
	}{s.EncodeCode(), NUM_STAGES})
	if err != nil {
		log.Fatal("Could not execute template", err)
	}
}

func handleTakePill(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")

	s := getState(r.FormValue("driver_license"))
	if s == nil {
		json.NewEncoder(w).Encode(JsonResponse{Action: "expired"})
		return
	}

	var resp JsonResponse
	color := r.FormValue("color")
	if s.GetColor() == color {
		s.Stage++
		if s.Stage >= NUM_STAGES {
			resp = JsonResponse{Action: "flag", Text: fmt.Sprintf("Winner!<br>%s", FLAG)}
			s.Burn()
		} else {
			resp = JsonResponse{Action: color}
		}
	} else {
		s.Burn()
		resp = JsonResponse{Action: "burn", Text: "You took the wrong pill."}
	}
	json.NewEncoder(w).Encode(resp)
}

func handleExaminePill(w http.ResponseWriter, r *http.Request) {
	s := getState(r.FormValue("driver_license"))
	if s == nil {
		w.Header().Set("Content-Type", "text/plain")
		w.WriteHeader(http.StatusForbidden)
		fmt.Fprintln(w, "Your driver license expired. Try again.")
		return
	}
	var fn func([]byte)
	if s.GetColor() == "red" {
		fn = fillRc4
	} else {
		fn = fillRandom
	}
	w.Header().Set("Content-Type", "application/x-gtar")
	buildArchive(w, fn)
}

func buildArchive(w io.Writer, fillRandom func([]byte)) {
	size := 16
	randombytes := make([]byte, size)
	z := gzip.NewWriter(w)
	tw := tar.NewWriter(z)
	createTime := time.Now()
	for i := 0; i < NUM_CHEMICALS; i++ {
		tw.WriteHeader(&tar.Header{Name: CHEMICALS[i],
			Mode:     0666,
			Uid:      1000,
			Gid:      1000,
			Size:     int64(size),
			ModTime:  createTime,
			Typeflag: tar.TypeReg,
		})
		if i == 42 {
			tw.Write(HINT)
		} else {
			fillRandom(randombytes)
			tw.Write(randombytes)
		}
	}
	tw.Close()
	z.Close()
}

func getChemical(i int) string {
	prefixNumber := i & 0x7
	i >>= 3
	prefix := i & 0x7
	i >>= 3
	chemical := fmt.Sprintf("4R-%d-%syl", prefixNumber+1, CHEMICAL_PREFIX[prefix])

	isCyclic := i & 0x1
	i >>= 1
	prefix = i & 0x7
	i >>= 3
	if isCyclic == 1 {
		chemical = fmt.Sprintf("%s-%d-Cyclo%san", chemical, (prefix&0x3)+1, strings.ToLower(CHEMICAL_PREFIX[prefix]))
	} else {
		chemical = fmt.Sprintf("%s-2-%syl", chemical, CHEMICAL_PREFIX[prefix])
	}
	suffix := i & 0x3
	i >>= 2
	chemical = fmt.Sprintf("%s-%s%s", chemical, CHEMICAL_PREFIX[(prefix+5)%8], CHEMICAL_SUFFIX[suffix])
	return chemical
}

func fillRc4(data []byte) {
	for i := 0; i < len(data); i++ {
		data[i] = 0
	}
	key := make([]byte, 16)
	if _, err := io.ReadFull(rand.Reader, key); err != nil {
		log.Fatal("Oh no! Out of randomness for RC4 key")
	}
	c, _ := rc4.NewCipher(key)
	c.XORKeyStream(data, data)
	c.Reset()
}

func fillRandom(data []byte) {
	if _, err := io.ReadFull(rand.Reader, data); err != nil {
		log.Fatal("Oh no! Out of randomness for real random")
	}
}

func cleaner() {
	t := time.NewTicker(1 * time.Minute)
	for {
		<-t.C
		cleanup()
	}
}

func cleanup() {
	oldCodes := make([]string, 0)

	validStateMutex.Lock()
	for code, s := range validStates {
		if s.IsExpired() {
			oldCodes = append(oldCodes, code)
		}
	}
	for _, code := range oldCodes {
		delete(validStates, code)
	}
	validStateMutex.Unlock()
}
