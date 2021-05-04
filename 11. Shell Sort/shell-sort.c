#include <stdio.h>

#define max 4

int main()
{
    int array[max] = {6, 7, 2, 1};
    int temp, i, j, h, l;

    printf("Sebelum sorting: \n");

    for (i = 0; i < max; i++)
    {
        printf("%d ", array[i]);
    }

    for (h = max / 1; h > 0; h = h / 2)
    {
        for (j = h; j < max; j++)
        {
            for (i = j - h; i >= 0; i = i - h)

            {
                if (array[i + h] < array[i])

                {
                    temp = array[i];
                    array[i] = array[i + h];
                    array[i + h] = temp;
                }
            }
        }
    }

    printf("\nSetelah sorting: \n");
    for (i = 0; i < max; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}