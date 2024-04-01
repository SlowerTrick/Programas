#include <stdio.h>

int main (void)
{
    char input[100];
    printf ("Nome do arquivo: ");
    scanf ("%s", input);

    FILE *arquivo = fopen (input, "r");
    if (!arquivo)
    {
        printf ("Arquivo não encontrado\n");
        return 1;
    }

    char aux;
    while(fscanf(arquivo, "%c", &aux) != EOF)
    {
        printf ("%c", aux);
    }

    return 0;
}

