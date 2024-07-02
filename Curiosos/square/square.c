#include <stdio.h>

void AlteraArray(int matriz[100][100], int altura, int largura, int apotema);

int main(void) 
{
    FILE *arquivo = fopen("square.txt", "r");
    if (!arquivo) 
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    int apotema = 0;
    fscanf(arquivo, "%d", &apotema);
    int altura = 0, largura = 0;
    fscanf(arquivo, "%d %d", &altura, &largura);
    int matriz[100][100];  // Definindo um tamanho fixo para evitar erros

    for (int i = 0; i < altura; i++) 
    {
        for (int j = 0; j < largura; j++) 
        {
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }

    fclose(arquivo);

    // Imprimindo a matriz após a leitura
    printf("Matriz lida do arquivo:\n");
    for (int i = 0; i < altura; i++) 
    {
        for (int j = 0; j < largura; j++) 
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    AlteraArray(matriz, altura, largura, apotema);

    printf("Matriz apos AlteraArray:\n");
    for (int i = 0; i < altura; i++) 
    {
        for (int j = 0; j < largura; j++) 
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void AlteraArray(int matriz[100][100], int altura, int largura, int apotema) 
{
    for (int i = 0; i < altura; i++) 
    {
        for (int j = 0; j < largura; j++) 
        {
            if (matriz[i][j] == 1) 
            {
                // Calculando os limites da área a ser modificada
                int minPosX = j - apotema;
                if (minPosX < 0) 
                {
                    minPosX = 0;
                }

                int minPosY = i - apotema;
                if (minPosY < 0) 
                {
                    minPosY = 0;
                }

                int maxPosX = j + apotema;
                if (maxPosX >= largura) 
                {
                    maxPosX = largura - 1;
                }

                int maxPosY = i + apotema;
                if (maxPosY >= altura) 
                {
                    maxPosY = altura - 1;
                }

                // Alterando os valores na área determinada pelo apotema
                for (int y = minPosY; y <= maxPosY; y++) 
                {
                    for (int x = minPosX; x <= maxPosX; x++) 
                    {
                        matriz[y][x] = 2;
                    }
                }
                // Mantendo o valor original como 1
                matriz[i][j] = 1;
            }
        }
    }
}
