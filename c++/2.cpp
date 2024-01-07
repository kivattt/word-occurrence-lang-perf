#include <iostream>
#include <fstream>
#include <sstream>
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

	std::stringstream buf;
	buf << file.rdbuf();

	int ret = 0;
	string split = "";
	for (char c : buf.str()){
		if (c == ' ' || c == '\t' || c == '\r' || c == '\n'){ // :skull:
			ret += split == word;

			split = "";
			continue;
		}

		split += c;
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
