#include "func_grep.h"

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parcer(int argc, char* argv[], opt* options) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && strlen(argv[i]) == 1 && options->check_e != 1 &&
        options->check_f != 1) {
      if (i != argc - 1) {
        strcpy(options->templateSave[options->templateCounter], argv[i]);
        options->templateCounter++;
      } else if (i == argc - 1) {
        options->stopread = 1;
      }
    } else if (argv[i][0] == '-' && strlen(argv[i]) == 2) {
      switch (argv[i][1]) {
        case 'e':
          options->e = 1;
          if (i != argc - 1) {
            strcpy(options->templateSave[options->templateCounter], argv[++i]);
            options->templateCounter++;
          }
          break;
        case 'i':
          options->i = 1;
          if (i != argc - 1 && options->templateCounter == 0) {
            if (options->check_e != 1 && argv[i + 1][0] != '-' &&
                options->check_f != 1) {
              strcpy(options->templateSave[options->templateCounter],
                     argv[++i]);
              options->templateCounter++;
            }
          }
          break;
        case 'v':
          options->v = 1;
          if (i != argc - 1 && options->templateCounter == 0) {
            if (options->check_e != 1 && argv[i + 1][0] != '-' &&
                options->check_f != 1) {
              strcpy(options->templateSave[options->templateCounter],
                     argv[++i]);
              options->templateCounter++;
            }
          }
          break;
        case 'c':
          options->c = 1;
          if (i != argc - 1 && options->templateCounter == 0) {
            if (options->check_e != 1 && argv[i + 1][0] != '-' &&
                options->check_f != 1) {
              strcpy(options->templateSave[options->templateCounter],
                     argv[++i]);
              options->templateCounter++;
            }
          }
          break;
        case 'l':
          options->l = 1;
          if (i != argc - 1 && options->templateCounter == 0) {
            if (options->check_e != 1 && argv[i + 1][0] != '-' &&
                options->check_f != 1) {
              strcpy(options->templateSave[options->templateCounter],
                     argv[++i]);
              options->templateCounter++;
            }
          }
          break;
        case 'n':
          options->n = 1;
          if (i != argc - 1 && options->templateCounter == 0) {
            if (options->check_e != 1 && argv[i + 1][0] != '-' &&
                options->check_f != 1) {
              strcpy(options->templateSave[options->templateCounter],
                     argv[++i]);
              options->templateCounter++;
            }
          }
          break;
        case 'h':
          options->h = 1;
          if (i != argc - 1 && options->templateCounter == 0) {
            if (options->check_e != 1 && argv[i + 1][0] != '-' &&
                options->check_f != 1) {
              strcpy(options->templateSave[options->templateCounter],
                     argv[++i]);
              options->templateCounter++;
            }
          }
          break;
        case 's':
          options->s = 1;
          if (i != argc - 1 && options->templateCounter == 0) {
            if (options->check_e != 1 && argv[i + 1][0] != '-' &&
                options->check_f != 1) {
              strcpy(options->templateSave[options->templateCounter],
                     argv[++i]);
              options->templateCounter++;
            }
          }
          break;
        case 'f':
          options->f = 1;
          if (i != argc - 1) {
            FILE* f;
            f = fopen(argv[++i], "r");
            char string_save[1024];
            while (fgets(string_save, 1024, f) != NULL) {
              string_save[strcspn(string_save, "\n")] = 0;
              strcpy(options->templateSave[options->templateCounter],
                     string_save);
              options->templateCounter++;
            }
          }
          break;
        case 'o':
          options->o = 1;
          if (i != argc - 1 && options->templateCounter == 0) {
            if (options->check_e != 1 && argv[i + 1][0] != '-' &&
                options->check_f != 1) {
              strcpy(options->templateSave[options->templateCounter],
                     argv[++i]);
              options->templateCounter++;
            }
          }
          break;

        default:
          options->stopread = 1;
          break;
      }
    } else if (argv[i][0] == '-' && strlen(argv[i]) > 2) {
      int check_e_in_that_argv = 0;  // DELETE ME
      for (int j = 1; j < strlen(argv[i]); j++) {
        switch (argv[i][j]) {
          case 'e':
            options->e = 1;
            if (j != strlen(argv[i]) - 1) {
              char* result_without_e = argv[i] + j + 1;
              j = strlen(argv[i]);
              strcpy(options->templateSave[options->templateCounter],
                     result_without_e);
              options->templateCounter++;
            } else if ((j == strlen(argv[i]) - 1) && i < argc - 1) {
              strcpy(options->templateSave[options->templateCounter],
                     argv[++i]);
              options->templateCounter++;
            }
            break;
          case 'i':
            options->i = 1;
            break;
          case 'v':
            options->v = 1;
            break;
          case 'c':
            options->c = 1;
            break;
          case 'l':
            options->l = 1;
            break;
          case 'n':
            options->n = 1;
            break;
          case 'h':
            options->h = 1;
            break;
          case 's':
            options->s = 1;
            break;
          case 'f':
            options->f = 1;
            if (j != strlen(argv[i]) - 1) {
              char* result_without_f = argv[i] + j + 1;
              j = strlen(argv[i]);
              FILE* f;
              f = fopen(result_without_f, "r");
              char string_save[1024];
              while (fgets(string_save, 1024, f) != NULL) {
                string_save[strcspn(string_save, "\n")] = 0;
                strcpy(options->templateSave[options->templateCounter],
                       string_save);
                options->templateCounter++;
              }
            } else if ((j == strlen(argv[i]) - 1) && i < argc - 1) {
              FILE* f;
              f = fopen(argv[++i], "r");
              char string_save[1024];
              while (fgets(string_save, 1024, f) != NULL) {
                string_save[strcspn(string_save, "\n")] = 0;
                strcpy(options->templateSave[options->templateCounter],
                       string_save);
                options->templateCounter++;
              }
            }
            break;
          case 'o':
            options->o = 1;
            break;

          default:
            options->stopread = 1;
            break;
        }
      }
    } else {
      if (options->fileCounter == 0 && i == 1 && options->check_e != 1 &&
          options->check_f != 1) {
        strcpy(options->templateSave[options->templateCounter], argv[i]);
        options->templateCounter++;
      } else {
        if (strcmp(argv[i], "-") == 0 && options->check_e == 1) {
          options->stopread = 1;
        }
        if (strcmp(argv[i], "-") == 0 && options->check_f == 1) {
          options->stopread = 1;
        }
        strcpy(options->fileSave[options->fileCounter], argv[i]);
        options->fileCounter++;
      }
    }
  }
}

int fileisopen(char* argv[], int i) {
  FILE* file;
  if ((file = fopen(argv[i], "r"))) {
    fclose(file);
    return 0;  // File is open
  }
  return 1;  // File is closed
}

int fileisopenOptions(char (*argv)[200], int i) {
  FILE* file;
  if ((file = fopen(argv[i], "r"))) {
    fclose(file);
    return 0;  // File is open
  }
  return 1;  // File is closed
}

void func_check_e(int argc, char* argv[], opt* options) {
  int check_exist_file_after_e_without_stopread = 0;
  int exist_controversial_situation = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && strlen(argv[i]) <= 2) {
      if (argv[i][1] == 'e') {
        options->check_e = 1;
        if (i + 1 >= argc) {
          if (exist_controversial_situation != 1) {
            options->stopread = 1;
          } else {
            exist_controversial_situation = 0;
          }
        }
        if (options->check_e == 1 && options->stopread != 1 && argc == 3) {
          if (i + 1 >= argc - 1) {
            options->stopread = 1;
          }
        }
        if (options->check_e == 1 && options->stopread != 1 && argc > 3) {
          for (int p = i + 1; p < argc; p++) {
            if (argv[p][0] != '-') {
              check_exist_file_after_e_without_stopread =
                  1;  // 1 file exist in line
            }
          }
          if (check_exist_file_after_e_without_stopread == 0) {
            options->stopread = 1;
          }
        }
      }
    }
    if (argv[i][0] == '-' && strlen(argv[i]) > 2) {
      int exist_controversial_situation_two = 0;
      for (int j = 1; j < strlen(argv[i]); j++) {
        if (argv[i][j] == 'e') {
          options->check_e = 1;
          if (j == strlen(argv[i]) - 1 && i == argc - 1) {
            options->stopread = 1;
          }
          if (j < strlen(argv[i]) - 1) {
            exist_controversial_situation_two = 1;
          }
          if (j == strlen(argv[i]) - 1 && i < argc - 1 &&
              argv[i + 1][0] == '-' && exist_controversial_situation_two != 1) {
            options->stopread = 0;
            exist_controversial_situation = 1;
          }
        }
      }
    }
  }
}

void func_check_f(int argc, char* argv[], opt* options) {
  int check_file_before_f = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && strlen(argv[i]) <= 2) {
      if (argv[i][1] == 'f') {
        options->check_f = 1;
        if (i >= argc - 1) {
          options->stopread = 1;
        }
        if (options->stopread != 1 && i < argc - 1) {
          i++;

          if (fileisopen(argv, i) == 0 && i < argc - 1) {
            int check_file_after_f = 0;  // 1 -file exist
            for (int p = i + 1; p < argc; p++) {
              if (argv[p][0] != '-') {
                check_file_after_f = 1;
              }
            }
            if (check_file_after_f == 0) {
              options->stopread = 1;
            }
          } else if (fileisopen(argv, i) == 0 && i == argc - 1 &&
                     check_file_before_f == 0) {
            options->stopread = 1;
          } else if (fileisopen(argv, i) == 0 && i == argc - 1 &&
                     check_file_before_f != 0) {
          } else {
            options->return_no_such_file_for_f = 1;
            options->stopread = 1;
          }
        }
      }
    } else {
      check_file_before_f++;
    }
    if (argv[i][0] == '-' && strlen(argv[i]) > 2) {
      for (int j = 1; j < strlen(argv[i]); j++) {
        if (argv[i][j] == 'f') {
          options->check_f = 1;
          if (j == strlen(argv[i]) - 1 && i == argc - 1) {
            options->stopread = 1;
          }
          if (j == strlen(argv[i]) - 1) {
            FILE* f;
            if ((f = (fopen((argv[++i]), "r")))) {
              fclose(f);
            } else {
              options->return_no_such_file_for_f = 1;
              options->stopread = 1;
            }
          }
          if (j < strlen(argv[i]) - 1) {
            char* result_without_f = argv[i] + j + 1;
            j = strlen(argv[i]);
            FILE* file;
            if ((file = fopen(result_without_f, "r"))) {
              fclose(file);
            } else {
              options->return_no_such_file_for_f = 1;
              options->stopread = 1;
            }
          }
        }
      }
    }
  }
}

void output_grep_functions(opt options) {
  char string_save[1024];
  regex_t regex;
  int count_matched_lines = 0;
  int count_matched_files = 0;
  int counter_lines = 0;
  int check_matching_files = 0;
  int check_matching_lines = 0;
  int check_no_matching_files = 0;
  int check_matching_lines_for_l = 0;
  int counter_status_o = 0;

  FILE* file;

  for (int i = 0; i < options.fileCounter; i++) {
    count_matched_lines = 0;
    count_matched_files = 0;
    counter_lines = 0;

    if ((file = fopen(options.fileSave[i], "r")) == NULL) {
      if (options.s != 1) {
        fprintf(stderr, "grep: %s: No such file or directory\n",
                options.fileSave[i]);
      }
    } else {
      while (fgets(string_save, 1024, file) != NULL) {
        counter_lines++;
        for (int j = 0; j < options.templateCounter; j++) {
          if (options.i == 1) {
            int check = regcomp(&regex, options.templateSave[j], REG_ICASE);
          } else {
            int check = regcomp(&regex, options.templateSave[j], 0);
          }
          int status = regexec(&regex, string_save, 0, NULL, REG_NEWLINE);
          if (options.c != 1 && options.l != 1) {
            if (status == 0) counter_status_o++;
          }
          if (status == 0) {
            check_matching_files = 1;
            check_matching_lines = 1;
            check_matching_lines_for_l = 1;
          } else {
            check_no_matching_files = 1;
          }
        }
        if (options.c != 1 && options.l != 1) {
          if (counter_status_o > 0 && options.v != 1) {
            if (options.n == 1) {
              if (options.fileCounter > 1 && options.h != 1) {
                printf("%s:%d:%s", options.fileSave[i], counter_lines,
                       string_save);
              } else {
                printf("%d:%s", counter_lines, string_save);
              }
            } else {
              if (options.fileCounter > 1 && options.h != 1) {
                printf("%s:%s", options.fileSave[i], string_save);
              } else {
                printf("%s", string_save);
              }
            }
          } else if (counter_status_o == 0 && options.v == 1) {
            if (options.n == 1) {
              if (options.fileCounter > 1 && options.h != 1) {
                printf("%s:%d:%s", options.fileSave[i], counter_lines,
                       string_save);
              } else {
                printf("%d:%s", counter_lines, string_save);
              }
            } else {
              if (options.fileCounter > 1 && options.h != 1) {
                printf("%s:%s", options.fileSave[i], string_save);
              } else {
                printf("%s", string_save);
              }
            }
          }
        }
        counter_status_o = 0;
        if (options.c == 1 && check_matching_lines == 1) count_matched_lines++;
        check_matching_lines = 0;
      }

      if (options.v == 1) {
        count_matched_lines = counter_lines - count_matched_lines;
        if (check_matching_files == 1 && check_no_matching_files == 1) {
          check_matching_lines_for_l == 1;
        } else if (check_matching_files == 0 && check_no_matching_files == 1) {
          check_matching_lines_for_l ^= 1;
        }
      }

      if (options.c == 1 && options.l != 1) {
        if (options.h == 1 || options.fileCounter == 1) {
          printf("%d\n", count_matched_lines);
        } else {
          printf("%s:%d\n", options.fileSave[i], count_matched_lines);
        }
      } else if (options.c == 1 && options.l == 1) {
        if (options.h == 1 || options.fileCounter == 1) {
          printf("%d\n", check_matching_lines_for_l);
        } else {
          printf("%s:%d\n", options.fileSave[i], check_matching_lines_for_l);
        }
      }
      check_matching_lines_for_l = 0;

      if (options.v == 0 && options.l == 1) {
        if (check_matching_files == 1) {
          printf("%s\n", options.fileSave[i]);
        }
      } else if (options.v == 1 && options.l == 1) {
        if (check_no_matching_files == 1) {
          printf("%s\n", options.fileSave[i]);
        }
      }
      check_matching_files = 0;
      check_no_matching_files = 0;

      rewind(file);
      regfree(&regex);

      fclose(file);
    }
  }
}

void testoptions(opt options) {
  printf("\noptions.e = %d\n", options.e);
  printf("options.i = %d\n", options.i);
  printf("options.v = %d\n", options.v);
  printf("options.c = %d\n", options.c);
  printf("options.l = %d\n", options.l);
  printf("options.n = %d\n", options.n);
  printf("options.h = %d\n", options.h);
  printf("options.s = %d\n", options.s);
  printf("options.f = %d\n", options.f);
  printf("options.o = %d\n\n", options.o);
}
