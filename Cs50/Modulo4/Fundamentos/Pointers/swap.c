#include <stdio.h>

void swap (int *a, int *b);

int main (void)
{
    int x = 10;
    int y = 5;

    printf ("Valor de x: %i, Valor de y: %i\n", x, y);
    swap(&x, &y);
    printf ("Valor de x: %i, Valor de y: %i\n", x, y);
}

void swap (int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

// & = local especifico
// * pode ser pensado como "oq estiver em"
