#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    int inicial = strlen(argv[1]);
    string cripto = argv[1];

    char letras [26];
    letras [0] = 'A';
    for (int i = 1; i < 26; i++)
    {
        letras[i] = 'A' + i;
    }
//Verifica se o código tem 16 linhas
    if (argc != 2 || inicial != 26)
    {
        printf ("Uso correto: ./subs chave(26 digitos)\n");
        return (1);
    }
//Verifica se existem letras iguais, pois j vai passar por todas as oportunidades menos a atual e checar se há alguma igual
    for (int i = 0; cripto[i] != '\0'; i++)
    {
        for (int j = 0; j < i; j++) //Passa por todas as letras anteriores a "i" para verificar se há uma repetição
        {
            if (cripto[i] == cripto[j])
            {
                printf ("Falha: Chave com elementos iguais\n");
                return (1);
            }
        }
    }
//Verifica se o código só possui letras
    for (int i = 0; cripto[i] != '\0'; i++)
    {
        if (cripto[i] < 'A' || (cripto[i] > 'Z' && cripto[i] < 'a') || cripto[i] > 'z')
        {
            printf ("Falha: Somente letras são aceitas na chave\n");
            return (1);
        }
    }
//Caso todas as condições tenham sido satisfeitas
    if (argc == 2)
    {
    string palavra = get_string ("Texto: ");
    printf ("Texto cifrado: ");
//Printa as respectivas letras cifradas
        for (int i = 0; palavra[i] != '\0'; i++)
        {

            if (isalpha(palavra[i])) //Verifica se é uma letra do alfabeto
            {
                for (int j = 0; j < 26; j++) //Passa por todas as letras e compara o alfabeto normal com o da criptografia
                {
                    if ((toupper(palavra[i])) == (toupper(letras[j])))
                    {
                        if (isupper(palavra[i])) //Verifica se a letra da mensagem a ser criptografada é maiuscula
                        {
                        cripto[j] = toupper(cripto[j]);
                        printf("%c", cripto[j]);
                        }
                        if (islower(palavra[i])) //Verifica se a letra da mensagem a ser criptografada é minuscula
                        {
                        cripto[j] = tolower(cripto[j]);
                        printf("%c", cripto[j]);
                        }
                    }
                }
            }
            else //Printa caracteres não letras
            {
            printf("%c", palavra[i]);
            }
        }
    printf ("\n");
    return (0);
    }
}
