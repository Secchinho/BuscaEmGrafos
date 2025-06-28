#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafo.h"
#define CANAIS 100

void construirGrafo(Grafo *g, bool canAdulto[CANAIS])
{
    for (int canal = 0; canal < CANAIS; canal++)
    {
        if(canAdulto[canal]){
            continue;
        }

        g->grau[canal] = 0;

        //Botão para somar 1
        int vizinho = (canal + 1) % CANAIS;
        if(!canAdulto[vizinho]){
            g->listaAdj[canal][g->grau[canal]++] = vizinho;
        }

        //Botão para subtrair 1
        if (canal == 0){
            vizinho = 99;
        }
        else{
            vizinho = canal - 1;
        }

        if(!canAdulto[vizinho]){
            g->listaAdj[canal][g->grau[canal]++] = vizinho;
        }

        //Botão para multiplicar por 2
        if(canal < CANAIS / 2){
            vizinho = canal *2;
            if(!canAdulto[vizinho]){
                g->listaAdj[canal][g->grau[canal]++] = vizinho;
            }
        }

        //Botão para multiplicar por 3
        if(canal * 3 < CANAIS){
            vizinho = canal * 3;
            if(!canAdulto[vizinho])
            {
                g->listaAdj[canal][g->grau[canal]++] = vizinho;
            }
        }

        //Botão para dividir por 2
        if(canal % 2 == 0){
            vizinho = canal / 2;
            if(!canAdulto[vizinho])
            {
                g->listaAdj[canal][g->grau[canal]++] = vizinho;
            }
        }
        
    }
}