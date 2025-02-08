#pragma once

#include "pokemon.h"

typedef struct trainer *tTreinador;

tTreinador cria_treinador(char *nome);
void imprime_pokemons_treinador(tTreinador t);
void imprime_um_pokemon_treinador(tTreinador t, char *nome);
void adiciona_pokemon_time(tTreinador t, char *nome, char *tipo1, char *tipo2, int level);
void remove_pokemon_time(tTreinador t, char *nome);
int obtem_numero_pokemons(tTreinador t);
tPokemon obtem_pokemon(tTreinador t, char *nome);
void libera_todos_pokemons(tTreinador t);