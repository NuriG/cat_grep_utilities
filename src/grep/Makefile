.PHONY: clean all

all: func_grep.o main.o
	gcc func_grep.o main.o -o s21_grep

func_grep.o: func_grep.c
	gcc -c func_grep.c -o func_grep.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -rf *.o s21_grep