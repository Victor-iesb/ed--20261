#include <stdio.h>

unsigned long long FatorialDeRepet(int num){

    unsigned long long resultado = 1;
    
    if (num < 0 || num > 20){

        printf("Numero Incorreto\n");
        return 0; 
    }
    
    if (num == 0 || num == 1){

        return 1;
    } 
    
    for(int i = 1; i <= num; i++){

        resultado *= i;
    }

    return resultado;
}

unsigned long long FatorialDeRecurs(int num){

    if (num < 0 || num > 20){

        printf("Numero Incorreto\n");
        return 0;
    } 
    
    if (num == 0 || num == 1){

        return 1;
    }

    return num * FatorialDeRecurs(num - 1);
}

int main(){
    
    int valor;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &valor);

    unsigned long long ValorDeRepet = FatorialDeRepet(valor);
    unsigned long long ValorDeRecurs = FatorialDeRecurs(valor);

    printf("\nRepeticao:\n");
    printf("O Fatorial de repeticao e de %d: %llu\n", valor, ValorDeRepet);

    printf("Recursividade:\n");
    printf("O Fatorial de recursividade e de %d: %llu\n\n", valor, ValorDeRecurs);

    printf("--- Complexidade Assintotica ---\n");
    
    printf("1. Abordagem Iterativa (Repeticao):\n");
    printf("   - Complexidade de Tempo: O(n)\n");
    printf("   - Complexidade de Espaco: O(1)\n\n");

    printf("2. Abordagem Recursiva:\n");
    printf("   - Complexidade de Tempo: O(n)\n");
    printf("   - Complexidade de Espaco: O(n)\n");
    
    return 0;
}