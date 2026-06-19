#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

struct conta_t {

    int numero;
    double saldo;

};

conta conta_criar(int numero) {

    conta nova_conta = (conta) malloc(sizeof(struct conta_t));

    if (nova_conta != NULL) {

        nova_conta->numero = numero;
        nova_conta->saldo = 0.0;

    }

    return nova_conta;
}

void conta_depositar(conta c, double valor) {

    if (c != NULL && valor > 0) {

        c->saldo += valor;

    }
}

int conta_sacar(conta c, double valor) {

    if (c != NULL && valor > 0 && c->saldo >= valor) {

        c->saldo -= valor;
        return 1; 

    }
    return 0; 

}

double conta_ver_saldo(conta c) {

    if (c != NULL) {

        return c->saldo;

    }

    return 0.0;

}

void conta_destruir(conta c) {

    if (c != NULL) {

        free(c);
    }
}