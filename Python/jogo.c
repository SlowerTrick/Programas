#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Player;

void move(Player *player, char direction) {
    switch (direction) {
        case 'd':
            player->x += 1;
            break;
        case 'a':
            player->x -= 1;
            break;
        case 'w':
            player->y -= 1;
            break;
        case 's':
            player->y += 1;
            break;
    }
}

int main() {
    Player player = {0, 0};
    char direction;

    while (1) {
        system("clear");
        printf("____________________________________________\n");
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 10; x++) {
                if (player.x == x && player.y == y) {
                    printf("P");
                } else {
                    printf("G");
                }
            }
            printf("\n");
        }
        printf("____________________________________________\n");
        printf("Next direction (w,s,d,a): ");
        scanf(" %c", &direction);  // The space before %c is to skip any whitespace characters
        move(&player, direction);
    }

    return 0;
}