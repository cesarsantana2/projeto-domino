#include "DOM-GCC-model.c"
#include "DOM-GCC-view.c"
#include <time.h>

//Variáveis globais
int quantidade_de_jogadores = 0;
int quantidade_de_pecas_jogadas = 0;

//Prototype das funcoes do controller
void cria_conjunto_de_pecas (Peca pecas_do_jogo[28]);
void embaralha_conjunto_de_pecas(Peca pecas_do_jogo[28]);
void reorganiza_conjunto_de_pecas(Peca pecas_do_jogo[28]);
void distribui_pecas(Peca pecas_do_jogo[28]);
void cria_mesa_do_jogo(Mesa estrutura_mesa[28]);
void novo_jogo();
void comeca_jogo(char a);
void joga_primeira_peca(Peca pecas_do_jogo[28], int indice_da_peca);
void joga_peca(Mesa mesa_do_jogo, int indice_da_peca);
void insere_peca_no_comeco(Mesa mesa_do_jogo, int indice_da_peca);
void passa_a_jogada(Mesa mesa_do_jogo, char segundo_jogador);
void compra_peca (Mesa mesa_do_jogo);
bool verificacao_de_batida(Mesa mesa_do_jogo);
bool verificacao_de_empate(Mesa mesa_do_jogo);
bool verificacao_necessidade_de_compra(Mesa mesa_do_jogo);
bool peca_valida(Mesa mesa_do_jogo, int indice_peca_comprada);



//Funcao que chama o menu principal
void entrypoint(){
    
    int opcao = 0;
    while(opcao != 6){
        
        opcao = apresenta_menu_principal();

        switch (opcao)
        {
        case 1:
            novo_jogo();
            break;
        case 2:
            print("Continuar a Jogar -- Esta Funcao sera implementada futuramente");
            break;
        case 3:
            print("Salvar Jogo -- Esta Funcao sera implementada futuramente");
            break;
        case 4:
            print("Carregar Jogo -- Esta Funcao sera implementada futuramente");
            break;
        case 5:
            print("Regras do Jogo -- Esta Funcao sera implementada futuramente");
            break;
        default:
            exit(0);
        }
    }
}

//Funcao que cria a base de um novo jogo
void novo_jogo(){
    
    quantidade_de_jogadores = apresenta_menu_quantidade_jogadores();

    if (quantidade_de_jogadores = 1){
        comeca_jogo('C');
    } else {
        comeca_jogo('2');
    }
}


//Funcao que cuida do jogo em si
void comeca_jogo(char segundo_jogador){

    //Cria mesa do jogo
    Mesa mesa_do_jogo;

    //Embaralha as pecas da mesa
    embaralha_conjunto_de_pecas(mesa_do_jogo.pecas);
    
    //Distribui as pecas do jogo
    distribui_pecas(mesa_do_jogo.pecas, segundo_jogador);

    //Identifica maior peca e executa primeira jogada usando-a
    indice_primeira_peca = identifica_index_da_maior_peca(mesa_do_jogo.pecas);
    joga_primeira_peca(mesa_do_jogo, indice_primeira_peca);

    
    
}


//Funcao que cria um conjunto de peças ordenadas de maneira crescente
void cria_conjunto_de_pecas(Peca pecas_do_jogo[28]){
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
void embaralha_conjunto_de_pecas(Peca pecas_do_jogo[28]){
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
void reorganiza_conjunto_de_pecas(Peca pecas_do_jogo[28]){
    
    int i;
    Peca pecas_aux[28];
    cria_conjunto_de_pecas(pecas_aux);
    
    for (i = 0; i < 28; i++){
        pecas_do_jogo[i] = pecas_aux[i];
    }
}

//Função que distribui as pecas entre os jogadores
void distribui_pecas(Peca pecas_do_jogo[28], char segundo_jogador){

    int i;

    for(i = 0; i < 28; i++){
        if(i < 6){
            pecas_do_jogo[i].status = '1';
        }else if(i > 5 && i < 12 ){
            pecas_do_jogo[i].status = segundo_jogador;
        }else{
            pecas_do_jogo[i].status = 'N'
        }
    }
}

//Funcao que identifica o index da maior peca
int identifica_index_da_maior_peca(Peca pecas_do_jogo[28]){

    int i, indice = 0, maior = 0;

    for(i = 0; i < 12; i++){
        if(pecas_do_jogo[i].valores[0] == pecas_do_jogo[i].valores[1]){
            if (maior < pecas_do_jogo[i].valores[0]){
                maior = pecas_do_jogo[i].valores[0];
                indice = i;
            }
        }
    }
    return indice;
}

//Funcao responsavel por executar a primeira jogada
void joga_primeira_peca(Mesa mesa_do_jogo, int indice_da_peca){

    char jogador_da_vez;

    jogador_da_vez = mesa_do_jogo.peca[indice_da_peca].status;
    mesa_do_jopo.pecas[indice_da_peca].status = 'M';
    mesa_do_jogo.pecas_na_mesa[quantidade_de_pecas_jogadas] = mesa_do_jogo.pecas[indice_da_peca];
    quantidade_de_pecas_jogadas++;
    mesa_do_jogo.valores[0] = mesa_do_jogo.pecas[indice_da_peca].valores[0];
    mesa_do_jogo.valores[1] = mesa_do_jogo.pecas[indice_da_peca].valores[1];

    passa_a_jogada(mesa_do_jogo, jogador_da_vez)
}

//Esssa funcao tem um corpo maior pois cuida da validacao e caso exista a necessidade
//de inversao da peca, ela fara isso automaticamente
void joga_peca(Mesa mesa_do_jogo, int indice_da_peca){

    lado_esquerdo_da_mesa = mesa_do_jogo.valores[0];
    lado_direito_da_mesa = mesa_do_jogo.valores[1];

    int aux;

    if(lado_esquerdo_da_mesa == mesa_do_jogo.pecas[indice_da_peca].valores[0]){
        
        //swap que inverte a peca
        aux = mesa_do_jogo.pecas[indice_da_peca].valores[0];
        mesa_do_jogo.pecas[indice_da_peca].valores[0] = mesa_do_jogo.pecas[indice_da_peca].valores[1];
        mesa_do_jogo.pecas[indice_da_peca].valores[1] = aux;
        
        //todo funcao que insere no comeco
        insere_peca_no_comeco(mesa_do_jogo, indice_da_peca);
    
    } else if (lado_esquerdo_da_mesa == mesa_do_jogo.pecas[indice_da_peca].valores[1]){
        insere_peca_no_comeco(mesa_do_jogo, indice_da_peca);
    
    } else if (lado_direito_da_mesa == mesa_do.mesa_do_jogo.pecas[indice_da_peca].valores[0]){
        insere_peca_no_final(mesa_do_jogo, indice_da_peca);
    
    }else if (lado_direito_da_mesa == mesa_do.mesa_do_jogo.pecas[indice_da_peca].valores[1]){

        //swap que inverte a peca
        aux = mesa_do_jogo.pecas[indice_da_peca].valores[1];
        mesa_do_jogo.pecas[indice_da_peca].valores[1] = mesa_do_jogo.pecas[indice_da_peca].valores[0];
        mesa_do_jogo.pecas[indice_da_peca].valores[0] = aux;

        insere_peca_no_final(mesa_do_jogo, indice_da_peca);
    } 
}

void insere_peca_no_comeco(Mesa mesa_do_jogo, int indice_da_peca){

    Peca pecas_aux;
    int i;

    //altera status da peca que vai pra mesa 
    mesa_do_jogo.pecas[indice_da_peca].status = 'M';
    pecas_aux[0] = mesa_do_jogo.pecas[indice_da_peca];

    for (i = 1; i < 28; i++){
        pecas_aux[i] = mesa_do_jogo.pecas_na_mesa[i];
    }

    //Mesa aponta para o novo array atualizado
    mesa_do_jogo.pecas_na_mesa = *pecas_aux;

    //itera a quantidade de pecas novamente
    quantidade_de_pecas_jogadas++;

}

void insere_peca_no_final(Mesa mesa_do_jogo, int indice_da_peca){

    //insere nova peca no vetor de pecas_na_mesa, que por sua vez
    //é um atribudo da estrutura mesa_do_jogo
    mesa_do_jogo.pecas_na_mesa[quantidade_de_pecas_jogadas] = mesa_do_jogo.pecas[indice_da_peca];

    //itera a quantidade de pecas na mesa
    quantidade_de_pecas_jogadas++;
}

//funcao que passa a vez de jogada 
void passa_a_jogada(Mesa mesa_do_jogo, char jogador_da_vez){

    if(mesa_do_jogo.status == jogador_da_vez){
        mesa_do_jogo.status = '1';
    }else {
        mesa_do_jogo.status = jogador_da_vez;
    }
}

bool peca_valida(Mesa mesa_do_jogo, int indice_peca_comprada){

    if(mesa_do_jogo.valores[0] ==  mesa_do_jogo.pecas[indice_peca_comprada].valores[0] ||
       mesa_do_jogo.valores[0] == mesa_do_jogo.pecas[indice_peca_comprada].valores[1] ||
       mesa_do_jogo.valores[1] == mesa_do_jogo.pecas[indice_peca_comprada].valores[0] ||
       mesa_do_jogo.valores[1] == mesa_do_jogo.pecas[indice_peca_comprada].valores[1]){
           return true
       }
    return false
}

//funcao que realiza a compra de pecas
bool compra_peca (Mesa mesa_do_jogo){

    int i;
    bool sem_pecas_para_jogar = true;

    for (i = 0; i < 28; i++){
        if(mesa_do_jogo.pecas[i].status == 'N'){
            mesa_do_jogo.pecas[i].status = mesa_do_jogo.status;
            if(peca_valida(mesa_do_jogo.pecas[i])){
                joga_peca(mesa_do_jogo, i);
                verificacao_de_batida(Mesa mesa_do_jogo);
                passa_a_jogada(mesa_do_jogo, mesa_do_jogo.status)
                sem_pecas_para_jogar = false;
                return sem_pecas_para_jogar;
            }

        }
    }
    return sem_pecas_para_jogar;
}


//funcao que eh executada ao final de cada jogada para saber se ha algum vencedor
void verificacao_de_batida(Mesa mesa_do_jogo){

    int i;

    for (i = 0; i < 28; i++){
        if(mesa_do_jogo.pecas[i] == mesa_do_jogo.status){
            acaba_jogo();
        }
    }
}


//funcao que eh executada antes uma compra de peca para verificar se existe alguma peca possivel de ser jogada
bool verificacao_de_empate(Mesa mesa_do_jogo){


}

//funcao que eh executada antes da jogada de cada jogador durante o jogo
bool verificacao_necessidade_de_compra(Mesa mesa_do_jogo){

    int i;

    for (i = 0; i < 28; i++){
        if(mesa_do_jogo.pecas[i].status == mesa_do_jogo.status){
            if(peca_valida(mesa_do_jogo, mesa_do_jogo.pecas[i])){
                return false;
            }
        }
    }
    return true;
}

//funcao que administra o fim do jogo
//permite que o usuario salve o resultado
//feche o programa ou volte para o menu principal
void acaba_jogo(){
    menu_do_fim_do_jogo();
}