#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"
#define TAMANHO 100


void copia_vetor(int origem[], int destino[], int n) {

    for (int i = 0; i < n; i++) {

        destino[i] = origem[i];
    }
}

int main() {

    int vetor_original[TAMANHO];
    int vetor_teste[TAMANHO];
    clock_t tempo_inicio, tempo_fim;
    double tempo_gasto;

    srand(time(NULL));

    for (int i = 0; i < TAMANHO; i++) {

        vetor_original[i] = rand() % 1000;
    }

    printf("=== Comparacao de Algoritmos de Selecao (%d elementos) ===\n\n", TAMANHO);
    int alvo_busca = vetor_original[TAMANHO / 2]; 
    int k_esimo = TAMANHO / 2; 
    
    copia_vetor(vetor_original, vetor_teste, TAMANHO);
    tempo_inicio = clock();
    int pos = linear_search(vetor_teste, TAMANHO, alvo_busca);
    tempo_fim = clock();
    tempo_gasto = ((double) (tempo_fim - tempo_inicio)) / CLOCKS_PER_SEC;

    printf("1. Linear Search:\n");
    printf("   Procurando o numero: %d\n", alvo_busca);

    if (pos != -1) {

        printf("   Encontrado no indice: %d\n", pos);

    } else {

        printf("   Nao encontrado.\n");

    }

    printf("   Tempo: %f segundos\n\n", tempo_gasto);
    copia_vetor(vetor_original, vetor_teste, TAMANHO);
    tempo_inicio = clock();

    int valor_encontrado = quick_select(vetor_teste, 0, TAMANHO - 1, k_esimo - 1);
    tempo_fim = clock();
    tempo_gasto = ((double) (tempo_fim - tempo_inicio)) / CLOCKS_PER_SEC;

    printf("2. Quick Select:\n");
    printf("   Buscando o %d-esimo menor elemento do vetor...\n", k_esimo);
    printf("   Valor encontrado: %d\n", valor_encontrado);
    printf("   Tempo: %f segundos\n", tempo_gasto);

    return 0;
}