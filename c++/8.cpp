#include <iostream>
#include <thread>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <immintrin.h>

using std::string;

void usage(){
	std::cout << "Usage: main <filename>\n";
}

int wordOccurrence(const string &filename){
	FILE *file;
	file = fopen(filename.c_str(), "rb");

	if (file == NULL){
		std::cerr << "Failed to open file " << filename << '\n';
		return -1;
	}

	struct stat statbuf;
	stat(filename.c_str(), &statbuf);

	char *data = (char*)mmap(NULL, statbuf.st_size, PROT_READ, MAP_SHARED, fileno(file), 0);
	int ret = 0;

	for (int i = 0; i < statbuf.st_size; i += 8) {
		unsigned long long chunk = *reinterpret_cast<unsigned long long*>(&data[i]);
		for (int j = 0; j < 8; j++) {
			ret += ((chunk >> (i*8)) & 0xff) == 'i';
		}
	}

	munmap(data, statbuf.st_size);
	fclose(file);
	return ret;
}

int main(int argc, char *argv[]){
	if (argc < 2){
		usage();
		return 1;
	}

	std::cout << "\033[36m" << wordOccurrence(argv[1]) << "\033[0m\n";
};
