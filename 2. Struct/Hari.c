#include <stdio.h>
#include <string.h>
typedef struct {
    char hari[20];
    int tanggal;
    int bulan;
    int tahun;
    }dateTime;

int main()
{   dateTime Yesterday;
    dateTime Today;
    dateTime Tomorrow;

    strcpy(Yesterday.hari, "Senin");
    Yesterday. tanggal = 8;
    Yesterday.bulan = 2;
    Yesterday.tahun = 2020;

    strcpy(Today.hari, "Selasa");
    Today. tanggal = 9;
    Today.bulan = 2;
    Today.tahun = 2020;

    strcpy(Tomorrow.hari, "Rabu");
    Tomorrow. tanggal = 10;
    Tomorrow.bulan = 2;
    Tomorrow.tahun = 2020;

    printf("--Kemarin--\n");
    printf ("Hari %s, Tanggal %d-%d-%d\n", Yesterday.hari, Yesterday.tanggal, Yesterday.bulan, Yesterday.tahun);
    printf("\n--Hari ini--\n");
    printf ("Hari %s, Tanggal %d-%d-%d\n", Today.hari, Today.tanggal, Today.bulan, Today.tahun);
    printf("\n--Besok--\n");
    printf ("Hari %s, Tanggal %d-%d-%d\n", Tomorrow.hari, Tomorrow.tanggal, Tomorrow.bulan, Tomorrow.tahun);
    return 0;
}