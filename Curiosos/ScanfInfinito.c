#include <stdio.h>

int main() 
{
    int numeros[1000];
    int i = 0, j = 0, aux = 0, total = 0; 
    char verificador;

    while(scanf("%d%c", &numeros[i], &verificador) != EOF && i < 1000) 
    {
        i++;
        total++;
        if(verificador == '\n')
        {
            break;
        }
    }

    for (i = 0; i < total; i++)
    {
        for (j = i + 1; j < total; j++)
        {
            if (numeros[i] > numeros[j])
            {
                aux = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = aux;
            }
        }
    }

     for (i = 0; i < total; i++)
     {
        printf ("Numero %i: %i\n", i, numeros[i]);
     }

    return 0;
}