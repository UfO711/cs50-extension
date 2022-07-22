#include <stdio.h>

int main(void)
{
    // Less efficient
    int a[] = {6,4,3,1,2};
    int min;
    // Notice: i < 5 or i < 4 does not make any difference, because when i < 5, in the last iteration, i = 4, and j = 5 so the inner for loop will break immediately
    for (int i = 0; i < 5; i++)
    {
        min = a[i];
        for (int j = i + 1; j < 5; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                a[j] = a[i];
                a[i] = min;
            }
        }
        
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Some improvement
    // This variation search the minimum element's index and swap outside the inner for loop. By doing so, it swaps only once a time in each iteration under the big for loop
    int b[] = {6,4,3,1,2};
    int min_index;
    for (int i = 0; i < 5; i++)
    {
        min_index = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (b[min_index] > b[j])
            {
                min_index = j;
            }
        }
        // Notice: it is outside the inner for loop
        int temp;
        temp = b[min_index];
        b[min_index] = b[i];
        b[i] = temp;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}