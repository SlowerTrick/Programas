#include <stdio.h>

extern int strlen(const char *str);

int main() 
{
    const char *msg = "Hello!";
    int len = strlen(msg);
    printf("Length: %d\n", len);
    return 0;
}