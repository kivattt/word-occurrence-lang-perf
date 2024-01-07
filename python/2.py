import sys

def usage():
	print("Usage: python3 2.py <filename>")

def wordOccurrence(filename):
	f = open(filename, "r")

	ret = 0
	for line in f:
		for char in line:
			if char == 'h':
				continue

			if char == 'i':
				ret += 1

	return ret

if len(sys.argv) < 2:
	usage()
	sys.exit(1)

print("\033[36m" + str(wordOccurrence(sys.argv[1])) + "\033[0m")
