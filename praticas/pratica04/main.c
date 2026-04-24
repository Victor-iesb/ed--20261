#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

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

    printf("=== Comparacao de Algoritmos (%d elementos) ===\n\n", TAMANHO);

    copia_vetor(vetor_original, vetor_teste, TAMANHO); 
    tempo_inicio = clock(); 
    bubble_sort(vetor_teste, TAMANHO); 
    tempo_fim = clock(); 
    tempo_gasto = ((double) (tempo_fim - tempo_inicio)) / CLOCKS_PER_SEC;
    printf("Tempo Bubble Sort:    %f segundos\n", tempo_gasto);


    
    copia_vetor(vetor_original, vetor_teste, TAMANHO);
    tempo_inicio = clock();
    selection_sort(vetor_teste, TAMANHO);
    tempo_fim = clock();
    tempo_gasto = ((double) (tempo_fim - tempo_inicio)) / CLOCKS_PER_SEC;
    printf("Tempo Selection Sort: %f segundos\n", tempo_gasto);



    copia_vetor(vetor_original, vetor_teste, TAMANHO);
    tempo_inicio = clock();
    quick_sort(vetor_teste, 0, TAMANHO - 1);
    tempo_fim = clock();
    tempo_gasto = ((double) (tempo_fim - tempo_inicio)) / CLOCKS_PER_SEC;
    printf("Tempo Quick Sort:     %f segundos\n", tempo_gasto);

    return 0;
}