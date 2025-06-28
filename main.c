#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"
#include "grafo.h"
#include "buscaL.h"
#define CANAIS 100

int main(int argc, char const *argv[])
{
    int canAtual = 0;
    int canTv = 0;
    int numCanAdult = 0;
    int qtdAdulto = 0;
    int visita[CANAIS];
    bool canAdulto[CANAIS] = {false};

    Grafo g;

    if(argc != 2)
    {
        exit(1);
    }

    FILE *arq = fopen(argv[1], "r");

    //Lendo a primeira linha do arquivo
    fscanf(arq, "%d %d %d", &canAtual, &canTv, &qtdAdulto);

    for(int i = 0; i < qtdAdulto; i++)
    {
        fscanf(arq, "%d", &numCanAdult);
        canAdulto[numCanAdult-1] = true;
    }

    construirGrafo(&g, canAdulto);

    canAtual--;
    canTv--;
    
    bLargura(&g, canAtual, visita);

    printf("Número mínimo de cliques: %d\n", visita[canTv]);


    fclose(arq);
    return 0;
}
