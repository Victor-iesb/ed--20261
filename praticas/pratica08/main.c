#include <stdio.h>
#include "fila.h"

int main() {
    printf("--- Testando TDA Fila ---\n");
    
    Fila minha_fila = fila_criar();
    if (minha_fila == NULL) {
        printf("Erro ao criar a fila.\n");
        return 1;
    }
    
    printf("A fila esta vazia? %s\n\n", fila_esta_vazia(minha_fila) ? "Sim" : "Nao");
    
    // Testando enfileiramento
    printf("Enfileirando valores 10, 20 e 30...\n");
    fila_enfileirar(minha_fila, 10);
    fila_enfileirar(minha_fila, 20);
    fila_enfileirar(minha_fila, 30);
    fila_exibir(minha_fila);
    
    // Consultando o início
    int valor_no_inicio;
    if (fila_inicio(minha_fila, &valor_no_inicio)) {
        printf("\nValor no inicio atualmente: %d\n", valor_no_inicio);
    }
    
    // Testando desenfileiramento
    printf("\nDesenfileirando um elemento (deve remover o 10)...\n");
    fila_desenfileirar(minha_fila);
    fila_exibir(minha_fila);
    
    if (fila_inicio(minha_fila, &valor_no_inicio)) {
        printf("Novo valor no inicio: %d\n", valor_no_inicio);
    }
    
    printf("\nDesenfileirando outro elemento (deve remover o 20)...\n");
    fila_desenfileirar(minha_fila);
    fila_exibir(minha_fila);
    
    // Destruindo a fila
    printf("\nDestruindo a fila para liberar memoria...\n");
    fila_destruir(minha_fila);
    printf("Programa finalizado com sucesso.\n");
    
    return 0;
}