#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

No *inicio = NULL;
No *fim = NULL;

void enfileirar(int valor) {
    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = NULL;

    if (inicio == NULL) {
        inicio = novo;
        fim = novo;
        return;
    }

    fim->prox = novo;
    fim = novo;
}

void desenfileirar() {
    if (inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    No *aux = inicio;

    inicio = inicio->prox;

    if (inicio == NULL) {
        fim = NULL;
    }

    free(aux);
}

void exibir() {
    No *aux = inicio;

    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }

    printf("\n");
}

int main() {
    enfileirar(10);
    enfileirar(20);
    enfileirar(30);

    printf("Fila:\n");
    exibir();

    desenfileirar();

    printf("Depois de remover:\n");
    exibir();

    return 0;
}

