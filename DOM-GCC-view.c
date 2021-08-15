//Esse arquivo até o momento nao precisa fazer imports

//Função de apresentação das peças
void mostra_pecas(Peca pecas_do_jogo[28])
{
    for (int i = 0; i < 28; i++)
    {
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
        puts("4 - Sair do jogo\n");

        scanf("%d", &opcao);
        return opcao;
}