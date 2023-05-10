.PHONY: clean all

all: cat_func.o main.o
	gcc -g main.o cat_func.o -o s21_cat

cat_func.o: cat_func.c
	gcc -g -c cat_func.c -o cat_func.o

main.o: main.c
	gcc -g -c main.c -o main.o

clean:
	rm -rf *.o s21_cat