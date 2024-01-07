package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func usage() {
	fmt.Println("Usage: main <filename>")
}

// Hardcoded to match "hi"
func wordOccurrence(filename string) int {
	file, err := os.Open(filename)
	if err != nil {
		log.Fatal(err)
	}

	defer file.Close()

	scanner := bufio.NewScanner(file)
	scanner.Split(bufio.ScanRunes)

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}

	ret := 0
	for scanner.Scan() {
		if scanner.Text()[0] == 'h' {
			continue
		}

		if scanner.Text()[0] == 'i' {
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
