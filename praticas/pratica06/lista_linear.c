#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

// Struct interna para o nó
typedef struct no_t {
    struct no_t* anterior;
    int valor;
    struct no_t* proximo;
} no_t;

// Struct interna para a lista
struct lista_t {
    no_t* primeiro;
    no_t* ultimo;
};

// Cria uma nova lista vazia
Lista lista_criar() {
    Lista l = (Lista) malloc(sizeof(struct lista_t));
    if (l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

// Verifica se a lista está vazia
int lista_esta_vazia(Lista l) {
    if (l == NULL) return 1;
    return (l->primeiro == NULL) ? 1 : 0;
}

// Insere um elemento no final da lista
int lista_inserir(Lista l, int valor) {
    if (l == NULL) return 0;
    
    no_t* novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0;
    
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = l->ultimo;
    
    if (lista_esta_vazia(l)) {
        l->primeiro = novo;
    } else {
        l->ultimo->proximo = novo;
    }
    l->ultimo = novo;
    
    return 1;
}

// Remove a primeira ocorrência do valor na lista
int lista_remover(Lista l, int valor) {
    if (l == NULL || lista_esta_vazia(l)) return 0;
    
    no_t* atual = l->primeiro;
    
    // Busca o nó que contém o valor
    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }
    
    // Se não encontrou, retorna 0
    if (atual == NULL) return 0;
    
    // Ajusta o ponteiro do nó anterior
    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        l->primeiro = atual->proximo; // Era o primeiro elemento
    }
    
    // Ajusta o ponteiro do nó próximo
    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    } else {
        l->ultimo = atual->anterior; // Era o último elemento
    }
    
    free(atual);
    return 1;
}

// Busca por um valor (retorna 1 se encontrou, 0 caso contrário)
int lista_buscar(Lista l, int valor) {
    if (l == NULL || lista_esta_vazia(l)) return 0;
    
    no_t* atual = l->primeiro;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1; 
        }
        atual = atual->proximo;
    }
    return 0;
}

// Exibe os elementos da lista do início ao fim
void lista_exibir(Lista l) {
    if (l == NULL || lista_esta_vazia(l)) {
        printf("Lista vazia.\n");
        return;
    }
    
    no_t* atual = l->primeiro;
    printf("Lista: ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

// Libera toda a memória alocada para a lista
void lista_destruir(Lista l) {
    if (l != NULL) {
        no_t* atual = l->primeiro;
        no_t* aux;
        
        while (atual != NULL) {
            aux = atual;
            atual = atual->proximo;
            free(aux);
        }
        free(l);
    }
}