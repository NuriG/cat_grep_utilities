#ifndef FUNC
#define FUNC

typedef struct options {
    int e;
    int i;
    int v;
    int c;
    int l;
    int n;
    int h;
    int s;
    int f;
    int o;
    int check_e;
    int check_f;
    int stopread;
    int return_no_such_file_for_f;
    char templateSave[1024][1024];
    int templateCounter;
    char fileSave[1024][1024];
    int fileCounter;
} opt;

int fileisopen(char* argv[], int i);

void parcer(int argc, char* argv[], opt* options);

void testoptions(opt options);

int fileisopenOptions(char (*argv)[200], int i);

void func_check_e(int argc, char* argv[], opt* options);

void func_check_f(int argc, char* argv[], opt* options);

void output_grep_functions(opt options);

#endif