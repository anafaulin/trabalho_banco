#ifndef OPERACOES_H
#define OPERACOES_H

#include "conta.h"

// Funções de menu  
void menuAbrirConta(Conta contas[], int *qtd_contas);
void menuDepositar(Conta contas[], int qtd_contas);
void menuSacar(Conta contas[], int qtd_contas);
void menuTransferir(Conta contas[], int qtd_contas);
void menuConsultar(Conta contas[], int qtd_contas);
void menuAtualizar(Conta contas[], int qtd_contas);
void menuEncerrarConta(Conta contas[], int *qtd_contas);

// funções de operações "reais" (chamam as funções de conta.c)
void realizar_deposito(Conta contas[], int qtd, const char* cpf, double valor);
void realizar_saque(Conta contas[], int qtd, const char* cpf, double valor);
void realizar_transferencia(Conta contas[], int qtd, const char* cpf_origem, const char* cpf_destino, double valor);

#endif
