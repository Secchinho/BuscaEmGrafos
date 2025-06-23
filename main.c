#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(int argc, char const *argv[])
{
    if(argc != 2)
    {
        exit(1);
    }

    FILE *arq = fopen(argv[1], "r");

    return 0;
}
