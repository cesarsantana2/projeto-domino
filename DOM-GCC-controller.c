#include "DOM-GCC-Main.c"
#include "DOM-GCC-Model.c"
#include "DOM-GCC-View.c"

//Função que cria um conjunto de peças ordenadas de maneira crescente
void cria_conjunto_de_pecas (struct conjunto_de_pecas *pecas)
{
    int i = 0, j = 0, count = 0;
        for(i; i < 7; i++){
            for (j; j < 7, j++){
                pecas[count].valores[0] = i;
                pecas.valores[1] = j;
                count++
            }
        }
}
