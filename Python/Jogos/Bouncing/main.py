import pygame
import os
import random

# Incialização do pygame
pygame.init()

# Informações do monitor do usuario
os.environ['SDL_VIDEO_CENTERED'] = '1'
info = pygame.display.Info()
SCREEN_WIDTH, SCREEN_HEIGHT = info.current_w, info.current_h
SCREEN_WIDTH_OFFSET = 100
SCREEN_HEIGHT_OFFSET = 170

# Inicializa a tela
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT - 50), pygame.RESIZABLE)

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
quantidadeCubos = 1
cubos = []

# Numeros acessórios de Cubo
INDEX_PRIMEIRA_TECLA = 48
INDEX_ULTIMA_TECLA = INDEX_PRIMEIRA_TECLA + 9

# Posição do Player
def player(cuboAtual, x, y):
    screen.blit(cores[cubos[cuboAtual]["cuboCor"]], (x, y))

# Adiciona Mais cubos
def adicionaCubos(qtdCubos):
    for i in range(qtdCubos):
        cubo = {
            "cuboAtual": "cinza",
            "cuboX": random.randint(1, SCREEN_WIDTH - SCREEN_WIDTH_OFFSET),
            "cuboY": random.randint(1, SCREEN_HEIGHT - SCREEN_HEIGHT_OFFSET),
            "cuboXalteracao": random.randint(1, 15),
            "cuboYalteracao": random.randint(1, 15),
            "cuboCor": "cinza",
            "corAnterior": 0
        }
        cubos.append(cubo)

# Cria os cubos inciais
adicionaCubos(quantidadeCubos)

# Colisão
def colisao(modo, x, y):
    if modo == 'x':
        if x <= 0:
            return -1
        if x >= SCREEN_WIDTH - SCREEN_WIDTH_OFFSET:
            return -1
    elif modo == 'y':
        if y <= 0:
            return -1
        if y >= SCREEN_HEIGHT - SCREEN_HEIGHT_OFFSET:
            return -1
    return 1

def alteraCorCubo(cuboAtual):
    cor = cubos[cuboAtual]["corAnterior"]

    while cubos[cuboAtual]["corAnterior"] == cor:
        cor = random.randint(1, 11)

    cubos[cuboAtual]["cuboCor"] = list(cores.keys())[cor]
    cubos[cuboAtual]["corAnterior"] = cor

def EhTeclaValida(tecla):
    return INDEX_PRIMEIRA_TECLA <= tecla <= INDEX_ULTIMA_TECLA

# Loop principal
running = True
while running:
    clock.tick(FPS)
    screen.fill((0, 0, 0))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        if event.type == pygame.KEYDOWN:
            if EhTeclaValida(event.key):
                quantidadeCubos = event.key - INDEX_PRIMEIRA_TECLA
                adicionaCubos(quantidadeCubos)

    for i in range(quantidadeCubos):
        colisaoX = colisao('x', cubos[i]["cuboX"], cubos[i]["cuboY"])
        colisaoY = colisao('y', cubos[i]["cuboX"], cubos[i]["cuboY"])
        cubos[i]["cuboXalteracao"] = colisaoX * cubos[i]["cuboXalteracao"]
        cubos[i]["cuboYalteracao"] = colisaoY * cubos[i]["cuboYalteracao"]

        if colisaoX == -1 or colisaoY == -1:
            alteraCorCubo(i)

        cubos[i]["cuboX"] += cubos[i]["cuboXalteracao"]
        cubos[i]["cuboY"] += cubos[i]["cuboYalteracao"]

        player(i ,cubos[i]["cuboX"], cubos[i]["cuboY"])

    pygame.display.update()