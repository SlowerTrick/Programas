#include <stdio.h>

int somar (int x);

int main (void)
{

    int numero;
    do
    {
        char verificador;
        printf("Numero desejado: ");
        while(scanf("%d%c", &numero, &verificador) != 2 || verificador != '\n' || numero <= 0) //Checa termo e verificador
        {
            printf("Entrada inválida. Por favor, insira um número inteiro.\nNumero desejado: ");
            while(getchar() != '\n'); // Limpa o buffer de entrada
        }
    }
    while(numero < 0);

    printf ("Resultado: %i\n", somar(numero));
}

int somar (int x)
{
    if (x == 0)
    {
        return x;
    }
    else
    return x + somar(x-1);
}
