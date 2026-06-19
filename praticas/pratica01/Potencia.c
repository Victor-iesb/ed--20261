#include <stdio.h>

int main(){

    int base, expoente, i;
    long long resultado = 1;
    printf("De um valor para a base:\n");
    scanf("%d", &base);

    printf("De um valor para o expoente:\n");
    scanf("%d", &expoente);

    for(i = 1; i <= expoente; i++){

        resultado = resultado * base;

    }

    printf("O resultado de %d elevado a %d e: %lld", base, expoente, resultado);

    return 0;
}