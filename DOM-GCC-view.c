//Esse arquivo até o momento nao precisa fazer imports

//Função de apresentação das peças
void mostra_pecas(Peca pecas_do_jogo[28])
{
    for (int i = 0; i < 28; i++)
    {
        printf("[%d | %d]\n", pecas_do_jogo[i].valores[0], pecas_do_jogo[i].valores[1]);
    }
}

//Função de apresentação da mesa
//FUNÇÃO NÃO FINALIZADA
void mostra_mesa(Mesa estrutura_mesa[28])
{
    for (int i = 0; i < 28; i++) {
        if (estrutura_mesa[i].status == 'NULL') 
            continue;
        else
            printf("[%d | %d]\n", pecas_do_jogo[i].valores[0], pecas_do_jogo[i].valores[1]);
    }
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