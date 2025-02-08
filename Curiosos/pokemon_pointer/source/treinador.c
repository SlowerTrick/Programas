#include "treinador.h"

struct trainer{
    char *nome;
    tPokemon *pokemon;
    int n_pokemons;
};

tTreinador cria_treinador(char *nome)
{
    tTreinador t = malloc(sizeof(struct trainer));
    if (t == NULL)
    {
        printf("ERRO! falta de memória");
        exit(1);
    }
    t->nome = malloc(strlen(nome) + 1);
    strcpy(t->nome, nome);
    t->n_pokemons = 0;
    t->pokemon = NULL;
    return t;
}

void imprime_pokemons_treinador(tTreinador t)
{
    printf("\nTodos os pokemons:\n");
    for(int i = 0; i < obtem_numero_pokemons(t); i++)
    {
        imprime_pokemon(t->pokemon[i]);
        printf("\n");
    }
}

void imprime_um_pokemon_treinador(tTreinador t, char *nome)
{
    tPokemon p = obtem_pokemon(t, nome);
    if (p == NULL)
    {
        printf("\nO Pokemon nao esta na sua party!\n");
        return;
    }
    printf("Pokemon escolhido:\n");
    imprime_pokemon(p);
}

void adiciona_pokemon_time(tTreinador t, char *nome, char *tipo1, char *tipo2, int level)
{
    if (t->n_pokemons >= 6)
    {
        printf("\nO seu time já está cheio, libere um Pokémon antes de adicionar mais um.\n");
        return;
    }

    t->pokemon = realloc(t->pokemon, sizeof(tPokemon) * ++t->n_pokemons);
    if (t->pokemon == NULL)
    {
        printf("ERRO! falta de memória");
        exit(1);
    }
    t->pokemon[t->n_pokemons - 1] = captura_pokemon(nome, tipo1, tipo2, level);
}

void remove_pokemon_time(tTreinador t, char *nome)
{
    if(t->n_pokemons <= 0)
    {
        printf("\nO seu time está vazio! Nenhum Pokemon para remover.\n");
        return;
    }

    int index_pokemon = -1;
    for(int i = 0; i < t->n_pokemons; i++)
    {
        if(eh_mesmo_pokemon(t->pokemon[i], nome))
        {
            index_pokemon = i;
            break;
        }
    }

    if(index_pokemon == -1)
    {
        printf("\nO Pokemon nao esta na sua party!\n");
        return;
    }

    libera_pokemon(t->pokemon[index_pokemon]);

    for(int i = index_pokemon; i < t->n_pokemons - 1; i++)
    {
        t->pokemon[i] = t->pokemon[i + 1];
    }

    t->pokemon = realloc(t->pokemon, sizeof(tPokemon) * --t->n_pokemons);
}

int obtem_numero_pokemons(tTreinador t)
{
    return t->n_pokemons;
}

tPokemon obtem_pokemon(tTreinador t, char *nome)
{
    for (int i = 0; i < t->n_pokemons; i++)
    {
        if (eh_mesmo_pokemon(t->pokemon[i], nome))
        {
            return t->pokemon[i];
        }
    }
    return NULL;
}

void libera_todos_pokemons(tTreinador t)
{
    for(int i = 0 ; i < t->n_pokemons; i++)
    {
        printf("%s liberado!\n", obtem_nome_pokemon(t->pokemon[i]));
        libera_pokemon(t->pokemon[i]);
    }
    if (t)
    {
        if (t->nome) free(t->nome);
        if (t->pokemon) free(t->pokemon);
        t->nome = NULL;
        t->pokemon = NULL;
        free(t);
    }
}