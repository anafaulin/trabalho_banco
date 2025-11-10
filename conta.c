#include "conta.h"

// Encontra uma conta pelo número
int encontrar_conta_por_numero(const Conta contas[], int qtd, int numero) {
    for (int i = 0; i < qtd; i++) {
        if (contas[i].numero == numero) {
            return i; // posição no vetor
        }
    }
    return -1; // não encontrou
}

// Encontra uma conta pelo CPF
int encontrar_conta_por_cpf(const Conta contas[], int qtd, const char* cpf) {
    for (int i = 0; i < qtd; i++) {
        if (strcmp(contas[i].cpf, cpf) == 0 && contas[i].status == ATIVA) {
            return i;
        }
    }
    return -1;
}

// Abre uma nova conta
int abrir_conta(Conta contas[], int* qtd, const char* nome, const char* cpf,
                const char* agencia, const char* telefone) {
    if (*qtd >= MAX_CONTAS) {
        printf("Limite máximo de contas atingido\n");
        return 0;
    }

    if (encontrar_conta_por_cpf(contas, *qtd, cpf) != -1) {
        printf("Já existe uma conta com esse CPF\n");
        return 0;
    }

    Conta nova;
    nova.numero = *qtd + 1;
    strcpy(nova.nome, nome);
    strcpy(nova.cpf, cpf);
    strcpy(nova.agencia, agencia);
    strcpy(nova.telefone, telefone);
    nova.saldo = 0.0;
    nova.status = ATIVA;

    contas[*qtd] = nova;
    (*qtd)++;

    printf("Conta criada com sucesso! Número: %d\n", nova.numero);
    return 1;
}

// Depositar dinheiro
void depositar(Conta contas[], int qtd, const char* cpf, double valor) {
    int i = encontrar_conta_por_cpf(contas, qtd, cpf);
    if (i == -1) {
        printf("Conta não encontrada.\n");
        return;
    }
    if (valor <= 0) {
        printf("Valor inválido para depósito.\n");
        return;
    }
    contas[i].saldo += valor;
    printf("Depósito de %.2f realizado com sucesso! Novo saldo: %.2f\n", valor, contas[i].saldo);
}


// Sacar dinheiro
void sacar(Conta contas[], int qtd, const char* cpf, double valor) {
    int i = encontrar_conta_por_cpf(contas, qtd, cpf);
    if (i == -1) {
        printf("Conta não encontrada.\n");
        return;
    }
    if (valor <= 0) {
        printf("Valor inválido para saque.\n");
        return;
    }
    if (contas[i].saldo < valor) {
        printf("Saldo insuficiente.\n");
        return;
    }
    contas[i].saldo -= valor;
    printf("Saque de %.2f realizado com sucesso! Novo saldo: %.2f\n", valor, contas[i].saldo);
}

// Transferir dinheiro entre contas
void transferir(Conta contas[], int qtd, const char* cpf_origem, const char* cpf_destino, double valor) {
    int origem = encontrar_conta_por_cpf(contas, qtd, cpf_origem);
    int destino = encontrar_conta_por_cpf(contas, qtd, cpf_destino);

    if (origem == -1 || destino == -1) {
        printf("Conta de origem ou destino não encontrada.\n");
        return;
    }

    if (valor <= 0) {
        printf("Valor inválido para transferência.\n");
        return;
    }

    if (contas[origem].saldo < valor) {
        printf("Saldo insuficiente na conta de origem.\n");
        return;
    }

    contas[origem].saldo -= valor;
    contas[destino].saldo += valor;

    printf("Transferência de %.2f realizada com sucesso!\n", valor);
    printf("Novo saldo da conta origem: %.2f\n", contas[origem].saldo);
    printf("Novo saldo da conta destino: %.2f\n", contas[destino].saldo);
}


// Consultar saldo e dados
void consultar(const Conta contas[], int qtd, const char* cpf) {
    int i = encontrar_conta_por_cpf(contas, qtd, cpf);
    if (i == -1) {
        printf("Conta não encontrada.\n");
        return;
    }

    printf("\n--- Dados da Conta ---\n");
    printf("Número: %d\n", contas[i].numero);
    printf("Nome: %s\n", contas[i].nome);
    printf("CPF: %s\n", contas[i].cpf);
    printf("Agência: %s\n", contas[i].agencia);
    printf("Telefone: %s\n", contas[i].telefone);
    printf("Saldo: %.2f\n", contas[i].saldo);
    printf("Status: %s\n", contas[i].status == ATIVA ? "Ativa" : "Encerrada");
}

// Atualizar telefone e agência
void atualizar(Conta contas[], int qtd, const char* cpf, const char* novo_tel, const char* nova_agencia) {
    int i = encontrar_conta_por_cpf(contas, qtd, cpf);
    if (i == -1) {
        printf("Conta não encontrada.\n");
        return;
    }

    strcpy(contas[i].telefone, novo_tel);
    strcpy(contas[i].agencia, nova_agencia);

    printf("Dados atualizados com sucesso!\n");
}

// Listar todas as contas
void listar_contas(const Conta contas[], int qtd) {
    if (qtd == 0) {
        printf("Nenhuma conta cadastrada.\n");
        return;
    }

    printf("\n--- Lista de Contas ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("Número: %d | Nome: %s | CPF: %s | Saldo: %.2f | Status: %s\n",
               contas[i].numero, contas[i].nome, contas[i].cpf,
               contas[i].saldo, contas[i].status == ATIVA ? "Ativa" : "Encerrada");
    }
}

// Encerrar conta
void encerrar_conta(Conta contas[], int* qtd, const char* cpf) {
    int indice = encontrar_conta_por_cpf(contas, *qtd, cpf);
    if (indice == -1) {
        printf("Conta não encontrada.\n");
        return;
    }

    contas[indice].status = ENCERRADA;
    printf("Conta do CPF %s foi encerrada com sucesso.\n", cpf);
}
