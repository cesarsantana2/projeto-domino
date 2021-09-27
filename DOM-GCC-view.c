//Função que apresenta o menu principal
int apresenta_menu_principal(){

    int opcao = 0;

    puts("--- BEM VINDO AO JOGO DE DOMINO DO GRUPO GCC ---\n\n");
    puts("Escolha uma opcao abaixo:\n");
    puts("1 - Iniciar novo Jogo");
    puts("2 - Continuar a Jogar");
    puts("3 - Salvar jogo");
    puts("4 - Carregar Jogo");
    puts("5 - Regras do Jogo");
    puts("6 - Sair do jogo\n");

    scanf("%d", &opcao);
    return opcao;
}

//Função que apresenta o menu onde eh informada a quantidade de jogadores que participarao da partida
int apresenta_menu_quantidade_jogadores(){

    int opcao = 0;

    puts("--- BEM VINDO AO JOGO DE DOMINO DO GRUPO GCC ---\n\n");
    puts("Selecione a quantidade de jogadores: [1] [2]\n");

    scanf("%d", &opcao);
    return opcao;
}

//Função que apresenta o menu de opcao disponiveis a cada jogada de cada jogador
int apresenta_menu_de_jogada(){

    int opcao = 0;

    puts("--- JOGO DE DOMINO DO GRUPO GCC ---\n\n");
    puts("Escolha uma opcao abaixo:\n");
    puts("1 - Mesa do Domino");
    puts("2 - Ver suas pecas");
    puts("3 - Comprar peca");
    puts("4 - Jogar");
    puts("Voltar ao Menu Principal");
}


//Função de apresentação das peças
void mostra_pecas(Peca pecas_do_jogo[28])
{
    for (int i = 0; i < 28; i++)
    {
        printf("[%d | %d]\n", pecas_do_jogo[i].valores[0], pecas_do_jogo[i].valores[1]);
    }
}

//to-do reavaliar funcao
//Função de apresentação da mesa
void mostra_mesa(Mesa estrutura_mesa[28])
{
    printf("__________________\n");
    printf("M E S A:\n");
    printf("__________________\n");
    for (int i = 0; i < 28; i++) {
        if (estrutura_mesa[i].status == 'N') 
            continue;
        else
            printf("[%d | %d]       ", estrutura_mesa[i].valores[0], estrutura_mesa[i].valores[1]);
    }
    printf("\n__________________\n");
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
        if(pecas_do_jogo[i].status == '1')
        {
            printf("&d.[%d | %d]        ", i, pecas_do_jogo[i].valores[0], pecas_do_jogo[i].valores[1]);
        }
    }
    printf("\n\n");
}

//Função de apresentação das peças do Jogador 2
void apresenta_jogador_2(Peca pecas_do_jogo[28])
{
    printf("Peças do jogador 2: ");
    for (int i = 0; i < 27; i++)
    {
        if(pecas_do_jogo[i].status == '2')
        {
            printf("&d.[%d | %d]        ", i, pecas_do_jogo[i].valores[0], pecas_do_jogo[i].valores[1]);
        }
    }
    printf("\n\n");
}

void menu_do_fim_do_jogo(){

    //TODO

}

void exibe_pontucao_dos_melhores(){

    //TODO
}
