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
        
        printf(">>> RELATORIOS <<< :) \n");
        printf("10. Saldo total do banco\n");
        printf("11. Conta com maior e menor saldo\n");
        printf("12. Listar contas com saldo abaixo de um valor\n");
        printf("13. Listar contas ordenadas por saldo\n");
        printf("=============================\n");
        printf("Escolha uma opcao: ");

        

        if (scanf("%d", &op) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada inválida! Digite um número.\n");
            continue;
        }
 
        switch (op) {
            
            case 1:  // Abrir conta
                menuAbrirConta(contas, &qtd_contas);
                break;

            case 2:  // Depositar
                menuDepositar(contas, qtd_contas);
                break;

            case 3:  // Sacar
                menuSacar(contas, qtd_contas);
                break;

            case 4:  // Transferir
                menuTransferir(contas, qtd_contas);
                break;

            case 5:  // Consultar conta
                menuConsultar(contas, qtd_contas);
                break;

            case 6:  // Atualizar dados
                menuAtualizar(contas, qtd_contas);
                break;

            case 7:  // Listar todas as contas
                listar_contas(contas, qtd_contas);
                break;

            case 8:  // Encerrar conta
                menuEncerrarConta(contas, &qtd_contas);
                break;

            case 10: {  // Relatório: saldo total
                double total = calcular_saldo_total(contas, qtd_contas);
                printf("\nSaldo total do banco: R$ %.2f\n", total);
                break;
            }

            case 11: // Relatório: maior e menor saldo
                mostrar_maior_menor_saldo(contas, qtd_contas);
                break;

            case 12: // Relatório: contas com saldo abaixo de um valor
                listar_contas_saldo_baixo(contas, qtd_contas);
                break;

            case 13: // Relatório: contas ordenadas por saldo
                listar_contas_ordenadas(contas, qtd_contas);
                break;

            case 9:  // Sair
                printf("\nEncerrando o sistema...\n");
                break;

            default: // Opção inválida
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

    } while (op != 9);

    return 0;
}

