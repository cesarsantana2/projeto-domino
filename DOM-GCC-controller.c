#include "DOM-GCC-model.c"

//Função que cria um conjunto de peças ordenadas de maneira crescente
void cria_conjunto_de_pecas (Peca pecas_do_jogo[28])
{

    int i = 0;
    int j = 0;
    int count = 0;

    
        for(i = 0; i < 7; i++){
            for (j = i; j < 7; j++){

                pecas_do_jogo[count].valores[0] = i;
                pecas_do_jogo[count].valores[1] = j;

                count++;
            }
            j = 0;
        } i = 0;
}

//TODO FUNÇÃO PARA EMBARALHAR PEÇAS