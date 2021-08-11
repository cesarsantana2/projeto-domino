#include <stdio.h>
#include <stdlib.h>
#include "DOM-GCC-Controller.c"
#include "DOM-GCC-Model.c"
#include "DOM-GCC-View.c"

int main()
{
    int op;

    do{
    printf("\n\n");
    printf("  == DOMINÓ GCC ==  \n");
    printf("1. Mostrar peças\n");
    printf("2. Embaralhar peças\n");
    printf("3. Organizar peças\n");
    printf("4. Sair do jogo\n\n");
    printf("Selecione sua opcao: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        montapecas();
        mostrapecas();
        printf("\n\n");
        break;
    case 2:
        montapecas();
        embaralhapecas();
        mostrapecas();
        printf("\n\n");
        break;
    case 3:
        montapecas();
        mostrapecas();
        printf("\n\n");
        break;
    case 4:
        exit(0);
    }}while(op!=4);
}

//função para embaralhar as peças
void embaralhapecas()
{
    srand((unsigned) time(NULL));
    for (pc1; pc1 < n; pc1++)
    {
        for (pc2 = pc1; pc2 < n; pc2++)
        {
            fflush(stdout);
            int ale = rand()%28;

            peças[ale].lado1 = auxiliar[ale].aux1;
            peças[x].lado1 = peças[ale].lado1;
            auxiliar[ale].aux1 = peças[x].lado1;
            peças[ale].lado2 = auxiliar[ale].aux2;
            peças[x].lado2 = peças[ale].lado2;
            auxiliar[ale].aux2 = peças[x].lado2;
            x++;
        }
        pc2 = pc1;
    }
}
