//#include "DOM-GCC-Main.c"
#include "DOM-GCC-Model.c"
#include "DOM-GCC-View.c"

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

//função que cria as 28 peças do dominó
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
