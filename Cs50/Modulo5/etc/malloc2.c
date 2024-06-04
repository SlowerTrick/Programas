#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    int elementos = 1;
    int *lista = malloc(sizeof(int));

    if (lista == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    char confirmação = 0;

    do
    {
        printf("Deseja adicionar um elemento a lista ('s' ou 'n')? ");
        scanf(" %c", &confirmação);
        while (getchar() != '\n');
        
        if (tolower(confirmação) == 's')
        {
            printf("Quantidade de elementos atual: %i\n\n", elementos - 1);

            int *tmp = realloc(lista, elementos * sizeof(int));

            if (tmp == NULL)
            {
                printf("Erro na realocação de memória.\n");
                free(lista);
                return 1;
            }

            lista = tmp;

            int novoElemento = 0;
            printf("Novo elemento: ");
            scanf("%i", &novoElemento);
            lista[elementos - 1] = novoElemento;

            for (int i = 0; i < elementos; i++)
            {
                printf("Elemento %i: %i\n", i + 1, lista[i]);
            }
            printf("\n");

            elementos++;
        }
        else if (tolower(confirmação) != 'n')
        {
            printf("Resposta invalida. Digite 's' para sim ou 'n' para nao.\n");
        }
    } 
    while (tolower(confirmação) != 'n');

    free(lista);
    return 0;
}