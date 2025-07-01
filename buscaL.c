#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "grafo.h"
#define CANAIS 100

void bLargura(Grafo* g, int v, int visita[CANAIS]) {
    Fila *f = criarFila();
    
    for (int i = 0; i < CANAIS; i++)
    {
        visita[i] = -1;
    }
    
    //o vértice inicial recebe 0, pois já estamos nele
    visita[v] = 0;
    inserirFila(f, v);

    while (!estaVazia(f)) 
    {
        //canalProces corresponde ao índice do canal que será processado
        int canalProces = removerDaFila(f);
        for (int i = 0; i < g->grau[canalProces]; i++) 
        {
            //vizinhoCanal corresponde a um vizinho do canal em canalProces
            int vizinhoCanal = g->listaAdj[canalProces][i];

            //checa se esse vizinho já foi visitado anteriormente
            if (visita[vizinhoCanal] == -1) 
            {
                inserirFila(f, vizinhoCanal);
                //soma o caminho até "aqui" mais um clique para chegar no vizinho
                visita[vizinhoCanal] = visita[canalProces] + 1;
            }
        }
    }
}

