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
    int totalInimigosLinha1;
    int totalInimigosLinha2;
    int totalInimigosLinha3;
}
tMapa;

FILE *InicializaFile(char *diretorio, int modo);
tMapa InicializaMapa(char *diretorio);
tInimigo InicializaInimigo(FILE *arquivo);
int InicializaPosicoesInimigos(FILE *arquivo, tPosicao posicao[]);
tMapa PreencheMapa(tMapa mapa);
void PrintaBordaMapaHorizontal(FILE *arquivo, int largura);
void PrintaMapa(FILE *arquivo, tMapa mapa);

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

tMapa InicializaMapa(char *diretorio)
{
    char localMapa[1000];
    char localInimigo[1000];
    sprintf(localMapa, "%s/mapa.txt", diretorio);
    sprintf(localInimigo, "%s/inimigo.txt", diretorio);

    FILE *arquivoMapa = InicializaFile(localMapa, 1);
    if (!arquivoMapa)
    {
        exit(1);
    }
    FILE *arquivoInimigo = InicializaFile(localInimigo, 1);
    if (!arquivoInimigo)
    {
        fclose(arquivoMapa);
        exit(1);
    }

    tMapa mapa;
    fscanf (arquivoMapa, "%d %d\n", &mapa.largura, &mapa.altura);
    fscanf (arquivoMapa, "(%d %d)", &mapa.jogador.posX, &mapa.jogador.posY);
    fgetc(arquivoMapa);

    mapa.desenhoInimigo = InicializaInimigo(arquivoInimigo);
    mapa.totalInimigosLinha1 = InicializaPosicoesInimigos(arquivoMapa, mapa.inimigoLinha1);
    mapa.totalInimigosLinha2 = InicializaPosicoesInimigos(arquivoMapa, mapa.inimigoLinha2);
    mapa.totalInimigosLinha3 = InicializaPosicoesInimigos(arquivoMapa, mapa.inimigoLinha3);

    char arquivoSaidaInicializacao[50];
    sprintf(arquivoSaidaInicializacao, "saida/inicializacao.txt");
    FILE *saidaInicializacao = InicializaFile(arquivoSaidaInicializacao, 2);
    if (!saidaInicializacao)
    {
        fclose(arquivoMapa);
        fclose(arquivoInimigo);
        exit(1);
    }

    //mapa = PreencheMapa(mapa);
    //PrintaBordaMapaHorizontal(saidaInicializacao, mapa.largura);
    //PrintaMapa(saidaInicializacao, mapa);
    //PrintaBordaMapaHorizontal(saidaInicializacao, mapa.largura);

    fclose(arquivoMapa);
    fclose(arquivoInimigo);
    fclose(saidaInicializacao);
    return mapa;
}

tMapa PreencheMapa(tMapa mapa) 
{
    
}

FILE *InicializaFile(char *diretorio, int modo)
{
    FILE *arquivo = NULL;

    if (modo == 1)
    {
        arquivo = fopen(diretorio, "r");
        if (!arquivo)
        {
            printf ("Nao foi possivel abrir o arquivo %s", diretorio);
            return arquivo;
        }
        return arquivo;
    }
    if (modo == 2)
    {
        arquivo = fopen(diretorio, "w");
        if (!arquivo)
        {
            printf ("Nao foi possivel abrir o arquivo %s", diretorio);
            return arquivo;
        }
        return arquivo;
    }
    return arquivo;
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

int InicializaPosicoesInimigos(FILE *arquivo, tPosicao posicao[])
{
    int i = 0;
    
    char temp = fgetc(arquivo);
    if (temp == '\n')
        return i;
    ungetc(temp, arquivo); // Devolve o caractere para o arquivo se a linha não estiver vazia

    char linha[500]; //Segundo a logica do programa, a linha nao tera mais de 500 caracteres
    fgets(linha, sizeof(linha), arquivo);

    if (linha[i] == '\n' || feof(arquivo))
    {
        return i;
    }

    int read = 0;
    int atual = 0;
    while (1)
    {
        sscanf(&linha[atual] ,"(%d %d)%c%n", &posicao[i].posX, &posicao[i].posY, &temp, &read);
        if (read == 0) // Nada foi lido, sscanf chegou ao final da linha.
            break;
        atual += read; // "Avanca" o atual, (quantidade de caracteres lidos) vezes.
        i++;
        if (temp == '\n')
        {
            return i;
        }
    }
    return i;
}

void PrintaBordaMapaHorizontal(FILE *arquivo, int largura)
{
    fprintf (arquivo, "+");
    for (int i = 0; i < largura; i++)
    {
        fprintf (arquivo, "-");
    }
    fprintf (arquivo, "+\n");
    return;
}

void PrintaMapa(FILE *arquivo, tMapa mapa)
{
    for (int i = 0; i < mapa.altura; i++)
    {
        if (i != mapa.jogador.posX - 2)
        {
            fprintf (arquivo, "|");
        }
        else
        {
            fprintf (arquivo, "-");
        }

        for (int j = 0; j < mapa.largura; j++)
        {
            fprintf (arquivo, "%c", mapa.mapa[i][j]);
        }

        if (i != mapa.jogador.posX - 2)
        {
            fprintf (arquivo, "|\n");
        }
        else
        {
            fprintf (arquivo, "-\n");
        }
    }
}