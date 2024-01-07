package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"strconv"
)

func usage() {
	fmt.Println("Usage: main <filename>")
}

// Hardcoded to match "hi"
func wordOccurrence(filename string) int {
	buf, err := ioutil.ReadFile(filename)
	if err != nil {
		log.Fatal(err)
	}

	ret := 0
	for _, b := range buf {
		if b == 'h' {
			continue
		}

		if b == 'i' {
			ret++
		}
	}

	return ret
}

func main() {
	if len(os.Args) < 2 {
		usage()
		os.Exit(1)
	}

	fmt.Println("\033[36m" + strconv.Itoa(wordOccurrence(os.Args[1])) + "\033[0m")
}
