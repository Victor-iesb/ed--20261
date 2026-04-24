#include <stdio.h>
#include <time.h>
#define TAM_MATRIZ 10
#define QUANT_ELEMENTOS 100

int main(){

    int Matriz[TAM_MATRIZ][TAM_MATRIZ];
    clock_t inicio, fim;
    double TempoAninhado, TempoSimples;
    volatile int LeituraDotempo;

    for (int i = 0; i < TAM_MATRIZ; i++){

        for (int j = 0; j < TAM_MATRIZ; j++){
            
            Matriz[i][j] = (i * TAM_MATRIZ) + j + 1;

        }        
    }

    inicio = clock();

    for (int i = 0; i < TAM_MATRIZ; i++){

        for (int j = 0; j < TAM_MATRIZ; j++){

            LeituraDotempo = Matriz[i][j];

        }
    }

    fim = clock();
    TempoAninhado =T((double) (fim - inicio)) / CLOCKS_PER_SEC;

    int *PonteiroDaMatriz = &Matriz[0][0]; 
    
    inicio = clock();
    for (int k = 0; k < QUANT_ELEMENTOS; k++) {

        LeituraDotempo = PonteiroDaMatriz[k]; 
        
        }

    fim = clock();
    TempoSimples = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Resultados:\n");
    printf("A Primeira Abordagem com laco aninhado foi de: %f segundos\n", TempoAninhado);   
    printf("A Segunda Abordagem com laco simples foi de:  %f segundos\n", TempoSimples);

    return 0;
}
