#include <stdio.h>
#include <cs50.h>

void selectionsort (int val[], int n);

int main (void)
{
    const int MAXIMO = get_int("Numero de variaveis: ");
    int variavel[MAXIMO];

    for (int i = 0; i < MAXIMO; i++)
    {
        variavel[i] = get_int ("Variavel %i: ", i+1);
    }

    selectionsort (variavel, MAXIMO);

    for (int i = 0; i < MAXIMO; i++)
    {
        printf ("Variavel organizada %i: %i\n", i+1, variavel[i]);
    }
    return 0;
}

void selectionsort (int val[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (val[i] > val[j])
            {
                int aux = val[i];
                val[i] = val[j];
                val[j] = aux;
            }
        }
    }
}

/*
for (int i = 0; i < MAX; i++)
{
    for (int j = i+1; j < MAX; j++)
    {
        if (Val1[i] > Val2[j])
        {
            int aux = Val1[i];
            Val1[i] = Val2[j];
            Val2[j] = aux;
        }
    }
}
*/
