#include "DOM-GCC-model.c"
#include "DOM-GCC-view.c"

//Prototype das funcoes do controller
void cria_conjunto_de_pecas (Peca pecas_do_jogo[28]);
void embaralha_conjunto_de_pecas(Peca pecas_do_jogo[28]);
void reorganiza_conjunto_de_pecas(Peca pecas_do_jogo[28]);


//Funcao que chama o menu principal
void inicia_jogo(){
    
    int opcao = 0;
    while(opcao != 4){
        opcao = apresenta_menu();
        Peca pecas_do_jogo[28];
        cria_conjunto_de_pecas(pecas_do_jogo);

        switch (opcao)
        {
        case 1:
            mostra_pecas(pecas_do_jogo);
            break;
        case 2:
            embaralha_conjunto_de_pecas(pecas_do_jogo);
            mostra_pecas(pecas_do_jogo);
            break;
        case 3:
            reorganiza_conjunto_de_pecas(pecas_do_jogo);
            mostra_pecas(pecas_do_jogo);
            break;
        default:
            break;
        }
    }
}

//Funcao que cria um conjunto de peças ordenadas de maneira crescente
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
        } 
    count = 0;
}

//Função que embaralha as pecas de um conjunto
void embaralha_conjunto_de_pecas(Peca pecas_do_jogo[28])
{
    Peca pecas_aux[28];

      for (int i = 0; i < 28; i++){
        int k = rand() % 28;
        int j = rand() % 28;

        //Aqui nos usamos estrategia de swap para a permutacao dos elementos
        pecas_aux[i] = pecas_do_jogo[k];
        pecas_do_jogo[k] = pecas_do_jogo [j];
        pecas_do_jogo[j] = pecas_aux[i]; 
    }
}

//Função que reorganiza as pecas de um conjunto
void reorganiza_conjunto_de_pecas(Peca pecas_do_jogo[28])
{
    int i;
    Peca pecas_aux[28];
    cria_conjunto_de_pecas(pecas_aux);
    
    for (i = 0; i < 28; i++){
        pecas_do_jogo[i] = pecas_aux[i];
    }
}