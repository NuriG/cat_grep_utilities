#include <stdio.h>

#include "cat_func.h"

int main(int argc, char *argv[]) {
  opt options = {0};

  if (argc > 1) {
    parcer(argc, argv, &options);
    if (options.stopread == 0 && options.startcounterfile != 0) {
      for (int i = options.startcounterfile; i < argc; i++) {
        if (fileisopen(argc, argv, i) == 0) {
          fileoutput(argv, i, options);
        } else {
          fprintf(stderr, "s21_cat: %s: No such file or directory\n", argv[i]);
        }
      }
    } else if (options.stopread == 0 && options.startcounterfile == 0) {
      fprintf(stderr, "usage: s21_cat [-benst] [file ...]\n");
    } else {
      fprintf(stderr, "s21_cat: illegal option -- %c\n",
              options.illegaloptions);
      fprintf(stderr, "usage: s21_cat [-benst] [file ...]\n");
    }
  } else {
    fprintf(stderr, "usage: cat [-benst] [file ...]\n");
  }
  return 0;
}