#include <stdio.h>
#include <stdlib.h>
#include "DOM-GCC-controller.c"
#include "DOM-GCC-model.c"
#include "DOM-GCC-view.c"

int main()
{
    //Declarando um conjunto de pecas
    conjunto_de_pecas pecas_do_jogo;
    //Preencho o conjunto de pecas recem criadas com 28 estruturas de peca
    pecas_do_jogo = cria_conjunto_de_pecas();

    mostra_pecas(pecas_do_jogo);

}