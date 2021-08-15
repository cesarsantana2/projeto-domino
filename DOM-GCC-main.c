#include <stdio.h>
#include <stdlib.h>
#include "DOM-GCC-controller.c"
#include "DOM-GCC-view.c"

int main()
{

    // menu_principal();


    //Declarando um conjunto de pecas e preencho o conjunto de pecas recem criadas com 28 estruturas de peca
    Peca pecas_do_jogo[28];
    
    //Criando um conjunto de pecas validas para o jogop
    cria_conjunto_de_pecas(pecas_do_jogo);

    //Mostrando as pecas do jogo recem criadas
    mostra_pecas(pecas_do_jogo);

    //Embaralhando as pecas
    embaralha_conjunto_de_pecas(pecas_do_jogo);

    //Dando espaco entre os prints
    printf("\n\n\n\n\n");

    //Mostrando pecas embaralhadas
    mostra_pecas(pecas_do_jogo);

    reorganiza_conjunto_de_pecas(pecas_do_jogo);

    //Dando espaco entre os prints
    printf("\n\n\n\n\n");

    //Reorganizando as pecas
    mostra_pecas(pecas_do_jogo);


}