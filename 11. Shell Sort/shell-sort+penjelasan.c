#include <stdio.h>

#define max 4

int main()
{
    int array[max] = {6, 7, 2, 1};
    int temp, i, j, h;

    printf("Sebelum sorting: \n");

    for (i = 0; i < max; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n\nProses sorting : \n");
    for (h = max / 2; h > 0; h = h / 2)
    {
        printf("\nPengulangan pada saat h = %d\n\n", h);
        for (j = h; j < max; j++)
        {
            for (i = j - h; i >= 0; i = i - h)
            {
                if (array[i + h] < array[i])
                {
                    temp = array[i];
                    array[i] = array[i + h];
                    array[i + h] = temp;
                    printf("Array[%d] = yaitu {%d} ditukar dengan array[%d] yaitu {%d}\n", i, array[i + h], i + h, array[i]);
                    printf("Array setelah penukaran : ");
                }
                else
                {
                    printf("Urutan tetap karena array[%d] yaitu {%d} < array[%d] yaitu {%d}", i, array[i], i + h, array[i + h]);
                }
                printf("\n");
            }
            for (i = 0; i < max; i++)
            {
                printf("%d ", array[i]);
            }
            printf("\n\n");
        }
    }

    printf("\nSetelah sorting: \n");
    for (i = 0; i < max; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}