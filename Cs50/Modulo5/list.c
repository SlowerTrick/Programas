#include <stdio.h>

typedef struct node
{
    int number;
    struct node;
}
node;

int main (void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }
}