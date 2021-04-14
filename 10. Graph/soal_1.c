#include <stdio.h>
#include <stdlib.h>

int graph [5][5];

int i,j;
for (i = 0; i < 5; i++)
{
    for (j = 0; i < 5; i++)
    {
        printf("Masukkan value [%d][%d]", i, j);
        scanf("%d", graph[i][j]);
    }
}