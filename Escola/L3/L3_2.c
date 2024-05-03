#include <stdio.h>

float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);

int main()
{
    float num1 = 0, num2 = 0, num3 = 0, infinito = 0;
    char operacao = 0;
    float result = 0;
 
    scanf ("%f %f %c", &num1, &num2, &operacao);    

    while (infinito == 0)
    {
        if (operacao == '+')
        {
            result = Soma(num1, num2);
        }
        else if (operacao == '-')
        {
            result = Subtracao(num1, num2);
        }
        else if (operacao == '/')
        {
            result = Divisao(num1, num2);
        }
        else if (operacao == '*')
        {
            result = Multiplicacao(num1, num2);
        }

        fgets()

        printf ("%.2f", result);
        break;
    }

    return 0; 
}

float Soma(float num1, float num2)
{
    float soma = 0;
    soma = num1 + num2;

    return soma;
}

float Subtracao(float num1, float num2)
{
    float subtracao = 0;
    subtracao = num1 - num2;

    return subtracao;
}

float Divisao(float num1, float num2)
{
    float divisao = 0;
    divisao = num1 / num2;

    return divisao;
}

float Multiplicacao(float num1, float num2)
{
    float multiplicacao = 0;
    multiplicacao = num1 * num2;

    return multiplicacao;
}