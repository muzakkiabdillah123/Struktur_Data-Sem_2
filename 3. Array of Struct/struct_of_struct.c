/*Buat ADT struct titik yang terdiri dari 
Int X
Int Y
Buat ADT struct garis yang terdiri dari
Titik awal
Titik akhir
Dalam program utama (main) buat 3 garis secara sembarang yang datanya dari input keybord
*/

#include <stdio.h>
#define p printf
#define s scanf

typedef struct{
    int x;
    int y;
}titik;

typedef struct{
    titik awal;
    titik akhir;
}garis;

int main(){
    garis GARIS[3];
    int i;
    int j;
    for (i = 0 ; i<3 ; i++){
        p("Garis ke-%d\n", i+1);

        p("Masukkan koordinat x awal = ");
        s("%d",&GARIS[i].awal.x);

        p("Masukkan koordinat y awal = ");
        s("%d",&GARIS[i].awal.y);

        p("Masukkan koordinat x akhir = ");
        s("%d",&GARIS[i].akhir.x);

        p("Masukkan koordinat y akhir = ");
        s("%d",&GARIS[i].akhir.y);

        p("------------------------------\n");
    }
    for(j=0 ; j<3 ; j++){
        p("Garis ke-%d\n",j+1);
        p("Garis ke-%d dengan titik awal (%d,%d) dan titik akhir (%d,%d)\n", j+1, GARIS[j].awal.x, GARIS[j].awal.y, GARIS[j].akhir.x, GARIS[j].akhir.y);
        p("-----------------------------\n");
    }

    return 0;
}
