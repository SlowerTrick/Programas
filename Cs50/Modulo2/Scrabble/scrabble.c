#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Pontos equivalentes a cada letra do alfabeto
const int PONTOS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int pontos[2] = {0, 0};

int compute_score(string palavra);

int main(void)
{
    // Solicitação dos valores
    string palavra1 = get_string("Player 1: ");
    string palavra2 = get_string("Player 2: ");

    // Da os pontos de cada jogador
    pontos[0] = compute_score(palavra1);
    pontos[1] = compute_score(palavra2);
    printf("Player 1: %i Pontos\n", pontos[0]);
    printf("Player 2: %i Pontos\n", pontos[1]);

    if (pontos[0] > pontos[1])
    {
        printf ("Player 1 Ganhou!\n");
    }
    else if (pontos[0] < pontos[1])
    {
        printf ("Player 2 Ganhou!\n");
    }
    else
    printf ("Resultado: Empate!\n");
}

//string palavra é só um nome generico, qualquer outro poderia ter sido utilizado. A string desejada citada por exemplo em
//"compute_score(palavra1);" na função main que é a string que é jogada nessa outra função compute_score

int compute_score(string palavra)
{
    int resultado = 0;

    for (int i = 0; palavra[i] != '\0'; i++)
    {
        if (isalpha(palavra[i]))
        {
            palavra[i] = toupper(palavra[i]);
            palavra[i] = palavra[i] - 'A';
            int calculo = palavra[i];
            resultado = resultado + PONTOS[calculo];
        }
    }
    return (resultado);
}
