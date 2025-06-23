all: compila

compila: main.o fila.o
	gcc main.o fila.o -o prog

main.o: main.c
	gcc -c main.c

fila.o: fila.c
	gcc -c fila.c

rm:
	rm main.o fila.o prog

del:
	del main.o fila.o prog
