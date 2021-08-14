#include "DOM-GCC-model.c"

//função de apresentação das peças
void mostra_pecas(struct Peca *pecas)
{
    for (int i = 0; i < 28; i++)
    {
        printf("[%d | %d]\n", pecas[i].lado[0], peças[i].lado[1]);
        fflush(stdout);
    }
}


//TODO FUNÇÃO PARA EXIBIR O MENU