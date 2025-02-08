#include "pokemon.h"

struct poke
{
    char *nome;
    char *tipo1;
    char *tipo2;
    int level;
};

tPokemon captura_pokemon(char *nome, char *tipo1, char *tipo2, int level)
{
    tPokemon pokemon = malloc(sizeof(struct poke));
    if (!pokemon) {
        printf("ERRO! falta de memória");
        exit(1);
    }

    pokemon->nome = malloc(strlen(nome) + 1);
    if (!pokemon->nome) {
        free(pokemon);
        printf("ERRO! falta de memória");
        exit(1);
    }
    strcpy(pokemon->nome, nome);

    pokemon->tipo1 = malloc(strlen(tipo1) + 1);
    if (!pokemon->tipo1) {
        free(pokemon->nome);
        free(pokemon);
        printf("ERRO! falta de memória");
        exit(1);
    }
    strcpy(pokemon->tipo1, tipo1);

    pokemon->tipo2 = malloc(strlen(tipo2) + 1);
    if (!pokemon->tipo2) {
        free(pokemon->tipo1);
        free(pokemon->nome);
        free(pokemon);
        printf("ERRO! falta de memória");
        exit(1);
    }
    strcpy(pokemon->tipo2, tipo2);

    pokemon->level = level;

    return pokemon;
}

void imprime_pokemon(tPokemon p)
{
    printf("\tNome: %s\n", p->nome);
    printf("\tTipo 1: %s\n", p->tipo1);
    printf("\tTipo 2: %s\n", p->tipo2);
    printf("\tLevel: %d\n", p->level);
}

void subir_level_pokemon(tPokemon p)
{
    p->level++;
}

char *obtem_tipo1_pokemon(tPokemon p)
{
    return p->tipo1;
}

char *obtem_tipo2_pokemon(tPokemon p)
{
    return p->tipo2;
}

char *obtem_nome_pokemon(tPokemon p)
{
    return p->nome;
}   

int obtem_level_pokemon(tPokemon p)
{
    return p->level;
}

int eh_mesmo_pokemon(tPokemon p, char *nome)
{
    return strcmp(p->nome, nome) == 0;
}

void libera_pokemon(tPokemon p)
{
    if(p->nome)
    {
        free(p->nome);
        p->nome = NULL;
    }
    if(p->tipo1)
    {
        free(p->tipo1);
        p->tipo1 = NULL;
    }
    if(p->tipo2)
    {
        free(p->tipo2);
        p->tipo2 = NULL;
    }
    if(p)
    {
        free(p);
        p = NULL;
    }
}