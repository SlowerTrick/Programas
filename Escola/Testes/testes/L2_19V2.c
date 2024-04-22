#include <stdio.h>

int main (void)
{
    int delegacoes = 0, contador1 = 0, contador2 = 0, contador3 = 0, atleta = 0;
    int tamanhodelegacao[10000] = {0};
    int notas[10000][3];
    char generos[10000];
    int i = 0;
    int melhornotamasculino = 0, piornotamasculino = 0, melhornotafeminino = 0, piornotfeminino = 0;

    scanf ("%i", &delegacoes);
    getchar();

    while (contador1 < delegacoes)
    {
        while (1)
        {
            scanf ("%i", &atleta);
            if (atleta == -1)
            {
                break;
            }
            scanf (" %c %i %i %i", &generos[contador2], &notas[contador2][0], &notas[contador2][1], &notas[contador2][2]);
            contador2++;
            tamanhodelegacao[contador1]++;
        }
        contador1++;
    }
    contador1 = 0;
    contador2 = 0;