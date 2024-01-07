package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func usage() {
	fmt.Println("Usage: main <word> <filename>")
}

func wordOccurrence(word, filename string) int {
	file, err := os.Open(filename)
	if err != nil {
		log.Fatal(err)
	}

	defer file.Close()

	scanner := bufio.NewScanner(file)

	ret := 0
	for scanner.Scan() {
		for _, split := range strings.Fields(scanner.Text()) {
			if split == word {
				ret++
			}
		}
	}

	return ret
}

func main() {
	if len(os.Args) < 3 {
		usage()
		os.Exit(1)
	}

	fmt.Println("\033[0;36m" + strconv.Itoa(wordOccurrence(os.Args[1], os.Args[2])) + "\033[0m")
}
