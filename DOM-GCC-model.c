#include "DOM-GCC-Main.c"
#include <stdio.h>
#include <stdlib.h>

//variáveis usadas em todas as funções
int i = 0;
int x = 0;
int pc1 = 0;
int pc2 = 0;
int n = 7;

//parametrando funções
void embaralhapecas();
void montapecas();
void mostrapecas();

//estrutura base para as peças
struct cria_peças{
    int lado1;
    int lado2;
    char stat;
};
struct cria_peças peças[28];

//estutura da mesa que será usada posteriormente
struct mostrar_mesa{
    int ladoE;
    int ladoD;
};
struct mostrar_mesa mesa[28];

//estrutura auxiliar para embaralhamento
struct rand_auxiliar{
    int aux;
};
struct rand_auxiliar auxiliar;
