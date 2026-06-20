#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    printf("--- Testando TDA Arvore Binaria ---\n");
    
    Arvore minha_arvore = arvore_criar();
    if (minha_arvore == NULL) {
        printf("Erro ao criar a arvore.\n");
        return 1;
    }
    
    printf("A arvore esta vazia? %s\n\n", arvore_esta_vazia(minha_arvore) ? "Sim" : "Nao");
    
    /* Inserindo valores para criar a seguinte arvore de busca:
              50
            /    \
          30      70
         /  \    /  \
        20  40  60  80
    */
    printf("Inserindo valores: 50, 30, 70, 20, 40, 60, 80...\n\n");
    arvore_inserir(minha_arvore, 50);
    arvore_inserir(minha_arvore, 30);
    arvore_inserir(minha_arvore, 70);
    arvore_inserir(minha_arvore, 20);
    arvore_inserir(minha_arvore, 40);
    arvore_inserir(minha_arvore, 60);
    arvore_inserir(minha_arvore, 80);
    
    // Exibindo nos diferentes percursos
    printf("Exibindo percursos:\n");
    arvore_exibir_pre_ordem(minha_arvore);
    arvore_exibir_em_ordem(minha_arvore);
    arvore_exibir_pos_ordem(minha_arvore);
    
    // Destruindo a árvore
    printf("\nDestruindo a arvore para liberar memoria...\n");
    arvore_destruir(minha_arvore);
    printf("Programa finalizado com sucesso.\n");
    
    return 0;
}