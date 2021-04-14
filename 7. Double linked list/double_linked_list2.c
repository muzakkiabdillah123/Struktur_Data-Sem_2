#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//struct list
typedef struct list{
	int nilai;
	struct list *next;
	struct list *prev;
}list;

//fungsi add list
list *addList (int Nilai){
	list *listBaru = NULL;
	listBaru = (list*) malloc (sizeof(list));
	listBaru->nilai = Nilai;
	listBaru->next = NULL;
	listBaru->prev = NULL;
	return listBaru;
}

//prosedur add awal
void addAwal(int Nilai, list **listProduk){
	list *newList = addList(Nilai);
	newList -> next = (*listProduk);
	(*listProduk) = newList;
	(*listProduk)-> prev = newList;
	newList = NULL;
}

//prosedur add tengah
void addTengah (int nilai, int B, list *myList)
{
	list * newNode = addList (nilai);
	list * temp = NULL;
	temp = (myList);
	while (temp -> nilai!=B){
		temp = temp -> next;
	}
	newNode -> next = temp->next;
	newNode -> prev = temp;
	temp-> next ->prev = newNode;
	temp -> next = newNode;
	temp = NULL;
	newNode=NULL;
}
// void addTengah(int Nilai, int a, list *listProduk)
// {
// 	list *newList = addList(Nilai);
// 	list *cek = NULL;
// 	cek = (listProduk);
// 	while(cek->nilai != a){
// 		cek = cek->next;
// 	}
// 	newList -> prev = cek->prev;
// 	newList -> next = cek;
// 	cek -> prev = newList;
// 	cek ->prev->next = newList;
// 	newList = NULL;
// }
	
//prosedur add akhir
void addAkhir(int Nilai, list *listProduk)
{
	list *newList = addList(Nilai);
	list *cek = NULL;
	cek = (listProduk);
	while(cek->next != NULL){
		cek = cek->next;
	}
	cek -> next = newList;
	newList->prev = cek -> next;
	newList = NULL;
}

//prosedur menampilkan hasil
void show(list *listProduk){
	list *cek = listProduk;
	do{
		printf("Nilai %d\n", cek->nilai);
		cek = cek->next;
	}while(cek!= NULL);
}

int main()
{
	list *nilainya;
	printf("List Nilai : \n");
	nilainya=addList(10);
	addAwal(7, &nilainya);
	addAkhir(5, nilainya);
	addTengah(12,10, nilainya);
	show(nilainya);
	return 0;
}
