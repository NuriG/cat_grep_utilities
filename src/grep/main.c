#include <stdio.h>

#include "func_grep.h"

int main(int argc, char* argv[]) {
  opt options = {0};

  if (argc > 2) {
    func_check_e(argc, argv, &options);
    func_check_f(argc, argv, &options);
    if (options.stopread != 1) {
      parcer(argc, argv, &options);
      if (options.fileCounter > 0 && options.stopread != 1) {
        output_grep_functions(options);
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