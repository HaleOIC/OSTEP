#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/* self-defined version of grep */
void search_file(FILE *, char *);

int main(int argc, char** argv) {
    /* Print out usage message */
    if (argc == 1) {
        fprintf(stdout, "wgrep: searchterm [file ...]\n");
        return 1;
    }

    /* Case1: only give a keyword */
    char *keyword = argv[1];
    if (argc == 2) {
        char buffer[BUFFER_SIZE];
        while (fgets(buffer, BUFFER_SIZE, stdin)) {
            if (strstr(buffer, keyword) != NULL) {
                printf("%s", buffer);
            }
        }
    }

    /* Case2: enumerate each file and find keyword */
    for (int i = 2; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wgrep: cannot open file\n");
            return 1;
        }
        search_file(fp, keyword);
    }
    return 0;
}

/* Pls make sure fp is not nullptr */
void search_file(FILE *fp, char *key) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&line, &len, fp)) != -1) {
        /* search keyword in this line */
        if (strstr(line, key) != NULL) {
            printf("%s", line);
        }
    }
}