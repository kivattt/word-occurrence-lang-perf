#include <iostream>
#include <fstream>
#include <string>

using std::string;

void usage(){
	std::cout << "Usage: main <word> <filename>\n";
}

int wordOccurrence(const string &word, const string &filename){
	std::ifstream file(filename);
	if (!file.is_open()){
		std::cerr << "Failed to open file " << filename << '\n';
		return -1;
	}

	int ret = 0;
	int delimiter;
	string split;

	for (string line; std::getline(file, line);){
		string split = "";
		for (char c : line){
			if (c == ' ' || c == '\t' || c == '\r' || c == '\t'){ // :skull:
				ret += split == word;

				split = "";
				continue;
			}

			split += c;
		}
	}

	return ret;
}

int main(int argc, char *argv[]){
	if (argc < 3){
		usage();
		return 1;
	}

	std::cout << "\033[36m" << wordOccurrence(argv[1], argv[2]) << "\033[0m\n";
}
