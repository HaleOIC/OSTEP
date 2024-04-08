#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/* Make unzip for given file pointer */
void make_unzip(FILE *fp);

int main(int argc, char **argv) {
    /* Make sure you input files to compress */
    if (argc == 1) {
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wzip: can't open %s\n", argv[i]);
            return 1;
        }
        make_unzip(fp);
        fclose(fp);
    }
}

void make_unzip(FILE *fp) {
    char cur;
    int cnt;
    while (fread(&cnt, sizeof(int), 1, fp)) {
        if (!fread(&cur, sizeof(char), 1, fp)) {
            exit(1);
        }
        for (int i = 0; i < cnt; i++) {
            fwrite(&cur, sizeof(char), 1, stdout);
        }
    }
}