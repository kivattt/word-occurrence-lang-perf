package main

import (
	"fmt"
	"log"
	"os"
	"strconv"
	"syscall"
)

func usage() {
	fmt.Println("Usage: main <filename>")
}

// Hardcoded to match "hi"
func wordOccurrence(filename string) int {
	f, err := os.Open(filename)
	if err != nil {
		log.Fatalf("Failed to open " + filename)
	}
	defer f.Close()

	fi, err := f.Stat()
	if err != nil {
		log.Fatalf("Failed to stat " + filename)
	}

	size := fi.Size()

	data, err := syscall.Mmap(int(f.Fd()), 0, int(size), syscall.PROT_READ, syscall.MAP_SHARED)
	if err != nil {
		log.Fatalf("Failed to mmap " + filename)
	}

	defer func() {
		if err := syscall.Munmap(data); err != nil {
			log.Fatalf("Failed to munmap " + filename)
		}
	}()

	ret := 0
	for _, b := range data {
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
