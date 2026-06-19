#include <stdio.h>
#include "pilha.h"

int main() {
    printf("--- Testando TDA Pilha ---\n");
    
    Pilha minha_pilha = pilha_criar();
    if (minha_pilha == NULL) {
        printf("Erro ao criar a pilha.\n");
        return 1;
    }
    
    printf("A pilha esta vazia? %s\n\n", pilha_esta_vazia(minha_pilha) ? "Sim" : "Nao");
    
    // Testando empilhamento
    printf("Empilhando valores 10, 20 e 30...\n");
    pilha_empilhar(minha_pilha, 10);
    pilha_empilhar(minha_pilha, 20);
    pilha_empilhar(minha_pilha, 30);
    pilha_exibir(minha_pilha);
    
    // Consultando o topo
    int valor_no_topo;
    if (pilha_topo(minha_pilha, &valor_no_topo)) {
        printf("Valor no topo atualmente: %d\n\n", valor_no_topo);
    }
    
    // Testando desempilhamento
    printf("Desempilhando um elemento (deve remover o 30)...\n");
    pilha_desempilhar(minha_pilha);
    pilha_exibir(minha_pilha);
    
    if (pilha_topo(minha_pilha, &valor_no_topo)) {
        printf("Novo valor no topo: %d\n\n", valor_no_topo);
    }
    
    printf("Desempilhando outro elemento...\n");
    pilha_desempilhar(minha_pilha);
    pilha_exibir(minha_pilha);
    
    // Destruindo a pilha
    printf("Destruindo a pilha para liberar memoria...\n");
    pilha_destruir(minha_pilha);
    printf("Programa finalizado com sucesso.\n");
    
    return 0;
}