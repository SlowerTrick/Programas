#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string nome;
    string numero;
}
pessoa;

int main (void)
{
    pessoa individuo[2];

    individuo[0].nome = "Artur";
    individuo[0].numero = "123";

    individuo[1].nome = "Jonas";
    individuo[1].numero = "321";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(individuo[i].numero, "123") == 0)
        {
        printf ("Número do %s\n", individuo[i].nome);
        return 0;
        }
    }
    printf ("Não achei nada não\n");
    return 1;
}
