package main

import (
	"net/http"

	"os"
	"path/filepath"
	"time"
)

const (
	flagPW = "XXX"
	flag   = "hackover15{XXX}"
)

var (
	fail      *os.File
	staticDir = "static"
)

func main() {
	staticDir = os.Args[1]
	var err error
	if fail, err = os.Open(filepath.Join(staticDir, "fail.jpg")); err != nil {
		os.Exit(5417)
	}

	http.Handle("/login", logger(http.HandlerFunc(login)))

	http.Handle("/", http.FileServer(http.Dir("./static")))
	http.ListenAndServe(":8080", nil)
}

func login(w http.ResponseWriter, r *http.Request) {
	switch r.Method {
	case "HEAD":
		hint(w, r)
	case "POST":
		check(w, r)
	default:
		gotoFail(w, r, "/fail.jpg", http.StatusMethodNotAllowed)
	}
}

func check(w http.ResponseWriter, r *http.Request) {
	if err := r.ParseForm(); err != nil {
		gotoFail(w, r, "fail.jpg", 401)
	}
	if r.PostForm.Get("pw") != flagPW {
		gotoFail(w, r, "fail.jpg", 401)
	}

	w.WriteHeader(http.StatusAccepted)
	if _, err := w.Write([]byte(flag)); err != nil {
	}
}

func hint(w http.ResponseWriter, r *http.Request) {
	if r.Header.Get("X-XXX") == "XXX" {
		w.Header().Set("X-XXX", flagPW)
		w.WriteHeader(http.StatusAccepted)
		return
	}
	w.Header().Set("X-XXX", "XXX")
	w.WriteHeader(http.StatusPartialContent)
}

func gotoFail(w http.ResponseWriter, r *http.Request, path string, respCode int) {
	http.ServeContent(w, r, "fail.jpg", time.Now().UTC(), fail)
}

func logger(h http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		h.ServeHTTP(w, r)
	})
}
