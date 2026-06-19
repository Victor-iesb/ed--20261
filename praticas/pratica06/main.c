#include <stdio.h>
#include "lista_linear.h"

int main() {
    printf("--- Testando TDA Lista Duplamente Encadeada ---\n");
    
    Lista minha_lista = lista_criar();
    if (minha_lista == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }
    
    printf("A lista esta vazia? %s\n", lista_esta_vazia(minha_lista) ? "Sim" : "Nao");
    
    // Testando inserção
    printf("\nInserindo valores 10, 20 e 30...\n");
    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 20);
    lista_inserir(minha_lista, 30);
    lista_exibir(minha_lista);
    
    // Testando busca
    printf("\nBuscando valor 20: %s\n", lista_buscar(minha_lista, 20) ? "Encontrado" : "Nao encontrado");
    printf("Buscando valor 50: %s\n", lista_buscar(minha_lista, 50) ? "Encontrado" : "Nao encontrado");
    
    // Testando remoção no meio, início e fim
    printf("\nRemovendo o valor 20...\n");
    lista_remover(minha_lista, 20);
    lista_exibir(minha_lista);
    
    printf("\nRemovendo o valor 10...\n");
    lista_remover(minha_lista, 10);
    lista_exibir(minha_lista);
    
    printf("\nInserindo valor 40...\n");
    lista_inserir(minha_lista, 40);
    lista_exibir(minha_lista);
    
    // Testando destruição
    printf("\nDestruindo a lista para liberar memoria...\n");
    lista_destruir(minha_lista);
    printf("Programa finalizado com sucesso.\n");
    
    return 0;
}