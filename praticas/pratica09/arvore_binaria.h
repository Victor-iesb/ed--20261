#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

// Definição do tipo opaco Arvore
typedef struct arvore_t* Arvore;

// Protótipos das funções do TDA
Arvore arvore_criar();
int arvore_inserir(Arvore a, int valor);
void arvore_exibir_pre_ordem(Arvore a);
void arvore_exibir_em_ordem(Arvore a);
void arvore_exibir_pos_ordem(Arvore a); // Corrigido o erro de digitação da imagem
int arvore_esta_vazia(Arvore a);
void arvore_destruir(Arvore a);

#endif