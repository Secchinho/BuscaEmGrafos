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
        if(canAdulto[canal]){
            continue;
        }

        int vizinho; //Canal atingível após um clique
        int canal_real = canal + 1; // Para os cálculos matemáticos, já que o canal está armazenado em um vetor de 0 a 99

        //Botão para somar 1
        vizinho = (canal + 1) % CANAIS;
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
        if(canal_real < 51){
            vizinho = (canal_real * 2) - 1;
            if(!canAdulto[vizinho]){
                g->listaAdj[canal][g->grau[canal]++] = vizinho;
            }
        }

        //Botão para dividir por 2
        if(canal_real % 2 == 0){
            vizinho = (canal_real / 2) - 1;
            if(!canAdulto[vizinho])
            {
                g->listaAdj[canal][g->grau[canal]++] = vizinho;
            }
        }

        //Botão para multiplicar por 3
        if(canal_real < 34){
            vizinho = (canal_real * 3) - 1;
            if(!canAdulto[vizinho])
            {
                g->listaAdj[canal][g->grau[canal]++] = vizinho;
            }
        }
    }
}