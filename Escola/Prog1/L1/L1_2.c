#include <stdio.h>
#include <math.h>

int main (void)
{
    float x = 0;
    float y = 0;

    scanf ("%f%f", &x, &y);

    x = x + x;
    y = y + y;

    float soma = x + y;

    printf ("%.2f\n", soma);
}