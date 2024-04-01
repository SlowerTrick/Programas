#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int fibonacci (int x, int lista[]);

int main (void)
{
    int termo;
    do
    {
        char verificador;
        printf("Termo desejado: ");
        while(scanf("%d%c", &termo, &verificador) != 2 || verificador != '\n' || termo <= 0) //Checa termo e verificador
        {
            printf("Entrada inválida. Por favor, insira um número inteiro.\nTermo desejado: ");
            while(getchar() != '\n'); // Limpa o buffer de entrada
        }
    }
    while(termo == 0);

    int qtermos[termo];

    printf ("%i° termo: %i\n", termo, fibonacci(termo-1, qtermos));

    return 0;
}

int fibonacci (int x, int lista[])
{
    lista [0] = 0;
    lista [1] = 1;

    if (x == 0 || x == 1)
    {
        return x;
    }

    else
    {
        lista[x] = fibonacci(x - 1, lista) + lista[x - 2];
    }

    lista[x] = lista[x - 1] + lista[x - 2];

    return lista[x];
}
