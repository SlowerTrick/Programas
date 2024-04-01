#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Número máximo de candidatos
#define MAX 9

// preferencias[i][j] é o número de eleitores que preferem i em relação a j
int preferencias[MAX][MAX];

// trancado[i][j] significa que i está trancado em relação a j
bool trancado[MAX][MAX];

// Cada par tem um vencedor e um perdedor
typedef struct
{
    int vencedor;
    int perdedor;
}
par;

// Array de candidatos
string candidatos[MAX];
par pares[MAX * (MAX - 1) / 2];

int contador_pares;
int contador_candidatos;

// Protótipos de função
bool votar(int rank, string nome, int ranks[]);
void registrar_preferencias(int ranks[], int eleitores);
void adicionar_pares(void);
void ordenar_pares(void);
void bloquear_pares(void);
void imprimir_vencedor(void);
void caminhovalido(int seta)

int main(int argc, string argv[])
{
    // Verifica o uso inválido
    if (argc < 2)
    {
        printf("Uso: tideman [candidato ...]\n");
        return 1;
    }

    // Preenche o array de candidatos
    contador_candidatos = argc - 1;
    if (contador_candidatos > MAX)
    {
        printf("O número máximo de candidatos é %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < contador_candidatos; i++)
    {
        candidatos[i] = argv[i + 1];
    }

    // Limpa o gráfico de pares selecionados
    for (int i = 0; i < contador_candidatos; i++)
    {
        for (int j = 0; j < contador_candidatos; j++)
        {
            trancado[i][j] = false;
        }
    }

    contador_pares = 0;
    int numero_eleitores = get_int("Número de eleitores: ");

    // Consulta para votos
    for (int i = 0; i < numero_eleitores; i++)
    {
        // ranks[i] é a i-ésima preferência do eleitor
        int ranks[contador_candidatos];
        printf("Votos do eleitor %i:\n\n", i);

        // Consulta para cada classificação
        for (int j = 0; j < contador_candidatos; j++)
        {
            string nome = get_string("Rank %i: ", j + 1);

            if (!votar(j, nome, ranks))
            {
                printf("Voto inválido.\n");
                return 3;
            }
        }

        registrar_preferencias(ranks, numero_eleitores);
        printf("\n");
    }

    adicionar_pares();
    ordenar_pares();
    bloquear_pares();
    imprimir_vencedor();

    /*
    for (int i = 0; i < contador_candidatos; i++)
    {
        for (int j = 0; j < contador_candidatos; j++)
        {
            if (i != j)
            {
                printf ("%i Preferem o candidato %i relação ao candidato %i\n", preferencias[i][j], i, j);
            }
        }
    }
    */
    return 0;
}

// Atualiza as classificações dado um novo voto
bool votar(int rank, string nome, int ranks[])
{
    for (int i = 0; i < contador_candidatos; i++)
    {
        if (strcmp(nome, candidatos[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Atualiza as preferências dada as classificações de um eleitor
void registrar_preferencias(int ranks[], int eleitores)
{
    for (int i = 0; i < eleitores; i++)
    {
        for (int j = 0; j < contador_candidatos; j++)
        {

            if (i == j)
            {
                preferencias[i][j] = 0;
            }
            if (i < j)
            {
                preferencias[ranks[i]][ranks[j]]++;
            }
        }
    }
    return;
}



// Registra pares de candidatos onde um é preferido sobre o outro
void adicionar_pares(void)
{
    for (int i = 0; i < contador_candidatos; i++)
    {
        for (int j = 0; j < contador_candidatos; j++)
        {
            if (preferencias[i][j] > preferencias[j][i])
            {
                pares[contador_pares].vencedor = i;
                pares[contador_pares].perdedor = j;
                contador_pares++;
                printf ("Candidato %i ganha de %i\n", i , j);
            }
        }
    }
    printf ("Numero de pares criados: %i\n\n", contador_pares);
    return;
}

// Ordena pares em ordem decrescente pela força da vitória

void ordenar_pares (void)
{
    for (int i = 0; i < contador_pares; i++)
    {
        for (int j = i+1; j < contador_pares; j++)
        {
            if (preferencias[pares[i].vencedor][pares[i].perdedor] < preferencias[pares[j].vencedor][pares[j].perdedor])
            {
                int aux = pares[i].vencedor;
                pares[i].vencedor = pares[j].vencedor;
                pares[j].vencedor= aux;

                aux = pares[i].perdedor;
                pares[i].perdedor = pares[j].perdedor;
                pares[j].perdedor = aux;
            }
        }
    }

    // Impressão dos vencedores ordenados
    for (int i = 0; i < contador_pares; i++)
    {
        printf ("Vencedor: %i ", pares[i].vencedor);
        printf ("Perdedor: %i \n", pares[i].perdedor);
    }
    printf("\n");
}


// Bloqueia pares no gráfico de candidatos em ordem, sem criar ciclos
void bloquear_pares(void)
{
    for (int i = 0; i < contador_pares; i++)
    {
        if(!caminhovalido(i))
        {
            trancado[pares[i].vencedor][pares[i].perdedor] = true;
        }
    }
}

void caminhovalido (int seta)
{
    int ganhador = pares[seta].vencedor;
    int perdedor = pares[seta].perdedor;

    

    return false
}



// Imprime o vencedor da eleição
void imprimir_vencedor(void)
{
    // TODO
    return;
}
