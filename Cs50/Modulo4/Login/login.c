#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void registrar(char *registro, int tipo);
bool verificador(char *usuario, char *senha);

int main(int argc, char *argv[]) {
    if (argc != 2 || strlen(argv[1]) > 1) {
        printf("\nUso correto: ./login (modo)\nModo 1: Registrar senha\nModo 2: Logar\n\n");
        return 1;
    }

    int modo = atoi(argv[1]);

    FILE *dados = fopen("dados.csv", "a+");
    if (dados == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 2;
    }

    if (modo == 1) {
        char usuario[100];
        char senha[100];

        registrar(usuario, 1);
        registrar(senha, 2);

        fprintf(dados, "%s, %s\n", usuario, senha);
        printf("Usuário registrado com sucesso.\n");
    }

    if (modo == 2) {
        char usuario[100];
        char senha[100];

        printf("Usuário: ");
        scanf("%99s", usuario);
        printf("Senha: ");
        scanf("%99s", senha);

        if (verificador(usuario, senha)) {
            printf("Login bem-sucedido.\n");
        } else {
            printf("Usuário ou senha incorretos.\n");
        }
    }

    fclose(dados);
    return 0;
}

void registrar(char *registro, int tipo) {
    if (tipo == 1)
        printf("Usuario: ");
    else
        printf("Senha: ");

    scanf("%99s", registro);
}

bool verificador(char *usuario, char *senha) {
    char linha[256];
    FILE *dados = fopen("dados.csv", "r");
    if (dados == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return false;
    }

    while (fgets(linha, sizeof(linha), dados)) {
        char *usr = strtok(linha, ",");
        char *pass = strtok(NULL, ",");
        pass[strlen(pass) - 1] = '\0'; // remove o caractere de nova linha

        if (strcmp(usuario, usr) == 0 && strcmp(senha, pass) == 0) {
            fclose(dados);
            return true;
        }
    }

    fclose(dados);
    return false;
}
