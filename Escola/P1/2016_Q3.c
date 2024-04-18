#include <stdio.h>
#include <ctype.h>

int is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int is_consonant(char c) {
    return isalpha(c) && !is_vowel(c);
}

int main() {
    char codigo[5];
    int i;

    scanf("%s", codigo);

    if (isupper((unsigned char)codigo[0]) && isdigit((unsigned char)codigo[1]) && is_vowel(codigo[2]) && is_consonant(codigo[3]) && islower((unsigned char)codigo[3])) {
        for(i = 0; i < 4; i++) {
            codigo[i] = toupper((unsigned char)codigo[i]);
        }
        printf("%s\n", codigo);
    } else {
        printf("Invalido\n");
    }

    return 0;
}