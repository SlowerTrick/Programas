import pygame

# Constantes para configuração do jogador
PLAYER_WIDTH = 100
PLAYER_HEIGHT = 100
JUMP_HEIGHT = 200
JUMP_SPEED = -8
MOVE_SPEED = 4

# Classe Player para gerenciar atributos e comportamento do jogador
class Player:
    def __init__(self, initialPosX, initialPosY):
        self.x = initialPosX
        self.y = initialPosY
        self.speed_x = 0
        self.speed_y = 0
        self.y_jump_init = self.y
        self.PlayerState = 'idle'
        self.AttackState = 'available'
        # Carrega e redimensiona a imagem do jogador
        self.playerImg = pygame.image.load('Assets/Hornet/chibi.jpg')
        self.playerImg = pygame.transform.scale(self.playerImg, (PLAYER_WIDTH, PLAYER_HEIGHT))
        
    def update_position(self):
        # Atualiza a posição do jogador com base na sua velocidade e estado
        self.x += self.speed_x
        if self.PlayerState == 'going_up':
            if self.y > self.y_jump_init - JUMP_HEIGHT:
                self.y += self.speed_y
            else:
                self.PlayerState = 'going_down'
                self.speed_y = -self.speed_y
            
        if self.PlayerState == 'going_down':
            if self.y < self.y_jump_init:
                self.y += self.speed_y
            else:
                self.y = self.y_jump_init
                self.PlayerState = 'idle'

    def draw(self, screen):
        # Desenha o jogador na tela
        screen.blit(self.playerImg, (self.x, self.y))

# Classe Game para gerenciar o estado e o comportamento do jogo
class Game:
    def __init__(self, screen, player):
        # Inicializa a classe "Game"
        self.screen = screen
        self.player = player
        self.keys = {'left': False, 'right': False, 'jump': False}

    def render_text(self, what, color, where, size):
        # Renderiza texto na tela
        font = pygame.font.Font('Assets/etc/RobotoMono-Bold.ttf', size)
        text = font.render(what, True, pygame.Color(color))
        self.screen.blit(text, where)

    def handle_keydown(self, event):
        # Lida com eventos de pressionamento de tecla
        if event.key in {pygame.K_a, pygame.K_LEFT}:
            self.keys['left'] = True
        if event.key in {pygame.K_d, pygame.K_RIGHT}:
            self.keys['right'] = True
        if event.key in {pygame.K_w, pygame.K_UP, pygame.K_SPACE}:
            self.keys['jump'] = True
        self.update_player_speed()

    def handle_keyup(self, event):
        # Lida com eventos de liberação de tecla
        if event.key in {pygame.K_a, pygame.K_LEFT}:
            self.keys['left'] = False
        if event.key in {pygame.K_d, pygame.K_RIGHT}:
            self.keys['right'] = False
        self.update_player_speed()

    def update_player_speed(self):
        # Atualiza a velocidade do jogador com base nas entradas do teclado
        self.player.speed_x = MOVE_SPEED if self.keys['right'] else -MOVE_SPEED if self.keys['left'] else 0

        if self.keys['jump'] and self.player.PlayerState == 'idle':
            self.player.y_jump_init = self.player.y
            self.player.speed_y = JUMP_SPEED
            self.player.PlayerState = 'going_up'
            self.keys['jump'] = False
    
    def process_events(self):
        # Processa todos os eventos do jogo 
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return False
            elif event.type == pygame.KEYDOWN:
                self.handle_keydown(event)
            elif event.type == pygame.KEYUP:
                self.handle_keyup(event)
        return True

    def update(self):
        # Atualiza o estado do jogo
        self.player.update_position()

    def draw(self):
        # Desenha todos os elementos do jogo
        self.player.draw(self.screen)
