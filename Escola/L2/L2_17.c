#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void codificar(char *texto, int chave) {
    int i = 0;
    while (texto[i] != '.') {
        if (islower(texto[i])) {
            texto[i] = 'a' + (texto[i] - 'a' + chave) % 26;
        }
        i++;
    }
}

void decodificar(char *texto, int chave) {
    int i = 0;
    while (texto[i] != '.') {
        if (islower(texto[i])) {
            texto[i] = 'a' + (texto[i] - 'a' - chave + 26) % 26;
        }
        i++;
    }
}

int main() {
    int modo, chave;
    char texto[1000];

    scanf("%d %d ", &modo, &chave);
    fgets(texto, sizeof(texto), stdin);

    texto[strlen(texto) - 1] = '\0'; // Remover o caractere de nova linha do final da entrada

    if (modo == 1) {
        codificar(texto, chave);
        printf("%s", texto);
    } else if (modo == 2) {
        decodificar(texto, chave);
        printf("%s", texto);
    } else {
        printf("Operacao invalida.");
    }

    return 0;
}