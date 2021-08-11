/* PROJETO DOMINÓ SEMANA 1
CAIO DE CARVALHO ENGLER, CESAR SANTANA, GABRIEL CAVALCANTI
GRUPO GCCT
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrapecas();
void embaralhapecas();
void organizarpecas();

struct cria_peças{
    int lado1;
    int lado2;
    char stat;
} peças[28];

struct mostrar_mesa{
    int ladoE;
    int ladoD;
} mesa[28];

int i = 0;
int x = 0;
int pc1 = 0;
int pc2 = 0;
int n = 7;

int main()
{
    int op;

    printf("  ･ﾟ･･ﾟ･ DOMINÓ GCCT ･ﾟ･･ﾟ･  \n");
    printf("Selecione sua opcao:\n");
    printf("1. Mostrar peças\n");
    printf("2. Embaralhar peças\n");
    printf("3. Organizar peças\n");
    printf("4. Sair do jogo\n");
    scanf("%d\n", &op);

    switch (op)
    {
    case 1:
        montapecas();
        mostrapecas();
    case 2:
        embaralhapecas();
        mostrapecas();
    case 3:
        montapecas();
        mostrapecas();
    case 4:
        exit(0);
    }
}

void embaralhapecas()
{
    srand((unsigned) time(NULL));
    int ale1 = rand()%6;
    int ale2 = rand()%6;

    for (i; i < n; i++)
    {
        for (pc2 = pc1; pc2 < n; pc2++)
        {
            peças[x].lado1 = ale1;
            peças[x].lado2 = ale2;
            pc2++;
            x++;
        }
        pc1++;
        pc2 = pc1;
    }

}

void montapecas()
{
    for (pc1; pc1 < n; pc1++)
    {
        for (pc2 = pc1; pc2 < n; pc2++)
        {
            peças[x].lado1 = pc1;
            peças[x].lado2 = pc2;
            x++;
        }
        pc2 = pc1;
    }
}


void mostrapecas()
{
    for (i = 0; i < 28; i++)
    {
        printf("[%d | %d]\n", peças[i].lado1, peças[i].lado2);
        fflush(stdout);
    }
}
