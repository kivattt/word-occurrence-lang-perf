#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORDERING_EQUAL 0

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

    char *buffer = malloc(file_size + 1);

    if (buffer == NULL) panic("Couldn't allocate memory");

    (void)fread(buffer, sizeof(char), file_size, file);

    buffer[file_size + 1] = '\0';

    size_t word_count = 0;
    char *token = strtok(buffer, " \n\r\t");

    while (token != NULL) {
        if (strcmp(word, token) == ORDERING_EQUAL) word_count++;
        token = strtok(NULL, " \n\r\t");
    }

    (void)fclose(file);
    free(buffer);

    return word_count;
}

int main(int argc, char **argv) {
	printf("\033[36m%lu\033[0m\n", word_occurence(argv[1], argv[2]));
}
