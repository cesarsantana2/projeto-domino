#include <stdio.h>

int main(){

int opcao = 0;

do{

printf("Jogo de dominó (PUC-SP)");
printf("\n\n");
printf("1) Iniciar novo Jogo\n");
printf("2) Continuar a jogar\n");
printf("3) Salvar Jogo\n");
printf("4) Carregar Jogo");
printf("5) Regras do Jogo\n");
printf("6) Sair do Jogo\n\n");


scanf("%d", &opcao);
}while(opcao!=6);}
