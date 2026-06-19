#ifndef PILHA_H
#define PILHA_H

// Definição do tipo opaco Pilha
typedef struct pilha_t* Pilha;

// Protótipos das funções do TDA
Pilha pilha_criar();
int pilha_empilhar(Pilha p, int valor);
int pilha_desempilhar(Pilha p);
int pilha_topo(Pilha p, int* valor_topo);
int pilha_esta_vazia(Pilha p);
void pilha_exibir(Pilha p);
void pilha_destruir(Pilha p);

#endif