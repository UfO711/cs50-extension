#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(4);
    scanf("%s", s);
    printf("%s\n", s);
}