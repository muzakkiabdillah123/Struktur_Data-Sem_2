#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct element
{
    int id;
    char nama[20];
    long int harga;
    struct element * next;
}element;

element *createlist(int id,char nama[20],long int harga)
{
    element *newelement = NULL;
    newelement = (element*) malloc (sizeof(element));
    newelement->id = id;
    strcpy(newelement->nama,nama);
    newelement->harga = harga;
    newelement->next = NULL;
    return newelement;
}

void addAwal(int id, char nama[20], long int harga,element **myList) // dua bintang (**) untuk add awal (untuk mengakses alamat myList)
{
    element * newlist = createlist(id,nama,harga);  //buat newlist
    newlist->next = (*myList);      //nextAlamat (next) dari newlist jadi mengarah ke elemen pertama (yang sudah ada)
    (*myList) = newlist;            //elemen pertama jadi newlist tadi (elemen pertama jadi elemen kedua)
    newlist = NULL;                 //newlist sudah tidak dibutuhkan jadi NULL
}

void addTengah(int id,char nama[20], long int harga, int a, element *myList)
{
    element * newlist = createlist(id,nama,harga);  //buat newlist
    element * temp = NULL;          //buat variabel temp untuk muter"
    temp = myList;                  //temp nyari di myList
    while (temp->id !=a) {          //temp bakal muter sampe ada yang id-nya = a
        temp = temp->next;          //temp akan maju ke next untuk muter"tadi
    }
    newlist->next = temp->next;     //nextalamat(next) dari newlist jadi mengarah ke nextalamat (next) dari temp, yaitu elemen setelah elemen yang punya id = a
    temp->next = newlist;           //nextalamat dari temp mengarah ke elemen baru
    newlist = NULL;                 //newlist sudah tidak dibutuhkan jadi NULL
}

void addAkhir (int id, char nama[20],long int harga,element*myList)
{
    element * newlist = createlist(id,nama,harga);  //hampir sama kayak addTengah
    element * temp = NULL;
    temp = myList;
    while(temp->next!=NULL) {       //bedanya, temp nyari sampai nextAlamat-nya NULL
        temp = temp->next;
    }
    temp->next = newlist;           //nextAlamat dari temp (yang berarti elemen terakhir) jadi newlist
    newlist = NULL;                 //null
}

void printlist(element * myList)
{
    element * temp = myList;
    do{
        printf("Produk %d \n%s \n%d \n",temp->id, temp->nama, temp->harga);
        printf("---------------------\n");
        temp = temp->next;
    } while (temp!=NULL);
}

int main()
{
    element*produk;
    int id;
    char nama[20];
    int harga;

    for (int i= 1; i<=5 ; i++) 
    {
        if (i==1) {
            printf("1.Element pertama dalam list\n");
            //createlist dibawah
        } else if (i==2){
            printf("2.Add element diawal\n");
            addAwal(2,nama,harga,&produk);
        } else if (i==3) {
            printf("3.Add element diakhir\n");
            addAkhir(10,nama,harga,produk);
        } else if (i==4) {
            printf("4.Add element diawal\n");
            addAwal(1,nama,harga,&produk);
        } else if (i==5) {
            printf("5.Add element setelah id produk : 8\n");
            addTengah(9,nama,harga,8,produk);
        }

        printf("Masukkan id produk : ");
        scanf("%d",&id);
        printf("Masukkan nama produk : ");
        scanf(" %[^\n]%*c",nama);
        printf("Masukkan harga produk : ");
        scanf("%d", &harga);
        printf("---------------------------\n");

        if (i==1) {
            produk= createlist(8,nama,harga);
        }
    }
    
    printf("List Produk Toko : \n");
    printlist(produk);
}