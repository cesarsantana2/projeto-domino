#include "DOM-GCC-model.c"
//Função de apresentação das peças
void mostra_pecas(Peca pecas_do_jogo[28])
{
    for (int i = 0; i < 28; i++)
    {
        printf("[%d | %d]\n", pecas_do_jogo[i].valores[0], pecas_do_jogo[i].valores[1]);
    }
}

//Função de apresentação da mesa
void mostra_mesa(Mesa estrutura_mesa[28])
{
    printf("__________________\n");
    printf("M E S A:\n");
    printf("__________________\n");
    for (int i = 0; i < 28; i++) {
        if (estrutura_mesa[i].status == 'NULL') 
            continue;
        else
            printf("[%d | %d]       ", pecas_do_jogo[i].valores[0], pecas_do_jogo[i].valores[1]);
    }
    printf("__________________\n");
}

//Função do menu principal
int apresenta_menu(){

    int opcao = 0;

        puts("--- BEM VINDO AO JOGO DE DOMINO DO GRUPO GCC ---\n\n");
        puts("Escolha uma opcao abaixo:\n");
        puts("1 - Mostrar pecas do jogo");
        puts("2 - Embaralhar pecas do jogo");
        puts("3 - Reorganizar pecas para novo jogo");
        puts("4 - Iniciar jogo (2 jogadores)");
        puts("5 - Iniciar jogo (contra o computador)");
        puts("6 - Sair do jogo\n");

        scanf("%d", &opcao);
        return opcao;
}

//!! !! ENCONTRAR JEITO DE ABSTRAIR O USO DAS DUAS SEGUINTES FUNÇÕES !! !!
//Se a última jogada foi do jogador 1, mostrar as peças do jogador 2 e prosseguir o jogo;
//Se a última jogada foi do jogador 2, mostrar as peças do jogador 1 e prosseguir o jogo;
//Função de apresentação das peças do Jogador 1
void apresenta_jogador_1(Peca pecas_do_jogo[28])
{
    printf("Peças do jogador 1: ");
    for (int i = 0; i < 27; i++)
    {
        if(pecas_do_jogo[i].status == 'J1')
        {
            printf("&d.[%d | %d]        ", i, pecas_do_jogo[i].valores[0], pecas_do_jogo[i].valores[1]);
        }
    }
}

//Função de apresentação das peças do Jogador 2
void apresenta_jogador_2(Peca pecas_do_jogo[28])
{
    printf("Peças do jogador 1: ");
    for (int i = 0; i < 27; i++)
    {
        if(pecas_do_jogo[i].status == 'J2')
        {
            printf("&d.[%d | %d]        ", pecas_do_jogo[i].valores[0], pecas_do_jogo[i].valores[1]);
        }
    }
}