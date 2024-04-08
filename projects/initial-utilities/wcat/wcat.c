#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/* Fetch file content by using fopen and fgets */
void fetch(char *);

int main(int argc, char** argv) {
    if (argc == 1) {
        /* fprintf(stderr, "Usage: %s filenames\n", argv[0]); */
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        fetch(argv[i]);
    }
    return 0;
}


void fetch(char *filename) {
    FILE *fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("wcat: cannot open file\n");
        exit(1);
    }
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        printf("%s", buffer);
    }
    fclose(fp);   
}