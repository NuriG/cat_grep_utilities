#include "cat_func.h"
#include <stdio.h>
#include <string.h>

void parcer(int argc, char* argv[], opt* options) { 
    for (int i = 1; i < argc && options->stopread != 1; i++) {
        if (argv[i][0] == '-' && strlen(argv[i]) <= 2 && options->stopread != 1) {
            switch (argv[i][1])
            {
            case 'b':
            options->b = 1;
                break;
            case 'v':
            options->v = 1;
                break;
            case 'e':
            options->e = 1;
            options->v = 1;
                break;
            case 'n':
            options->n = 1;
                break;
            case 's':
            options->s = 1;
                break;
            case 't':
            options->t = 1;
            options->v = 1;
                break;
            case 'E':
            options->e = 1;
            options->v = 0;
                break;
            case 'T':
            options->t = 1;
            options->v = 0;
                break;
            default:
            options->illegaloptions = argv[i][1];
            options->stopread = 1;
                break;
            }
    } else if (argv[i][0] == '-' && strlen(argv[i]) > 2 && argv[i][1] != '-' && options->stopread != 1) {
        for (int j = 1; j < strlen(argv[i]) && options->stopread != 1; j++) {
            switch (argv[i][j])
            {
            case 'b':
            options->b = 1;
                break;
            case 'v':
            options->v = 1;
                break;
            case 'e':
            options->e = 1;
            options->v = 1;
                break;
            case 'n':
            options->n = 1;
                break;
            case 's':
            options->s = 1;
                break;
            case 't':
            options->t = 1;
            options->v = 1;
                break;
            case 'E':
            options->e = 1;
            options->v = 0;
                break;
            case 'T':
            options->t = 1;
            options->v = 0;
                break;
            default:
            options->illegaloptions = argv[i][j];
            options->stopread = 1;
                break;
            }
        }
    } else if (argv[i][0] == '-' && argv[i][1] == '-' && options->stopread != 1) {
        if (strcmp("--number-nonblank", argv[i]) == 0) {
            options->b = 1;
        } else if (strcmp("--number", argv[i]) == 0) {
            options->n = 1;
        } else if (strcmp("--squeeze-blank", argv[i]) == 0) {
            options->s = 1;
        } else {
            options->illegaloptions = argv[i][1];
            options->stopread = 1;
        }
    } else {
        options->startcounterfile = i;
        break;
    }
}
}

int fileisopen(int argc, char* argv[], int i) {
    int flag = 1; // 1 - closed, 0 - open
    FILE * file;
    if ((file = fopen(argv[i], "r"))) {
        flag = 0;
        fclose(file);
    }
    return flag;
}

int fileoutput(char* argv[], int i, opt options) {
    FILE * file = fopen(argv[i], "r");
    int ch;
    int lastch = '\n';
    int lines = 1;
    int countblanklines = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (options.s == 1) {
            if (lastch == '\n') {
                if (ch == '\n') {
                    countblanklines++;
                }
                if (ch != '\n') {
                    countblanklines = 0;
                }
            }
        }
        if (countblanklines > 1) continue;
        if (options.b == 1) {
            if (lastch == '\n') {
                if (ch != '\n') {
                    printf("%6d\t", lines++);
                }
            }
        }
        if (options.n == 1 && options.b == 0) {
            if (lastch == '\n') {
                    printf("%6d\t", lines++);
        }
        }
        if (options.e == 1) {
            if (ch == '\n') printf("$");
        }
        if (options.t == 1) {
            if (ch == '\t') {
            printf("^");
            ch = 'I';
        }
        }
        // 0 9 10 32 126 160 printf "^";  if > 126 - 64 else c + 64
        if (options.v == 1) {
            if (ch >= 0 && ch <= 31 && ch != '\n' && ch != '\t') {
                printf("^");
                ch = ch + 64;
            }
            if (ch == 127) {
                printf("^");
                ch = '?';
            }
        }
        lastch = ch;
        printf("%c", ch);
    }
    fclose(file);
}

void testoptions(opt options) {
    printf("options.b = %d\n", options.b);
    printf("options.e = %d\n", options.e);
    printf("options.n = %d\n", options.n);
    printf("options.s = %d\n", options.s);
    printf("options.t = %d\n", options.t);
    printf("options.v = %d\n", options.v);
}