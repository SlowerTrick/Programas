#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const int MAX = 9;

typedef struct {
    char *candidato;
    int votos;
} pessoa;

char *my_strdup(const char *s) {
    char *new_str = malloc(strlen(s) + 1);
    if (new_str == NULL) return NULL;
    strcpy(new_str, s);
    return new_str;
}

char *to_upper_str(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
    return str;
}

int strcasecompare(const char *s1, const char *s2) {
    while (*s1 && *s2 && tolower((unsigned char)*s1) == tolower((unsigned char)*s2)) {
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

int main(int argc, char *argv[]) {
    pessoa candidatos[MAX];

    if (argc > MAX + 1 || argc < 2) {
        printf("Uso correto: ./plural (2-9 candidatos)\n");
        return 1;
    }

    for (int i = 0; i < argc - 1; i++) {
        candidatos[i].candidato = my_strdup(argv[i + 1]);
        if (candidatos[i].candidato == NULL) {
            return 2; // Erro de alocação de memória
        }
        candidatos[i].candidato = to_upper_str(candidatos[i].candidato);
        candidatos[i].votos = 0;
    }

    int numeroVotantes;
    do {
        numeroVotantes = get_int("Número de votantes: ");
    } while (numeroVotantes <= 0 || numeroVotantes > MAX);

    for (int i = 0; i < numeroVotantes; i++) {
        char *voto = get_string("Voto %i: ", i + 1);
        to_upper_str(voto);
        bool encontrado = false;
        for (int j = 0; j < argc - 1; j++) {
            if (strcmp(voto, candidatos[j].candidato) == 0) {
                candidatos[j].votos++;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            printf("Candidato inválido.\n");
        }
    }

    // Ordenação dos candidatos por votos
    for (int i = 0; i < argc - 2; i++) {
        for (int j = i + 1; j < argc - 1; j++) {
            if (candidatos[i].votos < candidatos[j].votos) {
                pessoa temp = candidatos[i];
                candidatos[i] = candidatos[j];
                candidatos[j] = temp;
            }
        }
    }

    // Exibindo resultados
    printf("Resultados:\n");
    for (int i = 0; i < argc - 1; i++) {
        printf("Candidato %s recebeu %i votos.\n", candidatos[i].candidato, candidatos[i].votos);
    }

    // Verificando se há empate
    bool empate = false;
    for (int i = 1; i < argc - 1; i++) {
        if (candidatos[0].votos == candidatos[i].votos) {
            empate = true;
            break;
        }
    }

    // Anunciando o vencedor ou empate
    if (empate) {
        printf("Houve um empate entre os seguintes candidatos:\n");
        for (int i = 0; i < argc - 1; i++) {
            if (candidatos[0].votos == candidatos[i].votos) {
                printf("%s\n", candidatos[i].candidato);
            }
        }
    } else {
        printf("O vencedor é: %s\n", candidatos[0].candidato);
    }

    // Liberando memória
    for (int i = 0; i < argc - 1; i++) {
        free(candidatos[i].candidato);
    }

    return 0;
}
