#include <stdio.h>

int QtdDebitoPlaca(int presc);
int MaiorDebitoCidade();

int main(void) 
{
    int cidade = 0, i = 0, somatorio = 0;

    while (scanf("%d", &cidade) != EOF)
    {
        somatorio += MaiorDebitoCidade();
    }
    printf("SOMA:%i\n", somatorio);
    return 0;
}

int QtdDebitoPlaca(int presc) 
{
    int debito = 0, tempo = 0, somatorio = 0;
    char c = 0;

    scanf ("%c", &c);
    if (c == '(')
    {
        while (scanf("%i:%i)", &debito, &tempo) == 2) 
        {
            if (tempo <= presc) 
            {
                somatorio += debito;
            }
            scanf ("%c", &c);
            if (c == '\n' || c == EOF) 
            {
                break;
            }
            scanf ("%c", &c);
        }
    }
    return somatorio;
}

int MaiorDebitoCidade() 
{
    int presc = 0, debito = 0, maiordebito = 0;
    char letra1 = 0, letra2 = 0, letra3 = 0;
    char maiorletra1 = 0, maiorletra2 = 0, maiorletra3 = 0;

    scanf("%i", &presc);
    getchar();

    while (1) 
    {
        if (scanf("%c%c%c", &letra1, &letra2, &letra3) != 3) 
        { 
            break;
        }
        if (letra1 == 'F' && letra2 == 'I' && letra3 == 'M') 
        {
            break;
        }
        debito = QtdDebitoPlaca(presc);
        printf ("%i", debito);

        if (maiordebito < debito) 
        {
            maiordebito = debito;
            maiorletra1 = letra1;
            maiorletra2 = letra2;
            maiorletra3 = letra3;
        }
    }

    if (maiordebito > 0) 
    {
        printf("PLACA:%c%c%c DEBITO:%i\n", maiorletra1, maiorletra2, maiorletra3, maiordebito);
    } 
    else 
    {
        printf("SEM DEBITO!\n");
        return 0;
    }
    return maiordebito;
}

