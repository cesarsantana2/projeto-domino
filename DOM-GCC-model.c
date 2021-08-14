#include "DOM-GCC-Main.c"
#include <stdio.h>
#include <stdlib.h>

//Estrutura de uma Peca
struct Peca {
    int valores [2];
};

//Estrutura de um conjunto de peças
struct conjunto_de_pecas  {
    Peca pecas[28];
};