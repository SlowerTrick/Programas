#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int main (void)
{
    float palavras = 0;
    float frase = 0;
    float letras = 0;

    string texto = get_string ("Texto: ");
    for (int i = 0; texto[i] != '\0'; i++)
    {
        if (texto[i] >= 'a' && texto[i] <= 'z')
        {
            letras++;
        }

        if (texto[i] >= 'A' && texto[i] <= 'Z')
        {
            letras++;
        }

        if (texto[i] == ' ')
        {
            palavras++;
        }

        if (texto[i] == '!' || texto[i] == '.' || texto[i] == '?')
        {
            frase++;
        }
    }

    palavras = palavras + 1;

    float L = letras / (palavras/100);
    float S = frase / (palavras/100);
    float nivel = 0.0588 * L - 0.296 * S - 15.8;
    nivel = round(nivel);

    printf ("Letras: ");
    printf ("%.0f\n", letras);
    printf ("Palavras: ");
    printf ("%.0f\n", palavras);
    printf ("Frases: ");
    printf ("%.0f\n", frase);

    if (nivel < 1)
    {
        printf ("Grau Acadêmico: Prézinho\n");
    }

    if (nivel >= 1 && nivel <= 9)
    {
        printf ("Grau Acadêmico: ");
        printf ("%.0f", nivel);
        printf ("° Ano \n");
    }

    if (nivel > 9 && nivel < 13)
    {
        if (nivel == 10)
        printf ("Grau Acadêmico: 1° Ano do Ensino Médio\n");
        if (nivel == 11)
        printf ("Grau Acadêmico: 2° Ano do Ensino Médio\n");
        if (nivel == 12)
        printf ("Grau Acadêmico: 3° Ano do Ensino Médio\n");
    }

    if (nivel > 13)
    {
    printf ("Grau Acadêmico: Universitário+\n");
    }
}
