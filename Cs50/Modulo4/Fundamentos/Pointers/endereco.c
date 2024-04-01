#include <stdio.h>

int main (void)
{
    int n = 50;
    int *p = &n;
    printf ("%p\n", &n);
    printf ("%i\n", *&n);
    printf ("%p\n", p);
    printf ("%i\n", *p);

    char *s = "Chocolate!";
    printf ("%s\n", s);

    for (int i = 0; *(s+i) != '\0'; i++)
    {
        printf ("%c", *(s+i));
    }
    printf ("\n");

}

// "*" ir para um local da memorida ou serve como pointer
// "&" serve para mostrar em qual parte da memoria certa variavel esta alocada
// "char *s" é um tipo de dado igual ao "string" porém definir diretamente como "string" é uma simplificação do CS50!


