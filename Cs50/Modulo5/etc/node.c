#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next; // O struct é necessário pq node ainda não foi definido
}
node;

int main (void)
{
    node *list = NULL;
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1; //(*n).number = 1;
    n->next = NULL; //(*n).next = NULL;
    list = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free (list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free (list->next);
        free (list);
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    while (list != NULL) // Vai até o final da lista para não haver vazamento de memória 
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}