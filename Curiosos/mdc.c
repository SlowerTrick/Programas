#include <stdio.h>

int calcula_mdc(int x, int y)
{
    return y == 0 ? x : calcula_mdc(y, x % y);
}

int main(int argc, char **argv)
{
    int n1, n2;
    sscanf(argv[1], "%d", &n1);
    sscanf(argv[2], "%d", &n2);
    printf("mdc: %d\n", calcula_mdc(n1, n2));
    return 0;
}
