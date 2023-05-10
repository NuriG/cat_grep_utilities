#ifndef CAT_H
#define CAT_H

typedef struct options {
    int b;
    int e;
    int n;
    int s;
    int t;
    int v;
    char illegaloptions;
    int stopread; // 0 - read, 1 - stop read
    int startcounterfile;
} opt;

void parcer(int argc, char* argv[], opt* options);

void testoptions(opt options);

int fileisopen(int argc, char* argv[], int i); // return 1 - closed, 0 - open

int fileoutput(char* argv[], int i, opt options);

#endif