#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente {
    char nome[100];
    char email[100];
};

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    
    struct Cliente clientes[100];
    int opcao, numClientes = 0;
    char input[100];

    do {
        printf("Selecione uma opção:\n");
        printf("1 - Adicionar Cliente\n");
        printf("2 - Parar o programa\n\n");

        printf("> "); fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        opcao = (int)strtol(input, NULL, 10);

        switch (opcao) {
            case 1: {
                printf("Nome:\n"); fgets(clientes[numClientes].nome, sizeof(clientes[numClientes].nome), stdin);

                printf("Nome: %s\n", clientes[numClientes].nome);
                clientes[numClientes].nome[strcspn(clientes[numClientes].nome, "\n")] = '\0';
                numClientes++;
                printf("Numero de clientes (Atual): %i\n", numClientes);

                break;
            }

            case 2: {
                printf("Parando...\n");
                break;
            }
        }
    } while(opcao != 2);
    return 0;
}