#include "DOM-GCC-model.c"

//Função que cria um conjunto de peças ordenadas de maneira crescente
void cria_conjunto_de_pecas (Conjunto_de_pecas jogo)
{

    int i, j, count = 0;

    
        for(i = 0; i < 7; i++){
            for (j = 0; j < 7; j++){
                jogo.pecas[count].valores[0] = i;
                jogo.pecas[count].valores[1] = j;
                count++;
            }
            j = 0;
        } i = 0;
}

//TODO FUNÇÃO PARA EMBARALHAR PEÇAS