#include <stdio.h>

void bilangan(int A){
    if (A%2==0){
        printf("Bilangan Genap");
    }else{
        printf("Bilangan ganjil");
    }
}
int main(){
    int A;
    scanf("%d",&A);
    bilangan(A);
    return 0;
}