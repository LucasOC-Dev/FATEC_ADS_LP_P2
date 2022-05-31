#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "backlog.h"

void inicializar(Ativ *p[], int tamanho){
    for(int i=0; i<tamanho; i++){
        p[i] = NULL;
    }
}

void cadastrar(Ativ*p[], int posicao){

    p[posicao] = (Ativ*) malloc(sizeof(Ativ));
    
    printf("\t\tDigite o codigo da atividade(ID): ");
    scanf("%d", &p[posicao]->codigo);
    getchar();

    printf("\t\tNivel de prioridade sendo [1-5] : ");
    scanf("%d", &p[posicao]->prior);
    getchar();

    printf("\t\tDescricao resumida da atividade :\n");
    printf("\t\t");
    gets(p[posicao]->tarefa);

    printf("\t\tQnt dias estimados para concluir: ");
    scanf("%d", &p[posicao]->diasEsti);
    getchar();

    printf("\t\tPrazo max de entrega (dd/mm/aa) : ");
    gets(p[posicao]->dataFim);

    printf("\t\tEstado atual da atividade resum.: ");
    gets(p[posicao]->status);

    printf("\n\t\tAtividade Registrada com Sucesso!\n\n");
    system("pause");
}

void buscar(Ativ *p[],int tamanho){
    int codAt = 0;
    int atfind = 0;
    do {
        printf("\t\tDigite o codigo da atividade: ");
        scanf("%d", &codAt);
        getchar();
        for (int i = 0; i < tamanho; i++) {
            if (p[i]->codigo == codAt) {
                imprimir(p[i]);
                system("pause");
                return;
            }
        }
        atfind = 1;
        printf("\n\t\t-------- Codigo nao encontrado --------\n");
        printf("\t\t[1]Tentar novamente | [0]Retornar ao menu\n");
        printf("\n\t\tDigite a opcao desejada: ");
        scanf("%d", &atfind);
        getchar();
        printf("\n");
    } while (atfind == 1);
    return;
}

void alterar(Ativ* p[], int tamanho) {
    int codAt = 0;
    int atfind = 0;
    char simounao = 's';
    do {
        printf("\t\tDigite o codigo da atividade: ");
        scanf("%d", &codAt);
        getchar();
        for (int i = 0; i < tamanho; i++) {
            if (p[i]->codigo == codAt) {
                do { 
                    switch (menuAlt()) {
                    case 1:
                        //[1] Alterar codigo da atividade
                        printf("\t\tDigite o novo valor do,\n");
                        printf("\t\tcodigo da atividade(ID): ");
                        scanf("%d", &p[i]->codigo);
                        getchar();
                        break;
                    case 2:
                        //[2] Alterar nivel de prioridade
                        printf("\t\tDigite o novo valor do,\n");
                        printf("\t\tnivel de prioridade sendo [1-5] : ");
                        scanf("%d", &p[i]->prior);
                        getchar();
                        break;
                    case 3:
                        //[3] Alterar descricao resumida
                        printf("\t\tDigite o novo valor da,\n");
                        printf("\t\tdescricao resumida da atividade :\n");
                        printf("\t\t");
                        gets(p[i]->tarefa);
                        break;
                    case 4:
                        //[4] Alterar qnt de dias estimados
                        printf("\t\tDigite o novo valor de,\n");
                        printf("\t\tqnt dias estimados para concluir: ");
                        scanf("%d", &p[i]->diasEsti);
                        getchar();
                        break;
                    case 5:
                        //[5] Alterar prazo max de entrega
                        printf("\t\tDigite o novo valor do,\n");
                        printf("\t\tprazo max de entrega (dd/mm/aa) : ");
                        gets(p[i]->dataFim);
                        break;
                    case 6:
                        //[6] Alterar estado da atividade
                        printf("\t\tDigite o novo valor do,\n");
                        printf("\t\testado atual da atividade resum.: ");
                        gets(p[i]->status);
                        break;
                    default:
                        break;
                    }
                    printf("\n\t\tAlteracoes efetuadas com sucesso!\n");
                    printf("\t\tDeseja alterar outro campo desta atividade?\n");
                    printf("\t\t[s/n]: ");
                    scanf("%c", &simounao);
                    getchar();
                } while (simounao == 's' || simounao == 'S');
                return;
            }
        }
        atfind = 1;
        printf("\n\t\t-------- Codigo nao encontrado --------\n");
        printf("\t\t[1]Tentar novamente | [0]Retornar ao menu\n");
        printf("\n\t\tDigite a opcao desejada: ");
        scanf("%d", &atfind);
        getchar();
        printf("\n");
    } while (atfind == 1);
    return;
}

    int menuAlt(void) {
        int opMen = 0;
        printf("\n");
        printf("\t\t\t-=[ Menu de Alteracao ]=-\n");
        printf("\n");
        printf("\t\t[1] Alterar codigo da atividade\n");
        printf("\t\t[2] Alterar nivel de prioridade\n");
        printf("\t\t[3] Alterar descricao resumida\n");
        printf("\t\t[4] Alterar qnt de dias estimados\n");
        printf("\t\t[5] Alterar prazo max de entrega\n");
        printf("\t\t[6] Alterar estado da atividade\n");
        do {
            printf("\n\t\tDigite a opcao do campo que deseja alterar: ");
            scanf("%d", &opMen);
            getchar();
            if (opMen < 1 || opMen > 6) {
                printf("\n\t\tOpcao invalida, digite novamente.\n");
            }
        } while (opMen < 1 || opMen > 6);
        printf("\n");
        return opMen;
    }

void listar(Ativ *p[], int tamanho){
    for(int i=0; i<tamanho; i++){
        if(p[i]!=NULL){
            imprimir(p[i]);
        }        
    }
    system("pause");
}

void listarOrdem(Ativ* p[], int tamanho) {
    for (int j = 1; j <= 5; j++) {
        for (int i = 0; i < tamanho; i++) {
            if (p[i] != NULL) {
                if (p[i]->prior == j) {
                    imprimir(p[i]);
                }
            }
        }
    }
    system("pause");
}

void imprimir(Ativ *p){
    printf("\t ---------------------------------------------------------\n");
    printf("\t Nivel de Prioridade   : %d\n", p->prior);
    printf("\t Codigo da Atividade   : %d\n", p->codigo);
    printf("\t Descricao da Atividade: %s\n", p->tarefa);
    printf("\t Tempo estimado        : %d dias\n", p->diasEsti);
    printf("\t Prazo Final de Entrega: %s\n", p->dataFim);
    printf("\t Andamento da Atividade: %s\n", p->status);
    printf("\t ---------------------------------------------------------\n");
    printf("\n");
}

void excluir(Ativ* p[], int tamanho) {
    int codAt = 0;
    int atfind = 0;
    char simounao = 'n';
    do {
        printf("\t\tDigite o codigo da atividade: ");
        scanf("%d", &codAt);
        getchar();
        for (int i = 0; i < tamanho; i++) {
            if (p[i]->codigo == codAt) {
                printf("\n\t\tTem certeza que deseja excluir a atividade Cod.:[%d]?\n", p[i]->codigo);
                printf("\t\t[s/n]: ");
                scanf("%c", &simounao);
                getchar();
                if (simounao == 's' || simounao == 'S') {
                        p[i] = NULL;
                        printf("\n\t\tAtividade excluida com sucesso!\n\n");
                        system("pause");
                }
                return;
            }
        }
        atfind = 1;
        printf("\n\t\t-------- Codigo nao encontrado --------\n");
        printf("\t\t[1]Tentar novamente | [0]Retornar ao menu\n");
        printf("\n\t\tDigite a opcao desejada: ");
        scanf("%d", &atfind);
        getchar();
        printf("\n");
    } while (atfind == 1);
    return;
}