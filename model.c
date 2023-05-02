#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void inicializarMapa(int mesa[MAX][MAX], int mesaaux[MAX][MAX], int tamanhoMatriz){//coloca todos os valores em 0
    int i;
    for(i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            mesa[i][j] = 0;
        }
    }
    for(i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            mesaaux[i][j] = 0;
        }
    }

}

void colocarSerVivo(int mesa[MAX][MAX], int escolha, int escolha2, int tamanhoMatriz){//coloca a celula no local desejado da matriz
    if (escolha < tamanhoMatriz || escolha2 < tamanhoMatriz){
        mesa[escolha - 1][escolha2 - 1] = 1; 
    }else imprimirEscolhaInvalida();//view
}

void colocarPadrao(int mesa[MAX][MAX], int escolha, int tamanhoMatriz){//coloca um dos padroes pre-feitos na matriz
    int escolha2 = 0;
    int menu = escolha;
    escolha = 0;

    do{
        imprimirInstrucoesSerVivo();//view
        imprimirNumeroMaximoMapa(tamanhoMatriz);//view
        escolha = escolher();
        escolha2 = escolher();

        if (escolha > tamanhoMatriz || escolha2 > tamanhoMatriz){
            imprimirEscolhaInvalida();//view
        }
        
    } while (escolha > tamanhoMatriz || escolha2 > tamanhoMatriz);

    escolha--;
    escolha2--;

    switch(menu){//faz a verificacao para ver se o padrao pode ser inserido ou nao
        case 1:
            if (escolha != 0 && escolha != (tamanhoMatriz - 1)){
                mesa[escolha + 1][escolha2] = 1;
                mesa[escolha][escolha2] = 1;
                mesa[escolha - 1][escolha2] = 1;
            }else imprimirEscolhaInvalida();//view
            break;
        case 2:
            if (escolha2 != 0 && escolha2 != (tamanhoMatriz - 1)){
            mesa[escolha][escolha2 + 1] = 1;
            mesa[escolha][escolha2] = 1;
            mesa[escolha][escolha2 - 1] = 1;
            }else imprimirEscolhaInvalida();//view
            break;
        case 3:
            if(escolha > 0 && escolha2 > 0){
                mesa[escolha][escolha2] = 1;
                mesa[escolha][escolha2 - 1] = 1;
                mesa[escolha - 1][escolha2] = 1;
                mesa[escolha - 1][escolha2 - 1] = 1;
            }else imprimirEscolhaInvalida();//view
            break;
        case 4:
            if(escolha != 0 && escolha2 != (tamanhoMatriz - 1)){
                if(escolha != (tamanhoMatriz - 1)){
                    mesa[escolha][escolha2] = 1;
                    mesa[escolha][escolha2 + 1] = 1;
                    mesa[escolha + 1][escolha2] = 1;
                    mesa[escolha + 1][escolha2 + 1] = 1;
                }else imprimirEscolhaInvalida();//view
            }else imprimirEscolhaInvalida();//view
            break;
        case 5:
            if (escolha != 0 && escolha != tamanhoMatriz - 1){
                if(escolha2 != tamanhoMatriz - 1){
                    mesa[escolha - 1][escolha2 + 1] = 1;
                    mesa[escolha][escolha2] = 1;
                    mesa[escolha + 1][escolha2] = 1;
                }else imprimirEscolhaInvalida();//view
            }else imprimirEscolhaInvalida();//view
            break;
        case 6:
            if (escolha != tamanhoMatriz - 1 && escolha2 != tamanhoMatriz - 1){
                mesa[escolha][escolha2] = 1;
                mesa[escolha + 1][escolha2] = 1;
                mesa[escolha][escolha2 + 1] = 1;
            }else imprimirEscolhaInvalida();//view
            break;
        case 7:
            if(escolha != 0 && escolha2 != 0){
                if (escolha2 != tamanhoMatriz - 1){
                    mesa[escolha][escolha2 + 1] = 1;
                    mesa[escolha][escolha2] = 1;
                    mesa[escolha][escolha2 - 1] = 1;
                    mesa[escolha - 1][escolha2] = 1;
                }else imprimirEscolhaInvalida();//view
            }else imprimirEscolhaInvalida();//view
            break;
        case 8:
            if (escolha != 0 && escolha2 != 0){
                if(escolha != tamanhoMatriz - 1 && escolha2 != tamanhoMatriz - 1){
                    mesa[escolha - 1][escolha2 + 1] = 1;
                    mesa[escolha][escolha2] = 1;
                    mesa[escolha + 1][escolha2 - 1] = 1;
                }else imprimirEscolhaInvalida();//view
            }else imprimirEscolhaInvalida();//view         
            break;
        case 9:
            if(escolha2 != tamanhoMatriz - 2 && escolha2 != tamanhoMatriz - 1){
                if(escolha != tamanhoMatriz - 1 && escolha != 0){
                    mesa[escolha - 1][escolha2] = 1;
                    mesa[escolha - 1][escolha2 + 1] = 1;
                    mesa[escolha - 1][escolha2 + 2] = 1;
                    mesa[escolha][escolha2] = 1;
                    mesa[escolha + 1][escolha2 + 1] = 1;
                }else imprimirEscolhaInvalida();//view 
            }else imprimirEscolhaInvalida();//view 
            break;
        case 10:
            if(escolha != 0 && escolha != tamanhoMatriz - 1){
                if(escolha2 > 1){
                    mesa[escolha - 1][escolha2 - 2] = 1;
                    mesa[escolha - 1][escolha2 - 1] = 1;
                    mesa[escolha - 1][escolha2] = 1;
                    mesa[escolha][escolha2] = 1;
                    mesa[escolha + 1][escolha2 - 1] = 1;
                }else imprimirEscolhaInvalida();//view 
            }else imprimirEscolhaInvalida();//view
            break;
        default:
            imprimirEscolhaInvalida();//view
            break;
    }
}

void simularCelulas(int mesa[MAX][MAX], int mesaaux[MAX][MAX], int tamanhoMatriz){
    int cont = 0;
    for (int i = 0; i < tamanhoMatriz - 1; i++){
        for (int j = 0; j < tamanhoMatriz - 1; j++){
            //check para ver o num de vizinhos (verifica as 8 posicoes vizinhas)
            if (mesa[i - 1][j - 1] == 1){
                cont++;
            }
            if (mesa[i - 1][j] == 1){
                cont++;
            }
            if (mesa[i - 1][j + 1] == 1){
                cont++;
            }
            if (mesa[i][j - 1] == 1){
                cont++;
            }
            if (mesa[i][j + 1] == 1){
                cont++;
            }
            if (mesa[i + 1][j - 1] == 1){
                cont++;
            }
            if (mesa[i + 1][j] == 1){
                cont++;
            }
            if (mesa[i + 1][j + 1] == 1){
                cont++;
            }
            //fim do check

            if (mesa[i][j] == 0){
                if (cont == 3){//cria uma nova celula no lugar
                    mesaaux[i][j] = 1;
                }
            }else if (mesa [i][j] == 1){
                if (cont == 2 || cont == 3){//sobrevive para prox geracao
                    mesaaux[i][j] = 1;
                } else if (cont > 3){//morre devido a falta de comida
                    mesaaux[i][j] = 0;
                }else if (cont == 1 || cont == 0){//morre de solidao
                    mesaaux[i][j] = 0;
                }
            }
            cont = 0;
        }
    }
    for (int i = 0; i < tamanhoMatriz; i++){
        for (int j = 0; j < tamanhoMatriz; j++){
            mesa[i][j] = mesaaux[i][j];
        }
    }
}

void delay(int velocidadeSimulacao){//usa a biblioteca time.h para fazer um delay de acordo com o tanto de segundos desejado
    int converterMiliseg = 1000 * velocidadeSimulacao;
    
    clock_t inicio = clock();

    while (clock() < inicio + converterMiliseg);
}

void delayIndefinido(){//usa a biblioteca time.h para fazer um delay, nesse caso com um tempo pre setado
    int Miliseg = 750;
    
    clock_t inicio = clock();

    while (clock() < inicio + Miliseg);
}

int salvarMatriz(int mesa[MAX][MAX], int tamanhoMatriz){
    FILE *salvar;
    salvar = fopen("save.txt", "w");
    if (salvar == NULL){
        return 1;
    }else{
        for (int i = 0; i < MAX; i++){
            for (int j = 0; j < MAX; j++){
                fprintf(salvar," %d", mesa[i][j]);
            }
            fprintf(salvar, "\n");
        }
        
    }
    fclose(salvar);

    return 0;
}

int carregarMatriz(int mesa[MAX][MAX]){
    FILE *carregar;
    carregar = fopen("save.txt", "r");
    int temp[1][1];
    if (carregar == NULL){
        return 1;
    }else{
        for (int i = 0; i < MAX; i++){
            for (int j = 0; j < MAX; j++){
                fscanf(carregar," %d", &mesa[i][j]);
            }
        }
    }
    fclose(carregar);

    return 0;
    
}