import pygame

# Constantes para configuração do jogador
PLAYER_WIDTH = 80
PLAYER_HEIGHT = 80
JUMP_SPEED = -14
MOVE_SPEED = 4
GRAVITY = 0.5
ACCELERATION = 0.1

# Armazena diversas informações para o melhor funcionamento do jogo
class Info:
    def __init__(self, WIDTH, HEIGHT, WIDTH_OFFSET, HEIGHT_OFFSET):
        self.SCREEN_WIDTH = WIDTH 
        self.SCREEN_HEIGHT = HEIGHT
        self.SCREEN_WIDTH_OFFSET = WIDTH_OFFSET
        self.SCREEN_HEIGHT_OFFSET = HEIGHT_OFFSET
        self.GRID_WIDTH = 30
        self.TILE_SIZE = WIDTH // self.GRID_WIDTH
        self.GRID_HEIGHT = int(HEIGHT / self.TILE_SIZE)

# Classe Player para gerenciar atributos e comportamento do jogador
class Player:
    def __init__(self, initialPosX, initialPosY):
        self.x = initialPosX
        self.y = initialPosY - 300
        self.speed_x = 0
        self.speed_y = 0
        self.on_ground = False
        self.hit_box = pygame.Rect(self.x, self.y, PLAYER_WIDTH, PLAYER_HEIGHT)
        # Carrega e redimensiona a imagem do jogador
        self.playerImg = pygame.image.load('Assets/Hornet/chibi.jpg')
        self.playerImg = pygame.transform.scale(self.playerImg, (PLAYER_WIDTH, PLAYER_HEIGHT))

    def update_position(self, tile_list, keys):

        # Gravidade e Aceleração do jogador
        self.speed_y += GRAVITY
        if keys['right']:
            self.speed_x += ACCELERATION
        elif keys['left']:
            self.speed_x -= ACCELERATION
        else:
            if self.speed_x != 0 and self.speed_x > 0:
                self.speed_x -= 0.25
            if self.speed_x != 0 and self.speed_x < 0:
                self.speed_x += 0.25  

        if self.speed_x > 7:
            self.speed_x = 7
        elif self.speed_x < -7:
            self.speed_x = -7   
        elif -0.25 < self.speed_x < 0.25:
            self.speed_x = 0

        # Verificação das colisões
        new_player_x = self.x
        new_player_x += self.speed_x
        new_player_y = self.y
        new_player_rect = pygame.Rect(new_player_x, new_player_y, PLAYER_WIDTH, PLAYER_HEIGHT)

        x_collision = False
        for tile in tile_list:
            if tile.colliderect(new_player_rect):
                x_collision = True
                break
        
        if not x_collision:
            self.x = new_player_x
            self.hit_box = pygame.Rect(self.x, self.y, PLAYER_WIDTH, PLAYER_HEIGHT)
        
        self.on_ground = False
        new_player_x = self.x
        new_player_x += self.speed_x
        new_player_y = self.y
        new_player_y += self.speed_y
        new_player_rect = pygame.Rect(new_player_x, new_player_y, PLAYER_WIDTH, PLAYER_HEIGHT)
        
        y_collision = False
        for tile in tile_list:
            if tile.colliderect(new_player_rect):
                # Faz o player sempre ficar imediatamente a cima da plataforma
                if tile[1] > new_player_y:
                    self.y = tile[1] - PLAYER_HEIGHT
                y_collision = True
                self.speed_y = GRAVITY
                self.on_ground = True
                break
        
        if not y_collision:
            self.y = new_player_y
            self.hit_box = pygame.Rect(self.x, self.y, PLAYER_WIDTH, PLAYER_HEIGHT)
    
    def update_speed(self, keys):
        # Atualiza a velocidade do jogador com base nas entradas do teclado
        if keys['right']:
            self.speed_x = MOVE_SPEED
        elif keys['left']:
            self.speed_x = -MOVE_SPEED

        # Verificação do pulo do jogador
        if keys['jump'] and self.on_ground:
            self.speed_y = JUMP_SPEED
            keys['jump'] = False

    def draw(self, screen):
        # Desenha o jogador na tela
        screen.blit(self.playerImg, (self.x, self.y))

# Classe Game para gerenciar o estado e o comportamento do jogo
class Game:
    def __init__(self, screen, player, info, data):
        # Inicializa a classe "Game"
        self.screen = screen
        self.player = player
        self.info = info
        self.keys = {'left': False, 'right': False, 'jump': False}

        self.tile_list = []
        row_count = 0
        for row in data:
            col_count = 0
            for tile in row:
                if tile == 1:
                    img_rect = pygame.Rect(col_count * self.info.TILE_SIZE, row_count * self.info.TILE_SIZE, self.info.TILE_SIZE, self.info.TILE_SIZE)
                    self.tile_list.append(img_rect)
                col_count += 1
            row_count += 1

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
        self.player.update_speed(self.keys)

    def handle_keyup(self, event):
        # Lida com eventos de liberação de tecla
        if event.key in {pygame.K_a, pygame.K_LEFT}:
            self.keys['left'] = False
        if event.key in {pygame.K_d, pygame.K_RIGHT}:
            self.keys['right'] = False
        self.player.update_speed(self.keys)

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
    
    def draw(self):
        # Desenha todos os elementos do jogo
        self.player.draw(self.screen)
        # pygame.draw.rect(self.screen, (255, 0, 0), self.player.hit_box, 2) # HitBox Player
        for p in self.tile_list:
            pygame.draw.rect(self.screen, (255, 255, 255), p)
            # pygame.draw.rect(self.screen, (255, 0, 0), p, 2) # HitBox plataformas
    
    def draw_grid(self):
        for line in range(self.info.GRID_HEIGHT + 1):
            pygame.draw.line(self.screen, (255, 255, 255), (0, line * self.info.TILE_SIZE), (self.info.SCREEN_WIDTH, line * self.info.TILE_SIZE))
        for line in range(self.info.GRID_WIDTH + 1):
            pygame.draw.line(self.screen, (255, 255, 255), (line * self.info.TILE_SIZE, 0), (line * self.info.TILE_SIZE, self.info.SCREEN_HEIGHT))
