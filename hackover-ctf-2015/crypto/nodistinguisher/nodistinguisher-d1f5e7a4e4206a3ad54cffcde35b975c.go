package main

import (
	"bufio"
	"crypto/sha256"
	"encoding/base32"
	"fmt"
	"log"
	"net"
	"strings"
)

const KEY = "XXX"
const SECRET_MESSAGE = "Great! This was too easy, right? Here is your flag: hackover15{XXX}"

func main() {
	l, err := net.Listen("tcp", "0.0.0.0:1415")
	if err != nil {
		log.Fatal(err)
	}
	defer l.Close()
	for {
		conn, err := l.Accept()
		if err != nil {
			log.Fatal(err)
		}
		go handleConnection(conn)
	}
}

func encryptMessage(password string, message string) string {
	byteMessage := make([]byte, 240)
	if len(message) < len(byteMessage) {
		padByte := byte(len(byteMessage) - len(message))
		for i := 0; i < len(message); i++ {
			byteMessage[i] = message[i]
		}
		for i := len(message); i < len(byteMessage); i++ {
			byteMessage[i] = padByte
		}
	}

	key := deriveKey(password)
	for i := 0; i < len(byteMessage); i++ {
		byteMessage[i] ^= key[i%8]
	}
	return base32.StdEncoding.EncodeToString(byteMessage)
}

func decryptMessage(password string, ciphertext string) (string, bool) {
	byteCiphertext, err := base32.StdEncoding.DecodeString(ciphertext)
	if err != nil {
		return "", false
	}
	key := deriveKey(password)
	for i := 0; i < len(byteCiphertext); i++ {
		byteCiphertext[i] ^= key[i%8]
	}
	padByte := byteCiphertext[len(byteCiphertext)-1]
	for i := len(byteCiphertext) - 1; i >= 0 && i >= len(byteCiphertext)-int(padByte); i-- {
		if byteCiphertext[i] != padByte {
			return "", false
		}
		byteCiphertext[i] = ' '
	}
	plaintext := string(byteCiphertext)
	return strings.TrimSpace(plaintext), true
}

func deriveKey(password string) []byte {
	translation := "UEN8MXfV6rqD05nldvJjQPIKhke2bLHw"
	h := sha256.Sum256([]byte(password))
	key := make([]byte, 8)
	for i := 0; i < 8; i++ {
		key[i] = translation[h[h[i]&0xf]&0x1f]
	}
	return key
}

func handleConnection(conn net.Conn) {
	defer func() {
		log.Println(conn.RemoteAddr(), "disconnected")
		conn.Close()
	}()
	log.Println(conn.RemoteAddr(), "connected")

	fmt.Fprintln(conn, "Welcome to nodistinguisher, the best crypto service to encrypt your short messages!")
	fmt.Fprintln(conn, "We do not only hide the message, but also the message length. Nobody else does this!\n")
	fmt.Fprintln(conn, "See the following example, you won't be able to decrypt it:\n")
	fmt.Fprintln(conn, encryptMessage(KEY, SECRET_MESSAGE))
	fmt.Fprintln(conn, "\nConvinced? Great! Now go ahead and encrypt your messages!\n\n")

	r := bufio.NewReader(conn)
	for {
		fmt.Fprintln(conn, "Enter operation:")
		operation, err := r.ReadString('\n')
		if err != nil {
			return
		}
		operation = strings.TrimSpace(operation)
		if !(operation == "encrypt" || operation == "decrypt" || operation == "quit") {
			fmt.Fprintln(conn, "Invalid operation! Try encrypt, decrypt or quit.")
			continue
		}

		if operation == "quit" {
			fmt.Fprintln(conn, "Thanks for using our service. Bye!")
			return
		}

		fmt.Fprintln(conn, "Enter password:")
		password, err := r.ReadString('\n')
		if err != nil {
			return
		}
		password = strings.TrimSpace(password)

		if operation == "encrypt" {
			fmt.Fprintln(conn, "Enter short message:")
		} else if operation == "decrypt" {
			fmt.Fprintln(conn, "Enter ciphertext:")
		}
		message, err := r.ReadString('\n')
		if err != nil {
			return
		}
		message = strings.TrimSpace(message)

		if operation == "encrypt" {
			if len(message) > 180 {
				fmt.Fprintln(conn, "Message must be at most 180 characters. We encrypt SHORT messages!\n")
				continue
			}

			fmt.Fprintln(conn, "\nYour encrypted message is:")
			fmt.Fprintln(conn, encryptMessage(password, message))
			fmt.Fprintln(conn)
		} else if operation == "decrypt" {
			if len(message) != 384 {
				fmt.Fprintln(conn, "Invalid ciphertext length.\n")
				continue
			}
			plaintext, ok := decryptMessage(password, message)
			if ok {
				fmt.Fprintln(conn, "\nYour decrypted message is:")
				fmt.Fprintln(conn, plaintext)
				fmt.Fprintln(conn)
			} else {
				fmt.Fprintln(conn, "Invalid ciphertext\n")
				continue
			}
		}
	}
}
