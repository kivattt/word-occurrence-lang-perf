import sys

def usage():
	print("Usage: python3 1.py <word> <filename>")

def wordOccurrence(word, filename):
	f = open(filename, "r")

	ret = 0
	for line in f:
		for split in line.split():
			if split == word:
				ret += 1

	return ret

if len(sys.argv) < 3:
	usage()
	sys.exit(1)

print("\033[36m" + str(wordOccurrence(sys.argv[1], sys.argv[2])) + "\033[0m")
