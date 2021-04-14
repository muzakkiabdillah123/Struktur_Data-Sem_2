/*Buat ADT struct titik yang terdiri dari 
Int X
Int Y
Buat ADT struct bidang yang terdiri dari
Array Titik yang membangun bidang tersebut
Dalam program utama (main) buat 2 bidang secara sembarang yang datanya dari input keybord
*/

#include <stdio.h>
#define p printf
#define s scanf

typedef struct{
    int x;
    int y;
}titik;

typedef struct{
    titik TITIK[50];
}bidang;

int main(){
    bidang BIDANG[2];
    int jumlahTitik;
    int i;
    int j;
    int k;

    for(i= 0; i<2; i++){
        p("Bidang ke %d\n", i+1);
        p("Masukkan jumlah titik yang ingin digunakan = ");
        s("%d", &jumlahTitik);
        p("Jumlah titik adalah %d\n", jumlahTitik);
        p("--------------------\n");

        for(j=0; j<jumlahTitik; j++){
            p("Masukkan koordinat x ke %d = ", j+1);
            s("%d", &BIDANG[i].TITIK[j].x);
            p("Masukkan koordinat y ke %d = ", j+1);
            s("%d", &BIDANG[i].TITIK[j].y);
            p("-----------------------\n");
        }
        p("Bidang ke-%d\n", i+1);
        for(k=0; k<jumlahTitik; k++){
            p("Titik ke %d adalah (%d,%d)\n", k+1, BIDANG[i].TITIK[k].x, BIDANG[i].TITIK[k].y);
        }
        p("-----------------------\n");
    }
    
    return 0;
}