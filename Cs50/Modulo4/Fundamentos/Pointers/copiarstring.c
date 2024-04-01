#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h> //Serve para a utilização da função malloc

int main (void)
{
    char *str = get_string ("String a ser copiada: ");
    char *str2 = malloc(strlen(str) + 1);

    if (str2 == NULL) //Caso específico para caso malloc não encontre um locar para armazernar memoria, assim o programa para
    {
        return 1;
    }

    for (int i = 0, n = strlen(str); i <= n; i++)
    {
        str2[i] = str[i];

        // "str2[i] = str[i];" é igual a: "*(str2 + i) = *(str + i);"

        if (strlen(str) > 0) //Para evitar o caso de alterar um caracter vazio
        {
            str[i] = tolower(str[i]);
            str2[i] = toupper(str2[i]);
        }
    }

    printf ("%s\n", str);
    printf ("%s\n", str2);

    free (str2); //Libera a memoria solicitada por malloc

    /*Todo esse trabalho pode ser pulado como a utilização da função strcpy()

    Exemplo:
    strcpy(str2, str);

    copia str em str2, com um local de memoria diferente
    */
}
