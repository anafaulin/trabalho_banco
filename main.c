#include "conta.h"

Conta contas[MAX_CONTAS];
int qtd_contas = 0;

int main() {
    int op;
    int continuar = 1;

    do {
        printf("\n >>> MENU <<< :) \n");
        printf("1. Abrir conta\n");
        printf("2. Depositar\n");
        printf("3. Sacar\n");
        printf("4. Transferir\n");
        printf("5. Consultar saldo e dados\n");
        printf("6. Atualizar telefone e agencia\n");
        printf("7. Listar contas\n");
        printf("8. Encerrar conta\n");
        printf("9. Sair\n");
        printf("==========================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        if (op == 1) {
            char nome[TAM_NOME], cpf[TAM_CPF], agencia[TAM_AGENCIA], telefone[TAM_TELEFONE];

            printf("Nome: ");
            scanf(" %[^\n]", nome);
            printf("CPF: ");
            scanf(" %[^\n]", cpf);
            printf("Agencia: ");
            scanf(" %[^\n]", agencia);
            printf("Telefone: ");
            scanf(" %[^\n]", telefone);

            abrir_conta(contas, &qtd_contas, nome, cpf, agencia, telefone);
        }
        else if (op == 2){
        	char cpf[TAM_CPF];
        	float valor;
        	printf("CPF da conta: ");
            scanf(" %[^\n]", cpf);
            printf("Valor do deposito: ");
            scanf("%f", &valor);
            printf("Valor depositado!");
            depositar(contas, qtd_contas, cpf, valor);
		}
		 else if (op == 3) {
            char cpf[TAM_CPF];
            float valor;
            printf("CPF da conta: ");
            scanf(" %[^\n]", cpf);
            printf("Valor do saque: ");
            scanf("%f", &valor);
            sacar(contas, qtd_contas, cpf, valor);
        }

        else if (op == 4) {
            char cpfOrigem[TAM_CPF], cpfDestino[TAM_CPF];
            float valor;
            printf("CPF origem: ");
            scanf(" %[^\n]", cpfOrigem);
            printf("CPF destino: ");
            scanf(" %[^\n]", cpfDestino);
            printf("Valor da transferencia: ");
            scanf("%f", &valor);
            transferir(contas, qtd_contas, cpfOrigem, cpfDestino, valor);
        }

        else if (op == 5) {
            char cpf[TAM_CPF];
            printf("CPF da conta: ");
            scanf(" %[^\n]", cpf);
            consultar(contas, qtd_contas, cpf);
        }

        else if (op == 6) {
            char cpf[TAM_CPF], novoTelefone[TAM_TELEFONE], novaAgencia[TAM_AGENCIA];
            printf("CPF da conta: ");
            scanf(" %[^\n]", cpf);
            printf("Novo telefone: ");
            scanf(" %[^\n]", novoTelefone);
            printf("Nova agencia: ");
            scanf(" %[^\n]", novaAgencia);
            atualizar(contas, qtd_contas, cpf, novoTelefone, novaAgencia);
        }

        else if (op == 7) {
            listar_contas(contas, qtd_contas);
        }

        else if (op == 8) {
            char cpf[TAM_CPF];
            printf("CPF da conta a encerrar: ");
            scanf(" %[^\n]", cpf);
            encerrar_conta(contas, &qtd_contas, cpf);
        }

        else if (op == 9) {
            printf("Saindo do sistema...\n");
            continuar = 0;
        }

        else {
            printf("Opcao invalida! Tente novamente.\n");
        }

    } while (continuar);

    return 0;
}