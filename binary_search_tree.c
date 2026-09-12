#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct no
{
    int codigo;
    char nome[50];
    struct no *next, *back;
} no;

struct no *corrente, *auxiliar, *raiz;

void EnterData()
{
    printf("\n Informe o codigo: ");
    scanf("%d", &corrente->codigo);
    printf("\n Informe o nome...:  ");
    scanf("%s", &corrente->nome);
}

void Inserir()
{
    corrente = (no*)malloc(sizeof(no));
    corrente->next = NULL;
    corrente->back = NULL;
    EnterData();

    if(raiz == NULL)
    {
        raiz = corrente;
        auxiliar = corrente;
        printf("\n Elemento alocado na Raiz da arvore \n");
        system("pause");
    }
    else
    {
        int aloca = 0;
        auxiliar = raiz;
        while (aloca == 0) {
            if (auxiliar->codigo > corrente->codigo) {
                if (auxiliar->back == NULL) {
                    auxiliar->back = corrente;
                    printf("\n Elemento alocado na esquerda da arvore \n");
                    system("pause");
                    aloca = 1;
                } else {
                    auxiliar = auxiliar->back;
                }
            } else if (auxiliar->codigo < corrente->codigo){
                if (auxiliar->next == NULL) {
                    auxiliar->next = corrente;
                    printf("\n Elemento alocado na direita da arvore \n");
                    system("pause");
                    aloca = 1;
                } else {
                    auxiliar = auxiliar->next;
                }
            } else {
                printf("Chave duplicada");
                system("pause");
                break;
            }
        }
    }
}


int main()
{
    auxiliar = NULL;
    corrente = NULL;
    raiz = NULL;

    int op;

    do
    {
        system("cls");

        printf("\n======================");
        printf("\n Estrutura de dados");
        printf("\n======================");
        printf("\n 1 - Inserir Dados");
        printf("\n 7 - Sair");
        printf("\n======================");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &op);
        getchar();

        switch(op)
        {
            case 1:
                Inserir();
                break;

            case 7:
                printf("\n Saindo do sistema... \n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                system("pause");
        }

    } while(op != 6);

    return 0;
}

