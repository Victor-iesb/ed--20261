#include <stdio.h>
#define QUANTIDADE 100

int Busca(int vet[], int tamanho, int valor){

    for (int i = 0; i < tamanho; i++){

        if (vet[i] == valor){

            return i;

        }        
    }

    return -1;

}

int main(){

    int valor, resultado;
    int vetor[QUANTIDADE];
    
    for (int i = 0; i < QUANTIDADE; i++){

        vetor[i] = i + 1;    

    }

    printf("Digite um valor para busca:\n " );
    scanf("%d", &valor);

    resultado = Busca(vetor, QUANTIDADE, valor);

    if (resultado != -1){

        printf("A busca pelo valor %d resultou em: %d\n", valor, resultado);

    } else{

        printf("O valor %d nao existe.\n", valor);

    }

    return 0;

}