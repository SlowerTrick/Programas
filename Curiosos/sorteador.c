#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

bool numeroinvalido1 (int random, int minimo, int maximo);
bool numeroinvalido2 (int valor, int random, int numerosSalvos[]);

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        printf ("Uso correto: ./sorteador ('1' para sorteio de numeros aleatorios e '2' para sorteio com multiplos participantes)\n");
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Por favor, forneca apenas numeros positivos como entrada.\n");
            return 2;
        }
    }

    int tipodesorteio = atoi(argv[1]);

    if (tipodesorteio < 1 || tipodesorteio > 2)
    {
        printf ("Uso correto: ./sorteador2 ('1' para sorteio de numeros aleatorios e '2' para sorteio com multiplos participantes)\n");
        return 3;
    }

    if (tipodesorteio == 1)
    {
        srand(time(NULL));
        int min, max, aleatorio, Nnumeros;
        do
        {
            printf ("Numero de valores sorteados: ");
            scanf("%i", &Nnumeros);
            if (Nnumeros == 0 || Nnumeros < 0)
            {
                printf ("A quantidade de sorteios tem que ser maior do que 0\n");
            }
        }
        while (Nnumeros <= 0);

        printf ("Agora de informacoes quanto ao intervalo do sorteio\n");

        do
        {
            printf ("Valor minimo: ");
            scanf("%i", &min);
            printf ("Valor maximo: ");
            scanf("%i", &max);

            if (max < min)
            {
                printf ("O minimo de valores tem que ser menor que o maximo\n");
            }
        }
        while (max < min);

        max = max + 1;

        for (int i = 0; i < Nnumeros; i++)
        {
            do
            {
                aleatorio = rand() % max;
            }
            while (!numeroinvalido1 (aleatorio, min, max));

            printf ("Valor %i: %i", i+1, aleatorio);
            printf ("\n");
        }
    }

    if (tipodesorteio == 2)
    {
        srand(time(NULL));
        int aleatorio;
        int Nnumeros = 0;
        printf ("Numero de participantes do sorteio: ");
        scanf("%i", &Nnumeros);
        int resultados[Nnumeros];

        for (int i = 0; i < Nnumeros; i++)
        {
            do
            {
                aleatorio = rand() % Nnumeros + 1;
                resultados[i] = aleatorio;
            }
            while (numeroinvalido2(i, aleatorio, resultados));

            printf ("Numero Sorteado %i: %i ", i+1, aleatorio);
            printf ("\n");
        }
    }
}

bool numeroinvalido1 (int random, int minimo, int maximo)
{
    if (random >= minimo && random <= maximo)
    {
        return true;
    }
    return false;
}

bool numeroinvalido2 (int valor, int random, int numerosSalvos[])
{
    for (int j = 0; j < valor; j++)
    {
        if (numerosSalvos[j] == random)
        {
            return true;
        }
    }
    return false;
}
