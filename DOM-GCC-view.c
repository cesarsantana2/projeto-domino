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
int apresenta_menu_de_jogada(char jogador_da_vez){

    int opcao = 0;

    if(jogador_da_vez == '1'){
        puts("Vez do jogador 1");
    }else if(jogador_da_vez == '2'){
        puts("Vez do joadpr 2");
    }else {
        puts("Vez do computador");
    }

    puts("Escolha uma opcao abaixo:\n");
    puts("1 - Mesa do Domino");
    puts("2 - Ver suas pecas");
    puts("3 - Comprar peca");
    puts("4 - Jogar");
    puts("Voltar ao Menu Principal");
    
    scanf("%d", &opcao);
    return opcao;
}


//Função de apresentação das peças
void mostra_pecas(Peca *pecas_do_jogo)
{
    for (int i = 0; i < 28; i++)
    {
        printf("[%d | %d]", pecas_do_jogo[i].valores[0], pecas_do_jogo[i].valores[1]);
    }
}

//to-do reavaliar funcao
//Função de apresentação da mesa
void mostra_mesa(Mesa mesa_do_jogo, int quantidade_de_pecas_jogadas)
{
    int i = 0;

    printf("__________________\n");
    printf("M E S A:\n");
    printf("__________________\n");

    for (i = 0; i < quantidade_de_pecas_jogadas; i++){
        printf("[%d|%d]", mesa_do_jogo.pecas_na_mesa[i].valores[0], mesa_do_jogo.pecas_na_mesa[i].valores[1]);
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

void exibe_regras_do_jogo(){

    //TODO
}