#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "backlog.h"

// Defini��es
#define L 100

// Fun��es
void menu(void);

// Ponteiros e Vetores e Vari�veis Globais
int opMenu1 = 0;

int main(){

    // Definindo a localiza��o para PT-BR (Permitir acentua��o)
    setlocale(LC_ALL, "Portuguese");

    // Ponteiros e Vetores e Vari�veis
    Ativ * vetAtiv[L];
    inicializar(vetAtiv, L);
    int pos = 0;

    //Inicio do Programa
    do{
        menu();
        switch(opMenu1){
            case 1:
                //[1] Cadastrar nova atividade
                cadastrar(vetAtiv, pos);
                pos++;
                break;
            case 2:
                //[2] Buscar atividade existente
                buscar(vetAtiv, pos);
                break;
            case 3:
                //[3] Alterar conte�do da atividade
                alterar(vetAtiv, pos);
                //comprar(vetAtiv, pos, codproc, qtd);
                break;
            case 4:
                //[4] Excluir atividade registrada
                excluir(vetAtiv, pos);
                break;
            case 5:
                //[5] Listar todas atividades registradas
                listar(vetAtiv, pos);
                break;
            case 6:
                //[6] Listar atividades em ordem prioritaria
                listarOrdem(vetAtiv, pos);
                break;

            case 9:
                //[9] Sair
                break;
            default:
                printf("\n\t\tOp��o Invalida, digite novamente.\n\n");
                system("pause");
        }
    }while(opMenu1 != 9);
    printf("\n\t\tPrograma encerrado com sucesso. Obrigado!\n\n");
    system("pause");
    return 0;
}

void menu(void) {
    system("CLS");
    printf("\t ---------------------------------------------------------\n");
    printf("\t |                                                       |\n");
    printf("\t |      @@@@  @   @   @@@@  @@@@  @   @ @@ @@   @@@@     |\n");
    printf("\t |     @       @ @   @     @      @   @   @    @         |\n");
    printf("\t |     @@@      @    @@@   @      @   @   @    @@@       |\n");
    printf("\t |     @       @ @   @     @      @   @   @    @         |\n");
    printf("\t |      @@@@  @   @   @@@@  @@@@   @@@    @     @@@@     |\n");
    printf("\t |                                                       |\n");
    printf("\t |                 BACKLOG LIST SOLUTIONS                |\n");
    printf("\t ---------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t   -=[ Menu Principal ]=-\n");
    printf("\n");
    printf("\t\t[1] Cadastrar nova atividade\n");
    printf("\t\t[2] Buscar atividade existente\n");
    printf("\t\t[3] Alterar conte�do da atividade\n");
    printf("\t\t[4] Excluir atividade registrada\n");
    printf("\t\t[5] Listar todas atividades registradas\n");
    printf("\t\t[6] Listar atividades em ordem prioritaria\n");
    printf("\n");
    printf("\t\t[9] Sair\n");
    printf("\n\t\tDigite a op��o desejada: ");
    scanf("%d", &opMenu1);
    getchar();
    printf("\n");
}