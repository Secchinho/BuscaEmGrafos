#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "grafo.h"
#define CANAIS 100

void bLargura(Grafo* g, int v, int visita[CANAIS]) {
    Fila *f = criarFila();
    for (int i = 0; i < CANAIS; i++)
        visita[i] = -1;

    visita[v] = 0;
    inserirFila(f, v);

    while (!estaVazia(f)) {
        int x = removerDaFila(f);
        for (int i = 0; i < g->grau[x]; i++) {
            int y = g->listaAdj[x][i];
            if (visita[y] == -1) {
                inserirFila(f, y);
                visita[y] = visita[x] + 1;
            }
        }
    }
}
