import pygame
from pygame import mixer

import random
import math

# Inicializa o pygame (Linha importante)
pygame.init()

# Tela do jogo
screen = pygame.display.set_mode((800,600)) # Adiciona a proporção da tela
background = pygame.image.load('Assets/cenario.png') # Adiciona a imagem de fundo ao programa

# Titulo e Icone
pygame.display.set_caption("Attack on Poyo") # Adiciona o titulo ao jogo
icon = pygame.image.load('Assets/icone.jpg')
pygame.display.set_icon(icon)

# Música de fundo
mixer.music.load ('Assets/soundtrack.wav')
mixer.music.play(-1)

# Player
playerImg = pygame.image.load('Assets/kirby.png')
playerX = 370
playerY = 480
playerXalteracao = 0
playerYalteracao = 0
colisao_player = 0

# Ataque do Player
ataquePlayerImg = pygame.image.load('Assets/ataque.png')
ataquePlayerX = 1000
ataquePlayerY = 1000
ataquePlayerYalteracao = 6
estado_ataque = "pronto" # "pronto" para pode atirar e "recarga" para cooldown

# Inimigo
inimigoImg = []
inimigoX = []
inimigoY = []
inimigoXalteracao = []
inimigoYalteracao = []
numInimigos = 6

for i in range(numInimigos):
    inimigoImg.append(pygame.image.load('Assets/inimigo.png'))
    inimigoX.append(random.randint(0, 725))
    inimigoY.append(random.randint(50, 150))
    inimigoXalteracao.append(2.5)
    inimigoYalteracao.append(40)


# Pontuação
fonte_pontuacao = pygame.font.Font ('Assets/robotomono-bold.ttf', 32)
pontuacao = 0
textoX = 10
textoY = 10

# Game Over 
fonte_game_over = pygame.font.Font ('Assets/robotomono-bold.ttf', 64)
som_game_over = True

# Stage Clear 
fonte_stage_clear = pygame.font.Font ('Assets/robotomono-bold.ttf', 64)
som_stage_clear = True

# Funções para o funcionamento do programa
def player(x, y):
    screen.blit(playerImg, (x, y)) # "blit" desenha uma imagem na tela

def ataquePlayer(x, y):
    global estado_ataque
    estado_ataque = "recarga"
    screen.blit(ataquePlayerImg, (x + 10, y + 8))

def inimigo(x, y, i):
    screen.blit(inimigoImg[i], (x, y)) # "blit" desenha uma imagem na tela

def teveColisao (x1, y1, x2, y2):
    distancia = math.sqrt(math.pow(x1 - x2, 2) + (math.pow(y1 - y2, 2)))
    if distancia < 37:
        return True
    return False

def mostrarPontuacao (x , y):
    pontos = fonte_pontuacao.render("Pontos:" + str(pontuacao), True, (255, 255, 255))
    screen.blit(pontos, (x, y)) # "blit" desenha uma imagem na tela

def game_over():
    global som_game_over
    mixer.music.unload ()
    if som_game_over == True:
        Som_GO = mixer.Sound('Assets/derrota.wav')
        Som_GO.play()
        som_game_over = False
    texto_fim_de_jogo = fonte_game_over.render("GAME OVER", True, (255, 255, 255))
    for j in range(numInimigos):
        inimigoY[j] = 2000
    global playerY
    playerY = 3000
    global playerX
    playerX = 3000
    screen.blit(texto_fim_de_jogo, (250, 250)) # "blit" desenha uma imagem na tela

def stage_clear():
    global som_stage_clear
    mixer.music.unload ()
    if som_stage_clear == True:
        Som_SC = mixer.Sound('Assets/StageClear.mp3')
        Som_SC.play()
        som_stage_clear = False
    texto_fim_de_jogo = fonte_stage_clear.render("VITÓRIA!", True, (255, 255, 255))
    for j in range(numInimigos):
        inimigoY[j] = 2000
    global playerY
    playerY = 3000
    global playerX
    playerX = 3000
    screen.blit(texto_fim_de_jogo, (255, 250)) # "blit" desenha uma imagem na tela

# Rodar o jogo
running = True
while running:

    screen.fill((0, 0, 0)) # Alterar o fundo com base em RGB (Tem que ficar a cima, caso outros elementos tenham que aparecer)
    screen.blit(background, (0, 0))

    for event in pygame.event.get():
        if event.type == pygame.QUIT: # Fechar o jogo caso o botão de fechar seja apertado
            running = False
    
        # Inclusão das teclas de movimento
        if event.type == pygame.KEYDOWN:

            # Player
            if event.key == pygame.K_a or event.key == pygame.K_LEFT:
                    playerXalteracao = -2.8
            if event.key == pygame.K_d or event.key == pygame.K_RIGHT:
                    playerXalteracao = 2.8
            if event.key == pygame.K_w or event.key == pygame.K_UP:
                    playerYalteracao = -2.8
            if event.key == pygame.K_s or event.key == pygame.K_DOWN:
                    playerYalteracao = 2.8
            
            # Ataque do Player
            if event.key == pygame.K_p or event.key == pygame.K_SPACE:
                    # Se não tiver um ataque na tela, permite outro ataque
                    if (estado_ataque == "pronto"):
                        #Pega a posição X e Y do player e guarda
                        ataquePlayerY = playerY
                        ataquePlayerX = playerX

                        tiro = random.randint(0, 1)
                        if tiro == 1:
                            SomAtaque = mixer.Sound('Assets/SomAtaque1.wav')
                        else:
                            SomAtaque = mixer.Sound('Assets/SomAtaque2.wav')
                        SomAtaque.play()

                        ataquePlayer(ataquePlayerX, ataquePlayerY)

        # Verifica se a tecla foi soltada
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_a or event.key == pygame.K_LEFT:
                playerXalteracao = 0 
            if event.key == pygame.K_d or event.key == pygame.K_RIGHT:
                playerXalteracao = 0
            if event.key == pygame.K_w or event.key == pygame.K_UP:
                playerYalteracao = 0
            if event.key == pygame.K_s or event.key == pygame.K_DOWN:
                playerYalteracao = 0

    #Limitar movimentalão do player pra ele não sair da tela
    playerX += playerXalteracao
    if playerX >= 745:
        playerX = 745
    elif playerX <= 0:
        playerX = 0

    playerY += playerYalteracao
    if playerY >= 535:
        playerY = 535
    elif playerY <= 0:
        playerY = 0

    # Movimentação do ataque do Player
    if not colisao_player: 
        if ataquePlayerY <= -50:
            ataquePlayerY = 1000
            estado_ataque = "pronto"

        if (estado_ataque == "recarga"):
            ataquePlayer(ataquePlayerX, ataquePlayerY)
            ataquePlayerY -= ataquePlayerYalteracao

    # Movimentação dos inimigos

    for i in range(numInimigos):

        # Game Over
        if inimigoY[i] > 580:
            game_over()
            break

        inimigoX[i] += inimigoXalteracao[i]

        if inimigoX[i] <= -10:
            inimigoXalteracao[i] = 2.5
            inimigoY[i] += inimigoYalteracao[i]

        elif inimigoX[i] >= 735:
            inimigoXalteracao[i] = -2.5
            inimigoY[i] += inimigoYalteracao[i]
        
        # Colisão do Ataque do player
        colisao_ataque = teveColisao(inimigoX[i], inimigoY[i], ataquePlayerX, ataquePlayerY)
        if colisao_ataque: # Colisão do player com o inimigo
            SomAtingirInimigo = mixer.Sound('Assets/AtingiuInimigo.wav')
            SomAtingirInimigo.play()
            ataquePlayerY = 1000
            ataquePlayerX = 1000
            estado_ataque = "pronto"
            pontuacao += 1
            inimigoX[i] = random.randint(0, 725)
            inimigoY[i] = random.randint(50, 150)
        
        colisao_player = teveColisao(playerX, playerY, inimigoX[i], inimigoY[i])
        if colisao_player: # Colisão do player com o inimigo
            game_over()
            break

        # Movimentar o inimigo
        inimigo(inimigoX[i], inimigoY[i], i)

    if not colisao_player: 
        player(playerX, playerY) # Movimentar o player

    if pontuacao == 20:
        running == False
        break

    mostrarPontuacao (textoX , textoY) # Mostrar pontuação
    pygame.display.update() # Atualiza a tela do jogo (Linha importante)

running = True
while running:
    screen.fill((0, 0, 0)) # Alterar o fundo com base em RGB (Tem que ficar a cima, caso outros elementos tenham que aparecer)
    screen.blit(background, (0, 0))

    for event in pygame.event.get():
        if event.type == pygame.QUIT: # Fechar o jogo caso o botão de fechar seja apertado
            running = False

    stage_clear()
    pygame.display.update() # Atualiza a tela do jogo (Linha importante)