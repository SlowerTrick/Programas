#include <stdio.h>
#include <ctype.h>

int main() {
    int modo, chave;
    char caracter;

    scanf("%d %d", &modo, &chave);

    // Consumir qualquer caractere de espaço em branco ou de quebra de linha remanescente no buffer de entrada
    getchar();

    // Verifica se o modo é válido
    if (modo != 1 && modo != 2) {
        printf("Operacao invalida.");
        return 0; // Encerra o programa
    }

    while ((caracter = getchar()) != '.') {
        if (islower(caracter)) {
            if (modo == 1) { // Codificar
                caracter = ((caracter - 'a' + chave) % 26) + 'a';
            } else if (modo == 2) { // Decodificar
                caracter = ((caracter - 'a' - chave + 26) % 26) + 'a';
            }
        } else if (!isspace(caracter) && !ispunct(caracter)) { // Não-alfabético
            // Caracteres não alfabéticos não devem ser codificados
            // e devem ser impressos sem modificação.
            printf("%c", caracter);
            continue;
        }
        printf("%c", caracter);
    }

    printf(".");

    return 0;
}