#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
    char desenho[3][4];
} 
tParteInimigo;

typedef struct 
{
    int bonus;
    tParteInimigo partes[3];
} 
tInimigo;

typedef struct
{
    int posX;
    int posY;
}
tPosicao;

typedef struct 
{
    char mapa[40][100];
    int altura;
    int largura;
    tPosicao jogador;
    tInimigo desenhoInimigo;
    tPosicao inimigoLinha1[35]; // Eh impossivel a quantidade de inimigos ser maior do que 35, considerando um mapa de
    tPosicao inimigoLinha2[35]; // no maximo 100 de largura.
    tPosicao inimigoLinha3[35]; // 
}
tMapa;

FILE *InicializaFile(char *diretorio);
tMapa InicializaMapa(char *diretorio);
tInimigo InicializaInimigo(FILE *arquivo);
void InicializaPosicoesInimigos(FILE *arquivo, tPosicao posicao[]);

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        printf ("ERRO: Informe o diretorio com os arquivos de configuracao.");
        return 1;
    }
    tMapa mapa;
    mapa = InicializaMapa(argv[1]);
    /*
        TODO: Implementar o topico animação Bonus do inimigo
    */

    return 0;
}

FILE *InicializaFile(char *diretorio)
{
    FILE *arquivo = NULL;

    arquivo = fopen(diretorio, "r");
    if (!arquivo)
    {
        printf ("Nao foi possivel abrir o arquivo %s", diretorio);
        return arquivo;
    }
    return arquivo;
}

tMapa InicializaMapa(char *diretorio)
{
    char localMapa[1000];
    char localInimigo[1000];
    sprintf(localMapa, "%s/mapa.txt", diretorio);
    sprintf(localInimigo, "%s/inimigo.txt", diretorio);

    FILE *arquivoMapa = InicializaFile(localMapa);
    if (!arquivoMapa)
    {
        exit(1);
    }
    FILE *arquivoInimigo = InicializaFile(localInimigo);
    if (!arquivoInimigo)
    {
        fclose(arquivoMapa);
        exit(1);
    }

    tMapa mapa;
    fscanf (arquivoMapa, "%d %d\n", &mapa.largura, &mapa.altura);
    fscanf (arquivoMapa, "(%d %d)", &mapa.jogador.posX, &mapa.jogador.posX);
    /*
        TODO:
        As três linhas seguintes detalham as fileiras de inimigos, onde cada inimigo é descrito pelo 
        par de coordenadas (coluna linha), seguindo o mesmo formato usado para o jogador. 
        Observa-se que há apenas duas linhas com posições de inimigos, enquanto a terceira está 
        vazia, indicando que não é obrigatório haver inimigos em todas as fileiras. Cada linha, 
        apresentará os inimigos pertencentes àquela fileira e não haverá sobreposição entre os 
        inimigos. As coordenadas dos arquivos consideram a posição (1 1) como o canto superior 
        esquerdo do mapa
    */

    mapa.desenhoInimigo = InicializaInimigo(arquivoInimigo);
    /*
    for (int p = 0; p < 3; p++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%c", mapa.desenhoInimigo.partes[p].desenho[i][j]);
            }
            printf ("\n");
        }
    }
    */
    InicializaPosicoesInimigos(arquivoMapa, mapa.inimigoLinha1);
    InicializaPosicoesInimigos(arquivoMapa, mapa.inimigoLinha2);
    InicializaPosicoesInimigos(arquivoMapa, mapa.inimigoLinha3);

    fclose(arquivoMapa);
    fclose(arquivoInimigo);
    return mapa;
}

tInimigo InicializaInimigo(FILE *arquivo)
{
    tInimigo inimigo;
    char temp;
    fscanf(arquivo, "%d\n", &inimigo.bonus);
    for (int p = 0; p < 3; p++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                fscanf(arquivo, "%c", &inimigo.partes[p].desenho[i][j]);
            }
            fscanf(arquivo, "%c", &temp); // Consumir o '\n'
        }
    }
    return inimigo;
}

void InicializaPosicoesInimigos(FILE *arquivo, tPosicao posicao[])
{

}