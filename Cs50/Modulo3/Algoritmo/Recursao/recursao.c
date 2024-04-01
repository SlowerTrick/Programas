#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void reduzir (int n);
void somar (int n);

int main (int argc, string argv[])
{

    if (argc != 2)
    {
        printf ("Uso correto: ./recursao (numero desejado)\n");
        return 1;
    }

    int numero = atoi(argv[1]);
    int escolha;

    do
    {
        printf ("Somar(1) ou Reduzir(2)? ");
        scanf ("%i", &escolha);
    }
    while (escolha < 1 || escolha > 2);

    if (escolha == 1)
    {
        somar (numero);
    }
    else
    reduzir (numero);

    printf ("\n");
}

void reduzir (int n)
{
    if (n == 0)
    {
        printf ("%i\n", n);
        return;
    }
    else
    printf ("%i ", n);
    reduzir(n - 1);

}

void somar (int n)
{
    if (n == 0)
    {
        printf ("%i ", n);
        return;
    }
    else
    somar(n - 1);
    printf ("%i ", n);
}
