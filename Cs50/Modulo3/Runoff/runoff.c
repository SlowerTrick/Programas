#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_VOTANTES 100
#define MAX_CANDIDATOS 9

typedef struct
{
    string nome;
    int votos;
    bool eliminado;
}
candidato;

candidato candidatos[MAX_CANDIDATOS];
int preferencia [MAX_VOTANTES][MAX_CANDIDATOS];

bool votar(int votante, int rank, string nome, int totalcandidatos);
void contabilizar(int votante, int totalcandidatos);
bool ganhador(int votantes, int totalcandidatos);
int valorminimo(int totalcandidatos);
bool empate(int totalcandidatos);
void eliminar(int min, int totalcandidatos);

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 10)
    {
        printf("Uso correto: ./runoff candidatos(max 9)\n");
        return 1;
    }

    int valorcandidatos = argc - 1;

    for (int i = 0; i < valorcandidatos; i++)
    {
        candidatos[i].nome = argv[i+1];
        candidatos[i].votos = 0;
        candidatos[i].eliminado = false;
    }

    int nvotantes;

    do
    {
        nvotantes = get_int("Número de votantes (Max 100): ");
    }
    while (nvotantes < 0 || nvotantes > MAX_VOTANTES);

    for (int i = 0; i < nvotantes; i++)
    {
        for (int j = 0; j < 3; j++) // 3 votos por candidato
        {
            string voto = get_string("Voto %i do votante %i: ", j+1, i+1);
            if (!votar(i, j, voto, valorcandidatos)) // Se o voto não existir o programa para
            {
                return 2;
            }
        }
    }

    while (true)
    {
        for (int i = 0; i < nvotantes; i++)
        {
            contabilizar(i, valorcandidatos);
        }

        if (ganhador(nvotantes, valorcandidatos))
        {
            for (int i = 0; i < valorcandidatos; i++)
            {
                if (!candidatos[i].eliminado && candidatos[i].votos > nvotantes / 2)
                {
                    printf("Ganhador da eleição: %s\n", candidatos[i].nome);
                    return 0;
                }
            }
        }

        if (empate(valorcandidatos))
        {
            printf("Eleição Empatada!\n");
            return 0;
        }

        int min = valorminimo(valorcandidatos);
        eliminar(min, valorcandidatos);

        for (int i = 0; i < valorcandidatos; i++)
        {
            candidatos[i].votos = 0;
        }
    }
}

bool votar(int votante, int rank, string nome, int totalcandidatos)
{
    for (int i = 0; i < totalcandidatos; i++)
    {
        if (strcmp(nome, candidatos[i].nome) == 0)
        {
            preferencia[votante][rank] = i;
            return true;
        }
    }
    return false;
}

void contabilizar(int votante, int totalcandidatos)
{
    for (int rank = 0; rank < totalcandidatos; rank++)
    {
        int votado = preferencia[votante][rank];
        if (!candidatos[votado].eliminado)
        {
            candidatos[votado].votos++;
            break;
        }
    }
}

bool ganhador(int votantes, int totalcandidatos)
{
    for (int i = 0; i < totalcandidatos; i++)
    {
        if (!candidatos[i].eliminado && candidatos[i].votos > votantes / 2)
        {
            return true;
        }
    }
    return false;
}

int valorminimo(int totalcandidatos)
{
    int min = MAX_VOTANTES;
    for (int i = 0; i < totalcandidatos; i++)
    {
        if (!candidatos[i].eliminado && candidatos[i].votos < min)
        {
            min = candidatos[i].votos;
        }
    }
    return min;
}

bool empate(int totalcandidatos)
{
    int votos = -1;

    for (int i = 0; i < totalcandidatos; i++)
    {
        if (!candidatos[i].eliminado)
        {
            if (votos == -1)
            {
                votos = candidatos[i].votos;
            }
            else if (candidatos[i].votos != votos)
            {
                return false;
            }
        }
    }
    return true;
}

void eliminar(int min, int totalcandidatos)
{
    for (int i = 0; i < totalcandidatos; i++)
    {
        if (!candidatos[i].eliminado && candidatos[i].votos == min)
        {
            candidatos[i].eliminado = true;
        }
    }
}
