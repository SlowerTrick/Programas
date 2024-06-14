#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

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
    char mapa[41][101];
    int altura;
    int largura;
    tPosicao jogador;
    tPosicao tiro;
    tInimigo desenhoInimigo;
    char desenhoJogador[4][4];
    tPosicao inimigoLinha1[35]; // Eh impossivel a quantidade de inimigos ser maior do que 35, considerando um mapa de
    tPosicao inimigoLinha2[35]; // no maximo 100 de largura.
    tPosicao inimigoLinha3[35]; // 
    int totalInimigosLinha1;
    int totalInimigosLinha2;
    int totalInimigosLinha3;
    int totalPontos;
    int CoeficienteDeMovimento;
}
tMapa;

typedef struct
{
    
}
tEstatisticas;


// Funcoes de Inicializacao do Mapa
tMapa InicializaMapa(char *diretorio);
tInimigo InicializaInimigo(FILE *arquivo);
int InicializaPosicoesInimigos(FILE *arquivo, tPosicao posicao[]);
tMapa InicializaJogador(tMapa mapa);

// Funcoes de Realizacao do Jogo
tMapa RealizaJogo (char *diretorio, tMapa mapa);
tMapa VerificaColisao(tMapa mapa);
tMapa AlterarPosicaoInimigos(tMapa mapa, int totalInimigos);
tMapa MovimentaInimigosNaVertical(tMapa mapa);
tMapa MovimentaInimigosNaHorizontal(tMapa mapa);
tPosicao AlterarPosicaoPlayer(tPosicao player, char movimento);
tPosicao AlterarPosicaoTiro(tPosicao tiro);
tPosicao DispararTiro(tPosicao tiro, tPosicao player);
bool HouveColisao(tPosicao tiro, tPosicao inimigo);
bool Vitoria(int totalinimigos);
bool Derrota(tMapa mapa);
bool ExisteTiroAtivo(tPosicao tiro);
bool EhMovimentoValido(char movimento, tMapa mapa);
bool VaiSairDaBordaHorizontal(tPosicao entidade, int largura, int coeficiente);
char LeMovimentoPlayer(FILE *arquivo);
int EncontraMaisProximoDaBorda(tMapa mapa, int modo);
int InimigosRestantes(tMapa mapa);

//Funcoes Acessorias
FILE *InicializaFile(char *diretorio, int modo);
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
    mapa = RealizaJogo(argv[1], mapa);
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
    fscanf (arquivoMapa, "%d %d", &mapa.largura, &mapa.altura);
    fgetc(arquivoMapa);
    fscanf (arquivoMapa, "(%d %d)", &mapa.jogador.posX, &mapa.jogador.posY);
    fgetc(arquivoMapa);

    mapa.desenhoInimigo = InicializaInimigo(arquivoInimigo);
    mapa.totalInimigosLinha1 = InicializaPosicoesInimigos(arquivoMapa, mapa.inimigoLinha1);
    mapa.totalInimigosLinha2 = InicializaPosicoesInimigos(arquivoMapa, mapa.inimigoLinha2);
    mapa.totalInimigosLinha3 = InicializaPosicoesInimigos(arquivoMapa, mapa.inimigoLinha3);
    mapa = InicializaJogador(mapa);

    char arquivoSaidaInicializacao[50];
    sprintf(arquivoSaidaInicializacao, "saida/inicializacao.txt");
    FILE *saidaInicializacao = InicializaFile(arquivoSaidaInicializacao, 2);
    if (!saidaInicializacao)
    {
        fclose(arquivoMapa);
        fclose(arquivoInimigo);
        exit(1);
    }

    mapa = PreencheMapa(mapa);
    PrintaBordaMapaHorizontal(saidaInicializacao, mapa.largura);
    PrintaMapa(saidaInicializacao, mapa);
    PrintaBordaMapaHorizontal(saidaInicializacao, mapa.largura);
    fprintf (saidaInicializacao, "A posicao central do jogador iniciara em (%d %d).", mapa.jogador.posX, mapa.jogador.posY);

    fclose(arquivoMapa);
    fclose(arquivoInimigo);
    fclose(saidaInicializacao);
    return mapa;
}

tMapa PreencheMapa(tMapa mapa) 
{
    for (int i = 0; i < mapa.altura; i++)
    {
        for (int j = 0; j < mapa.largura; j++)
        {
            mapa.mapa[i][j] = ' ';
        }
    }
    // Posiciona o jogador
    mapa.mapa[mapa.jogador.posY-2][mapa.jogador.posX] = mapa.desenhoJogador[0][2];
    mapa.mapa[mapa.jogador.posY-2][mapa.jogador.posX-1] = mapa.desenhoJogador[0][1];
    mapa.mapa[mapa.jogador.posY-2][mapa.jogador.posX-2] = mapa.desenhoJogador[0][0];

    mapa.mapa[mapa.jogador.posY-1][mapa.jogador.posX] = mapa.desenhoJogador[1][2];
    mapa.mapa[mapa.jogador.posY-1][mapa.jogador.posX-1] = mapa.desenhoJogador[1][1];
    mapa.mapa[mapa.jogador.posY-1][mapa.jogador.posX-2] = mapa.desenhoJogador[1][0];

    mapa.mapa[mapa.jogador.posY][mapa.jogador.posX] = mapa.desenhoJogador[2][2];
    mapa.mapa[mapa.jogador.posY][mapa.jogador.posX-1] = mapa.desenhoJogador[2][1];
    mapa.mapa[mapa.jogador.posY][mapa.jogador.posX-2] = mapa.desenhoJogador[2][0];

    // Posiciona os inimigos
    for (int i = 0; i < mapa.totalInimigosLinha1; i++)
    {
        if (mapa.inimigoLinha1[i].posX != -1)
        {
            mapa.mapa[mapa.inimigoLinha1[i].posY-2][mapa.inimigoLinha1[i].posX] = mapa.desenhoInimigo.partes[0].desenho[0][2];
            mapa.mapa[mapa.inimigoLinha1[i].posY-2][mapa.inimigoLinha1[i].posX-1] = mapa.desenhoInimigo.partes[0].desenho[0][1];
            mapa.mapa[mapa.inimigoLinha1[i].posY-2][mapa.inimigoLinha1[i].posX-2] = mapa.desenhoInimigo.partes[0].desenho[0][0];

            mapa.mapa[mapa.inimigoLinha1[i].posY-1][mapa.inimigoLinha1[i].posX] = mapa.desenhoInimigo.partes[0].desenho[1][2];
            mapa.mapa[mapa.inimigoLinha1[i].posY-1][mapa.inimigoLinha1[i].posX-1] = mapa.desenhoInimigo.partes[0].desenho[1][1];
            mapa.mapa[mapa.inimigoLinha1[i].posY-1][mapa.inimigoLinha1[i].posX-2] = mapa.desenhoInimigo.partes[0].desenho[1][0];

            mapa.mapa[mapa.inimigoLinha1[i].posY][mapa.inimigoLinha1[i].posX] = mapa.desenhoInimigo.partes[0].desenho[2][2];
            mapa.mapa[mapa.inimigoLinha1[i].posY][mapa.inimigoLinha1[i].posX-1] = mapa.desenhoInimigo.partes[0].desenho[2][1];
            mapa.mapa[mapa.inimigoLinha1[i].posY][mapa.inimigoLinha1[i].posX-2] = mapa.desenhoInimigo.partes[0].desenho[2][0];
        }
    }
    for (int i = 0; i < mapa.totalInimigosLinha2; i++)
    {
        if (mapa.inimigoLinha2[i].posX != -1)
        {
            mapa.mapa[mapa.inimigoLinha2[i].posY-2][mapa.inimigoLinha2[i].posX] = mapa.desenhoInimigo.partes[0].desenho[0][2];
            mapa.mapa[mapa.inimigoLinha2[i].posY-2][mapa.inimigoLinha2[i].posX-1] = mapa.desenhoInimigo.partes[0].desenho[0][1];
            mapa.mapa[mapa.inimigoLinha2[i].posY-2][mapa.inimigoLinha2[i].posX-2] = mapa.desenhoInimigo.partes[0].desenho[0][0];

            mapa.mapa[mapa.inimigoLinha2[i].posY-1][mapa.inimigoLinha2[i].posX] = mapa.desenhoInimigo.partes[0].desenho[1][2];
            mapa.mapa[mapa.inimigoLinha2[i].posY-1][mapa.inimigoLinha2[i].posX-1] = mapa.desenhoInimigo.partes[0].desenho[1][1];
            mapa.mapa[mapa.inimigoLinha2[i].posY-1][mapa.inimigoLinha2[i].posX-2] = mapa.desenhoInimigo.partes[0].desenho[1][0];

            mapa.mapa[mapa.inimigoLinha2[i].posY][mapa.inimigoLinha2[i].posX] = mapa.desenhoInimigo.partes[0].desenho[2][2];
            mapa.mapa[mapa.inimigoLinha2[i].posY][mapa.inimigoLinha2[i].posX-1] = mapa.desenhoInimigo.partes[0].desenho[2][1];
            mapa.mapa[mapa.inimigoLinha2[i].posY][mapa.inimigoLinha2[i].posX-2] = mapa.desenhoInimigo.partes[0].desenho[2][0];
        }
    }
    for (int i = 0; i < mapa.totalInimigosLinha3; i++)
    {
        if (mapa.inimigoLinha2[i].posX != -1)
        {
            mapa.mapa[mapa.inimigoLinha3[i].posY-2][mapa.inimigoLinha3[i].posX] = mapa.desenhoInimigo.partes[0].desenho[0][2];
            mapa.mapa[mapa.inimigoLinha3[i].posY-2][mapa.inimigoLinha3[i].posX-1] = mapa.desenhoInimigo.partes[0].desenho[0][1];
            mapa.mapa[mapa.inimigoLinha3[i].posY-2][mapa.inimigoLinha3[i].posX-2] = mapa.desenhoInimigo.partes[0].desenho[0][0];

            mapa.mapa[mapa.inimigoLinha3[i].posY-1][mapa.inimigoLinha3[i].posX] = mapa.desenhoInimigo.partes[0].desenho[1][2];
            mapa.mapa[mapa.inimigoLinha3[i].posY-1][mapa.inimigoLinha3[i].posX-1] = mapa.desenhoInimigo.partes[0].desenho[1][1];
            mapa.mapa[mapa.inimigoLinha3[i].posY-1][mapa.inimigoLinha3[i].posX-2] = mapa.desenhoInimigo.partes[0].desenho[1][0];

            mapa.mapa[mapa.inimigoLinha3[i].posY][mapa.inimigoLinha3[i].posX] = mapa.desenhoInimigo.partes[0].desenho[2][2];
            mapa.mapa[mapa.inimigoLinha3[i].posY][mapa.inimigoLinha3[i].posX-1] = mapa.desenhoInimigo.partes[0].desenho[2][1];
            mapa.mapa[mapa.inimigoLinha3[i].posY][mapa.inimigoLinha3[i].posX-2] = mapa.desenhoInimigo.partes[0].desenho[2][0];
        }
    }

    // Posiciona o tiro
    if (mapa.tiro.posX != -1)
    {
        mapa.mapa[mapa.tiro.posY][mapa.tiro.posX] = 'o';
    }

    return mapa;
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

tMapa InicializaJogador(tMapa mapa)
{
    mapa.desenhoJogador[0][0] = 'M';
    mapa.desenhoJogador[0][1] = ' ';
    mapa.desenhoJogador[0][2] = 'M';
    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mapa.desenhoJogador[i][j] = 'M';
        }
    }
    mapa.tiro.posX = -1;
    mapa.tiro.posY = -1;
    return mapa;
}

tInimigo InicializaInimigo(FILE *arquivo)
{
    tInimigo inimigo;
    char temp;
    fscanf(arquivo, "%d", &inimigo.bonus);
    temp = fgetc(arquivo);

    for (int p = 0; p < 3; p++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                fscanf(arquivo, "%c", &inimigo.partes[p].desenho[i][j]);
            }
            temp = fgetc(arquivo);
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
    while (sscanf(&linha[atual] ,"(%d %d)%c%n", &posicao[i].posX, &posicao[i].posY, &temp, &read) == 3)
    {
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
        if (i != mapa.jogador.posY - 3)
        {
            fprintf (arquivo, "|");
        }
        if (i == mapa.jogador.posY - 3)
        {
            fprintf (arquivo, "-");
        }

        for (int j = 0; j < mapa.largura; j++)
        {
            fprintf (arquivo, "%c", mapa.mapa[i][j]);
        }

        if (i != mapa.jogador.posY - 3)
        {
            fprintf (arquivo, "|\n");
        }
        if (i == mapa.jogador.posY - 3)
        {
            fprintf (arquivo, "-\n");
        }
    }
}

tMapa RealizaJogo (char *diretorio, tMapa mapa)
{
    int i = 0, verificadorfinal = 0;
    int totalInimigos = mapa.totalInimigosLinha1 + mapa.totalInimigosLinha2 + mapa.totalInimigosLinha3;
    mapa.tiro.posX = -1; // Inicializacao do tiroX
    mapa.tiro.posY = -1; // Inicializacao do tiroY
    mapa.CoeficienteDeMovimento = 1; // Inicializacao do coeficiente
    mapa.totalPontos = 0; // Inicializacao dos pontos

    char localEntrada[1000];
    sprintf(localEntrada, "%s/entrada.txt", diretorio);
    FILE *arquivoEntrada = InicializaFile(localEntrada, 1);
    if (!arquivoEntrada)
    {
        exit(1);
    }
    char arquivoSaidaSaida[50];
    sprintf(arquivoSaidaSaida, "saida/saida.txt");
    FILE *saidaSaida = InicializaFile(arquivoSaidaSaida, 2);
    if (!saidaSaida)
    {
        fclose(arquivoEntrada);
        exit(1);
    }

    fprintf(saidaSaida, "Pontos: %i | Iteracoes: %i\n", mapa.totalPontos, i);
    PrintaBordaMapaHorizontal(saidaSaida, mapa.largura);
    PrintaMapa(saidaSaida, mapa);
    PrintaBordaMapaHorizontal(saidaSaida, mapa.largura);

    bool CheckVitoria = false; // Vitoria tem que passar 2 vezes para a iteracao final
    int ContaVitorias = 0;
    
    if (!Vitoria(totalInimigos))
    {
        while (!CheckVitoria && !Derrota(mapa))
        {
            bool TiroDisparadoNessaIteracao = false;
            char movimento = LeMovimentoPlayer(arquivoEntrada);

            if (EhMovimentoValido(movimento, mapa))
            {
                if (movimento == ' ')
                {
                    mapa.tiro = DispararTiro(mapa.tiro, mapa.jogador);
                    TiroDisparadoNessaIteracao = true;
                }
                else if (movimento == 'a' || movimento == 'd')
                {
                    mapa.jogador = AlterarPosicaoPlayer(mapa.jogador, movimento);
                }
            }

            mapa = AlterarPosicaoInimigos(mapa, totalInimigos);
            
            if (ExisteTiroAtivo(mapa.tiro) && TiroDisparadoNessaIteracao == false)
            {
                mapa.tiro = AlterarPosicaoTiro(mapa.tiro);
            }
            mapa = PreencheMapa(mapa); 

            i++;
            fprintf(saidaSaida, "Pontos: %i | Iteracoes: %i\n", mapa.totalPontos, i);
            PrintaBordaMapaHorizontal(saidaSaida, mapa.largura);
            PrintaMapa(saidaSaida, mapa);
            PrintaBordaMapaHorizontal(saidaSaida, mapa.largura);

            if (Derrota(mapa))
            {
                break;
            }

            mapa = VerificaColisao(mapa);
            if (mapa.tiro.posY == 0)
            {
                mapa.tiro.posY = -1;
                mapa.tiro.posX = -1;
            }

            totalInimigos = InimigosRestantes(mapa);
            TiroDisparadoNessaIteracao = false; 

            if (Vitoria(totalInimigos))
            {
                ContaVitorias++;
                if (ContaVitorias == 2)
                {
                    CheckVitoria = true;
                }
            }
        }
    }

    if (Vitoria(totalInimigos))
    {
        fprintf(saidaSaida, "Parabéns, você ganhou!\n");
    }
    if (Derrota(mapa))
    {
        fprintf(saidaSaida, "Você perdeu, tente novamente!\n");
    }

    fclose(arquivoEntrada);
    fclose(saidaSaida);
    return mapa;
}

bool Vitoria(int totalinimigos)
{
    if (totalinimigos == 0)
    {
        return true;
    }
    return false;
}

bool Derrota(tMapa mapa)
{
    for (int i = 0; i < mapa.totalInimigosLinha1; i++)
    {
        if (mapa.inimigoLinha1[i].posX != -1)
        {
            if (mapa.inimigoLinha1[i].posY == mapa.jogador.posY - 2)
            {
                return true;
            }
        }
    }
    for (int i = 0; i < mapa.totalInimigosLinha2; i++)
    {
        if (mapa.inimigoLinha2[i].posX != -1)
        {
            if (mapa.inimigoLinha2[i].posY == mapa.jogador.posY - 1)
            {
                return true;
            }
        }
    }
    for (int i = 0; i < mapa.totalInimigosLinha3; i++)
    {
        if (mapa.inimigoLinha3[i].posX != -1)
        {
            if (mapa.inimigoLinha3[i].posY == mapa.jogador.posY - 1)
            {
                return true;
            }
        }
    }
    return false;
}

char LeMovimentoPlayer(FILE *arquivo)
{
    char movimento = fgetc(arquivo);
    if (movimento == '\n')
    {
        movimento = fgetc(arquivo);
        fgetc(arquivo);
        return movimento;
    }
    fgetc(arquivo);
    return movimento;
}

bool EhMovimentoValido(char movimento, tMapa mapa)
{
    if (movimento == 's')
    {
        return true;
    }
    if (movimento == ' ' || movimento == '\n')
    {
        if (!ExisteTiroAtivo(mapa.tiro))
        {
            return true;
        }
        return false;
    }
    if (movimento == 'a')
    {
        if (!VaiSairDaBordaHorizontal(mapa.jogador, mapa.largura, -1))
        {
            return true;
        }
        return false;
    }
    if (movimento == 'd')
    {
        if (!VaiSairDaBordaHorizontal(mapa.jogador, mapa.largura, 1))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool ExisteTiroAtivo(tPosicao tiro)
{
    if (tiro.posX != -1 || tiro.posY != -1)
    {
        return true;
    }
    return false;
}

tMapa VerificaColisao(tMapa mapa)
{
    for (int i = 0; i < mapa.totalInimigosLinha1; i++)
    {
        if (HouveColisao(mapa.tiro, mapa.inimigoLinha1[i]))
        {
            mapa.totalPontos += mapa.inimigoLinha1[i].posX * (mapa.altura - mapa.inimigoLinha1[i].posY);
            mapa.tiro.posX = -1;
            mapa.tiro.posY = -1;
            mapa.inimigoLinha1[i].posX = -1;
            mapa.inimigoLinha1[i].posY = -1;
            return mapa;
        }
    }
    for (int i = 0; i < mapa.totalInimigosLinha2; i++)
    {
        if (HouveColisao(mapa.tiro, mapa.inimigoLinha2[i]))
        {
            mapa.totalPontos += mapa.inimigoLinha2[i].posX * (mapa.altura - mapa.inimigoLinha2[i].posY);
            mapa.tiro.posX = -1;
            mapa.tiro.posY = -1;
            mapa.inimigoLinha2[i].posX = -1;
            mapa.inimigoLinha2[i].posY = -1;
            return mapa;
        }
    }
    for (int i = 0; i < mapa.totalInimigosLinha3; i++)
    {
        if (HouveColisao(mapa.tiro, mapa.inimigoLinha3[i]))
        {
            mapa.totalPontos += mapa.inimigoLinha3[i].posX * (mapa.altura - mapa.inimigoLinha3[i].posY);
            mapa.tiro.posX = -1;
            mapa.tiro.posY = -1;
            mapa.inimigoLinha3[i].posX = -1;
            mapa.inimigoLinha3[i].posY = -1;
            return mapa;
        }
    }
    return mapa;
}

bool HouveColisao(tPosicao tiro, tPosicao inimigo)
{
    if (inimigo.posX != -1)
    {
        if (tiro.posX == inimigo.posX - 1 && tiro.posY == inimigo.posY - 1)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX - 2 && tiro.posY == inimigo.posY - 1)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX - 2 && tiro.posY == inimigo.posY - 2)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX - 1 && tiro.posY == inimigo.posY - 2)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX && tiro.posY == inimigo.posY - 1)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX && tiro.posY == inimigo.posY)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX - 1 && tiro.posY == inimigo.posY)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX && tiro.posY == inimigo.posY - 2)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX - 2 && tiro.posY == inimigo.posY)
        {
            return true;
        }
    }
    return false;
}

int InimigosRestantes(tMapa mapa)
{
    int total = 0;
    for (int i = 0; i < mapa.totalInimigosLinha1; i++)
    {
        if (mapa.inimigoLinha1[i].posX != -1)
        {
            total++;
        }
    }
    for (int i = 0; i < mapa.totalInimigosLinha2; i++)
    {
        if (mapa.inimigoLinha2[i].posX != -1)
        {
            total++;
        }
    }
    for (int i = 0; i < mapa.totalInimigosLinha3; i++)
    {
        if (mapa.inimigoLinha3[i].posX != -1)
        {
            total++;
        }
    }
    return total;
}

tMapa AlterarPosicaoInimigos(tMapa mapa, int totalInimigos)
{
    if (mapa.CoeficienteDeMovimento == 1)
    {
        tPosicao inimigoMaisAhDireita;
        inimigoMaisAhDireita.posX = EncontraMaisProximoDaBorda(mapa, 1);
        
        if (VaiSairDaBordaHorizontal(inimigoMaisAhDireita, mapa.largura, mapa.CoeficienteDeMovimento))
        {
            mapa = MovimentaInimigosNaVertical(mapa);
            return mapa;
        }
        else
        {
            mapa = MovimentaInimigosNaHorizontal(mapa);
            return mapa;
        }
    }
    if (mapa.CoeficienteDeMovimento == -1)
    {
        tPosicao inimigoMaisAhEsquerda;
        inimigoMaisAhEsquerda.posX = EncontraMaisProximoDaBorda(mapa, 2);

        if (VaiSairDaBordaHorizontal(inimigoMaisAhEsquerda, mapa.largura, mapa.CoeficienteDeMovimento))
        {
            mapa = MovimentaInimigosNaVertical(mapa);
            return mapa;
        }
        else
        {
            mapa = MovimentaInimigosNaHorizontal(mapa);
            return mapa;
        }
    }
    return mapa;
}

tMapa MovimentaInimigosNaVertical(tMapa mapa)
{
    for (int i = 0; i < mapa.totalInimigosLinha1; i++)
    {
        if (mapa.inimigoLinha1[i].posX != -1)
        {
            mapa.inimigoLinha1[i].posY += 1;
        }
    }
    for (int i = 0; i < mapa.totalInimigosLinha2; i++)
    {
        if (mapa.inimigoLinha2[i].posX != -1)
        {
            mapa.inimigoLinha2[i].posY += 1;
        }
    }
    for (int i = 0; i < mapa.totalInimigosLinha3; i++)
    {
        if (mapa.inimigoLinha3[i].posX != -1)
        {
            mapa.inimigoLinha3[i].posY += 1;
        }
    }
    mapa.CoeficienteDeMovimento = mapa.CoeficienteDeMovimento * (-1);
    return mapa;
}

tMapa MovimentaInimigosNaHorizontal(tMapa mapa)
{
    for (int i = 0; i < mapa.totalInimigosLinha1; i++)
    {
        if (mapa.inimigoLinha1[i].posX != -1)
        {
            mapa.inimigoLinha1[i].posX += mapa.CoeficienteDeMovimento;
        }
    }
    for (int i = 0; i < mapa.totalInimigosLinha2; i++)
    {
        if (mapa.inimigoLinha2[i].posX != -1)
        {
            mapa.inimigoLinha2[i].posX += mapa.CoeficienteDeMovimento;
        }
    }
    for (int i = 0; i < mapa.totalInimigosLinha3; i++)
    {
        if (mapa.inimigoLinha3[i].posX != -1)
        {
            mapa.inimigoLinha3[i].posX += mapa.CoeficienteDeMovimento;
        }
    }
    return mapa;
}

int EncontraMaisProximoDaBorda(tMapa mapa, int modo)
{
    if (modo == 1)
    {
        tPosicao inimigoMaisAhDireita;
        inimigoMaisAhDireita.posX = 0;

        for (int i = 0; i < mapa.totalInimigosLinha1; i++)
        {
            if (inimigoMaisAhDireita.posX < mapa.inimigoLinha1[i].posX && mapa.inimigoLinha1[i].posX != -1)
            {
                inimigoMaisAhDireita.posX = mapa.inimigoLinha1[i].posX;
            }
        }
        for (int i = 0; i < mapa.totalInimigosLinha2; i++)
        {
            if (inimigoMaisAhDireita.posX < mapa.inimigoLinha2[i].posX && mapa.inimigoLinha2[i].posX != -1)
            {
                inimigoMaisAhDireita.posX = mapa.inimigoLinha2[i].posX;
            }
        }
        for (int i = 0; i < mapa.totalInimigosLinha3; i++)
        {
            if (inimigoMaisAhDireita.posX < mapa.inimigoLinha3[i].posX && mapa.inimigoLinha3[i].posX != -1)
            {
                inimigoMaisAhDireita.posX = mapa.inimigoLinha3[i].posX;
            }
        }
        return inimigoMaisAhDireita.posX;
    }
    if (modo == 2)
    {
        tPosicao inimigoMaisAhEsquerda;
        inimigoMaisAhEsquerda.posX = mapa.largura;

        for (int i = 0; i < mapa.totalInimigosLinha1; i++)
        {
            if (mapa.inimigoLinha1[i].posX < inimigoMaisAhEsquerda.posX && mapa.inimigoLinha1[i].posX != -1)
            {
                inimigoMaisAhEsquerda.posX = mapa.inimigoLinha1[i].posX;
            }
        }
        for (int i = 0; i < mapa.totalInimigosLinha2; i++)
        {
            if (mapa.inimigoLinha2[i].posX < inimigoMaisAhEsquerda.posX && mapa.inimigoLinha2[i].posX != -1)
            {
                inimigoMaisAhEsquerda.posX = mapa.inimigoLinha2[i].posX;
            }
        }
        for (int i = 0; i < mapa.totalInimigosLinha3; i++)
        {
            if (mapa.inimigoLinha3[i].posX > inimigoMaisAhEsquerda.posX && mapa.inimigoLinha3[i].posX != -1)
            {
                inimigoMaisAhEsquerda.posX = mapa.inimigoLinha3[i].posX;
            }
        }
        return inimigoMaisAhEsquerda.posX;
    }
    return 0;
}

tPosicao AlterarPosicaoTiro(tPosicao tiro)
{
    tiro.posY -= 1;
    return tiro;
}

tPosicao AlterarPosicaoPlayer(tPosicao player, char movimento)
{
    if (movimento == 'a')
    {
        player.posX -= 1;
        return player;
    }
    if (movimento == 'd')
    {
        player.posX += 1;
        return player;
    }
    return player;
}

tPosicao DispararTiro(tPosicao tiro, tPosicao player)
{
    tiro.posX = player.posX - 1;
    tiro.posY = player.posY - 3;
    return tiro;
}

bool VaiSairDaBordaHorizontal(tPosicao entidade, int largura, int coeficiente)
{
    if (entidade.posX + coeficiente == largura || entidade.posX + coeficiente == 1)
    {
        return true;
    }
    return false;
}