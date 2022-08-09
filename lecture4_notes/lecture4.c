#include <stdio.h>
int main(void)
{
    int n = 50;
    int* p;
    p = &n;
    printf("%p\n", p);
    // 0x7ffee9d6b85c
    printf("%p\n", &n);
    // 0x7ffee9d6b85c
    // printf("%d\n", &n);
    // warning
    char* s = "hi!";
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
    printf("%c\n", *(s + 3));
    printf("%c\n", *(s + 4));

    int number[] = {8, 3 ,2, 1};
    printf("%i\n", *number);


}