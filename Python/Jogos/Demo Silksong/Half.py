import pygame

# Constantes para configuração do jogador
PLAYER_WIDTH = 80
PLAYER_HEIGHT = 80
JUMP_SPEED = -14
MOVE_SPEED = 4
GRAVITY = 0.5

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
        self.hit_box = pygame.Rect(self.x, self.y, PLAYER_WIDTH, PLAYER_HEIGHT)
        self.on_ground = False
        self.hitting_wall = False
        # Carrega e redimensiona a imagem do jogador
        self.playerImg = pygame.image.load('Assets/Hornet/chibi.jpg')
        self.playerImg = pygame.transform.scale(self.playerImg, (PLAYER_WIDTH, PLAYER_HEIGHT))
        
    def update_position(self):
        # Atualiza a posição horizontal do jogador com base na sua velocidade
        if not self.hitting_wall:
            self.x += self.speed_x

        # Aplicar gravidade
        if not self.on_ground:
            self.speed_y += GRAVITY
            
        self.y += self.speed_y

        # Atualiza a posição da hitbox
        self.hit_box.topleft = (self.x, self.y)
    
    def update_collision(self, tile_list):
        # Atualiza a posição do jogador
        self.update_position()

        # Verificação da colisão com as plataformas
        self.on_ground = False
        for tile in tile_list:
            if self.hit_box.colliderect(tile):
                if self.speed_y > 0:
                    self.y = tile.top - PLAYER_HEIGHT
                    self.speed_y = GRAVITY
                    self.on_ground = True
                    
                if self.speed_y < 0:
                    self.y = tile.bottom
                    self.speed_y = GRAVITY
                    break

        # Atualiza a posição da hitbox após ajustar a posição do jogador
        self.hit_box.topleft = (self.x, self.y)

        for tile in tile_list:
            if self.hit_box.colliderect(tile):
                if self.speed_x > 0:  # Movendo-se para a direita
                    self.x = tile.left - PLAYER_WIDTH
                elif self.speed_x < 0:  # Movendo-se para a esquerda
                    self.x = tile.right

    def update_speed(self, keys):
        # Atualiza a velocidade do jogador com base nas entradas do teclado
        if keys['right']:
            self.speed_x = MOVE_SPEED
        elif keys['left']:
            self.speed_x = -MOVE_SPEED
        else:
            self.speed_x = 0

        # Verificação do pulo do jogador
        if keys['jump'] and self.on_ground:
            self.speed_y = JUMP_SPEED
            self.on_ground = False
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
        # pygame.draw.rect(self.screen, (255, 0, 0), self.player.hit_box, 2) "HitBox Player"
        for p in self.tile_list:
            pygame.draw.rect(self.screen, (255, 255, 255), p)
            # pygame.draw.rect(self.screen, (255, 0, 0), p, 2) "HitBox plataformas"
    
    def draw_grid(self):
        for line in range(self.info.GRID_HEIGHT + 1):
            pygame.draw.line(self.screen, (255, 255, 255), (0, line * self.info.TILE_SIZE), (self.info.SCREEN_WIDTH, line * self.info.TILE_SIZE))
        for line in range(self.info.GRID_WIDTH + 1):
            pygame.draw.line(self.screen, (255, 255, 255), (line * self.info.TILE_SIZE, 0), (line * self.info.TILE_SIZE, self.info.SCREEN_HEIGHT))