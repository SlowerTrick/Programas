#include <stdio.h>

int main() {
    const int x = 2;
    const int y = 4;
    int valores_x[] = {1, 2};
    int valores_y[] = {5, 6, 7, 8};

    int array_x[y];
    int array_y[y];

    for (int i = 0; i < y; i++) {
        if (i < x) 
        {
            array_x[i] = 0;
        } else {
            array_x[i] = valores_x[i - x];
        }
        array_y[i] = valores_y[i];
    }

    printf("Array x final: ");
    for (int i = 0; i < y; i++) {
        printf("%d ", array_x[i]);
    }
    printf("\n");

    printf("Array y final: ");
    for (int i = 0; i < y; i++) {
        printf("%d ", array_y[i]);
    }
    printf("\n");

    return 0;
}