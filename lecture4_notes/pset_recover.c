#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open file
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    BYTE* buffer = malloc(sizeof(BYTE) * BLOCK_SIZE);
    char filename[8];
    int num_jpeg = 0;
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        if (num_jpeg == 0)
        {
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                sprintf(filename, "%03i.jpg", num_jpeg);
                FILE *img = fopen(filename, "w");
                for (int i = 0; i < BLOCK_SIZE; i++)
                {
                    fwrite(&buffer[i], sizeof(BYTE), BLOCK_SIZE, img);
                }
                fclose(img);
                num_jpeg++;
            }
        }
        else
        {
            sprintf(filename, "%03i.jpg", num_jpeg);
            FILE *img = fopen(filename, "a");
            for (int i = 0; i < BLOCK_SIZE; i++)
            {
                fwrite(&buffer[i], sizeof(BYTE), BLOCK_SIZE, img);
            }
            fclose(img);
        }
    }
    fclose(raw_file);
    return 0;
}