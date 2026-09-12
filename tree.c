#include<stdlib.h>
#include<stdio.h>

typedef struct no
{
    int codigo;
    char nome[50];
    struct no*next;
    struct no*back;
    struct no*bellow;
} no;

struct no *corrente, *auxiliar, *raiz;

void EnterData()
{
    printf("\n Informe o codigo: ");
    scanf("%d", &corrente->codigo);
    printf("\n Informe o nome...:  ");
    scanf("%s", &corrente->nome);
}

void Encadeamento(){
    int path = 0;
    printf("\nInsira a direcao a ser encadeada...");
    printf("\n[1] - Esquerda [2] - Direita [3] - Abaixo: ");
    scanf("%d", &path);
    switch(path) {
        case 1:
            if (auxiliar->back != NULL) {
                auxiliar = auxiliar->back;
                Encadeamento();
            } else {
            auxiliar->back = corrente;
            break;
            }
        case 2:
            if (auxiliar->next != NULL) {
                auxiliar = auxiliar->next;
                Encadeamento();
            } else {
            auxiliar->next = corrente;
            break;
            }
        case 3:
            if (auxiliar->bellow != NULL) {
                auxiliar = auxiliar->bellow;
                Encadeamento();
            } else {
            auxiliar->bellow = corrente;
            break;
            }
        default:
            printf("\nInsira uma opção válida!");
            system("pause");
            Encadeamento();
            break;
    }
}

void Inserir()
{
    corrente = (no*)malloc(sizeof(no));
    corrente->next = NULL;
    corrente->back = NULL;
    corrente->bellow = NULL;

    EnterData();

    if(raiz == NULL)
    {
        raiz = corrente;
        auxiliar = corrente;
    }
    else
    {
        auxiliar = raiz;
        Encadeamento();
    }
}

void Consulta() {

}



int main ()
{
    auxiliar = NULL;
    corrente = NULL;
    raiz = NULL;

    int op;

    do
    {
        system("cls");

        printf("\n======================================================");
        printf("\n Estrutura de dados - Arvore");
        printf("\n======================================================");
        printf("\n 1 - Inserir");
        printf("\n 2 - Consulta");
        printf("\n 6 - Sair\n");
        printf("======================================================\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &op);
        getchar();

        switch (op)
        {
        case 1:
            Inserir();
            break;

        case 2:
            break;


        case 3:
            break;

        case 6:
            printf("\nSaindo do sistema...\n");
            break;

        default:
            printf("\nOpção invalida!\n");
            system("pause");
        }

    }
    while (op != 6);

    return 0 ;
}

