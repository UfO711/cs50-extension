#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char letter;
    struct node * next;
}
node;

int main(void)
{
    // node *letter_variable;
    node *letter_malloc = malloc(sizeof(node));

    letter_malloc->letter = 'a';
    // letter_variable->letter = 'b';

    printf("%c\n", letter_malloc->letter);
    // printf("%c\n", letter_variable->letter);

    int arr[] = {3, 4 , 1};
    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n", arr[2]);
    printf("%d\n", arr[3]);
    free(letter_malloc);
}