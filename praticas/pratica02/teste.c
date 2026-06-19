#include <stdio.h>

// 1. O computador aprende a fazer a repetição primeiro
unsigned long long fatorial_rep(int num){
    unsigned long long resultado = 1;
    
    if (num < 0 || num > 20){
        printf("Numero negativo ou grande demais\n");
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

// 2. Depois ele aprende a fazer a recursividade
unsigned long long fatorial_rec(int num){
    if (num < 0 || num > 20){
        printf("Numero negativo ou grande demais\n");
        return 0;
    }
    if (num == 0 || num == 1){
        return 1;
    }
    return num * fatorial_rec(num - 1);
}

// 3. Só agora, no final, vem o seu bloco principal que chama as funções de cima
int main(){
    int valor;

    printf("Digite um numero inteiro positivo (maximo 20): ");
    scanf("%d", &valor);

    unsigned long long resposta_rep = fatorial_rep(valor);
    unsigned long long resposta_rec = fatorial_rec(valor);

    printf("\nPor repeticao:\n");
    printf("fatorial de %d: %llu\n", valor, resposta_rep);

    printf("Por recursividade:\n");
    printf("fatorial de %d: %llu\n\n", valor, resposta_rec);

    printf("--- Complexidade Assintotica ---\n");
    
    printf("1. Abordagem Iterativa (Repeticao):\n");
    printf("   - Complexidade de Tempo: O(n)\n");
    printf("   - Complexidade de Espaco: O(1)\n\n");

    printf("2. Abordagem Recursiva:\n");
    printf("   - Complexidade de Tempo: O(n)\n");
    printf("   - Complexidade de Espaco: O(n)\n");
    
    return 0;
}