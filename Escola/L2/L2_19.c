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

    while (contador1 < delegacoes)
    {
        for (i = 0; i < tamanhodelegacao[contador1]; i++)
        {
            printf ("Genero do atleta %i: %c, nota1: %i, nota2: %i, nota3: %i\n", i+1, generos[contador2], notas[contador2][0], notas[contador2][1], notas[contador2][2]);
            contador2++;
        }
        printf ("\n");
        contador1++;
    }

    contador1 = 0;
    contador2 = 0;
    int melhoresnotasmasculino[100];
    int melhoresnotasfeminino[100];
    int pioresnotasmasculino[100];
    int pioresnotasfeminino[100];

    while (contador1 < delegacoes)
    {
        for (i = 0; i < tamanhodelegacao[contador1]; i++)
        {
            if (generos[contador2] == 'M')
            {
                if (melhornotamasculino < notas[contador2][0])
                {
                    melhornotamasculino = notas[contador2][0];
                }
                if (melhornotamasculino < notas[contador2][1])
                {
                    melhornotamasculino = notas[contador2][1];
                }
                if (melhornotamasculino < notas[contador2][2])
                {
                    melhornotamasculino = notas[contador2][2];
                }
            }
            if (generos[contador2] == 'F')
            {
                if (melhornotafeminino < notas[contador2][0])
                {
                    melhornotafeminino = notas[contador2][0];
                }
                if (melhornotafeminino < notas[contador2][1])
                {
                    melhornotafeminino = notas[contador2][1];
                }
                if (melhornotafeminino < notas[contador2][2])
                {
                    melhornotafeminino = notas[contador2][2];
                }
            }
            contador2++;
        }
        melhoresnotasmasculino[contador1] = melhornotamasculino;
        melhoresnotasfeminino[contador1] = melhornotafeminino;

        if (notas[])



        printf ("\nDelegacao: %i, Melhor nota masculino: %i\n", contador1+1 ,melhoresnotasmasculino[contador1]);
        printf ("Delegacao: %i, Melhor nota feminino: %i\n", contador1+1  , melhoresnotasfeminino[contador1]);

        contador1++;
    }
    contador1 = 0;
    contador2 = 0;
    contador3 = 0;

    int jogadorescommelhornotasmasculino[100] = {0};
    int jogadorescommelhornotasfeminino[100] = {0};

    contador1 = 0;
    contador2 = 0;

    for (i = 0; i < contador3; i++)
    {
        printf("%i ", jogadorescommelhornotasmasculino[contador1]);
        contador1++;
    }
    printf ("\n");
    contador1 = 0;
    for (i = 0; i < contador3; i++)
    {
        printf("%i ", jogadorescommelhornotasfeminino[contador1]);
        contador1++;
    }
}