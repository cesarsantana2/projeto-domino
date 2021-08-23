#include "DOM-GCC-model.c"
#include "DOM-GCC-view.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Peca pecas_do_jogo[28];
Peca pecas_aux[28];
Mesa estrutura_mesa[28];

//Prototype das funcoes do controller
void cria_conjunto_de_pecas (Peca pecas_do_jogo[28]);
void embaralha_conjunto_de_pecas(Peca pecas_do_jogo[28]);
void reorganiza_conjunto_de_pecas(Peca pecas_do_jogo[28]);
void cria_mesa(Mesa estrutura_mesa[28]);


//Funcao que chama o menu principal
void inicia_jogo(){
    
    int opcao = 0;
    while(opcao != 6){
        opcao = apresenta_menu();
        Peca pecas_do_jogo[28];
        cria_conjunto_de_pecas(pecas_do_jogo);
        cria_mesa(pecas_do_jogo);

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
        case 4:
            distribui_pecas_rand(pecas_do_jogo);
            break;
        case 5:
            //jogo contra o computador
            break;
        default:
            exit(0);
        }
    }
}

//Funcao que cria um conjunto de peças ordenadas de maneira crescente
void cria_conjunto_de_pecas(Peca pecas_do_jogo[28])
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


//Função que cria e organiza a mesa
void cria_mesa(Mesa estrutura_mesa[28])
{
    int i = 0;
    int j = 0;
    int count = 0;

        for(i = 0; i < 7; i++){
            for (j = i; j < 7; j++){
                estrutura_mesa[count].status = "NULL";
                estrutura_mesa[count].status = "NULL";
                count++;
            }
        } 
    count = 0;
}

//Função que distribui peças aleatoriamente para o jogador 1, jogador 2 e para a estrutura de compra (C)
void distribui_pecas_rand(Peca pecas_do_jogo[28])
{
    embaralha_conjunto_de_pecas(pecas_do_jogo);
    srand((unsigned) time(NULL));
    int ale;

    for (int i = 0; i < 7; i++)
    {
        ale = rand()%28;
        printf("%d\n", ale);
        pecas_do_jogo[ale].status = "J1";
    }

    for (int i = 0; i < 7; i++)
    {
        ale = rand()%28;
        printf("%d\n", ale);
        pecas_do_jogo[ale].status = "J2";
    }

    for (int i = 0; i < 13; i++)
    {
        ale = rand()%28;
        printf("%d\n", ale);
        pecas_do_jogo[ale].status = "C";
    }
}

//Função que passa três primeiras peças da estrutura de compra para o jogador 1 ou 2 
void comprar_pecas(Peca pecas_do_jogo[28])
{
    char jog;
    printf("Identifique o jogador (J1 ou J2): ");
    scanf("%c\n", &jog);
    jog = toupper(jog);

    do
    {
        for (int i = 0; i < 2; i++) 
        {
        if (pecas_do_jogo[i].status == 'C') {
            pecas_do_jogo[i].status = jog;
            i = 28;
        }
        }
        printf("\n3 peças compradas com sucesso para %c.\n\n", jog);
    } while ((jog == "J1") || (jog == "J2"));

    //Necessário fazer adaptação: reentrada caso o usuário não digite j1 ou j2.
}

char primeira_jogada(Peca pecas_do_jogo[28], Mesa estrutura_mesa[28])
{
    int identidade;
    for (int i = 0; i < 27; i++)
    {
        if((pecas_do_jogo[i].valores[0] == 6) && (pecas_do_jogo[i].valores[1] == 6))
            {
                estrutura_mesa[14].valores[0] = 6;
                estrutura_mesa[14].valores[1] = 6;
                pecas_do_jogo[i].status = identidade;
                pecas_do_jogo[i].status = "NULL";
            }
    }
    mostra_mesa(estrutura_mesa);
    return identidade;
}

void giragira(int id, Peca pecas_do_jogo[28])
{
    int aux;
    pecas_do_jogo[id].valores[0] = aux;
    pecas_do_jogo[id].valores[1] = pecas_do_jogo[id].valores[0];
    aux = pecas_do_jogo[id].valores[1];
}

//Função que dá fluidez ao jogo
void jogada()
{
    int idjogador, op, indexpeca, simnao; 
    char indexmesa;
    idjogador = primeira_jogada(pecas_do_jogo, estrutura_mesa);
    printf("A primeira jogada foi do jogador %d.\n", idjogador);
    
    /*
    if (idjogador == 1)
    {
        apresenta_jogador_2(pecas_do_jogo);
    }
    else
    {
        apresenta_jogador_1(pecas_do_jogo);
    }
    */

    do
    {
    
        printf("1 - Jogar\n");
        printf("2 - Comprar\n");
        printf("3 - Passar\n");
        printf("0 - Sair\n");
        printf("Digite sua opção: ");
        scanf("%d\n", &op);

        switch (op)
        {
        case 1:
            printf("Opção 1: jogar!\n");
            mostra_mesa(estrutura_mesa);
            if (idjogador == 1)
            {
                printf("Peças do jogador 2:\n");
                apresenta_jogador_2(pecas_do_jogo);
                printf("Escolha a peça para jogar: \n");
                scanf("%d\n", &indexpeca);
                printf("Deseja girar a peca? (S/N): \n");
                scanf("%d\n", &simnao);
                simnao = toupper(simnao);

                if (simnao == 'S')
                {
                    giragira(indexpeca, pecas_do_jogo);
                }
                

                printf("Escolha o lado da mesa (D ou E): \n");
                scanf("%c\n", &indexmesa);
                indexmesa = toupper(indexmesa);

                if (indexmesa == 'D')
                {
                    estrutura_mesa[indexpeca].valores[0] = pecas_do_jogo[indexpeca].valores[0];
                    estrutura_mesa[indexpeca].valores[1] = pecas_do_jogo[indexpeca].valores[1];
                    mostra_mesa(estrutura_mesa);
                }
                if (indexmesa == 'E')
                {
                    estrutura_mesa[indexpeca].valores[0] = pecas_do_jogo[indexpeca].valores[0];
                    estrutura_mesa[indexpeca].valores[1] = pecas_do_jogo[indexpeca].valores[1];
                    mostra_mesa(estrutura_mesa);
                }
                
            }
            else
            {
                printf("Peças do jogador 1:\n");
                apresenta_jogador_1(pecas_do_jogo);
                printf("Escolha a peça para jogar: \n");
                scanf("%d\n", &indexpeca);
                printf("Deseja girar a peca? (S/N): \n");
                scanf("%d\n", &simnao);
                simnao = toupper(simnao);
                if (simnao == 'S')
                {
                    giragira(indexpeca, pecas_do_jogo);
                }
                printf("Escolha o lado da mesa (D ou E): \n");
                scanf("%c\n", &indexmesa);
                indexmesa = toupper(indexmesa);

                if (indexmesa == 'D')
                {
                    estrutura_mesa[indexpeca].valores[0] = pecas_do_jogo[indexpeca].valores[0];
                    estrutura_mesa[indexpeca].valores[1] = pecas_do_jogo[indexpeca].valores[1];
                    mostra_mesa(estrutura_mesa);
                }
                if (indexmesa == 'E')
                {
                    estrutura_mesa[indexpeca].valores[0] = pecas_do_jogo[indexpeca].valores[0];
                    estrutura_mesa[indexpeca].valores[1] = pecas_do_jogo[indexpeca].valores[1];
                    mostra_mesa(estrutura_mesa);
                }
            }

            break;
    
        case 2:
            comprar_pecas(pecas_do_jogo);
            break;
    
        case 3:
            /* code */
            break;
    
        default:
            exit(0);
        }

    } while (op != 0);
    
    
}