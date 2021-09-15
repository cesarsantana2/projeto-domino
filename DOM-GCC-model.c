//Esse arquivo até o momento nao precisa fazer import

//Estrutura de uma Peca
typedef struct{
    int valores[2];
    //O status de cada peça reflete a sua atual situação.
    //Caso ela ja esteja na mesa, seu status sera M, caso esteja para ser usada, sera N,
    //caso a mesma tenha um valor igual a 1,  2, ou C como status, pertecenra ao primeiro, e ao segundo jogardor ou computador.
    char status; //NULL -> N,  '1', '2', C, M
}Peca;

typedef struct{
    //LADO DIREITO = valores_mesa[0] | LADO ESQUERDO = valores_mesa[1]
    int valores[2];
    Peca pecas[28];
    Peca pecas_na_mesa[28];
     //O status da mesa reflete a quem pertence a jogadfa
    //Caso a mesma tenha um valor igual a 1 ou a 2, pertecenra ao primeiro ou ao segundo
    //jogador consequentemente.
    char status; //'1', '2', C
}Mesa;
