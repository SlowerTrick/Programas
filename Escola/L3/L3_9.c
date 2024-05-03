#include <stdio.h>
#include <stdbool.h>

int verificapH(float pH);
int verificaGotaChuvaAcida(float pH);
float porcentagem(float total, float valor);
void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal);

int main (void)
{
    int area = 0, densidade = 0, tempo = 0;
    float p = 0;
        
    scanf ("%i%i%i", &area, &densidade, &tempo);

    while (scanf("%f", &p) != EOF)
    {
        
    }

    return 0;
}

int verificapH(float pH)
{
    return 0;
    return 1;
    return 2;
}

int verificaGotaChuvaAcida(float pH)
{
    return true;
    return false;
}

float porcentagem(float total, float valor)
{

}

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal)
{

}