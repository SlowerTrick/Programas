#include <stdio.h>
#include <string.h>

int main (void)
{
    char string[100];
    printf ("Nome a ser lido: ");
    fgets (string, 100, stdin);

    printf ("String: %s", string);

    int tamanho = strlen(string) - 1; // A função "fgets" também pega o caractere '\n', por isso strlen está um valor maior
    printf ("Tamanho da string: %i\n", tamanho);

    for (int i = 0; i < strlen(string) - 1; i++)
    {

        printf ("%i: %c\n",i+1, string[i]);
    }
    return 0;
}

/*
Medida de proteção para o código:

    char string[11]; // Espaço para 10 caracteres e o caractere nulo
    int i;
    char c;

    do
    {
        i = 0;
        printf("Nome a ser lido (max 10 caracteres): ");

        while(i < 10 && (c = getchar()) != '\n' && c != EOF)
        {
            string[i++] = c;
        }

        // Limpa o buffer de entrada se mais de 10 caracteres foram inseridos
        while (c != '\n' && c != EOF)
        {
            c = getchar();
        }

        string[i] = '\0'; // Adiciona o caractere nulo no final

        if (i == 10)
        {
            printf("Entrada inválida! Por favor, insira no máximo 10 caracteres.\n");
        }
    }
}
*/
