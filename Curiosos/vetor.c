#include <stdio.h>

void AlteraVetor (int vetor[]);

int main (void)
{
    int vetor[5] = {0, 1, 2, 3, 4};
    printf ("Antes: ");
    for (int i = 0; i < 5; i++)
    {
        printf ("%i ", vetor[i]);
    }
    printf ("\n");
    AlteraVetor(vetor);
    printf ("Depois: ");
    for (int i = 0; i < 5; i++)
    {
        printf ("%i ", vetor[i]);
    }
    printf ("\n");
    return 0;
}

void AlteraVetor (int vetor[])
{
    for (int i = 0; i < 5; i++)
    {
        vetor[i] += 1;
    }
    return;
}