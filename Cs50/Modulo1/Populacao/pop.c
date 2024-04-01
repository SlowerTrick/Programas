#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
     long inicial = 0;
     long final = 0;
     long anos = 0;
     long calculo1 = 0;
     long calculo2 = 0;


     do
     {
          inicial = get_long ("População Inicial (Maior que 9):");
     }
     while (inicial < 9);

     do
     {
          final = get_long ("População Inicial (Maior ou igual a inicial):");
     }
     while (final < inicial);

     do
     {
          if (inicial < final)
          {
          calculo1 = inicial;
          calculo2 = inicial;
          calculo1 = calculo1 / 3;
          calculo1 = round (calculo1);
          calculo2 = calculo2 / 4;
          calculo2 = round (calculo2);
          inicial = inicial + (calculo1 - calculo2);
          anos++;
          printf ("Polução após ");
          printf ("%li", anos);
          printf (" ano(s): " );
          printf ("%li\n", inicial);
          }
     }
     while (inicial < final);

     printf ("Número de anos: ");
     printf ("%li\n", anos);
}

