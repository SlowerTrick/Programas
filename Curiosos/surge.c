#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define altura 3
#define largura 5 
#define correto 1
#define incorreto 0

typedef struct
{
    int x;
    int y;
}
tCoordenadas;

bool EncerrarPrograma(tCoordenadas cord);
bool VerificaResultado(int matriz[altura][largura]);
void PrintaMatriz(int matriz[altura][largura]);
void LimpaMatriz(int matriz[altura][largura]);
void SorteiaMatriz(int matriz[altura][largura]);
int LerNumero();
tCoordenadas ArmazenaCoordenadas();
bool VerificaCoordenadas(tCoordenadas cord);

int main(void)
{
    srand(time(NULL));
    while (1)
    {
        int matriz[altura][largura] = {incorreto};
        printf ("Escolha um valor da matriz no formato: (y, x)\nOBS:\nNao eh necessario utilizar virgula e parenteses\nA matriz vai de (1, 1) ate (3, 5)\nSelecione (-1, -1) para encerrar o programa\n\n");
        printf ("Matiz inicial:\n");
        PrintaMatriz(matriz);
        while (1)
        {
            SorteiaMatriz(matriz);
            if (VerificaResultado(matriz))
            {
                printf ("Parabens! voce ganhou!");
                return 0;
            }
            LimpaMatriz(matriz);
        }
    }
    return 0;
}

bool VerificaResultado(int matriz[altura][largura])
{
    tCoordenadas cord = ArmazenaCoordenadas();
    if (matriz[cord.y][cord.x] == 1)
    {
        int matrizatual[altura][largura] = {incorreto};
        matrizatual[cord.y][cord.x] = 1;
        printf ("\nAcertou!\n\nMatriz atual:\n");
        PrintaMatriz(matrizatual);

        printf ("O proximo ponto esta adjacente ah (%d, %d)\n", cord.y+1, cord.x+1);
        tCoordenadas cord = ArmazenaCoordenadas();
        if (matriz[cord.y][cord.x] == 1)
        {
            return true;
        }
    }
    printf ("\nERROU!\n");
    printf ("Posicoes Corretas:\n");
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            if (matriz[i][j] == 1)
            {
                printf ("y: %d, x: %d\n", i+1, j+1);
            }
        }
    }
    return false;
}

void SorteiaMatriz(int matriz[altura][largura])
{
    tCoordenadas posicao1, posicao2;
    posicao1.y = rand() % altura;
    posicao1.x = rand() % largura;
    matriz[posicao1.y][posicao1.x] = correto;
    while (1)
    {
        posicao2.y = rand() % altura;
        posicao2.x = rand() % largura;

        if ((posicao2.y >= posicao1.y - 1 && posicao2.y <= posicao1.y + 1) && 
        (posicao2.x >= posicao1.x - 1 && posicao2.x <= posicao1.x + 1) && 
        !(posicao1.x == posicao2.x && posicao1.y == posicao2.y))
        {
            matriz[posicao2.y][posicao2.x] = correto;
            break;
        }
    }
    //printf ("%d %d\n", posicao1.y+1, posicao1.x+1);
    //printf ("%d %d\n", posicao2.y+1, posicao2.x+1);
    return;
}

void LimpaMatriz(int matriz[altura][largura])
{
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            matriz[i][j] = 0;
        } 
    }
    return;
}

int LerNumero() {
    char entrada[100];
    int numero;
    int valido;

    while (1) 
    {
        valido = true;
        scanf("%s", entrada);

        for (int i = 0; entrada[i] != '\0'; i++) {
            if (!isdigit(entrada[i]) && entrada[i] != '-') {
                valido = false;
                break;
            }
        }

        if (valido) 
        {
            numero = atoi(entrada);
            return numero;
        } 
        else 
        {
            printf("Entrada invalida! Insira um numero: ");
        }
    }
}

tCoordenadas ArmazenaCoordenadas() {
    tCoordenadas cord;

    while (1) {
        printf("\ny: ");
        cord.y = LerNumero();

        printf("x: ");
        cord.x = LerNumero();

        if ((!EncerrarPrograma(cord) && (cord.x == -1 || cord.y == -1)) || VerificaCoordenadas(cord)) {
            printf("Coordenadas invalidas! Escolha novamente:\n");
            continue;
        }

        cord.x -= 1;
        cord.y -= 1;
        break;
    }

    return cord;
}

bool VerificaCoordenadas(tCoordenadas cord)
{
    if ((cord.x < -1 || cord.x > largura) || (cord.y < -1 || cord.y > altura))
    {
        return true;
    }
    return false;
}

bool EncerrarPrograma(tCoordenadas cord)
{
    if (cord.x == -1 && cord.y == -1)
    {
        printf ("Bye Bye!");
        exit(0);
    }
    return false;
}

void PrintaMatriz(int matriz[altura][largura])
{
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            printf ("%d", matriz[i][j]);
        }
        printf ("\n");
    }
}