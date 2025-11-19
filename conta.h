#ifndef CONTA_H
#define CONTA_H

#include <stdio.h>
#include <string.h>

#define MAX_CONTAS 100        // máximo de contas no sistema
#define TAM_NOME 100          // ttamanho máximo do nome
#define TAM_CPF 15            // tamanho máximo do CPF 
#define TAM_AGENCIA 10        // tamanho máximo da agência
#define TAM_TELEFONE 20       // tamanho máximo do telefone

#define ATIVA 1
#define ENCERRADA 0

//  Estrutura da Conta ;)
typedef struct {
    int numero;                     // Número da conta
    char nome[TAM_NOME];            // Nome do titular
    char cpf[TAM_CPF];              // CPF do titular
    char agencia[TAM_AGENCIA];      // Agência da conta
    char telefone[TAM_TELEFONE];    // Telefone do titular
    double saldo;                   // Saldo da conta
    int status;                     
} Conta;



// Encontrar uma conta pelo número
int encontrar_conta_por_numero(const Conta contas[], int qtd, int numero);

// Encontrar uma conta pelo CPF
int encontrar_conta_por_cpf(const Conta contas[], int qtd, const char* cpf);

// abrir nova conta
int abrir_conta(Conta contas[], int* qtd, const char* nome, const char* cpf,
                const char* agencia, const char* telefone);

// operações financeiras
void depositar(Conta contas[], int qtd, const char* cpf, double valor);
void sacar(Conta contas[], int qtd, const char* cpf, double valor);
void transferir(Conta contas[], int qtd, const char* cpf_origem, const char* cpf_destino, double valor);

// consultas e atualizações
void consultar(const Conta contas[], int qtd, const char* cpf);
void atualizar(Conta contas[], int qtd, const char* cpf, const char* novo_tel, const char* nova_agencia);

// Listagem e encerramento
void listar_contas(const Conta contas[], int qtd);
void encerrar_conta(Conta contas[], int* qtd, const char* cpf);

#endif


