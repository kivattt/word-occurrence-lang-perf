import sys

def iOccurrence(filename):
    f = open(filename, "r")

    ret = 0
    while (byte := f.read(1)):
        if byte == 'i':
            ret += 1

    return ret

print("\033[36m" + str(iOccurrence(sys.argv[1])) + "\033[0m")
