// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int CABECALHO = 44;

typedef uint8_t BYTE;
typedef int16_t DOISBYTES;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Uso correto: ./volume input.wav output.wav fator\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Arquivo não encontrado.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Arquivo não encontrado.\n");
        return 1;
    }

    float fator = atof(argv[3]);

    // TODO: Copy header from input file to output file

    BYTE buffer1[CABECALHO];
    fread(&buffer1, sizeof(BYTE), CABECALHO, input);
    fwrite(&buffer1, sizeof(BYTE), CABECALHO, output);

    // TODO: Read samples from input file and write updated data to output file

    DOISBYTES buffer2;

    while (fread(&buffer2, sizeof(DOISBYTES), 1, input))
    {
        buffer2 *= fator;
        fwrite(&buffer2, sizeof(DOISBYTES), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
