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
    printf("\n__________________\n");
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


int submenu_jogo()
{
    int op;
    printf("1 - Jogar\n");
    printf("2 - Comprar\n");
    printf("3 - Passar\n");
    printf("0 - Sair\n");
    printf("Digite sua opção: ");
    scanf("%d\n", &op);

    return op;
}

//!! !! ENCONTRAR JEITO DE ABSTRAIR O USO DAS DUAS SEGUINTES FUNÇÕES !! !!
//Se a última jogada foi do jogador 1, mostrar as peças do jogador 2 e prosseguir o jogo;
//Se a última jogada foi do jogador 2, mostrar as peças do jogador 1 e prosseguir o jogo;
void apresenta_jogador(int vez, Peca pecas_do_jogo[28])
{
    char id;
    if (vez == 1)
        id = J1;
    else
        id = J2;
    
    printf("Peças do jogador %c: ", id);
    for (int i = 0; i < 27; i++)
    {
        if(pecas_do_jogo[i].status == id)
        {
            printf("&d.[%d | %d]        ", i, pecas_do_jogo[i].valores[0], pecas_do_jogo[i].valores[1]);
        }
    }
    printf("\n\n");
}
