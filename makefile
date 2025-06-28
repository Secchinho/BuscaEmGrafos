all: compila

compila: main.o fila.o buscaL.o grafo.o
	gcc main.o fila.o buscaL.o grafo.o -o prog

main.o: main.c
	gcc -c main.c

fila.o: fila.c
	gcc -c fila.c

buscaL.o: buscaL.c
	gcc -c buscaL.c

grafo.o: grafo.c
	gcc -c grafo.c

rm:
	rm main.o fila.o buscaL.o grafo.o prog

del:
	del main.o fila.o prog
