#include <stdio.h>
int main(){
    
    /*Array usia*/
    int usia[8] = {19,20,21,21,20,19,20,20};

    /*Print array usia*/
    printf("Daftar Usia {%d %d %d %d %d %d %d %d} \n", usia[0], usia[1], usia[2], usia[3], usia[4], usia[5], usia[6], usia[7]);
    printf("\n");
    
    /*Array nama versi 1*/
    char *nama[13] = {"Muhammad", "Rizal", "Rifky", "Sri", "Mulky", "Meggy", "Aulia", "Andika", "Tika", "Gina", "Umar", "Ihsan", "Tika"};
    
    /*Print array nama versi 1 (lurus)*/
    printf("Daftar nama berdasarkan posisi duduk:\n%s %s %s %s %s %s %s %s %s %s %s %s %s \n", nama[0], nama[1], nama[2], nama[3], nama[4], nama[5], nama[6], nama[7], nama[8], nama[9], nama[10], nama[11], nama[12]);
    printf("\n");

    /*Array nama versi 2*/
    char kursi[16][10] = {"Muhammad,", "Rizal   ,", "Rifky,", "Sri,", "Mulky   ,", "Meggy   ,", "Aulia,", "   ", ",       ,", "Andika  ,", "Tika  ,", "Gina", "Umar    ,", "Ihsan   ,", "     ,", "Tika"};
    
    /*Print array nama versi 2 (matriks)*/
    printf("Daftar nama berdasarkan posisi duduk:\n");
    printf("%s %s %s %s \n", kursi[0], kursi[1], kursi[2], kursi[3]);
    printf("%s %s %s %s \n", kursi[4], kursi[5], kursi[6], kursi[7]);
    printf("%s %s %s %s \n", kursi[8], kursi[9], kursi[10], kursi[11]);
    printf("%s %s %s %s \n", kursi[12], kursi[13], kursi[14], kursi[15]);

    return 0;
}