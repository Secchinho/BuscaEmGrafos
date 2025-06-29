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
    int visita[CANAIS];
    bool canAdulto[CANAIS] = {false};

    Grafo g;

    // Lendo da entrada padrão (stdin), usando "<"
    scanf("%d %d %d", &canAtual, &canTv, &qtdAdulto);

    for(int i = 0; i < qtdAdulto; i++)
    {
        scanf("%d", &numCanAdult);
        // Acessa o índice correto (canal 1 está no índice 0)
        canAdulto[numCanAdult-1] = true;
    }

    construirGrafo(&g, canAdulto);

    // Converte para os índices 0-99 para a busca
    canAtual--;
    canTv--;
    
    bLargura(&g, canAtual, visita);

    // Imprime o resultado final como nos exemplos
    printf("A quantidade de cliques para atingir o canal correto é: %d\n", visita[canTv]);

    return 0;
}