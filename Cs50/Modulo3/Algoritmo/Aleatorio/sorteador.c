#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

bool numeroinvalido1 (int random, int minimo, int maximo);
bool numeroinvalido2 (int valor, int random, int numerosSalvos[]);

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("Uso correto: ./sorteador ('1' para sorteio de números aleatorios e '2' para sorteio com multiplos participantes)\n");
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Por favor, forneça apenas números positivos como entrada.\n");
            return 2;
        }
    }

    int tipodesorteio = atoi(argv[1]);

    if (tipodesorteio < 1 || tipodesorteio > 2)
    {
        printf ("Uso correto: ./sorteador2 ('1' para sorteio de números aleatorios e '2' para sorteio com multiplos participantes)\n");
        return 3;
    }

    if (tipodesorteio == 1)
    {
        srand(time(NULL));
        int min, max, aleatorio, Nnumeros;
        do
        {
            Nnumeros = get_int ("Número de valores sorteados: ");
            if (Nnumeros == 0 || Nnumeros < 0)
            {
                printf ("A quantidade de sorteios tem que ser maior do que 0\n");
            }
        }
        while (Nnumeros <= 0);

        printf ("Agora dê informações quanto ao intervalo do sorteio\n");

        do
        {
            min = get_int ("Valor mínimo: ");
            max = get_int ("Valor máximo: ");
            if (max < min)
            {
                printf ("O minimo de valores tem que ser menor que o máximo\n");
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
        int Nnumeros = get_int ("Número de participantes do sorteio: ");
        int resultados[Nnumeros];

        for (int i = 0; i < Nnumeros; i++)
        {
            do
            {
                aleatorio = rand() % Nnumeros + 1;
                resultados[i] = aleatorio;
            }
            while (numeroinvalido2(i, aleatorio, resultados));

            printf ("Número Sorteado %i: %i ", i+1, aleatorio);
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
