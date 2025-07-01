#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"
#include "grafo.h"
#include "buscaL.h"
#define CANAIS 100

int main()
{
    int canAtual = 0;
    int canTv = 0;
    int numCanAdult = 0;
    int qtdAdulto = 0;
    int visita[CANAIS]; //armazena a quantidade de cliques para visita de cada canal
    bool canAdulto[CANAIS] = {false};

    Grafo g;

    // Lendo a entrada padrão (stdin), usando "<"
    scanf("%d %d %d", &canAtual, &canTv, &qtdAdulto);

    for(int i = 0; i < qtdAdulto; i++)
    {
        scanf("%d", &numCanAdult);
        // Acessa o índice correto, já que o vetor vai de 0 a 99
        canAdulto[numCanAdult - 1] = true;
    }

    construirGrafo(&g, canAdulto);

    // Converte para os índices 0-99 para a busca
    canAtual--;
    canTv--;
    
    bLargura(&g, canAtual, visita);

    // Imprime o resultado final
    if(visita[canTv] != -1)
    {
        printf("\nA quantidade de cliques para atingir o canal correto é: %d\n", visita[canTv]);
    }
    else
    {
        printf("\nImpossível chegar ao canal misericórdia sem passar por um canal adulto\n");
    }

    return 0;
}