#include "cs50.c"
#include <stdio.h>

int main (void)

{
    int tamanho;

    do
    {
       tamanho = get_int ("Tamanho (1-8): ");
    }

    while (tamanho < 1 || tamanho > 9);

    for (int i = 0; i <= tamanho; i++)
    {
        for (int j = 0; j < tamanho - i; j++)
        {
            printf (" ");
        }

        for (int j = 0; j < i; j++)
        {
            printf ("#");
        }
        printf ("\n");
    }
}
