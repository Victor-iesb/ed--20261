#include <stdio.h>

int main(){

    int informado, i;
    double valor, resultado, soma = 0;

    printf("Digite quantos numeros deseja informar:\n");
    scanf("%d",informado);

    if(informado < 0 || informado > 100){

        printf("O valor informado extrapola ou e inferior ao necessario");

    } else {

        for(i = 0; i < informado; i++){
            
            printf("Informe o valor:\n");
            scanf("%f",&valor);

            soma = soma + valor;

        }

        resultado = soma / informado;

    }

    return 0;
}