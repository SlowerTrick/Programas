import pygame

# Classe do player
class Player:
    def __init__(self, initialPosX, initialPosY):
        self.x = initialPosX
        self.y = initialPosY
        self.speed_x = 0
        self.speed_y = 0
        self.PlayerState = 'idle'
        self.AttackState = 'available'
        self.playerImg = pygame.image.load('Assets/Hornet/chibi.jpg')
        self.playerImg = pygame.transform.scale(self.playerImg, (100, 100))

    def update_position(self):
        self.x += self.speed_x
        self.y += self.speed_y

    def draw(self, screen):
        # Desenha o jogador como um quadrado branco, por exemplo
        screen.blit(self.playerImg, (self.x, self.y))

# Classe do jogo
class Game:
    def __init__(self, screen, player):
        self.screen = screen
        self.player = player
        self.keys = {'left': False, 'right': False, 'jump': False}

    def render_text(self, what, color, where, size):
        font = pygame.font.Font('Assets/etc/RobotoMono-Bold.ttf', size)
        text = font.render(what, 1, pygame.Color(color))
        self.screen.blit(text, where)

    def handle_keydown(self, event):
        if event.key == pygame.K_a or event.key == pygame.K_LEFT:
            self.keys['left'] = True
        if event.key == pygame.K_d or event.key == pygame.K_RIGHT:
            self.keys['right'] = True
        if event.key == pygame.K_w or event.key == pygame.K_UP or event.key == pygame.K_SPACE:
            self.keys['right'] = True
        self.update_player_speed()

    def handle_keyup(self, event):
        if event.key == pygame.K_a or event.key == pygame.K_LEFT:
            self.keys['left'] = False
        if event.key == pygame.K_d or event.key == pygame.K_RIGHT:
            self.keys['right'] = False
        self.update_player_speed()

    def update_player_speed(self):
        if self.keys['left'] and not self.keys['right']:
            self.player.speed_x = -4
        elif self.keys['right'] and not self.keys['left']:
            self.player.speed_x = 4
        else:
            self.player.speed_x = 0
    
    def process_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return False
            elif event.type == pygame.KEYDOWN:
                self.handle_keydown(event)
            elif event.type == pygame.KEYUP:
                self.handle_keyup(event)
        return True

    def update(self):
        self.player.update_position()
        self.player.draw(self.screen)
