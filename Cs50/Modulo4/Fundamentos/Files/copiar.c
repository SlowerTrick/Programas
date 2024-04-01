#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main (int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Uso correto: ./copiar (Arquivo de destino)\n"); //stderr = standard erroriu
        return 1;
    }
    FILE *fonte = fopen(argv[1], "r");
    if (!fonte)
    {
        printf ("Não foi possivel abrir %s\n", argv[1]);
        return 2;
    }

    FILE *destino = fopen(argv[2], "w");
    if (!destino)
    {
        fclose(fonte);
        printf ("Não foi possivel abrir %s\n", argv[2]);
        return 3;
    }

    // copia a fonte no destino, um Byte de cada vez
    BYTE buffer;
    while (fread(&buffer, sizeof(BYTE), 1, fonte))
    {
        fwrite(&buffer, sizeof(BYTE), 1, destino);
    }

    //fechar arquivos
    fclose (fonte);
    fclose (destino);
    return 0;
}
