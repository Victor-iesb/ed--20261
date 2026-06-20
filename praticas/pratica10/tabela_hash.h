#ifndef TABELA_HASH_H
#define TABELA_HASH_H

// Definição do tipo opaco TabelaHash
typedef struct hash_t* TabelaHash;

// Protótipos das funções do TDA
TabelaHash hash_criar();
int hash_inserir(TabelaHash h, int valor);
int hash_buscar(TabelaHash h, int valor);
int hash_remover(TabelaHash h, int valor);
void hash_exibir(TabelaHash h);
int hash_esta_vazia(TabelaHash h);
void hash_destruir(TabelaHash h);

#endif