#include "treinador.h"
#include "suporte.h"

int main(void)
{
    imprime_menu_inicial();
    char nome_treinador[NOME_MAX];
    scanf("%100[^\n]%*c", nome_treinador);
    imprime_boas_vindas(nome_treinador);

    tTreinador treinador = cria_treinador(nome_treinador);

    while(1)
    {
        int flag_fim_programa = 0;
        imprime_menu_principal();
        char opcao;
        scanf(" %c%*c", &opcao);
        opcao = toupper(opcao);

        switch (opcao)
        {
            case 'A':
                char nome[NOME_MAX], tipo1[TIPO_MAX], tipo2[TIPO_MAX];
                int level;

                le_pokemon_adicionar(nome, tipo1, tipo2, &level);

                adiciona_pokemon_time(treinador, nome, tipo1, tipo2, level);
                break;

            case 'R':
                char nome_pokemon_remover[NOME_MAX];

                le_nome_pokemon(nome_pokemon_remover);
                remove_pokemon_time(treinador, nome_pokemon_remover);

                break;

            case 'T':
                imprime_pokemons_treinador(treinador);
                break;

            case 'P':
                char nome_pokemon[NOME_MAX];

                le_nome_pokemon(nome_pokemon);
                imprime_um_pokemon_treinador(treinador, nome_pokemon);

                break;

            case 'E':
                libera_todos_pokemons(treinador);
                flag_fim_programa = 1;
                break;
            
            default:
                printf("Acao invalida, escolha uma das opcoes validas!\n");
                break;
        }
        if (flag_fim_programa)
            break;
    }

    return 0;
}