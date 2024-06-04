#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct
{
    char nome;
    char tipo;
    int nivel;
    int vidaMaxima;
    int ataque;
    int defesa;
    int velocidade;
    int vidaAtual;
}
Pokemon;

typedef struct
{
    int totalbatalhas;  
    int qtdDeAdversarios;
    Pokemon diogo;
    Pokemon adversario;
}
Ginasio;

float calculaVantagem(Pokemon atacante, Pokemon defensor);
int calculaDano(Pokemon atacante, Pokemon defensor);
int estaVivo(Pokemon p);
int menorNivel(Pokemon atacante, Pokemon defensor);
Pokemon subirDeNivel(Pokemon p);
Ginasio batalhar(Pokemon atacante, Pokemon defensor, Ginasio ginasio);
Pokemon lePokemon();
void imprimePokemon(Pokemon p);
Ginasio inicializaGinasio();
Ginasio RealizaBatalha(Ginasio ginasio);
void FinalizaBatalha(Ginasio ginasio);

int main()
{
    Ginasio ginasio = inicializaGinasio();
    ginasio = RealizaBatalha(ginasio);
    FinalizaBatalha(ginasio);
    return 0;
}

float calculaVantagem(Pokemon atacante, Pokemon defensor)
{
    if (atacante.tipo == 'W')
    {
        if (defensor.tipo == 'F' || defensor.tipo == 'R' || defensor.tipo == 'G')
        {
            return 1.5;
        }
        else if (defensor.tipo == 'E' || defensor.tipo == 'P')
        {
            return 0.5;
        }
        else
        {
            return 1.0;
        }
    }
    if (atacante.tipo == 'F')
    {
        if (defensor.tipo == 'P')
        {
            return 1.5;
        }
        else if (defensor.tipo == 'W' || defensor.tipo == 'G' || defensor.tipo == 'R')
        {
            return 0.5;
        }
        else
        {
            return 1.0;
        }
    }
    if (atacante.tipo == 'P')
    {
        if (defensor.tipo == 'W' || defensor.tipo == 'G' || defensor.tipo == 'R')
        {
            return 1.5;
        }
        else if (defensor.tipo == 'F')
        {
            return 0.5;
        }
        else
        {
            return 1.0;
        }
    }
    if (atacante.tipo == 'G')
    {
        if (defensor.tipo == 'F' || defensor.tipo == 'E' || defensor.tipo == 'R')
        {
            return 1.5;
        }
        else if (defensor.tipo == 'W' || defensor.tipo == 'P')
        {
            return 0.5;
        }
        else
        {
            return 1.0;
        }
    }
    if (atacante.tipo == 'E')
    {
        if (defensor.tipo == 'W')
        {
            return 1.5;
        }
        else if (defensor.tipo == 'G')
        {
            return 0.5;
        }
        else
        {
            return 1.0;
        }
    }
    if (atacante.tipo == 'R')
    {
        if (defensor.tipo == 'F')
        {
            return 1.5;
        }
        else if (defensor.tipo == 'W' || defensor.tipo == 'P'|| defensor.tipo == 'G')
        {
            return 0.5;
        }
        else
        {
            return 1.0;
        }
    }
}

int calculaDano(Pokemon atacante, Pokemon defensor)
{
    float adv = calculaVantagem(atacante, defensor);
    int dano = floor((((0.4 * atacante.nivel + 2) * (atacante.ataque / defensor.defesa)) + 2) * adv);
    return dano;
}

int estaVivo(Pokemon p)
{
    if (p.vidaAtual > 0)
    {
        return 1;
    }
    return 0;
}

int menorNivel(Pokemon atacante, Pokemon defensor)
{
    if (atacante.nivel < defensor.nivel)
    {
        return 1;
    } 
    return 0;
}

Pokemon subirDeNivel(Pokemon p)
{
    p.ataque = floor(p.ataque + (0.1 * p.ataque));
    p.defesa = floor(p.defesa + (0.1 * p.defesa));
    p.velocidade = floor(p.velocidade + (0.1 * p.velocidade));
    p.vidaMaxima = floor(p.vidaMaxima + (0.1 * p.vidaMaxima));
    p.nivel++;
    p.vidaAtual = p.vidaMaxima;
    return p;
}

Ginasio batalhar(Pokemon atacante, Pokemon defensor, Ginasio ginasio)
{
    while(estaVivo(atacante) && estaVivo(defensor))
    {
        defensor.vidaAtual -= floor(calculaDano(atacante, defensor));
        if (!estaVivo(defensor))
        {
            if (atacante.velocidade == ginasio.diogo.velocidade)
            {
                ginasio.diogo.vidaAtual = atacante.vidaAtual;
                ginasio.adversario.vidaAtual = defensor.vidaAtual;
            }
            else
            {
                ginasio.diogo.vidaAtual = defensor.vidaAtual;
                ginasio.adversario.vidaAtual = atacante.vidaAtual;
            }
            return ginasio;
        }
        atacante.vidaAtual -= floor(calculaDano(defensor, atacante));
        if (!estaVivo(atacante))
        {
            if (atacante.velocidade == ginasio.diogo.velocidade)
            {
                ginasio.diogo.vidaAtual = atacante.vidaAtual;
                ginasio.adversario.vidaAtual = defensor.vidaAtual;
            }
            else
            {
                ginasio.diogo.vidaAtual = defensor.vidaAtual;
                ginasio.adversario.vidaAtual = atacante.vidaAtual;
            }
            return ginasio;
        }
    }
}

Pokemon lePokemon()
{
    Pokemon pokemon;
    scanf(" %c", &pokemon.nome);
    scanf(" %c", &pokemon.tipo);
    scanf("%i", &pokemon.nivel);
    scanf("%i", &pokemon.vidaMaxima);
    scanf("%i", &pokemon.ataque);
    scanf("%i", &pokemon.defesa);
    scanf("%i", &pokemon.velocidade);
    getchar();
    pokemon.vidaAtual = pokemon.vidaMaxima;
    return pokemon;
}

void imprimePokemon(Pokemon p)
{
    printf("Nome: %c\n", p.nome);
    printf("Tipo: %c\n", p.tipo);
    printf("Nivel: %i\n", p.nivel);
    printf("VidaMax: %i \n", p.vidaMaxima);
    printf("VidaAtual: %i\n", p.vidaAtual);
    printf("Ataque: %i\n", p.ataque);
    printf("Defesa: %i\n", p.defesa);
    printf("Velocidade: %i\n", p.velocidade);
}   

Ginasio inicializaGinasio()
{
    Ginasio ginasio;
    scanf("%i", &ginasio.qtdDeAdversarios);
    getchar();
    ginasio.diogo = lePokemon();
    ginasio.adversario = lePokemon();
    ginasio.totalbatalhas = ginasio.qtdDeAdversarios;
    return ginasio;
}

Ginasio RealizaBatalha(Ginasio ginasio)
{
    int venceu = 0;
    while (ginasio.qtdDeAdversarios > 0 && estaVivo(ginasio.diogo))
    {
        if (ginasio.diogo.velocidade >= ginasio.adversario.velocidade)
        {
            ginasio = batalhar(ginasio.diogo, ginasio.adversario, ginasio);
            if (estaVivo(ginasio.diogo))
            {
                venceu = 1;
            }
            else
            {
                venceu = 0;
            }
        }
        else
        {
            ginasio = batalhar(ginasio.adversario, ginasio.diogo, ginasio);
            if (estaVivo(ginasio.diogo))
            {
                venceu = 1;
            }
            else
            {
                venceu = 0;
            }
        }
        ginasio.qtdDeAdversarios--;
        if (ginasio.adversario.nivel > ginasio.diogo.nivel && venceu == 1)
        {
            ginasio.diogo = subirDeNivel(ginasio.diogo);
        }
        if (ginasio.qtdDeAdversarios != 0)
        {
            ginasio.adversario = lePokemon();
        }
        venceu = 0;
    }
    return ginasio;
}

void FinalizaBatalha(Ginasio ginasio)
{
    if (estaVivo(ginasio.diogo))
    {
        printf("Diogo venceu todas as %i batalhas!\n", ginasio.totalbatalhas);
        printf("Pokemon de Diogo:\n");
        imprimePokemon(ginasio.diogo);
    }
    else
    {
        printf("Diogo perdeu na %i batalha!\n", ginasio.totalbatalhas - ginasio.qtdDeAdversarios);
        printf("Ultimo Pokemon adversario:\n");
        imprimePokemon(ginasio.adversario);
    }
    return;
}
