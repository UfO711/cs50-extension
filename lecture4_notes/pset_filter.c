#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int* i = malloc(3);
    i[0] = 1;
    i[1] = 2;
    i[2] = 3;
    i[3] = 4;
    printf("%lu\n", sizeof(int));
}