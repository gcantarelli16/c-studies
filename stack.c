#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct no {
    int codigo;
    char nome[20];
    struct no *next;
} no;

struct no *topo, *corrente;

void EnterData()
{
    printf("\n Informe o codigo: ");
    scanf("%d", &corrente->codigo);
    printf("\n Informe o nome:  ");
    scanf("%s", corrente->nome);
}

void Push() {

    corrente = (no*)malloc(sizeof(no));
    corrente->next = NULL;

    EnterData();

    if (topo == NULL) {
        topo = corrente;
    } else {
        corrente->next = topo;
        topo = corrente;
    }

}


void Pop() {

    if (topo == NULL) {
        printf("\nA pilha esta vazia");
        system("pause");
    } else {
        corrente = topo;
        topo = topo->next;
        free(corrente);
        corrente = NULL;
        printf ("\nO elemento foi removido\n");
        system("pause");
    }

}

void Top() {

    if (topo == NULL) {
        printf ("\nA pilha esta vazia");
        system ("pause");
    } else {
        printf("\nCodigo: %i", topo->codigo);
        printf("\nNome: %s\n", topo->nome);
        system ("pause");
    }

}

int main() {


    corrente = NULL;
    topo = NULL;

    int op;

    do
    {
        system("cls");

        printf("\n======================");
        printf("\n Estrutura de dados");
        printf("\n======================");

        printf("\n 1 - Push");
        printf("\n 2 - Pop");
        printf("\n 3 - Top");
        printf("\n 0 - Sair");

        printf("\n======================");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &op);
        getchar();

        switch(op)
        {
            case 1:
                Push();
                break;

            case 2:
                Pop();
                break;

            case 3:
                Top();
                break;

            case 0:
                printf("\n Saindo do sistema... \n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                system("pause");
        }

    } while(op != 0);

    return 0;
}

