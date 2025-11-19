#include <stdio.h>
#include "relatorios.h"

// RELATÓRIOS


 // Calcula o saldo total de todas as contas do banco
 
double calcular_saldo_total(Conta contas[], int qtd_contas) {
    double total = 0.0;
    for (int i = 0; i < qtd_contas; i++) {
        total += contas[i].saldo;
    }
    return total;
}


 //Mostra a conta com maior e menor saldo
 // se não houver contas, informa. se houver 1 conta, mostra apenas essa.
 
void mostrar_maior_menor_saldo(Conta contas[], int qtd_contas) {
    if (qtd_contas == 0) {
        printf("\nNão há contas cadastradas.\n");
        return;
    } 
    if (qtd_contas == 1) {
        printf("\nExiste apenas uma conta cadastrada:\n");
        printf("Nome: %s | CPF: %s | Saldo: R$ %.2f\n", 
               contas[0].nome, contas[0].cpf, contas[0].saldo);
        return;
    }

    int indice_maior = 0, indice_menor = 0;
    for (int i = 1; i < qtd_contas; i++) {
        if (contas[i].saldo > contas[indice_maior].saldo)
            indice_maior = i;
        if (contas[i].saldo < contas[indice_menor].saldo)
            indice_menor = i;
    }

    printf("\nConta com maior saldo:\n");
    printf("Nome: %s | CPF: %s | Saldo: R$ %.2f\n", 
           contas[indice_maior].nome, contas[indice_maior].cpf, contas[indice_maior].saldo);

    printf("\nConta com menor saldo:\n");
    printf("Nome: %s | CPF: %s | Saldo: R$ %.2f\n", 
           contas[indice_menor].nome, contas[indice_menor].cpf, contas[indice_menor].saldo);
}


 // Lista todas as contas com saldo abaixo de um valor informado pelo usuário

void listar_contas_saldo_baixo(Conta contas[], int qtd_contas) {
    if (qtd_contas == 0) {
        printf("\nNão há contas cadastradas.\n");
        return;
    }

    double limite;
    printf("Informe o valor limite: ");
    if (scanf("%lf", &limite) != 1) {
        int c; while ((c = getchar()) != '\n' && c != EOF);
        printf("Valor inválido!\n");
        return;
    }

    int encontrou = 0;
    printf("\nContas com saldo abaixo de R$ %.2f:\n", limite);
    for (int i = 0; i < qtd_contas; i++) {
        if (contas[i].saldo < limite) {
            printf("Nome: %s | CPF: %s | Saldo: R$ %.2f\n", 
                   contas[i].nome, contas[i].cpf, contas[i].saldo);
            encontrou = 1;
        }
    }
    if (!encontrou)
        printf("Nenhuma conta encontrada com saldo abaixo de R$ %.2f\n", limite);
}


 //Lista todas as contas ordenadas pelo saldo (decrescente)
 // método: bubble sort
 
void listar_contas_ordenadas(Conta contas[], int qtd_contas) {
    if (qtd_contas == 0) {
        printf("\nNão há contas cadastradas.\n");
        return;
    }

    // Cria uma cópia do vetor para ordenar, preservando a original
    Conta copia[qtd_contas];
    for (int i = 0; i < qtd_contas; i++) {
        copia[i] = contas[i];
    }

    // Bubble sort decrescente
    for (int i = 0; i < qtd_contas - 1; i++) {
        for (int j = 0; j < qtd_contas - i - 1; j++) {
            if (copia[j].saldo < copia[j + 1].saldo) {
                Conta temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    printf("\nContas ordenadas por saldo (maior para menor):\n");
    for (int i = 0; i < qtd_contas; i++) {
        printf("Nome: %s | CPF: %s | Saldo: R$ %.2f\n", 
               copia[i].nome, copia[i].cpf, copia[i].saldo);
    }
}
