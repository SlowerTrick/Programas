#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const int MAX = 9;

typedef struct
{
    string candidato;
    int votos;
}
pessoa;

int main (int argc, string argv[])
{
    pessoa candidatos[MAX];
    string original[MAX];

    if (argc > MAX + 1  || argc < 3)
    {
        printf ("Uso correto: ./plural (2-9 candidatos)\n");
        return 1;
    }

    for (int i = 0; i < argc - 1; i++)
    {

        candidatos[i].candidato = argv[i + 1];
        candidatos[i].votos = 0;
    }

    int numero = 0;
    string voto[MAX];

    do
    {
        numero = get_int ("Número de votantes: ");
    }
    while (numero <= 1 || numero > 9);

    for (int i = 0; i < numero; i++)
    {
        voto[i] = get_string("Voto %i: ", i + 1);
        for (int j = 0; j < argc - 1; j++)
        {
            if (strcmp(candidatos[j].candidato, voto[i]) == 0)
            {
                candidatos[j].votos++;
            }
        }
}

    for (int i = 0; i < argc - 1; i++)
    {
        for (int j = i+1; j < argc - 1; j++)
        {
            if (candidatos[i].votos > candidatos[j].votos)
            {
            pessoa aux1 = candidatos[i];
            candidatos[i] = candidatos[j];
            candidatos[j] = aux1;

                /* Logica completa:
                int aux1 = candidatos[i].votos;
                candidatos[i].votos = candidatos[j].votos;
                candidatos[j].votos = aux1;

                string aux2 = candidatos[i].candidato;
                candidatos[i].candidato = candidatos[j].candidato;
                candidatos[j].candidato = aux2;
                */
            }
        }
    }

    for (int i = 0; i < argc - 1; i++)
    {
    printf ("Votos do candidato %s: %i\n", candidatos[i].candidato, candidatos[i].votos);
    }

    int ganhador = candidatos[argc - 2].votos;
    int resultado = 0;

    for (int i = 0; i < argc - 1; i++)
    {
        if (candidatos[i].votos == ganhador)
        {
            resultado++;
        }
    }

    if (resultado == 1)
    {
        printf("Ganhador: Candidato(a) %s\n", candidatos[argc - 2].candidato);
    }

    if (resultado != 1)
    {
        printf ("Empate entre os candidatos: ");

        for (int i = 0; i < argc - 1; i++)
        {
            if (candidatos[i].votos == candidatos[argc - 2].votos)
            {
                printf ("%s", candidatos[i].candidato);
                printf (" ");
            }
        }
    }
    printf ("\n");
}
