#include "DOM-GCC-main.c"
#include <stdio.h>
#include <stdlib.h>

//função de apresentação das peças
void mostra_pecas(struct peca *pecas)
{
    for (i = 0; i < 28; i++)
    {
        printf("[%d | %d]\n", pecas[i].lado[0], peças[i].lado[1]);
        fflush(stdout);
    }
}


//TODO FUNÇÃO PARA EXIBIR O MENU