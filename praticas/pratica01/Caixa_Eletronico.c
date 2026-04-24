#include <stdio.h>

int main(){

    int valor ,resto;
    int n200, n100, n50, n20, n10, n5, n2;

    printf("Valor que se deseja sacar?\n");
    scanf("%d",&valor);

    if(valor < 2 ||  valor > 1000){

    printf("Valor de saque indisponivel\n");

    }else {

        n200 = valor / 200;
        resto = valor % 200;

        n100 = resto / 100;
        resto = resto % 100;

        n50 = resto / 50;
        resto = resto % 50;

        n20 = resto / 20;
        resto = resto % 20;

        n10 = resto / 10;
        resto = resto % 10;

        n5 = resto / 5;
        resto = resto % 5;

        n2 = resto / 2;
        resto = resto % 2;

        printf("Seu saque e de %d notas de 200, %d notas de 100, %d notas de 50, %d notas de 20, %d notas de 10, %d notas de 5 e %d notas de 2\n", n200, n100, n50, n20, n10, n5, n2);

    } if (resto > 0) {

        printf("O valor de R$%d saque nao pode ser sacado.\n", resto);

    }

    return 0;

}