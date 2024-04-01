#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    int aleatorio;
    srand(time(NULL));

    for (int i = 0; i < 30; i++)
    {
    aleatorio = rand() % 12;
    printf ("%i ", aleatorio);
    }
    printf ("\n");

    for (int i = 0; i < 10; i++)
    {
        float aleatorio_flutuante = 10 + ((float)rand() / (float)RAND_MAX) * 90.0;
        printf("%.1f ", aleatorio_flutuante);
    }
    printf ("\n");
    return 0;
}

/*
"%100" é utilizado para limitar os valores até 99
"%100 + 1" é utilizado para limitar os valores entra 1 e 100
"10 + rand() % 91" é utilizado para limitar o resultado entra 10 e 100
"10 + ((float)rand() / (float)RAND_MAX) * 90.0" Limita o resultado entre 10.0 e 100.0
*/
