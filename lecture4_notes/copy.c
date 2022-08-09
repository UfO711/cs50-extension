#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) 
{
    char* s = "hi!";
    // Using malloc for coppying string
    char* t = malloc(4);
    for (int i = 0; i < 4; i++)
    {
        t[i] = s[i];
    }
    printf("%s\n", t);
    // Using strcpy() function for copy
    char tt[4];
    strcpy(tt, s);
    printf("%s\n", tt);
    // Segmentation fault, change char* tt; to char* tt = malloc(4);
    // free(tt);

}
