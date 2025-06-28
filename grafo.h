#include <stdbool.h>
#define CANAIS 100
#define VIZINHOS 5

typedef struct grafo {
    int listaAdj[CANAIS][VIZINHOS];
    int grau[CANAIS];
} Grafo;

void construirGrafo(Grafo *g, bool canAdulto[CANAIS]);