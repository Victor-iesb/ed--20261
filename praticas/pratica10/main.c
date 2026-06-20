#include <stdio.h>
#include "tabela_hash.h"

int main() {
    printf("=== Testando TDA Tabela Hash ===\n\n");
    
    TabelaHash minha_tabela = hash_criar();
    if (minha_tabela == NULL) {
        printf("Erro ao criar a tabela hash.\n");
        return 1;
    }
    
    printf("A tabela esta vazia? %s\n\n", hash_esta_vazia(minha_tabela) ? "Sim" : "Nao");
    
    // Inserindo valores.
    // Sabendo que o tamanho padrão é 11, os valores 10, 21 e 32 vão colidir no índice 10.
    printf("Inserindo valores (15, 22, 10, 21, 32, 5)...\n");
    hash_inserir(minha_tabela, 15);
    hash_inserir(minha_tabela, 22);
    hash_inserir(minha_tabela, 10);
    hash_inserir(minha_tabela, 21);
    hash_inserir(minha_tabela, 32);
    hash_inserir(minha_tabela, 5);
    
    hash_exibir(minha_tabela);
    
    printf("A tabela esta vazia? %s\n\n", hash_esta_vazia(minha_tabela) ? "Sim" : "Nao");
    
    // Testando busca
    printf("Buscando o valor 21: %s\n", hash_buscar(minha_tabela, 21) ? "Encontrado" : "Nao encontrado");
    printf("Buscando o valor 99: %s\n\n", hash_buscar(minha_tabela, 99) ? "Encontrado" : "Nao encontrado");
    
    // Testando remoção
    printf("Removendo o valor 21 (que esta no meio de uma colisao)...\n");
    hash_remover(minha_tabela, 21);
    
    printf("Removendo o valor 15...\n");
    hash_remover(minha_tabela, 15);
    
    hash_exibir(minha_tabela);
    
    // Destruindo a tabela
    printf("Destruindo a tabela hash para liberar memoria...\n");
    hash_destruir(minha_tabela);
    printf("Programa finalizado com sucesso.\n");
    
    return 0;
}