#include <stdio.h>

typedef struct
{
    int atleta;
    char genero;
    int nota1;
    int nota2;
    int nota3;
    int delegacao;
}
atletas;

atletas atleta[10000];

int main (void)
{
    int delegacoes = 0, contador1 = 0, numero = 0, contador2 = 0;
    char genero;
    int nota1 = 0, nota2 = 0, nota3 = 0;

    scanf ("%i", &delegacoes);
    getchar();

    int totalatletas = 0;
    while (contador1 < delegacoes)
    {
        while (1)
        {
            scanf ("%i", &numero);
            if (numero == -1)
            {
                break;
            }
            scanf (" %c %i %i %i", &genero, &nota1, &nota2, &nota3);
            totalatletas++;
            contador2++;
            atleta[contador2].atleta = numero;
            atleta[contador2].delegacao = contador1;
            atleta[contador2].genero = genero;
            atleta[contador2].nota1 = nota1;
            atleta[contador2].nota2 = nota2;
            atleta[contador2].nota3 = nota3;
        }
        contador1++;
    }

    int i = 0, j = 0, aux = 0;

    for (i = 1; i < totalatletas; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (atleta[i].nota2 < atleta[i].nota3)
            {
                aux = atleta[i].nota2;
                atleta[i].nota2 = atleta[i].nota3;
                atleta[i].nota3 = aux;
            }
            if (atleta[i].nota1 < atleta[i].nota2)
            {
                aux = atleta[i].nota1;
                atleta[i].nota1 = atleta[i].nota2;
                atleta[i].nota2 = aux;
            }
        }
    }

    for (i = 1; i < totalatletas; i++)
    {
        printf ("Atleta: %i, ", atleta[i].atleta);
        printf ("Delegacao: %i, ", atleta[i].delegacao+1);
        printf ("Genero: %c, ", atleta[i].genero);
        printf ("Nota1: %i, ", atleta[i].nota1);
        printf ("Nota2: %i, ", atleta[i].nota2);
        printf ("Nota3: %i", atleta[i].nota3);
        printf ("\n");
    }
    printf ("\n");

    int melhornota1 = 0, melhornota2 = 0, melhornota3 = 0;
    int melhoresatletas[10000] = {0};
    contador1 = 0;
    contador2 = 0;
    int contador3 = 0;
    int menorindex = 0;

    for (i = 0; i < delegacoes; i++)
    {
        melhornota1 = 0;
        melhornota2 = 0;
        melhornota3 = 0;
        contador1 = 0;
        contador2 = 0;
        contador3 = 0;
        menorindex = 0;

        printf ("MELHORES ATLETAS DA DELEGACAO %i\n", (i+1));

        for (j = 1; j < totalatletas; j++)
        {
            if (atleta[j].delegacao == i && melhornota1 < atleta[j].nota1 && atleta[j].genero == 'M')
            {
                melhornota1 = atleta[j].nota1;
            }
        }
        printf ("\nMelhor nota masculina da delegação %i: %i\n", i+1, melhornota1);

        for (j = 1; j < totalatletas; j++)
        {
            if (atleta[j].delegacao == i && melhornota1 == atleta[j].nota1 && atleta[j].genero == 'M')
            {
                melhoresatletas[contador1] = atleta[j].atleta;
                contador1++;
            }
        }

        printf ("Atletas com a melhor nota pelo contador 1: %i\n", contador1);

        if (contador1 == 1)
        {
            printf ("MASCULINO: %i \n", melhoresatletas[contador1 - 1]);
            printf ("Meu contador: contador 1\n\n");
            continue;
        }
        else
        {
            for (j = 0; j < contador1; j++)
            {
                if (melhornota2 < atleta[melhoresatletas[j]].nota2)
                {
                    melhornota2 = atleta[melhoresatletas[j]].nota2;
                }
            }
        }

        for (j = 0; j < contador1; j++)
        {
            if (melhornota2 == atleta[melhoresatletas[j]].nota2)
            {
                melhoresatletas[contador2] = atleta[j].atleta;
                contador2++;
            }
        }

        printf ("Atletas com a melhor nota pelo contador 2: %i\n", contador2);

        if (contador2 == 1)
        {
            printf ("MASCULINO: %i \n", melhoresatletas[contador2 - 1]);
            printf ("Meu contador: contador 2\n\n");
            continue;
        }
        else
        {
            for (j = 0; j < contador2; j++)
            {
                if (melhornota3 < atleta[melhoresatletas[j]].nota3)
                {
                    melhornota3 = atleta[melhoresatletas[j]].nota3;
                }
            }
        }

        for (j = 0; j < contador2; j++)
        {
            if (melhornota3 == atleta[melhoresatletas[j]].nota3)
            {
                melhoresatletas[contador3] = atleta[j].atleta;
                contador3++;
            }
        }

        printf ("Atletas com a melhor nota pelo contador 3: %i\n\n", contador3);

        if (contador3 == 1)
        {
            printf ("MASCULINO: %i \n", melhoresatletas[contador3 - 1]);
            printf ("Meu contador: contador 3\n\n");
            continue;
        }
        else 
        {
            for (i = 0; i < contador3; i++)
            {
                menorindex = atleta[melhoresatletas[i]].atleta;
            }
            printf ("MASCULINO: %i \n", menorindex);
            printf ("Menor index\n\n");
            continue;
        }
    }
}