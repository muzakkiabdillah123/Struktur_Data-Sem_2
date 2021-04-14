#include<stdio.h>
#include<stdlib.h>
int main(){
    int  *b;
    b = (int*) malloc(sizeof(int));
    scanf("%d", b);
    printf("%d \n", *b);
    printf("%d", b);
    return 0;
}