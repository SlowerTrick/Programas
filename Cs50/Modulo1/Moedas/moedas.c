#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)

{
    int moedas = 0;
    float inicial;

    do
    {
        inicial = get_float ("Preço: ");
    }
    while (inicial < 0 || inicial == 0);

    int valor = round (inicial * 100);

    do
    {
        if (valor > 100 || valor == 100)
        {
        valor = valor - 100;
        moedas++;
        }

        if (valor > 49 && valor < 100)
        {
        valor = valor - 50;
        moedas++;
        }

        if (valor > 24 && valor < 50)
        {
            valor = valor - 25;
            moedas++;
        }

        if (valor > 9 && valor < 25)
        {

            valor = valor - 10;
            moedas++;
        }

        if (valor > 4 && valor < 10)
        {
            valor = valor - 5;
            moedas++;
        }

        if (valor > 0.9 && valor < 5)
        {
            valor = valor - 1;
            moedas++;
        }

    }
    while (valor > 0);

    printf ("Moedas necessárias: ");
    printf ("%i\n", moedas);
}
