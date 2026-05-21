#include <stdio.h>
#include <stdlib.h>

struct pilha {
    int valor;
    struct pilha *prox;
};

struct pilha *topo = NULL;

// Inserir elemento no topo 
void push(int i) {
    struct pilha *aux = (struct pilha*) malloc(sizeof(struct pilha));

    if (aux == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }

    aux->valor = i;

    if (topo == NULL)
        aux->prox = NULL;
    else
        aux->prox = topo;

    topo = aux;
}

// Remover elemento do topo 
int pop() {
    struct pilha *aux;
    int valor;

    if (topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }

    aux = topo;
    valor = topo->valor;
    topo = topo->prox;

    free(aux);

    return valor;
}

// Imprimir pilha 
void imprime() {
    struct pilha *aux;

    if (topo != NULL) {
        for (aux = topo; aux != NULL; aux = aux->prox)
            printf("Valor: %d\n", aux->valor);
    }
    else {
        printf("\nTentou imprimir uma pilha vazia\n");
    }
}

//Programa principal 
int main() {

    push(10);
    push(20);
    push(30);

    printf("Pilha:\n");
    imprime();

    printf("\nRemovido: %d\n", pop());

    printf("\nPilha apos pop:\n");
    imprime();

    return 0;
}