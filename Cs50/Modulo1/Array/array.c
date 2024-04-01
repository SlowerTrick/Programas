#include <cs50.h>
#include <stdio.h>

int main (void)
{

    string s = get_string ("INPUT:  ");
    printf ("OUTPUT: ");
    for (int i = 0; s[i] != '\0'; i++)
    {
        printf ("%c", s[i]);
    }
    printf ("\n");
}
