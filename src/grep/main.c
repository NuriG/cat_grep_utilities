#include <stdio.h>
#include "func_grep.h"

int main(int argc, char* argv[]) {
    opt options = {0};

    if (argc > 2) {
        func_check_e(argc, argv, &options); // save options.stopread = 1 if finded error
        //printf("\nafter_e_check - options.stopread = %d\n", options.stopread);
        func_check_f(argc, argv, &options); // save options.stopread = 1 if finded error
        //printf("\nafter_f_check - options.stopread = %d\n", options.stopread);
        if (options.stopread != 1) {
            parcer(argc, argv, &options);
            if (options.fileCounter > 0 && options.stopread != 1) {
                output_grep_functions(options);

                // printf("\nREAD  READ  READ   READ  READ  READ   READ  READ  READ\n");
                // for (int i = 0; i < options.templateCounter; i++) {
                // printf("%s - template\n", options.templateSave[i]);
                // if (i == options.templateCounter - 1) printf("\n");
                // }
                // for (int i = 0; i < options.fileCounter; i++) {
                // printf("%s - file\n", options.fileSave[i]);
                // if (i == options.fileCounter - 1) printf("\n");
                // }
                // for (int i = 0; i < options.templateCounterAsFile; i++) {
                // printf("%s - template in file\n", options.templateSaveAsFile[i]);
                // if (i == options.templateCounterAsFile - 1) printf("\n");
                // }
                // testoptions(options);
                
            } else {
                fprintf(stderr, "usage: ./s21_grep [options] template [file_name]\n");
            }
        } else {
            fprintf(stderr, "usage: ./s21_grep [options] template [file_name]\n");
        }
    } else {
        fprintf(stderr, "usage: ./s21_grep [options] template [file_name]\n");
    }
    return 0;
}