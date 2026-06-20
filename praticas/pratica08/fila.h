#ifndef FILA_H
#define FILA_H

// Definição do tipo opaco Fila
typedef struct fila_t* Fila;

// Protótipos das funções do TDA
Fila fila_criar();
int fila_enfileirar(Fila f, int valor);
int fila_desenfileirar(Fila f);
int fila_inicio(Fila f, int* valor_inicio);
int fila_esta_vazia(Fila f);
void fila_exibir(Fila f); // Corrigido de "lista_exibir"
void fila_destruir(Fila f);

#endif