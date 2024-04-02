#include <stdio.h>

void bubblesort (int val[], int n);

int main (void)
{
    const int MAX = get_int ("Quantidade de números: ");
    int numero[MAX];

    for (int i = 0; i < MAX; i++)
    {
        numero[i] = get_int ("Números %i: ", i+1);
    }

    bubblesort (numero, MAX);

    printf("Array ordenado: ");
    for (int i = 0; i < MAX; i++)
    {
        printf("%i ", numero[i]);
    }
    printf("\n");
    return 0;

}

void bubblesort (int val[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (val[j] > val[j+1])
            {
                int aux = val[j];
                val[j] = val[j+1];
                val[j+1] = aux;
            }
        }
    }
}

/*
for (int i = 0; i < MAX - 1; i++)
{
    for (int j = i+1; j < (MAX - i - 1); j++)
    {
        if (Val1[j] > Val2[j+1])
        {
            int aux = Val1[j];
            Val1[j] = Val2[j+1];
            Val2[j+1] = aux;
        }
    }
}
*/
