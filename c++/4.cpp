#include <iostream>
#include <fstream>
#include <string>

using std::string;

void usage(){
	std::cout << "Usage: main <word> <filename>\n";
}

int wordOccurrence(const string &word, const string &filename){
	FILE *file;
	file = fopen(filename.c_str(), "rb");

	if (file == NULL){
		std::cerr << "Failed to open file " << filename << '\n';
		return -1;
	}

	fseek(file, 0, SEEK_END);
	long fileSize = ftell(file);
	rewind(file);

	char *buffer = (char*)malloc(sizeof(char)*fileSize);
	if (buffer == NULL){
		std::cerr << "Failed to malloc\n";
		return -1;
	}

	size_t result = fread(buffer, 1, fileSize, file);
	if (result != fileSize){
		std::cerr << "Failed to read file into buffer\n";
		return -1;
	}

	int ret = 0;

	bool state = false;
	for (int i = 0; i < fileSize; i++){
		if (buffer[i] == 'h'){
			state = true;
			continue;
		}

		ret += state && buffer[i] == 'i';
		state = false;
	}

	fclose(file);
	free(buffer);
	return ret;
}

int main(int argc, char *argv[]){
	if (argc < 3){
		usage();
		return 1;
	}

	std::cout << "\033[36m" << wordOccurrence(argv[1], argv[2]) << "\033[0m\n";
}
