//função de apresentação das peças
void mostra_pecas(Peca pecas_do_jogo[28])
{
    for (int i = 0; i < 28; i++)
    {
        printf("[%d | %d]\n", pecas_do_jogo[i].valores[0], pecas_do_jogo[i].valores[1]);

    }
}


//TODO FUNÇÃO PARA EXIBIR O MENU