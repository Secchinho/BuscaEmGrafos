#include <stdbool.h>
#define CANAIS 100
#define VIZINHOS 5

typedef struct grafo {
    int listaAdj[CANAIS][VIZINHOS]; //Matriz que simula uma lista de adjacencia
    int grau[CANAIS];
} Grafo;

void construirGrafo(Grafo *g, bool canAdulto[CANAIS]);