#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"
#define CANAIS 100

int main(int argc, char const *argv[])
{
    if(argc != 2)
    {
        exit(1);
    }

    FILE *arq = fopen(argv[1], "r");

    int canAtual = 0, canTv = 0, qtdAdulto = 0;
    bool canAdulto[CANAIS] = {false};

    //Lendo a primeira linha do arquivo

    fscanf(arq, "%d %d %d", &canAtual, &canTv, &qtdAdulto);

    fclose(arq);
    return 0;
}
