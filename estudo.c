#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct no {
    int codigo;
    char nome[20];
    struct no *next;
} no;

no *corrente, *auxiliar, *inicio, *auxiliar2;

void menu();
void inserir();
void exibir();
void consultar();
void excluir();
void enterdata();

int main(){
    auxiliar = NULL;
    corrente = NULL;
    inicio = NULL;

    menu();
return 0;
}

void menu(){
    int opcao;

    do{
        printf("\n1 - Inserir novo registro");
        printf("\n2 - Exibir registro");
        printf("\n3 - Consultar registro");
        printf("\n4 - Excluir registro");
        printf("\n0 - Sair");
        printf("\nEscolha uma opcao:");
        scanf("%i", &opcao);

        switch(opcao){

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
                system("cls");
                printf("\nOpcao Invalida! Tente novamente.");
    }

    }while(opcao != 0);
}

void enterdata(){

    printf("\n");
    printf("\nInforme o Codigo:");
    scanf("%i", &auxiliar->codigo);
    printf("\nInforme o Nome:");
    scanf("%s", auxiliar->nome);
    system("pause");
    system("cls");

}

void inserir(){
	auxiliar = malloc(sizeof(no));
	
	if (auxiliar == NULL) {
	    printf("Erro de memoria\n");
	    return;
	}
	
	enterdata();
	auxiliar->next = NULL;}

    if (inicio==NULL){
        inicio = auxiliar;
        return;
    }

    corrente = inicio;
    auxiliar2 = NULL;

    while (corrente != NULL && strcmp(auxiliar->nome, corrente->nome) > 0){
        auxiliar2 = corrente;
        corrente = corrente->next;
    }

    if (auxiliar2 == NULL){
        auxiliar->next = inicio;
        inicio = auxiliar;
    }else{
        auxiliar2->next = auxiliar;
        auxiliar->next = corrente;

    }
}

void exibir(){

    system("cls");

    corrente = inicio;

    if (inicio == NULL){
        printf("\nA lista não tem dados");
        return;
    }

    while (corrente!=NULL){
        printf("\nCodigo: %i", corrente->codigo);
        printf("\nNome: %s", corrente->nome);
        printf("\n");
        corrente = corrente->next;
    }

    system("pause");
    system("cls");

}

void consultar(){
    int achou = 0;
    int pesquisa = -1;

    system("cls");

    printf("digite o codigo desejado:\n");
    scanf("%i", &pesquisa);

    corrente = inicio;

    if (inicio == NULL){
        printf("\nA lista não tem dados");
        return;
    }

    while (corrente!=NULL){
        if (corrente->codigo==pesquisa){
            printf("\nCodigo: %i", corrente->codigo);
            printf("\nNome: %s", corrente->nome);
            printf("\n");
            achou = 1;

            return;
        }else {
            corrente = corrente->next;
        }
    }

    if (!achou){
        printf("esse dado não existe\n");
    }


}

void excluir(){
    int achou = 0;
    int pesquisa = -1;

    system("cls");

    printf("digite o codigo desejado:\n");
    scanf("%i", &pesquisa);

    corrente = inicio;
    auxiliar = NULL;

    if (inicio == NULL){
        printf("\nA lista não tem dados");
        return;
    }

    while (corrente!=NULL){
        if (corrente->codigo==pesquisa){

                printf("\nNome do perfil excluido: %s\n", corrente->nome);
                achou = 1;

            if (corrente == inicio){
                    inicio = corrente->next;


            }else{
            auxiliar->next = corrente->next;
            }

            free(corrente);
            system("pause");
            system("cls");
            return;



        }else {
            auxiliar = corrente;
            corrente = corrente->next;
        }
    }

    if (!achou){
        printf("esse dado não existe\n");
    }

}









