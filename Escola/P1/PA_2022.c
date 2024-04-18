#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main (void)
{
    char c;
    int x = 0, y = 0, i = 0;
    int digitosX[99999] = {0};
    int digitosY[99999] = {0};

    scanf("(%c,%i,%i", &c, &x, &y);

    printf ("(");
    int digitosx = floor(log10(abs(x))) + 1;
    int digitosy = floor(log10(abs(y))) + 1;
    int copiax = x;
    int copiay = y;
    int maior = 0;

    int a = digitosx;
    int b = digitosy;

    printf ("%i, %i", digitosx, digitosy);

    for (i = digitosx - 1; i >= 0; i--)
    {
        if (a < b)
        {
            digitosX[i] = 0;
            a++;
            printf ("\n\n%i, %i\n", a, b);
        }
        else
        {
            digitosX[i + a] = copiax % 10;
            copiax = copiax / 10;
        }
    }
    for (i = digitosy - 1; i >= 0; i--)
    {
        if (a < b)
        {
            digitosY[i] = 0;
            a++;
            printf ("\n\n%i, %i\n", a, b);
        }
        else
        {
            digitosY[i + a] = copiax % 10;
            copiax = copiax / 10;
        }
    }

    if (isalpha(c))
    {

        printf (")");
    }

    printf ("\n\n");

    for (int i = 0; i < 10; i++)
    {
        printf ("%i ", digitosX[i]);
    }
    printf ("\n\n");

    for (int i = 0; i < 10; i++)
    {
        printf ("%i ", digitosY[i]);
    }

    return 0;
}