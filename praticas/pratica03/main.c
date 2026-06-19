#include <stdio.h>
#include <stdlib.h>
#include "conta.h" 

int main() {

    printf("=== Testando o TDA Conta Bancaria ===\n\n");
    conta minha_conta = conta_criar(12345);

    if (minha_conta == NULL) {

        printf("Erro ao criar a conta!\n");

        return 1;
    }

    printf("Conta criada com sucesso! Saldo inicial: R$ %.2f\n", conta_ver_saldo(minha_conta));

    
    printf("\nDepositando R$ 500.00...\n");

    conta_depositar(minha_conta, 500.00);

    printf("Saldo atual: R$ %.2f\n", conta_ver_saldo(minha_conta));
    printf("\nTentando sacar R$ 150.00...\n");

    if (conta_sacar(minha_conta, 150.00)) {

        printf("Saque realizado! Retire seu dinheiro.\n");

    } else {

        printf("Erro: Saldo insuficiente.\n");

    }

    printf("Saldo atual: R$ %.2f\n", conta_ver_saldo(minha_conta));
    printf("\nTentando sacar R$ 1000.00...\n");

    if (conta_sacar(minha_conta, 1000.00)) {

        printf("Saque realizado! Retire seu dinheiro.\n");

    } else {

        printf("Erro: Saldo insuficiente para essa operacao.\n");

    }

    printf("Saldo atual: R$ %.2f\n", conta_ver_saldo(minha_conta));
    conta_destruir(minha_conta);
    printf("\nConta encerrada e memoria liberada com sucesso.\n");

    return 0;
}