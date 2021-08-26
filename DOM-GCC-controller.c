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
    for (pc1; pc1 < n; pc1++)
    {
        for (pc2 = pc1; pc2 < n; pc2++)
        {
            estrutura_mesa[x].status = zero;
            estrutura_mesa[x].status = zero;
            x++;
        }
        pc2 = pc1;
    }
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
        pecas_do_jogo[ale].status = J1;
    }

    for (int i = 0; i < 7; i++)
    {
        ale = rand()%28;
        printf("%d\n", ale);
        pecas_do_jogo[ale].status = J2;
    }

    for (int i = 0; i < 13; i++)
    {
        ale = rand()%28;
        printf("%d\n", ale);
        pecas_do_jogo[ale].status = compra;
    }
}

//Função que passa uma peça da estrutura de compra para o jogador 1 ou 2 
void comprar_pecas(Peca pecas_do_jogo[28])
{
    char jog;
    int verif = 0;
    printf("Identifique o jogador (J1 ou J2): ");
    scanf("%c\n", &jog);
    jog = toupper(jog);

    //Variável verif = se a entrada está correta, a compra ocorre
    //e a variável assume o valor 1, saindo do loop.
    while (verif == 0)
    {
        if ((jog == J1) || (jog == J2))
        {
            if (pecas_do_jogo[i].status == compra) {
                pecas_do_jogo[i].status = jog;
                i = 28;
            }
            printf("\n1 peça compradas com sucesso para %c.\n\n", jog);
            verif = 1;
        }
        else
        printf("Entrada errada! :(\n\n");
    }
    
}

int primeira_jogada(Peca pecas_do_jogo[28], Mesa estrutura_mesa[28])
{
    int identidade;
    for (int i = 0; i < 27; i++)
    {
        if((pecas_do_jogo[i].valores[0] == 6) && (pecas_do_jogo[i].valores[1] == 6))
            {
                //Coloca a peça [6 | 6] no primeiro lugar da mesa
                estrutura_mesa[0].valores[0] = 6;
                estrutura_mesa[0].valores[1] = 6;
                if (pecas_do_jogo[i].status == J1)
                    identidade = 1;
                if (pecas_do_jogo[i].status == J2)
                    identidade = 2;
                pecas_do_jogo[i].status = zero;
            }
    }
    mostra_mesa(estrutura_mesa);
    return identidade;
}

//Funcao que inverte a peca do jogo
void giragira(int id, Peca pecas_do_jogo[28])
{
    int aux;
    pecas_do_jogo[id].valores[0] = aux;
    pecas_do_jogo[id].valores[1] = pecas_do_jogo[id].valores[0];
    aux = pecas_do_jogo[id].valores[1];
}

void nheee(int vez)
{
    printf("A primeira jogada foi do jogador %d.\n", vez);
    if (vez == 1)
        vez = 2;
    if (vez == 2)
        vez = 1;

    printf("Peças do jogador %d:\n", vez);
    apresenta_jogador(vez, pecas_do_jogo);
}

void escolhe_pecas(Peca pecas_do_jogo[28], Mesa estrutura_mesa[28])
{
    int index;
    printf("Escolha a peca a ser colocada na mesa: ");
    scanf("%d", &index);

    //Analisar mesa, encontrar a extremidade e o valor correspondente
    //Comparar o valor da peça (index dentro do array) (método de validação da jogada)
    //Se são iguais, colocar peça na mesa
    //Se não, reentrada de valor do index da peça
}

void jogo()
{
    int sentinela = 0;
    int op, vez;

    vez = primeira_jogada(pecas_do_jogo, estrutura_mesa);
    nheee(vez);

    do
    {
        
        
        op = submenu_jogo();

        switch (op)
        {
        case 1:
            printf("Voce escolheu: JOGAR!\n\n");
            apresenta_jogador(vez, pecas_do_jogo);
            //Chama função para colocar peça na mesa
            //If-else pra adicionar ou subtrair 1 na variável "vez"
            continue;
        
        case 2:
            printf("Voce escolheu: COMPRAR PEÇA!\n\n");
            comprar_pecas(pecas_do_jogo);
            continue;
        
        case 3:
            printf("Voce escolheu: PASSAR JOGADA\n\n");
            if (vez == 1)
                vez = 2;
            else    vez = 1;
            continue;
        
        case 0:
            printf("Voce escolheu: SAIR\n\n");
            sentinela = 1;
            continue;
        }

    } while (sentinela = 0);
    
}