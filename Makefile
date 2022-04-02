main: main.o tests.o
	gcc main.o tests.o -o main.exe

tests.o: tests.c
	gcc -c tests.c -o tests.o

main.o: main.c
	gcc -c main.c -o main.o