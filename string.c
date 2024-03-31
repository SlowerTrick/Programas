#include <stdio.h>
#include <string.h>

int main (void)
{
    char s1[1000];

    fgets (s1, sizeof(s1), stdin);
    printf ("\n");

    printf ("Tamanho da string original: %i\n", strlen(s1));

    for (int i = 0; i < strlen(s1); i++)
    {
        if (s1[i] == '\n')
        {
            printf ("Caractere %i: Espaco\n\n", i+1);
        }
        else
        printf ("Caractere %i: %c\n", i+1, s1[i]); 
    }

    s1[strlen(s1) - 1] = '\0';

    printf ("Tamanho da string final: %i\n", strlen(s1));
    for (int i = 0; i < strlen(s1); i++)
    {
        if (s1[i] == '\n')
        {
            printf ("Caractere %i: Espaco\n\n", i+1);
        }
        else
        printf ("Caractere %i: %c\n", i+1, s1[i]); 
    }

    printf ("\n");

}