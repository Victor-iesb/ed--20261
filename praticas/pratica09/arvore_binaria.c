#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

// Struct interna para o nó da árvore
typedef struct no_t {
    struct no_t* esquerda;
    int valor;
    struct no_t* direita;
} no_t;

// Struct interna para a árvore
struct arvore_t {
    no_t* raiz;
};

// Cria uma nova árvore vazia
Arvore arvore_criar() {
    Arvore a = (Arvore) malloc(sizeof(struct arvore_t));
    if (a != NULL) {
        a->raiz = NULL;
    }
    return a;
}

// Verifica se a árvore está vazia
int arvore_esta_vazia(Arvore a) {
    if (a == NULL) return 1;
    return (a->raiz == NULL) ? 1 : 0;
}

// Função auxiliar recursiva para inserir um nó (Lógica de Árvore de Busca)
no_t* inserir_no(no_t* raiz, int valor) {
    // Se chegou em um espaço vazio, cria o nó aqui
    if (raiz == NULL) {
        no_t* novo = (no_t*) malloc(sizeof(no_t));
        if (novo != NULL) {
            novo->valor = valor;
            novo->esquerda = NULL;
            novo->direita = NULL;
        }
        return novo;
    }
    
    // Se o valor for menor, vai para a subárvore esquerda
    if (valor < raiz->valor) {
        raiz->esquerda = inserir_no(raiz->esquerda, valor);
    } 
    // Se o valor for maior, vai para a subárvore direita
    else if (valor > raiz->valor) {
        raiz->direita = inserir_no(raiz->direita, valor);
    }
    // Retorna a raiz inalterada (valores iguais são ignorados nesta implementação simples)
    return raiz;
}

// Insere um valor na árvore
int arvore_inserir(Arvore a, int valor) {
    if (a == NULL) return 0;
    a->raiz = inserir_no(a->raiz, valor);
    return 1;
}

// Função auxiliar recursiva para Pré-ordem (Raiz, Esquerda, Direita)
void pre_ordem(no_t* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

// Função auxiliar recursiva para Em-ordem (Esquerda, Raiz, Direita)
void em_ordem(no_t* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->valor);
        em_ordem(raiz->direita);
    }
}

// Função auxiliar recursiva para Pós-ordem (Esquerda, Direita, Raiz)
void pos_ordem(no_t* raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

// Funções de exibição chamando as auxiliares
void arvore_exibir_pre_ordem(Arvore a) {
    if (a == NULL || arvore_esta_vazia(a)) {
        printf("Arvore vazia.\n"); return;
    }
    printf("Pre-ordem: ");
    pre_ordem(a->raiz);
    printf("\n");
}

void arvore_exibir_em_ordem(Arvore a) {
    if (a == NULL || arvore_esta_vazia(a)) {
        printf("Arvore vazia.\n"); return;
    }
    printf("Em-ordem:  ");
    em_ordem(a->raiz);
    printf("\n");
}

void arvore_exibir_pos_ordem(Arvore a) {
    if (a == NULL || arvore_esta_vazia(a)) {
        printf("Arvore vazia.\n"); return;
    }
    printf("Pos-ordem: ");
    pos_ordem(a->raiz);
    printf("\n");
}

// Função auxiliar recursiva para destruir nós
void destruir_nos(no_t* raiz) {
    if (raiz != NULL) {
        destruir_nos(raiz->esquerda);
        destruir_nos(raiz->direita);
        free(raiz); // Libera o nó depois de liberar seus filhos (pós-ordem)
    }
}

// Destrói a árvore
void arvore_destruir(Arvore a) {
    if (a != NULL) {
        destruir_nos(a->raiz);
        free(a);
    }
}