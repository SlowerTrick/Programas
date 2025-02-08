#ifndef POKEMON_H
#define POKEMON_H
#define NOME_MAX 100
#define TIPO_MAX 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct poke *tPokemon;

// Como tPokemon já é um ponteiro para a estrutura "struct poke"
// As funções podem so retornar um tPokemon, afinal ele já é um ponteiro e
// isso manterá o tipo opaco

void le_pokemon();
tPokemon captura_pokemon(char *nome, char *tipo1, char *tipo2, int level);
void imprime_pokemon(tPokemon p);
void subir_level_pokemon(tPokemon p);
char *obtem_tipo1_pokemon(tPokemon p);
char *obtem_tipo2_pokemon(tPokemon p);
char *obtem_nome_pokemon(tPokemon p);
int obtem_level_pokemon(tPokemon p);
int eh_mesmo_pokemon(tPokemon p, char *nome);
void libera_pokemon(tPokemon p);


#endif