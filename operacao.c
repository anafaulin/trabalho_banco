#include <stdio.h>
#include <string.h>
#include "operacoes.h"
#include "conta.h"

// MENUS AUXILIARES  

// Menu para abrir conta
void menuAbrirConta(Conta contas[], int *qtd_contas) {
    char nome[TAM_NOME], cpf[TAM_CPF], agencia[TAM_AGENCIA], telefone[TAM_TELEFONE];

    printf("Nome: ");
    scanf(" %[^\n]", nome);

    printf("CPF (somente números, 11 dígitos): ");
    scanf(" %[^\n]", cpf);
    if (strlen(cpf) != 11) {
        printf("CPF inválido!\n");
        return;
    }

    printf("Agência: ");
    scanf(" %[^\n]", agencia);

    printf("Telefone: ");
    scanf(" %[^\n]", telefone);

    abrir_conta(contas, qtd_contas, nome, cpf, agencia, telefone);
}

// Menu para depósito
void menuDepositar(Conta contas[], int qtd_contas) {
    char cpf[TAM_CPF];
    double valor;

    printf("CPF da conta: ");
    scanf(" %[^\n]", cpf);

    printf("Valor do depósito: ");
    if (scanf("%lf", &valor) != 1 || valor <= 0) {
        printf("Valor inválido!\n");
        int c; while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    realizar_deposito(contas, qtd_contas, cpf, valor);
}

// Menu para saque
void menuSacar(Conta contas[], int qtd_contas) {
    char cpf[TAM_CPF];
    double valor;

    printf("CPF da conta: ");
    scanf(" %[^\n]", cpf);

    printf("Valor do saque: ");
    if (scanf("%lf", &valor) != 1 || valor <= 0) {
        printf("Valor inválido!\n");
        int c; while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    realizar_saque(contas, qtd_contas, cpf, valor);
}

// Menu para transferência
void menuTransferir(Conta contas[], int qtd_contas) {
    char cpf_origem[TAM_CPF], cpf_destino[TAM_CPF];
    double valor;

    printf("CPF da conta origem: ");
    scanf(" %[^\n]", cpf_origem);

    printf("CPF da conta destino: ");
    scanf(" %[^\n]", cpf_destino);

    printf("Valor da transferência: ");
    if (scanf("%lf", &valor) != 1 || valor <= 0) {
        printf("Valor inválido!\n");
        int c; while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    realizar_transferencia(contas, qtd_contas, cpf_origem, cpf_destino, valor);
}

// menu para consultar conta
void menuConsultar(Conta contas[], int qtd_contas) {
    char cpf[TAM_CPF];
    printf("CPF da conta: ");
    scanf(" %[^\n]", cpf);

    consultar(contas, qtd_contas, cpf);
}

// Menu para atualizar conta
void menuAtualizar(Conta contas[], int qtd_contas) {
    char cpf[TAM_CPF], novo_tel[TAM_TELEFONE], nova_agencia[TAM_AGENCIA];

    printf("CPF da conta: ");
    scanf(" %[^\n]", cpf);

    printf("Novo telefone: ");
    scanf(" %[^\n]", novo_tel);

    printf("Nova agência: ");
    scanf(" %[^\n]", nova_agencia);

    atualizar(contas, qtd_contas, cpf, novo_tel, nova_agencia);
}

// Menu para encerrar conta
void menuEncerrarConta(Conta contas[], int *qtd_contas) {
    char cpf[TAM_CPF];
    printf("CPF da conta: ");
    scanf(" %[^\n]", cpf);

    encerrar_conta(contas, qtd_contas, cpf);
}
// OPERAÇÕES REAIS 

// chama a função depositar do conta.c
void realizar_deposito(Conta contas[], int qtd, const char* cpf, double valor) {
    depositar(contas, qtd, cpf, valor);
}

// chama a função sacar do conta.c
void realizar_saque(Conta contas[], int qtd, const char* cpf, double valor) {
    sacar(contas, qtd, cpf, valor);
}

// chama a função transferir do conta.c
void realizar_transferencia(Conta contas[], int qtd, const char* cpf_origem, const char* cpf_destino, double valor) {
    transferir(contas, qtd, cpf_origem, cpf_destino, valor);
}
