#include <cs50.h>
#include <stdio.h>

int main (void)
{
    long numero = 0;
    long calculo1 = 0;
    long calculo2 = 0;
    long calculo3 = 0;
    long calculo4 = 0;
    long calculo5 = 0;
    long calculo6 = 0;
    long calculo7 = 0;
    long calculo8 = 0;
    long calculo9 = 0;
    long calculo10 = 0;
    long calculo11 = 0;
    long calculo12 = 0;
    long calculo13 = 0;
    long calculo14 = 0;
    long calculo15 = 0;
    long calculo16 = 0;

    do
    {
     numero = get_long ("Número do cartão: ");

    }
    while (numero < 0);

    if (numero > 1000000000000) //16 digitos
    {
       long numero1 = numero % 100 - numero % 10;
       numero1 = numero1 / 10;
       calculo1 = numero1 * 2;

       long numero2 = numero % 10000 - numero % 1000;
       numero2 = numero2 / 1000;
       calculo2 = numero2 * 2;

       long numero3 = numero % 1000000 - numero % 100000;
       numero3 = numero3 / 100000;
       calculo3 = numero3 * 2;

       long numero4 = numero % 100000000 - numero % 10000000;
       numero4 = numero4 / 10000000;
       calculo4 = numero4 * 2;

       long numero5 = numero % 10000000000 - numero % 1000000000;
       numero5 = numero5 / 1000000000;
       calculo5 = numero5 * 2;

       long numero6 = numero % 1000000000000 - numero % 100000000000;
       numero6 = numero6 / 100000000000;
       calculo6 = numero6 * 2;

       long numero7 = numero % 100000000000000 - numero % 10000000000000;
       numero7 = numero7 / 10000000000000;
       calculo7 = numero7 * 2;

       long numero8 = numero % 10000000000000000 - numero % 1000000000000000;
       numero8 = numero8 / 1000000000000000;
       calculo8 = numero8 * 2;

       long numero9 = numero % 10;
       calculo9 = numero9;

       long numero10 = numero % 1000 - numero % 100;
       numero10 = numero10 / 100;
       calculo10 = numero10;

       long numero11 = numero % 100000 - numero % 10000;
       numero11 = numero11 / 10000;
       calculo11 = numero11;

       long numero12 = numero % 10000000 - numero % 1000000;
       numero12 = numero12 / 1000000;
       calculo12 = numero12;

       long numero13 = numero % 1000000000 - numero % 100000000;
       numero13 = numero13 / 100000000;
       calculo13 = numero13;

       long numero14 = numero % 100000000000 - numero % 10000000000;
       numero14 = numero14 / 10000000000;
       calculo14 = numero14;

       long numero15 = numero % 10000000000000 - numero % 1000000000000;
       numero15 = numero15 / 1000000000000;
       calculo15 = numero15;

       long numero16 = numero % 1000000000000000 - numero % 100000000000000;
       numero16 = numero16 / 100000000000000;
       calculo16 = numero16;

       if (calculo1 >= 10)
       {
       long num1 = calculo1 - (calculo1 - 1);
       calculo1 = (calculo1 - 10) + num1;
       }

       if (calculo2 >= 10)
       {
       long num2 = calculo2 - (calculo2 - 1);
       calculo2 = (calculo2 - 10) + num2;
       }

       if (calculo3 >= 10)
       {
       long num3 = calculo3 - (calculo3 - 1);
       calculo3 = (calculo3 - 10) + num3;
       }

       if (calculo4 >= 10)
       {
       long num4 = calculo4 - (calculo4 - 1);
       calculo4 = (calculo4 - 10) + num4;
       }

       if (calculo5 >= 10)
       {
       long num5 = calculo5 - (calculo5 - 1);
       calculo5 = (calculo5 - 10) + num5;
       }

       if (calculo6 >= 10)
       {
       long num6 = calculo6 - (calculo6 - 1);
       calculo6 = (calculo6 - 10) + num6;
       }

       if (calculo7 >= 10)
       {
       long num7 = calculo7 - (calculo7 - 1);
       calculo7 = (calculo7 - 10) + num7;
       }

       if (calculo8 >= 10)
       {
       long num8 = calculo8 - (calculo8 - 1);
       calculo8 = (calculo8 - 10) + num8;
       }
    }

    if ((calculo1 + calculo2 + calculo3 + calculo4 + calculo5+ calculo6 + calculo7 + calculo8 + calculo9 + calculo10 + calculo11 + calculo12 + calculo13+ calculo14 + calculo15 + calculo16  == 20))

    {
        printf ("Cartão Válido!\n");

        if (numero > 5099999999999999)
        printf ("Cartão: Mastercard\n");

        if (numero > 339999999999999 && numero < 509999999999999)
        printf ("Cartão: American Express\n");

        if (numero > 3999999999999 && numero < 5099999999999)
        printf ("Cartão: Visa\n");

        if (numero > 3999999999999999 && numero < 4999999999999999)
        printf ("Cartão: Visa\n");
    }

    else

    printf ("Cartão Invalido\n");
}
