#include <stdio.h>
#include <string.h>
typedef struct {
    int nim;
    char nama[30];
    int usia;
    char kelas[5];
    }Mahasiswa;

int main()
{   Mahasiswa A, B, C;

    //Data Mahasiswa A
    printf("\nData mahasiswa ke-1\n");
    printf("----------------------\n");

    printf("Masukkan NIM Mahasiswa ke-1:");  //NIM A
    scanf("%d", &A.nim);

    printf("Masukkan Nama Mahasiswa ke-1:");  //NAMA A
	scanf(" %[^\n]s",&A.nama);

    printf("Masukkan Usia Mahasiswa ke-1:");  //USIA A
    scanf("%d", &A.usia);

    printf("Masukkan kelas Mahasiswa ke-1: ");  //KELAS A
    scanf("%s", &A.kelas);


    //Data Mahasiswa B
    printf("\nData mahasiswa ke-2\n");
    printf("----------------------\n");

    printf("Masukkan NIM Mahasiswa ke-2:");  //NIM B
    scanf("%d", &B.nim);

    printf("Masukkan Nama Mahasiswa ke-2:");  //NAMA B
	scanf(" %[^\n]s",&B.nama);

    printf("Masukkan usia Mahasiswa ke-2:");  //USIA B
    scanf("%d", &B.usia);

    printf("Masukkan kelas Mahasiswa ke-2: ");  //KELAS B
    scanf("%s", &B.kelas);
    

    //Data Mahasiswa C
    printf("\nData mahasiswa ke-3\n");
    printf("----------------------\n");

    printf("Masukkan NIM Mahasiswa ke-3:");  //NIM C
    scanf("%d", &C.nim);

    printf("Masukkan Nama Mahasiswa ke-3:");  //NAMA C
	scanf(" %[^\n]s",&C.nama);

    printf("Masukkan usia Mahasiswa ke-3:");  //USIA C
    scanf("%d", &C.usia);

    printf("Masukkan kelas Mahasiswa ke-3:");  //KELAS C
    scanf("%s", &C.kelas);


    //Print semua biodata mahasiswa
    printf("\n");
    printf("-----Data mahasiswa-----\n");
    printf ("NIM : %d\t Nama : %s\t Usia : %d\t Kelas : %s\n", A.nim, A.nama, A.usia, A.kelas);
    printf ("NIM : %d\t Nama : %s\t Usia : %d\t Kelas : %s\n", B.nim, B.nama, B.usia, B.kelas);
    printf ("NIM : %d\t Nama : %s\t Usia : %d\t Kelas : %s\n", C.nim, C.nama, C.usia, C.kelas);
    
    return 0;
}