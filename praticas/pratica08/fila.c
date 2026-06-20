#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Struct interna para o nó
typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

// Struct interna para a fila
struct fila_t {
    no_t* inicio;
    no_t* fim;
};

// Cria uma nova fila vazia
Fila fila_criar() {
    Fila f = (Fila) malloc(sizeof(struct fila_t));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

// Verifica se a fila está vazia
int fila_esta_vazia(Fila f) {
    if (f == NULL) return 1;
    return (f->inicio == NULL) ? 1 : 0;
}

// Enfileira (insere) um elemento no fim da fila
int fila_enfileirar(Fila f, int valor) {
    if (f == NULL) return 0;
    
    no_t* novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0;
    
    novo->valor = valor;
    novo->proximo = NULL;
    
    if (fila_esta_vazia(f)) {
        f->inicio = novo; // Se estava vazia, o novo nó é o início e o fim
    } else {
        f->fim->proximo = novo; // O antigo fim aponta para o novo nó
    }
    f->fim = novo; // Atualiza o ponteiro de fim da fila
    
    return 1;
}

// Desenfileira (remove) o elemento do início da fila
int fila_desenfileirar(Fila f) {
    if (f == NULL || fila_esta_vazia(f)) return 0;
    
    no_t* no_remover = f->inicio;
    f->inicio = no_remover->proximo; // O início passa a ser o próximo elemento
    
    // Se a fila ficou vazia após remover, o fim também deve ser NULL
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(no_remover);
    return 1;
}

// Consulta o valor que está no início da fila sem removê-lo
int fila_inicio(Fila f, int* valor_inicio) {
    if (f == NULL || fila_esta_vazia(f)) return 0;
    
    *valor_inicio = f->inicio->valor;
    return 1;
}

// Exibe os elementos da fila (do início ao fim)
void fila_exibir(Fila f) {
    if (f == NULL || fila_esta_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    
    no_t* atual = f->inicio;
    printf("Fila (Inicio -> Fim): ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

// Libera toda a memória alocada para a fila
void fila_destruir(Fila f) {
    if (f != NULL) {
        no_t* atual = f->inicio;
        no_t* aux;
        
        while (atual != NULL) {
            aux = atual;
            atual = atual->proximo;
            free(aux);
        }
        free(f);
    }
}