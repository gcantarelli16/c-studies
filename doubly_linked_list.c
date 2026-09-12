#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct no {
    int codigo;
    char nome[20];
    struct no *next;
    struct no *back;
} no;

no *corrente, *auxiliar, *inicio, *auxiliar2;

void menu();
void inserir();
void exibir();
void consultar();
void excluir();
void enterdata();

int main() {

    auxiliar = NULL;
    corrente = NULL;
    inicio = NULL;

    menu();

    return 0;
}

void menu() {

    int opcao;

    do {

        printf("\n1 - Inserir novo registro");
        printf("\n2 - Exibir registro");
        printf("\n3 - Consultar registro");
        printf("\n4 - Excluir registro");
        printf("\n0 - Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%i", &opcao);

        switch(opcao) {

            case 1:
                inserir();
                break;

            case 2:
                exibir();
                break;

            case 3:
                consultar();
                break;

            case 4:
                excluir();
                break;

            case 0:
                printf("\nEncerrando o Programa...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.");
        }

    } while(opcao != 0);
}

void enterdata() {

    printf("\nInforme o Codigo: ");
    scanf("%i", &auxiliar->codigo);

    printf("\nInforme o Nome: ");
    scanf("%19s", auxiliar->nome);
}

void inserir() {

    auxiliar = malloc(sizeof(no));

    if (auxiliar == NULL) {
        printf("\nErro de memoria\n");
        return;
    }

    enterdata();

    auxiliar->next = NULL;
    auxiliar->back = NULL;

    if (inicio == NULL) {

        inicio = auxiliar;
        return;
    }

    corrente = inicio;
    auxiliar2 = NULL;

    while (corrente != NULL &&
           strcmp(auxiliar->nome, corrente->nome) > 0) {

        auxiliar2 = corrente;
        corrente = corrente->next;
    }

    // Inserção no início
    if (auxiliar2 == NULL) {

        auxiliar->next = inicio;
        inicio->back = auxiliar;
        inicio = auxiliar;

    } else {

        // Inserção no meio ou no final
        auxiliar2->next = auxiliar;
        auxiliar->back = auxiliar2;

        auxiliar->next = corrente;

        if (corrente != NULL) {
            corrente->back = auxiliar;
        }
    }
}

void exibir() {

    corrente = inicio;

    if (inicio == NULL) {
        printf("\nA lista nao tem dados.\n");
        return;
    }

    printf("\n===== REGISTROS =====\n");

    while (corrente != NULL) {

        printf("\nCodigo: %i", corrente->codigo);
        printf("\nNome: %s", corrente->nome);
        printf("\n");

        corrente = corrente->next;
    }
}

void consultar() {

    int pesquisa;
    int achou = 0;

    printf("\nDigite o codigo desejado: ");
    scanf("%i", &pesquisa);

    corrente = inicio;

    while (corrente != NULL) {

        if (corrente->codigo == pesquisa) {

            printf("\nCodigo: %i", corrente->codigo);
            printf("\nNome: %s\n", corrente->nome);

            achou = 1;
            return;
        }

        corrente = corrente->next;
    }

    if (!achou) {
        printf("\nEsse dado nao existe.\n");
    }
}

void excluir() {

    int pesquisa;

    printf("\nDigite o codigo desejado: ");
    scanf("%i", &pesquisa);

    corrente = inicio;

    while (corrente != NULL) {

        if (corrente->codigo == pesquisa) {

            printf("\nNome do perfil excluido: %s\n",
                   corrente->nome);

            // Se for o primeiro elemento
            if (corrente == inicio) {

                inicio = corrente->next;

                if (inicio != NULL) {
                    inicio->back = NULL;
                }

            } else {

                corrente->back->next = corrente->next;

                if (corrente->next != NULL) {
                    corrente->next->back = corrente->back;
                }
            }

            free(corrente);

            return;
        }

        corrente = corrente->next;
    }

    printf("\nEsse dado nao existe.\n");
}
