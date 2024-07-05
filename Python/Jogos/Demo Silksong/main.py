import pygame
import os
from classes import Game, Player

# Inicializa o Pygame
pygame.init()

# Obtém informações do monitor do usuário e define o tamanho da tela
os.environ['SDL_VIDEO_CENTERED'] = '1'
info = pygame.display.Info()
SCREEN_WIDTH, SCREEN_HEIGHT = info.current_w, info.current_h
SCREEN_WIDTH_OFFSET = 100
SCREEN_HEIGHT_OFFSET = 170

# Cria a janela do jogo
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT - 50), pygame.RESIZABLE)

# Define o título e o ícone do jogo
pygame.display.set_caption("DEMO Silksong")
icon = pygame.image.load('Assets/etc/icon.jpg')
pygame.display.set_icon(icon)

# Configura a taxa de quadros por segundo (FPS)
FPS = 60
clock = pygame.time.Clock()

# Instancia o jogador e o jogo
player = Player((SCREEN_WIDTH - SCREEN_WIDTH_OFFSET) / 2, SCREEN_HEIGHT - SCREEN_HEIGHT_OFFSET)
game = Game(screen, player)

# Loop principal do jogo
running = True
while running:
    clock.tick(FPS)
    screen.fill((0, 0, 0))  # Limpa a tela com a cor preta

    running = game.process_events()  # Processa os eventos
    game.update()  # Atualiza o estado do jogo
    game.draw()  # Desenha os elementos do jogo

    # Exibe o FPS no canto superior esquerdo
    game.render_text(str(int(clock.get_fps())), (255, 255, 255), (10, 10), 20)

    pygame.display.update()  # Atualiza a tela
