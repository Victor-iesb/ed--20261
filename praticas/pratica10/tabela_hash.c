#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

// Define um tamanho padrão para a tabela hash
#define TAMANHO_PADRAO 11 

// Struct interna para o nó (lista encadeada para colisões)
typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

// Struct interna para a tabela hash
struct hash_t {
    no_t** tabela; // Array de ponteiros para no_t
    int tamanho;
};

// Função de hash interna (calcula o índice)
int funcao_hash(int valor, int tamanho) {
    int indice = valor % tamanho;
    // Garante que o índice seja positivo
    return (indice < 0) ? indice + tamanho : indice;
}

// Cria e inicializa a tabela hash
TabelaHash hash_criar() {
    TabelaHash h = (TabelaHash) malloc(sizeof(struct hash_t));
    if (h != NULL) {
        h->tamanho = TAMANHO_PADRAO;
        h->tabela = (no_t**) malloc(h->tamanho * sizeof(no_t*));
        
        if (h->tabela == NULL) {
            free(h);
            return NULL;
        }
        
        // Inicializa todas as posições com NULL (listas vazias)
        for (int i = 0; i < h->tamanho; i++) {
            h->tabela[i] = NULL;
        }
    }
    return h;
}

// Verifica se a tabela inteira está vazia
int hash_esta_vazia(TabelaHash h) {
    if (h == NULL) return 1;
    
    for (int i = 0; i < h->tamanho; i++) {
        if (h->tabela[i] != NULL) {
            return 0; // Encontrou pelo menos um elemento
        }
    }
    return 1;
}

// Insere um valor na tabela
int hash_inserir(TabelaHash h, int valor) {
    if (h == NULL) return 0;
    
    int indice = funcao_hash(valor, h->tamanho);
    
    no_t* novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0;
    
    novo->valor = valor;
    // Insere no início da lista encadeada daquele índice
    novo->proximo = h->tabela[indice];
    h->tabela[indice] = novo;
    
    return 1;
}

// Busca um valor na tabela (retorna 1 se achou, 0 se não)
int hash_buscar(TabelaHash h, int valor) {
    if (h == NULL) return 0;
    
    int indice = funcao_hash(valor, h->tamanho);
    no_t* atual = h->tabela[indice];
    
    // Percorre a lista encadeada na posição do índice
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

// Remove um valor da tabela
int hash_remover(TabelaHash h, int valor) {
    if (h == NULL) return 0;
    
    int indice = funcao_hash(valor, h->tamanho);
    no_t* atual = h->tabela[indice];
    no_t* anterior = NULL;
    
    // Busca o nó a ser removido e mantém rastro do anterior
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual == NULL) return 0; // Valor não encontrado
    
    if (anterior == NULL) {
        // Era o primeiro nó da lista
        h->tabela[indice] = atual->proximo;
    } else {
        // Estava no meio ou fim da lista
        anterior->proximo = atual->proximo;
    }
    
    free(atual);
    return 1;
}

// Exibe a tabela completa mostrando os índices e suas listas
void hash_exibir(TabelaHash h) {
    if (h == NULL) {
        printf("Tabela Hash não existe.\n");
        return;
    }
    
    printf("--- Tabela Hash (Tamanho: %d) ---\n", h->tamanho);
    for (int i = 0; i < h->tamanho; i++) {
        printf("[%2d]: ", i);
        no_t* atual = h->tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
    printf("--------------------------------\n");
}

// Libera toda a memória da tabela (listas e o array principal)
void hash_destruir(TabelaHash h) {
    if (h != NULL) {
        for (int i = 0; i < h->tamanho; i++) {
            no_t* atual = h->tabela[i];
            no_t* aux;
            while (atual != NULL) {
                aux = atual;
                atual = atual->proximo;
                free(aux);
            }
        }
        free(h->tabela);
        free(h);
    }
}