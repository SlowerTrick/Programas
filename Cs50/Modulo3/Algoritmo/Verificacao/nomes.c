#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    string nomes[] = {"Artur", "Pedro", "Lucas", "Jonas", "Eduardo", "Ronald", "Kurisu", "Leon"};
    const int TOTAL = 8;

    for (int i = 0, n = TOTAL, j = 0; i < n; i++)
    {
        if(strcmp(nomes[i], "Kurisu") == 0)
        {
            printf ("Tudo certo!\n");
            return 0;
        }
        j++;
        printf ("Não deu bom %i vez(es)\n", j);
    }
    return 1;
}
