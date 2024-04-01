#include <stdio.h>

int calculo (int x);

int main (void)
{
    int numero;
    printf ("Numero ao qual o fatorial deve ser descoberto: ");
    scanf ("%i", &numero);

    printf ("Numero inicial: %i\n", numero);

    numero = calculo (numero);

    printf ("Fatorial: %i\n", numero);
}

int calculo (int x)
{
    if (x == 0)
    {
        x = 1;
    }
    else
    {
        x = x * calculo(x - 1);
    }
    return x;
}


