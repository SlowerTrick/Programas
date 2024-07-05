import pygame
import os
from pygame import mixer
import random
import math
from classes import Game, Player

# Inicialização do pygame
pygame.init()

# Informações do monitor do usuário
os.environ['SDL_VIDEO_CENTERED'] = '1'
info = pygame.display.Info()
SCREEN_WIDTH, SCREEN_HEIGHT = info.current_w, info.current_h
SCREEN_WIDTH_OFFSET = 100
SCREEN_HEIGHT_OFFSET = 170

# Inicializa a tela
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT - 50), pygame.RESIZABLE)

# Título e Ícone
pygame.display.set_caption("DEMO Silksong")
icon = pygame.image.load('Assets/etc/icon.jpg')
pygame.display.set_icon(icon)

# FPS
FPS = 60
clock = pygame.time.Clock()

# Instancia a classe do jogo e do jogador
player = Player((SCREEN_WIDTH - SCREEN_WIDTH_OFFSET) / 2, SCREEN_HEIGHT - SCREEN_HEIGHT_OFFSET)
game = Game(screen, player)

running = True
while running:
    clock.tick(FPS)
    screen.fill((0, 0, 0))

    running = game.process_events()
    game.update()

    # Mostrar FPS
    game.render_text(str(int(clock.get_fps())), (255, 255, 255), (10, 10), 20)

    pygame.display.update()

pygame.quit()
