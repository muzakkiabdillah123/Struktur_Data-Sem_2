#include <stdio.h>

int jumlah(int A){
    int i, n=0;
    for(i=0;i<=A;i++){
        n=n+1;
    }
        printf("%d", n);
        return n;
}

int main(){
    int  A, total;
    scanf("%d",&A);
    total = jumlah(A);
    return 0;
}