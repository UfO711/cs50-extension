#include <stdio.h>

int main(void)
{
    int a[] = {1,2,3,4,6};
    int temp;
    int swap_counter = -1;
    for (int i = 0; i < 4 && swap_counter != 0; i++)
    {
        swap_counter = 0;
        for (int j = 0; j < 4 - i; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swap_counter++;
                printf("%d\n", swap_counter);
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}