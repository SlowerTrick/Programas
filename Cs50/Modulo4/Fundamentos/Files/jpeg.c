#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        printf ("Uso correto: ./jpeg (imagem)\n");
        return 1;
    }

    FILE *file = fopen (argv[1], "r");
    if (!file) // (file == NULL)
    {
        return 2;
    }

    //Leitura dos 3 primeiros BYTES
    BYTE bytes[4];
    fread(bytes, sizeof(BYTE), 4, file);

    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
    {
        printf ("É um jpeg\n");
    }

    else
    {
        printf ("Não é um jpeg\n");
    }
    return 0;
}

