//Esse arquivo até o momento nao precisa fazer imports
#include <stdio.h>
#include <stdlib.h>

//Estrutura de uma Peca
typedef struct{
    int valores[2];
    char status; //NULL, '1', '2', '3', '4'
}Peca;


typedef struct{
    //LADO DIREITO = valores_mesa[0] | LADO ESQUERDO = valores_mesa[1]
    int valores[2];
    char status; //NULL, '1', '2', '3', '4'
}Mesa;


//Variáveis globais
char J1 = 'J1';
char J2 = 'J2';
char zero = 'NULL';
char compra = 'C';
int x = 0;
int pc1 = 0;
int pc2 = 0;
int n = 7;
int vez;

//Estruturas do jogo
Peca pecas_do_jogo[28];
Mesa estrutura_mesa[28];