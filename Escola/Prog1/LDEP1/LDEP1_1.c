#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const *argv[])
{
    int a = 0, b = 0, c = 0, d = 0;
	scanf("%i", &d);

    while(a < d)
    {
        scanf("%i %i", &b, &c);
        printf("%d\n", b + c);
        a++;
    }

    return 0;
}
