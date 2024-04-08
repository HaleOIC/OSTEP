#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

static int cnt = 0;
static char prev, cur;

/* Make zip for given file pointer */
void make_zip(FILE *fp);

int main(int argc, char **argv) {
    /* Make sure you input files to compress */
    if (argc == 1) {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wzip: can't open %s\n", argv[i]);
            return 1;
        }
        make_zip(fp);
        fclose(fp);
    }
    /* Check whether we have left some charaters to output */
    if (cnt != 0) {
        fwrite(&cnt, sizeof(cnt), 1, stdout);
        fwrite(&prev, sizeof(prev), 1, stdout);
    }
}

void make_zip(FILE *fp) {
    while ((cur = fgetc(fp)) != EOF) {
        if (cnt == 0) {
            cnt += 1;
            prev = cur;
            continue;
        }
        /* Encounter with unseen characters print it out with frequency */
        if (prev != cur) {
            fwrite(&cnt, sizeof(cnt), 1, stdout);
            fwrite(&prev, sizeof(prev), 1, stdout);
            cnt = 1;
            prev = cur;
        } else {
            cnt += 1;
        }
    }
}