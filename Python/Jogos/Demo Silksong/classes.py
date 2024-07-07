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

    def get_tile_size(self):
        return self.TILE_SIZE

    def get_grid_dimensions(self):
        return self.GRID_WIDTH, self.GRID_HEIGHT

# Classe Player para gerenciar atributos e comportamento do jogador
class Player:
    def __init__(self, initialPosX, initialPosY):
        self.x = initialPosX
        self.y = initialPosY - 300
        self.speed_x = 0
        self.speed_y = 0
        self.hit_box = pygame.Rect(self.x, self.y, PLAYER_WIDTH, PLAYER_HEIGHT)
        self.on_ground = False
        # Carrega e redimensiona a imagem do jogador
        self.playerImg = pygame.image.load('Assets/Hornet/chibi.jpg')
        self.playerImg = pygame.transform.scale(self.playerImg, (PLAYER_WIDTH, PLAYER_HEIGHT))
        
    def update_position(self):
        # Atualiza a posição horizontal do jogador com base na sua velocidade
        self.x += self.speed_x

        # Aplicar gravidade
        if not self.on_ground:
            self.speed_y += GRAVITY
            
        self.y += self.speed_y

        # Atualiza a posição da hitbox
        self.hit_box.topleft = (self.x, self.y)

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
        if self.keys['right']:
            self.player.speed_x = MOVE_SPEED
        elif self.keys['left']:
            self.player.speed_x = -MOVE_SPEED
        else:
            self.player.speed_x = 0

        # Verificação do pulo do jogador
        if self.keys['jump'] and self.player.on_ground:
            self.player.speed_y = JUMP_SPEED
            self.player.on_ground = False
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
        # Atualiza a posição do jogador
        self.player.update_position()

        # Verificação da colisão com as plataformas
        self.player.on_ground = False
        print (self.player.speed_y)
        for p in self.tile_list:
            if self.player.hit_box.colliderect(p):
                if (self.player.speed_y > 0):
                    self.player.y = p.top - PLAYER_HEIGHT
                    self.player.speed_y = GRAVITY
                    self.player.on_ground = True
                    break
                if (self.player.speed_y < 0):
                    self.player.y = p.bottom
                    self.player.speed_y = GRAVITY
                    self.player.on_ground = False
                    break

        # Atualiza a posição da hitbox após ajustar a posição do jogador
        self.player.hit_box.topleft = (self.player.x, self.player.y)

    def draw(self):
        # Desenha todos os elementos do jogo
        self.player.draw(self.screen)
        for p in self.tile_list:
            pygame.draw.rect(self.screen, (255, 255, 255), p)
    
    def draw_grid(self):
        for line in range(self.info.GRID_HEIGHT + 1):
            pygame.draw.line(self.screen, (255, 255, 255), (0, line * self.info.TILE_SIZE), (self.info.SCREEN_WIDTH, line * self.info.TILE_SIZE))
        for line in range(self.info.GRID_WIDTH + 1):
            pygame.draw.line(self.screen, (255, 255, 255), (line * self.info.TILE_SIZE, 0), (line * self.info.TILE_SIZE, self.info.SCREEN_HEIGHT))
