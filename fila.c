#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* criarFila()
{
    Fila *f = (Fila*)malloc(sizeof(Fila));

    if(f)
    {
        f->ini = f->fim = NULL;
    }
    return f;
}

int estaVazia(Fila *f)
{
    return (f->ini == NULL);
}

int removerDaFila(Fila* f)
{
    if(!estaVazia(f))
    {
        NoFila *aux;
        int rm = 0;

        aux = f->ini;
        rm = aux->info;

        f->ini = aux->prox;

        if(f->ini == NULL)
        {
            f->fim = NULL;
        }

        free(aux);
        return rm;
    }
    else
    {
        printf("\nLista vazia!\n");
    }
}

void inserirFila(Fila* f, int v)
{
    NoFila *novo = (NoFila*)malloc(sizeof(NoFila));

    if(novo)
    {
        novo->info = v;
        novo->prox = NULL;
        
        if(!estaVazia(f))
        {
            f->fim->prox = novo;
        }
        else
        {
            f->ini = novo;
        }
        f->fim = novo;
    }
    else
    {
        printf("\nFalha na alocação da memória!\n");
        exit(1);
    }
}

void liberarFila(Fila* f)
{
    if(!estaVazia(f))
    {
        NoFila *p, *temp;
        for(p = f->ini; p != NULL; p = temp)
        {
            temp = p->prox;
            free(p);
        }

        free(f);
    }
    else
    {
        printf("\nLista Vazia!\n");
    } 
}

void imprimeFila(Fila* f)
{
    if(!estaVazia(f))
    {
        NoFila *p;
        printf("\nImprimindo valores:\n");

        for(p = f->ini; p != NULL; p = p->prox)
        {
            printf("%.2f\n", p->info);
        }
    }
    else
    {
        printf("\nLista Vazia!\n");
    }
}