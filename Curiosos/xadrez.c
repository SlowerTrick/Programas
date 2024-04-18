#include <stdio.h>

const int altura = 9;
const int largura = 9;

void menu(int *x, int *y, char *c);

int main (void)
{
    int x = 0;
    int y = 0;
    int infinito = 0;
    char c = '0';
    char tabuleiro[altura][largura];

    while (infinito == 0)
    {
        printf ("\n");

        for (int i = 0; i < altura; i++)
        {
            for (int j = 0; j < largura; j++)
            {
                tabuleiro[i][j] = '-';
            }
        }

        menu(&x, &y, &c);

        if (c == 'Q' || c == 'q')
        {
            infinito++;
        }
        else
        {
            if (c == 'R' || c == 'r')
            {
                tabuleiro[x][y] = 'R';
                tabuleiro[x+1][y+1] = 'X';
                tabuleiro[x-1][y-1] = 'X';
                tabuleiro[x+1][y-1] = 'X';
                tabuleiro[x-1][y+1] = 'X';
                tabuleiro[x][y+1] = 'X';
                tabuleiro[x][y-1] = 'X';
                tabuleiro[x+1][y] = 'X';
                tabuleiro[x-1][y] = 'X';
            }
            if (c == 'D' || c == 'd')
            {
                for (int i = 0; i < altura; i++)
                {
                    tabuleiro[x][i] = 'X';
                    tabuleiro[i][y] = 'X';
                }

                for (int i = 0; i < altura; i++)
                {
                    if (x+i <= 9 && y+i <= 9)
                    {
                        tabuleiro[x+i][y+i] = 'X';
                    } 
                    if (x-i >= 0 && y-i >= 0)
                    {
                        tabuleiro[x-i][y-i] = 'X'; 
                    }
                    if (x-i >= 0 && y+i <= 9)
                    {
                        tabuleiro[x-i][y+i] = 'X';
                    } 
                    if (x+i <= 9 && y-i >= 0)
                    {
                        tabuleiro[x+i][y-i] = 'X';
                    } 
                }
                tabuleiro[x][y] = 'D';
            }

            if (c == 'T' || c == 't')
            {
                for (int i = 0; i < altura; i++)
                {
                    tabuleiro[x][i] = 'X';
                    tabuleiro[i][y] = 'X';
                }
                tabuleiro[x][y] = 'T';
            }

            if (c == 'B' || c == 'b')
            {
                for (int i = 0; i < altura; i++)
                {
                    if (x+i <= 9 && y+i <= 9)
                    {
                        tabuleiro[x+i][y+i] = 'X';
                    } 
                    if (x-i >= 0 && y-i >= 0)
                    {
                        tabuleiro[x-i][y-i] = 'X'; 
                    }
                    if (x-i >= 0 && y+i <= 9)
                    {
                        tabuleiro[x-i][y+i] = 'X';
                    } 
                    if (x+i <= 9 && y-i >= 0)
                    {
                        tabuleiro[x+i][y-i] = 'X';
                    } 
                }
                tabuleiro[x][y] = 'B';
            }
            if (c == 'C' || c == 'c')
            {
                if (x - 2 >= 0 && y - 1 >= 0)
                {
                    tabuleiro[x-2][y-1] = 'X';
                }

                if (x - 1 >= 0 && y - 2 >= 0)
                {
                    tabuleiro[x-1][y-2] = 'X';
                }

                if (x + 1 <= 9 && y - 2 >= 0)
                {
                    tabuleiro[x+1][y-2] = 'X';  
                }

                if (x + 2 <= 9 && y - 1 >= 0)
                {
                    tabuleiro[x+2][y-1] = 'X';
                }

                if (x - 2 >= 0 && y + 1 <= 9)
                {
                    tabuleiro[x-2][y+1] = 'X';
                }

                if (x - 1 >= 0 && y + 2 <= 9)
                {
                    tabuleiro[x-1][y+2] = 'X';
                }

                if (x + 1 <= 9 && y + 2 <= 9)
                {
                    tabuleiro[x+1][y+2] = 'X';
                }

                if (x + 2 <= 9 && y + 1 <= 9)
                {
                    tabuleiro[x+2][y+1] = 'X';
                }
                tabuleiro[x][y] = 'C';

            }

            printf ("\n");
            for (int i = 1; i < altura; i++)
            {
                for (int j = 1; j < largura; j++)
                {
                    printf ("%c ", tabuleiro[i][j]);
                }
                printf ("\n");
            }
        }
        int buffer;
        while ((buffer = getchar()) != '\n' && buffer != EOF);
    }
    return 0;
}

void menu (int *x, int *y, char *c)
{
    int valorvalido = 0;
    printf ("Menu:\n");
    printf ("R - Rei\n"); 
    printf ("D - Dama\n");
    printf ("T - Torre\n");
    printf ("B - Bispo\n");
    printf ("C - Cavalo\n");
    printf ("Q - Sair\n");
    printf ("Escolha uma opcao: \n");
    scanf ("%c", c);
    if (*c == 'Q' || *c == 'q')
    {
        return;
    }
    while (valorvalido == 0)
    {
        if (*c == 'T' || *c == 'R'|| *c == 'B' || *c == 'C' || *c == 't' || *c == 'r'|| *c == 'b' || *c == 'c' || *c == 'D' || *c == 'd')
        {
            valorvalido = 1;
        }
        else
        {
            int buffer;
            while ((buffer = getchar()) != '\n' && buffer != EOF);
            printf ("Opcao invalida! Escolha novamente.\n\n");
            printf ("Menu:\n");
            printf ("R - Rei\n"); 
            printf ("D - Dama\n");
            printf ("T - Torre\n");
            printf ("B - Bispo\n");
            printf ("C - Cavalo\n");
            printf ("Q - Sair\n");
            printf ("Escolha uma opcao: \n");
            scanf ("%c", c);
            if (*c == 'Q')
            {
                return;
            }
        }
    }
    valorvalido = 0;
    while (valorvalido == 0)
    {
        int buffer;
        while ((buffer = getchar()) != '\n' && buffer != EOF);
        printf ("Indique a coordenada (X, Y) [sem virgula]:\n");
        scanf ("%i%i", x, y);
        if ((*x > 0 && *x < 9) && (*y > 0 && *y < 9))
        {
            return;
        }
        else
        {
            printf ("Opcao invalida!\n");
            printf ("Intervalo permitido: [1, 8]\n");
            printf ("Escolha novamente.\n\n");
        }
    }
}