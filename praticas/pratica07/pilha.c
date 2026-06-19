#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Struct interna para o nó
typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

// Struct interna para a pilha
struct pilha_t {
    no_t* topo;
};

// Cria uma nova pilha vazia
Pilha pilha_criar() {
    Pilha p = (Pilha) malloc(sizeof(struct pilha_t));
    if (p != NULL) {
        p->topo = NULL;
    }
    return p;
}

// Verifica se a pilha está vazia
int pilha_esta_vazia(Pilha p) {
    if (p == NULL) return 1;
    return (p->topo == NULL) ? 1 : 0;
}

// Empilha (insere) um elemento no topo da pilha
int pilha_empilhar(Pilha p, int valor) {
    if (p == NULL) return 0;
    
    no_t* novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0;
    
    novo->valor = valor;
    novo->proximo = p->topo; // O novo nó aponta para o antigo topo
    p->topo = novo;          // O topo passa a ser o novo nó
    
    return 1;
}

// Desempilha (remove) o elemento do topo da pilha
int pilha_desempilhar(Pilha p) {
    if (p == NULL || pilha_esta_vazia(p)) return 0;
    
    no_t* no_remover = p->topo;
    p->topo = no_remover->proximo; // O topo passa a ser o elemento de baixo
    
    free(no_remover);
    return 1;
}

// Consulta o valor que está no topo da pilha sem removê-lo
// Passamos um ponteiro para armazenar o valor encontrado
int pilha_topo(Pilha p, int* valor_topo) {
    if (p == NULL || pilha_esta_vazia(p)) return 0;
    
    *valor_topo = p->topo->valor;
    return 1;
}

// Exibe os elementos da pilha (do topo para a base)
void pilha_exibir(Pilha p) {
    if (p == NULL || pilha_esta_vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    
    no_t* atual = p->topo;
    printf("Pilha (Topo -> Base):\n");
    while (atual != NULL) {
        printf("[%d]\n", atual->valor);
        atual = atual->proximo;
    }
    printf("---\n");
}

// Libera toda a memória alocada para a pilha
void pilha_destruir(Pilha p) {
    if (p != NULL) {
        no_t* atual = p->topo;
        no_t* aux;
        
        while (atual != NULL) {
            aux = atual;
            atual = atual->proximo;
            free(aux);
        }
        free(p);
    }
}