#include "DOM-GCC-Main.c"
#include <stdio.h>
#include <stdlib.h>

//função de apresentação das peças
void mostrapecas()
{
    for (i = 0; i < 28; i++)
    {
        printf("[%d | %d]\n", peças[i].lado1, peças[i].lado2);
        fflush(stdout);
    }
}
