#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int variavel[3];

    for (int i = 0; i < 2; i++)
    {
        variavel[i+1] = get_int ("Valor %i:", i+1);
    }

    variavel[0] = variavel[1];
    variavel[1] = variavel[2];
    variavel[2] = variavel[0];
    variavel[0] = 0;

    for (int i = 0; i < 2; i++)
    {
        printf ("Valor trocado: %i: %i\n", i+1, variavel[i+1]);
    }
}
