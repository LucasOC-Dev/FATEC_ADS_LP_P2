#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "backlog.h"

// Definições
#define L 100

// Funções
void menu(void);

// Ponteiros e Vetores e Variáveis Globais
int opMenu1 = 0;

int main(){

    // Definindo a localização para PT-BR (Permitir acentuação)
    setlocale(LC_ALL, "Portuguese");

    // Ponteiros e Vetores e Variáveis
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
                //[3] Alterar conteúdo da atividade
                alterar(vetAtiv, pos);
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
                printf("\n\t\tOpção Invalida, digite novamente.\n\n");
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
    printf("\t\t[3] Alterar conteúdo da atividade\n");
    printf("\t\t[4] Excluir atividade registrada\n");
    printf("\t\t[5] Listar todas atividades registradas\n");
    printf("\t\t[6] Listar atividades em ordem prioritaria\n");
    printf("\n");
    printf("\t\t[9] Sair\n");
    printf("\n\t\tDigite a opção desejada: ");
    scanf("%d", &opMenu1);
    getchar();
    printf("\n");
}
