#ifndef CONTA_H
#define CONTA_H

typedef struct conta_t* conta;

conta conta_criar(int numero);
void conta_depositar(conta c, double valor);
int conta_sacar(conta c, double valor); 
double conta_ver_saldo(conta c);
void conta_destruir(conta c);

#endif