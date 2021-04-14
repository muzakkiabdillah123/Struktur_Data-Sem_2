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
    temp->next = newlist;           //nestalamat dari newlist mengarah ke elemen baru
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
        //printf("---------------------\n");
        temp = temp->next;
    } while (temp!=NULL);
}

int main(){
    element*produk;

    produk=createlist(8,"Mie Instan",3200);
    addAwal(2,"Sabun Cuci",23200,&produk);
    addAkhir(10,"Kecap",8700,produk);
    addAwal(1,"Mie Instan",3200,&produk);
    addTengah(9,"Kopi",7600,8,produk);

    printf("List Produk Toko : \n");
    printlist(produk);
}