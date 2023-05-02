#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void imprimirMenuPrincipal(){
    
    printf("===============================================================================\n");
    printf("(1) - Simular jogo\n");
    printf("(2) - Definir seres vivos\n");
    printf("(3) - Limpar o mapa\n");
    printf("(4) - Definir quantas geracoes serao simuladas\n");
    printf("(5) - Definir velocidade de simulacao\n");
    printf("(6) - Colocar padroes de seres vivos\n");
    printf("(7) - Salvar jogo\n");
    printf("(8) - Carregar jogo\n");
    printf("(9) - Sair\n");
    printf("===============================================================================\n");
}

void imprimirOpcoesSimulacao(){
    printf("===============================================================================\n");
    printf("(1) - Simular jogo uma vez\n");
    printf("(2) - Simular jogo por geracoes\n");
    printf("(3) - Simular jogo por etapas (enter para continuar e s + enter par sair)\n");
    printf("===============================================================================\n");
}

void imprimirOpcoesPadroes(){//imprime as opcoes para os padroes de celulas
    printf("===============================================================================\n");
    printf(" *            **    **     *    **    *       *    ***    *** \n");
    printf(" *     ***    **    **    *     *    ***     *     *        * \n");
    printf(" *                        *                 *       *      *  \n");
    printf(" 1      2      3    4     5     6     7      8     9       10 \n");
    printf("===============================================================================\n");
}

int escolherTamanho(){
    int escolha = 0; 
    do{
        printf("Digite um valor (entre 10 e 60):");
        scanf("%d", &escolha);
    }while(escolha < 10 || escolha > 60);
    return escolha;
}

int escolher(){//funcao generalizada para escolha de valores inteiros
    int escolha = 0;
    printf("Digite um valor:");
    scanf("%d", &escolha);
    return escolha;
}

int escolherVelocidade(){
    int escolha = 0;
    printf("Digite um valor em segundos:");
    scanf("%d", &escolha);
    return escolha;
}

void imprimirDefinirTamanho(){
    printf("Defina o tamanho do jogo!\n");
}

void imprimirEmDesenvolvimento(){
    printf("Ainda em desenvolvimento!\n");
}

void imprimirInstrucoesSerVivo(){
    printf("A primeira escolha e para coluna!\n");
    printf("A segunda escolha e para linha!\n");
}

void imprimirNumeroMaximoMapa(int tamanhoMatriz){
    printf("Insira um numero de 1 a %d!\n", tamanhoMatriz);
}

void imprimirObrigadoPorJogar(){
    printf("===============================================================================\n");
    printf("Obrigado por jogar o nosso jogo, e ate a proxima vez!\n");
    printf("===============================================================================\n");
}

void imprimirConfirmarSaida(){
    printf("Deseja mesmo sair? (1 para sim 0 para nao)\n");
}

void imprimirEscolhaInvalida(){
    printf("Sua escolha e invalida, tente novamente!\n");
}

void imprimirEscolhaInvalidaGeracoes(){
    printf("Sua escolha e invalida, necessario colocar o valor das geracoes no menu!\n");
}

void imprimirSuccSave(){
    printf("Save feito com sucesso!\n");
}

void imprimirFailSave(){
    printf("Save nao feito!\n");
}

void imprimirSuccLoad(){
    printf("Load feito com sucesso!\n");
}

void imprimirFailLoad(){
    printf("Load nao feito!\n");
}

void imprimirMapa(int mesa[MAX][MAX], int tamanhoMatriz){
    printf("===============================================================================\n");
    printf("   ");
    for (int i = 0; i < tamanhoMatriz; i++){
        printf("%d ", i + 1);
    }
    printf("\n");
    
    for(int i = 0; i < tamanhoMatriz; i++){
        if (i > 8){
            printf("%d ", i + 1);
        }else printf(" %d ", i + 1);
        for(int j = 0; j < tamanhoMatriz; j++){
            if(mesa[i][j] == 0){
                if(j < 10){
                    printf("  ");   
                }else if (j >= 10){
                    printf("   ");
                }
            }else{
                if(j < 10){
                    printf("* ");   
                }else if (j >= 10){
                    printf(" * ");
                }
            }
             
        }   
        printf("\n");    
    }
}