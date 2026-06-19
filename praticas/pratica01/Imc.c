#include <stdio.h>

int main() {

    float peso, altura;
    printf("Digite seu peso:\n");
    scanf("%f", &peso);

    printf("Digite sua altura:\n");
    scanf("%f", &altura);

    float imc; 
    imc = peso / (altura * altura);

    if(imc < 18.5){

        printf("Abaixo do peso.\n");

    } else if(imc >=18.5 && imc <= 24.9){

        printf("Peso Normal\n");

    } else if(imc >= 25.0 && imc <= 29.9){

        printf("Sobrepeso\n");

    }else{

        printf("Obesidade\n");

    }
    
    return 0;
}