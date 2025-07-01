#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafo.h"
#define CANAIS 100

void construirGrafo(Grafo *g, bool canAdulto[CANAIS])
{
    for (int canal = 0; canal < CANAIS; canal++)
    {
        //Inicializando o grau para todos os canais
        g->grau[canal] = 0;

        //Pula os canais adultos
        if(canAdulto[canal])
        {
            continue;
        }

        int vizinho; //Canal atingível após um clique
        int canalReal = canal + 1; // Para os cálculos, já que o canal está armazenado em um vetor de 0 a 99

        //Botão para somar 1
        vizinho = canalReal % CANAIS;
        if(!canAdulto[vizinho])
        {
            g->listaAdj[canal][g->grau[canal]++] = vizinho;
        }

        //Botão para subtrair 1
        if (canal == 0)
        {
            vizinho = 99;
        }
        else
        {
            vizinho = canal - 1;
        }
        if(!canAdulto[vizinho])
        {
            g->listaAdj[canal][g->grau[canal]++] = vizinho;
        }

        //Botão para multiplicar por 2
        if(canalReal < 51)
        {
            vizinho = (canalReal * 2) - 1;
            if(!canAdulto[vizinho])
            {
                g->listaAdj[canal][g->grau[canal]++] = vizinho;
            }
        }

        //Botão para dividir por 2
        if(canalReal % 2 == 0){
            vizinho = (canalReal / 2) - 1;
            if(!canAdulto[vizinho])
            {
                g->listaAdj[canal][g->grau[canal]++] = vizinho;
            }
        }

        //Botão para multiplicar por 3
        if(canalReal < 34){
            vizinho = (canalReal * 3) - 1;
            if(!canAdulto[vizinho])
            {
                g->listaAdj[canal][g->grau[canal]++] = vizinho;
            }
        }
    }
}