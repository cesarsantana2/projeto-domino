//função de apresentação das peças
void mostra_pecas(Conjunto_de_pecas jogo)
{
    for (int i = 0; i < 28; i++)
    {
        printf("[%d | %d]\n", jogo.pecas[i].valores[0], jogo.pecas[i].valores[1]);

    }
}


//TODO FUNÇÃO PARA EXIBIR O MENU