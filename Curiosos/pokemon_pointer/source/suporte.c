#include "suporte.h"

void imprime_menu_inicial()
{
    printf("Seja bem-vindo a sua jornada Pokemon\n");
    printf("Escolha o nome do seu Treinador: ");
}

void imprime_boas_vindas(char *nome)
{
    printf("\nOla %s!\n", nome);
}

void imprime_menu_principal()
{
    printf("\nEscolha uma acao:\n");
    printf("'A': Adicionar Pokemon ao time\n");
    printf("'R': Remover pokemon do time\n");
    printf("'T': Mostrar todos os pokemons do time\n");
    printf("'P': Mostrar um pokemon do time\n");
    printf("'E': Sair do programa\n");
}

void le_pokemon_adicionar(char *nome, char *tipo1, char *tipo2, int *level)
{
    le_nome_pokemon(nome);
    printf("Tipo1: ");
    scanf(" %s", tipo1);
    printf("Tipo2: ");
    scanf(" %s", tipo2);
    printf("Level: ");
    scanf("%d", level);
}

void le_nome_pokemon(char *nome_pokemon_remover)
{
    printf("Nome do pokemon: ");
    scanf(" %s*c", nome_pokemon_remover);
}

