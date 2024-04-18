#include <stdio.h>
#include <string.h>

int main (void)
{
    int numero1 = 0, numero2 = 0, i = 0, loop = 0, contador = 0;
    char texto[1000];
    char temporario;

    scanf("%i%i", &numero1, &numero2);

    while (loop == 0)
    {
        scanf("%c", &temporario);
        if (temporario != '.')
        {
            texto[i] = temporario;
            i++;
        }
        else if (temporario == '.' && contador == 0)
        {
            texto[i] = temporario;
            contador = 1;
        }
        if (contador == 1)
        {
            loop++;
        }
    }

    if (numero1 == 1)
    {
        for (i = 1; i < strlen(texto); i++)
        {
            if (texto[i] >= 'a' && texto[i] <= 'z')
            {
                texto[i] = ((texto[i] - 'a' + numero2) % 26) + 'a';
            }
            printf ("%c", texto[i]);
        }
    }

    if (numero1 == 2)
    {
        for (i = 1; i < strlen(texto); i++)
        {
            if (texto[i] >= 'a' && texto[i] - 1 <= 'z')
            {
                texto[i] = ((texto[i] - 'a' - numero2 + 26) % 26) + 'a';
            }
            printf ("%c", texto[i]);
        }
    }
}