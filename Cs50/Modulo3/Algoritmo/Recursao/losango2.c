#include <stdio.h>

void desenhar (int x, int base);

int main (void)
{
    int tamanho;
    do
    {
        char verificador;
        printf ("Tamanho: ");
        while (scanf("%d%c", &tamanho, &verificador) != 2 || verificador != '\n' || tamanho <= 2)
        {
            if (verificador != '\n')
            {
                printf ("Só são aceitos números naturais positivos nesse programa!\n");
            }

            if (tamanho <= 2)
            {
                printf ("tamanho minimo para losango é 3\n");
            }
            printf ("Tamanho: ");
            while(getchar() != '\n');
        }
    }
    while (tamanho == 0);

    desenhar (tamanho, tamanho);
}

void desenhar (int x, int base)
{
    if (x == 0)
    {
        return;
    }
    else

    if (x > 1)
    {
        for (int i = 0; i < x*2; i++)
        {
            if (i == x || i == x - 1)
            {
                printf ("#");
            }
            else
            printf(" ");

            if (i == x - 1 && x != base)
            {
                for (int j = 0; j < base - x; j++)
                {
                    printf("  ");
                }
            }
        }
    }
    
    if (x != 1)
    {
        printf ("\n");
        desenhar (x - 1, base);
    }

    for (int i = 0; i < x * 2; i++)
    {
        if (i == x || i == x - 1)
        {
            printf ("#");
        }
        else
        printf(" ");

        if (i == x - 1 && x != base)
        {
            for (int j = 0; j < base - x; j++)
            {
                printf("  ");
            }
        }
    }
    printf ("\n");
}
