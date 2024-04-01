#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int argc, string argv[])
{

    if (argc != 2)
    {
        printf ("Uso correto: ./cesar chave\n");
        return (1);
    }

    int inicial = strlen(argv[1]);
    for (int i = 0; i < inicial; i++)
    {
        if (!isdigit(argv[1][i]))
        {
        printf("A chave deve ser um número.\n");
        return 1;
        }
    }

    if (argc == 2)
    {
        string texto = get_string ("Texto: ");
        printf ("Código criptografado: ");
        int chave = atoi(argv[1]);

        for (int i = 0; texto[i] != '\0'; i++)
        {
            if (texto[i] >= 'A' && texto[i] <= 'Z')
            {
                int cifrado = texto[i] - 'A';
                int cripto  = (cifrado + chave) % 26;
                cripto = (char) cripto + 'A';
                printf("%c", cripto);
            }

            if (texto[i] >= 'a' && texto[i] <= 'z')
            {
                int cifrado = texto[i] - 'a';
                int cripto  = (cifrado + chave) % 26;
                cripto = (char) cripto + 'a';
                printf("%c", cripto);
            }

            if (texto[i] < 65 || (texto[i] > 90 && texto[i] < 97) || texto[i] > 122)
            {
                printf ("%c", texto[i]);
            }
        }
    }

    printf ("\n");
    return (0);
}

