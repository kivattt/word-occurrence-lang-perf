#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORDERING_EQUAL 0
#define BUFFER_SIZE 2024

void panic(const char *error_message) {
	fprintf(stderr, "%s\n", error_message);
	exit(EXIT_SUCCESS);
}

size_t word_occurence(const char *word, const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) panic("Couldn't find file in current directory");

    int current_char;
    size_t buffer_size = BUFFER_SIZE;  
    size_t buffer_len = 0;
    char *buffer = malloc(BUFFER_SIZE);

    if (buffer == NULL) panic("Couldn't allocate memory to buffer");

    while ((current_char = fgetc(file)) != EOF) {
        buffer[buffer_len++] = (char)current_char;

        if (buffer_len == buffer_size - 1) {
            buffer_size *= 2;  
            buffer = realloc(buffer, buffer_size);

            if (buffer == NULL) panic("Couldn't allocate memory to buffer");
        }
    }

    buffer[buffer_len] = '\0';

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

