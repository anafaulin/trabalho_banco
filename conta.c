#include "conta.h"
#include <stdio.h>
#include <string.h>

//  FUNÇÕES DE BUSCA :)

// Encontrar conta pelo número
int encontrar_conta_por_numero(const Conta contas[], int qtd, int numero) {
    for (int i = 0; i < qtd; i++) {
        if (contas[i].numero == numero) {
            return i; // retorna índice da conta
        }
    }
    return -1; // não encontrado
}

// Encontrar conta pelo CPF
int encontrar_conta_por_cpf(const Conta contas[], int qtd, const char* cpf) {
    for (int i = 0; i < qtd; i++) {
        if (strcmp(contas[i].cpf, cpf) == 0 && contas[i].status == ATIVA) {
            return i;
        }
    }
    return -1;
}

// ABRIR CONTA 
int abrir_conta(Conta contas[], int* qtd, const char* nome, const char* cpf,
                const char* agencia, const char* telefone) {

    // Limite de contas
    if (*qtd >= MAX_CONTAS) {
        printf("Erro: limite máximo de contas atingido.\n");
        return 0;
    }

    // Verifica se CPF já existe
    if (encontrar_conta_por_cpf(contas, *qtd, cpf) != -1) {
        printf("Erro: já existe uma conta com este CPF.\n");
        return 0;
    }

    // Criação da nova conta
    Conta nova;
    nova.numero = *qtd + 1;
    strcpy(nova.nome, nome);
    strcpy(nova.cpf, cpf);
    strcpy(nova.agencia, agencia);
    strcpy(nova.telefone, telefone);
    nova.saldo = 0.0;
    nova.status = ATIVA;

    contas[*qtd] = nova; // adiciona ao vetor
    (*qtd)++;

    printf("Conta criada com sucesso! :) Número: %d\n", nova.numero);
    return 1;
}

//  OPERAÇÕES FINANCEIRAS 

// Depositar
void depositar(Conta contas[], int qtd, const char* cpf, double valor) {
    int idx = encontrar_conta_por_cpf(contas, qtd, cpf);
    if (idx == -1) { printf("Conta não encontrada.\n"); return; }
    if (valor <= 0) { printf("Valor inválido para depósito.\n"); return; }

    contas[idx].saldo += valor;
    printf("Depósito de R$ %.2f realizado! Novo saldo: R$ %.2f\n", valor, contas[idx].saldo);
}

// Sacar
void sacar(Conta contas[], int qtd, const char* cpf, double valor) {
    int idx = encontrar_conta_por_cpf(contas, qtd, cpf);
    if (idx == -1) { printf("Conta não encontrada.\n"); return; }
    if (valor <= 0) { printf("Valor inválido para saque.\n"); return; }
    if (contas[idx].saldo < valor) { printf("Saldo insuficiente.\n"); return; }

    contas[idx].saldo -= valor;
    printf("Saque de R$ %.2f realizado! Novo saldo: R$ %.2f\n", valor, contas[idx].saldo);
}

// Transferir
void transferir(Conta contas[], int qtd, const char* cpf_origem, const char* cpf_destino, double valor) {
    int origem = encontrar_conta_por_cpf(contas, qtd, cpf_origem);
    int destino = encontrar_conta_por_cpf(contas, qtd, cpf_destino);

    if (origem == -1 || destino == -1) {
        printf("Conta de origem ou destino não encontrada.\n");
        return;
    }
    if (valor <= 0) { printf("Valor inválido para transferência.\n"); return; }
    if (contas[origem].saldo < valor) { printf("Saldo insuficiente na conta de origem.\n"); return; }

    contas[origem].saldo -= valor;
    contas[destino].saldo += valor;

    printf("Transferência de R$ %.2f realizada com sucesso!\n", valor);
    printf("Novo saldo origem: R$ %.2f | destino: R$ %.2f\n", contas[origem].saldo, contas[destino].saldo);
}

//  CONSULTAS E ATUALIZAÇÕES :)

// Consultar dados
void consultar(const Conta contas[], int qtd, const char* cpf) {
    int idx = encontrar_conta_por_cpf(contas, qtd, cpf);
    if (idx == -1) { printf("Conta não encontrada.\n"); return; }

    printf("\n--- Dados da Conta ---\n");
    printf("Número: %d\n", contas[idx].numero);
    printf("Nome: %s\n", contas[idx].nome);
    printf("CPF: %s\n", contas[idx].cpf);
    printf("Agência: %s\n", contas[idx].agencia);
    printf("Telefone: %s\n", contas[idx].telefone);
    printf("Saldo: R$ %.2f\n", contas[idx].saldo);
    printf("Status: %s\n", contas[idx].status == ATIVA ? "Ativa" : "Encerrada");
}

// Atualizar telefone e agência
void atualizar(Conta contas[], int qtd, const char* cpf, const char* novo_tel, const char* nova_agencia) {
    int idx = encontrar_conta_por_cpf(contas, qtd, cpf);
    if (idx == -1) { printf("Conta não encontrada.\n"); return; }

    strcpy(contas[idx].telefone, novo_tel);
    strcpy(contas[idx].agencia, nova_agencia);
    printf("Dados atualizados com sucesso!\n");
}

// LISTAGEM E ENCERRAMENTO :)

// Listar todas as contas
void listar_contas(const Conta contas[], int qtd) {
    if (qtd == 0) { printf("Nenhuma conta cadastrada.\n"); return; }

    printf("\n--- Lista de Contas ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("Número: %d | Nome: %s | CPF: %s | Saldo: R$ %.2f | Status: %s\n",
               contas[i].numero, contas[i].nome, contas[i].cpf,
               contas[i].saldo, contas[i].status == ATIVA ? "Ativa" : "Encerrada");
    }
}

// Encerrar conta
void encerrar_conta(Conta contas[], int* qtd, const char* cpf) {
    int idx = encontrar_conta_por_cpf(contas, *qtd, cpf);
    if (idx == -1) { printf("Conta não encontrada.\n"); return; }

    contas[idx].status = ENCERRADA;
    printf("Conta do CPF %s encerrada com sucesso.\n", cpf);
}
