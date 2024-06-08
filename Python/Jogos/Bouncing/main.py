import pygame
from pygame import mixer
import os
import random

# Incialização do pygame
pygame.init()

# Informações do monitor do usuario
os.environ['SDL_VIDEO_CENTERED'] = '1'
info = pygame.display.Info()
screen_width, screen_height = info.current_w, info.current_h

# Inicializa a tela
screen = pygame.display.set_mode((screen_width, screen_height - 50), pygame.RESIZABLE)

# Titulo e Icone
pygame.display.set_caption("Bouncing")
icon = pygame.image.load('Assets/chibi.jpg')
pygame.display.set_icon(icon)

# FPS
FPS = 60
clock = pygame.time.Clock()

# Cores do Cubo
cores = {
    "cinza": pygame.image.load('Assets/cinza.png'),
    "amarelo": pygame.image.load('Assets/amarelo.png'),
    "azulescuro": pygame.image.load('Assets/azulescuro.png'),
    "branco": pygame.image.load('Assets/branco.png'),
    "ciano": pygame.image.load('Assets/ciano.png'),
    "laranja": pygame.image.load('Assets/laranja.png'),
    "purpura": pygame.image.load('Assets/purpura.png'),
    "roxo": pygame.image.load('Assets/roxo.png'),
    "verdeagua": pygame.image.load('Assets/verdeagua.png'),
    "verdeclaro": pygame.image.load('Assets/verdeclaro.png'),
    "verdeescuro": pygame.image.load('Assets/verdeescuro.png'),
    "vermelho": pygame.image.load('Assets/vermelho.png')
}

# Cubo
cuboX = random.randint(0, screen_width - 100)
cuboY = random.randint(0, screen_height - 170)
cuboXalteracao = 8
cuboYalteracao = 8
cuboAtual = "cinza"
corAnterior = 0

# Posição do Player
def player(x, y):
    screen.blit(cores[cuboAtual], (x, y))

# Colisão
def colisao(modo, x, y):
    if modo == 'x':
        if x <= 0:
            return -1
        if x >= screen_width - 100:
            return -1
    elif modo == 'y':
        if y <= 0:
            return -1
        if y >= screen_height - 170:
            return -1
    return 1

def alteraCorCubo(cuboAtual):
    global corAnterior
    cor = corAnterior

    while corAnterior == cor:
        cor = random.randint(1, 11)

    cuboAtual = list(cores.keys())[cor]
    corAnterior = cor

    return cuboAtual

# Loop principal
running = True
while running:
    clock.tick(FPS)
    screen.fill((0, 0, 0))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    colisaoX = colisao('x', cuboX, cuboY)
    colisaoY = colisao('y', cuboX, cuboY)
    cuboXalteracao = colisaoX * cuboXalteracao
    cuboYalteracao = colisaoY * cuboYalteracao

    if colisaoX == -1 or colisaoY == -1:
        cuboAtual = alteraCorCubo(cuboAtual)

    cuboX += cuboXalteracao
    cuboY += cuboYalteracao

    player(cuboX, cuboY)
    pygame.display.update()