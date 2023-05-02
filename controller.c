#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void acessarMenuPrincipal(int mesa[MAX][MAX], int mesaaux[MAX][MAX]){
    
    int tamanhoMatriz = 0;
    imprimirDefinirTamanho();//view
    tamanhoMatriz = escolherTamanho();//view

    int menu = 0;
    int sinal = 0;
    int escolha;
    int escolha2;
    int geracoes = 0;
    int velocidadeSimulacao = 0;
    int confirmacao = 0;
    int testeSave = 0;

    inicializarMapa(mesa, mesaaux, tamanhoMatriz);

    do{
        imprimirMenuPrincipal();//view
        sinal = 0;
        menu = escolher();//escolhe a opcao do menu //model

        switch (menu){
            case 1://simula as celulas
                acessarMenuJogando(mesa, mesaaux, tamanhoMatriz, geracoes, velocidadeSimulacao);
                break;
            case 2://coloca o ser vivo na posicao especifica
                imprimirInstrucoesSerVivo();//view
                escolha = escolher();//escolhe a opcao da coluna //view
                escolha2 = escolher();//escolhe a opcao da linha //view
                colocarSerVivo(mesa, escolha, escolha2, tamanhoMatriz);//coloca o ser vivo na posicao desejada //model
                break;
            case 3://limpa o mapa
                inicializarMapa(mesa, mesaaux, tamanhoMatriz);//limpa o mapa para comecar um novo jogo //model
                break;
            case 4://define as geracoes que serao geradas
                geracoes = escolher();//define o quanto de geracoes serao geradas //view
                break;
            case 5://define em segundos a velocidade da simulacao
                velocidadeSimulacao = escolherVelocidade();//define a velocidade de simulacao //view
                break;
            case 6://mostra os padroes do jogo
                imprimirOpcoesPadroes();//view
                escolha = escolher();
                colocarPadrao(mesa, escolha, tamanhoMatriz);
                break;
            case 7://salva a matriz em um arquivo txt
                testeSave = salvarMatriz(mesa, tamanhoMatriz);//model
                if (testeSave == 0){
                    imprimirSuccSave();//view
                }else imprimirFailSave();//view
                break;
            case 8://carrega o save para a matriz
                testeSave = carregarMatriz(mesa);//model
                if (testeSave == 0){
                    imprimirSuccLoad();//view
                }else imprimirFailLoad();//view
                break;
            case 9://sai do jogo
                sinal = sairDoJogo();//faz a confirmacao de saida //controller
                break;
            case 10://funcao escondida que imprime o mapa do jogo (debug)
                imprimirMapa(mesa, tamanhoMatriz);//view
                break;
            case 11://funcao escondida que limpa geracoes e delay (debug)
                geracoes = 0;
                velocidadeSimulacao = 0;
                break;
            default:
                imprimirEscolhaInvalida();//view
                break;
        }
    }while(sinal == 0);

    imprimirObrigadoPorJogar();//view

}

void acessarMenuJogando(int mesa[MAX][MAX], int mesaaux[MAX][MAX], int tamanhoMatriz, int geracoes, int velocidadeSimulacao){//menu da simulacao do jogo
    int escolha = 0;
    char ch;

    imprimirOpcoesSimulacao();//view
    escolha = escolher();//view
    if (escolha == 1){//simular apenas 1 geracao
        simularCelulas(mesa, mesaaux, tamanhoMatriz);//model
        imprimirMapa(mesa, tamanhoMatriz);//view
    }else if(escolha == 2){
        if (geracoes > 0){//simular multiplas geracoes
            system("cls");
            if (velocidadeSimulacao == 0){
                    velocidadeSimulacao = 1;
            }
            imprimirMapa(mesa, tamanhoMatriz);//view
            delay(velocidadeSimulacao);//model
            for (int i = 0; i < (geracoes - 1); i++){
                system("cls");
                simularCelulas(mesa, mesaaux, tamanhoMatriz);//model
                imprimirMapa(mesa, tamanhoMatriz);//view
                delay(velocidadeSimulacao);//model
            }
        }else imprimirEscolhaInvalidaGeracoes();//view
    }else if (escolha == 3){//simular passo a passo
        imprimirMapa(mesa, tamanhoMatriz);//view
        delay(velocidadeSimulacao);//model
        system("cls");
        do{
            system("cls");
            simularCelulas(mesa, mesaaux, tamanhoMatriz);//model
            imprimirMapa(mesa, tamanhoMatriz);//view
            delayIndefinido();//model
            fflush(stdin);
            ch = getchar();
        }while (ch != 's');
    }
}

int sairDoJogo(){
    int confirmacao = 0;
    imprimirConfirmarSaida();//view
    confirmacao = escolher();//pega o valor para ver se fecha o programa ou nao
    if(confirmacao == 1){
        return 1;
    } else return 0;
}