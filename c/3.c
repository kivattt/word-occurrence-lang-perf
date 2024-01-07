#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void panic(const char *error_message) {
	fprintf(stderr, "%s\n", error_message);
	exit(EXIT_SUCCESS);
}

size_t word_occurence(const char *word, const char *filename) {
	FILE *file = fopen(filename, "r");

    if (file == NULL) panic("Couldn't find file in current directory");

    if (fseek(file, 0, SEEK_END) != 0) fflush(file);
    long file_size = ftell(file);
    rewind(file);

    char *buffer = malloc(file_size);

    if (buffer == NULL) panic("Couldn't allocate memory");

    (void)fread(buffer, sizeof(char), file_size, file);

    size_t word_count = 0;
	int state = 0;
	for (int i = 0; i < file_size; i++){
		if (buffer[i] == 'h'){
			state = 1;
			continue;
		}

		word_count += state && buffer[i] == 'i';
	}

    (void)fclose(file);
    free(buffer);

    return word_count;
}

int main(int argc, char **argv) {
	printf("\033[36m%lu\033[0m\n", word_occurence(argv[1], argv[2]));
}

