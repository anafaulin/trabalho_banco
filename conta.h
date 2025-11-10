#ifndef CONTA_H
#define CONTA_H

#include <stdio.h>
#include <string.h>

#define MAX_CONTAS 100
#define TAM_NOME 100
#define TAM_CPF 15
#define TAM_AGENCIA 10
#define TAM_TELEFONE 20
#define ATIVA 1
#define ENCERRADA 0

typedef struct {
    int numero;
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    char agencia[TAM_AGENCIA];
    char telefone[TAM_TELEFONE];
    double saldo;
    int status;
} Conta;

/* Protótipos — devem combinar *exatamente* com as implementações em conta.c */
int encontrar_conta_por_numero(const Conta contas[], int qtd, int numero);
int encontrar_conta_por_cpf(const Conta contas[], int qtd, const char* cpf);

int abrir_conta(Conta contas[], int* qtd, const char* nome, const char* cpf,
                const char* agencia, const char* telefone);

/* Aqui uso double para valores (mais seguro). A implementação abaixo usa double também. */
void depositar(Conta contas[], int qtd, const char* cpf, double valor);
void sacar(Conta contas[], int qtd, const char* cpf, double valor);
void transferir(Conta contas[], int qtd, const char* cpf_origem, const char* cpf_destino, double valor);

void consultar(const Conta contas[], int qtd, const char* cpf);
void atualizar(Conta contas[], int qtd, const char* cpf, const char* novo_tel, const char* nova_agencia);

void listar_contas(const Conta contas[], int qtd);

/* encerramento — aqui não alteramos qtd no vetor (apenas marca status) */
void encerrar_conta(Conta contas[], int* qtd, const char* cpf);

#endif
