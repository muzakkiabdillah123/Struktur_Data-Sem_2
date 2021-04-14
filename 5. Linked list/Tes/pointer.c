#include<stdio.h>
void jumlah(int *A, int B){
    *A = *A+B;              //A akan berisi nilai di A + B
}
int main(){
    int A, B;
    scanf("%d %d", &A, &B);
    jumlah(&A,B);
    printf("%d %d", A, B);
    return 0;
}