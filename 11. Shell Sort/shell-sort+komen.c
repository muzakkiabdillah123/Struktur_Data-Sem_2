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

    /*
    array = 6,7,2,1
         ____
        |   |
    (1) 6,7,2,1 => 2,7,6,1
           ____
          |   |
    (2) 2,7,6,1 => 2,1,6,7
         ___
        |  |
    (3) 2,1,6,7 => 1,2,6,7
    */

    for (h = max / 2; h > 0; h = h / 2) //(1) m=2
                                        //(2) m=1
    {
        for (j = h; j < max; j++) //(1.1) j=2
                                  //(1.2) j=3
                                  //(1.3)j=4 (end for)
                                  //(2.1) j=1
                                  //(2.2) j=2
                                  //(2.3 dst) j=3 (Selanjutnya sama aja)
        {
            for (i = j - h; i >= 0; i = i - h) //(1.1.1) i=0
                                               //(1.1.2) i=-2 (end for)
                                               //(1.2.1) i=1
                                               //(1.2.2) i=-1 (end for)
                                               //(2.1.1) i=0
                                               //(2.1.2) i=-1 (end for)
                                               //(2.2.1) i=1
                                               //(2.2.2) i=0
                                               //(2.2.3) i=-1 (end for)

            {
                if (array[i + h] < array[i]) //(1.1.1) array[2] (2)<(6) array[0] (TRUE)
                                             //(1.2.1) array[3] (1)<(7) array[1] (TRUE)
                                             //(2.1.1) array[1] (1)<(2) array[0] (TRUE)
                                             //(2.2.1) array[2] (6)<(2) array[1] (FALSE)
                                             //(2.2.2) array[1] (2)<(1) array[0] (FALSE)

                {
                    temp = array[i];
                    array[i] = array[i + h];
                    array[i + h] = temp; //(1.1.1) array[0]=2, array[2]=6 {2,7,6,1}
                                         //(1.2.1) array[1]=1, array [3]=7 {2,1,6,7}
                                         //(2.1.1) array[0]=1, array[1]=2 {1,2,6,7}
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