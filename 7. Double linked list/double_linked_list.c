#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef  struct element{
	int nilai;
	struct element * prev;
	struct element * next;
}element;
element * creatElement(int nilai){
	element * eBaru;
	eBaru = (element*) malloc (sizeof(element));
	eBaru->nilai = nilai;
	eBaru->next = NULL;
	eBaru->prev = NULL;
	return eBaru;
}

void addFirst(int nilai, element **myList){
	element * newElement = creatElement (nilai);
	newElement -> next = (*myList);
	(*myList) -> prev = newElement;
	(*myList) = newElement;
}
void addAfter (int nilai, int B, element *myList){
	element * newElement = creatElement (nilai);
	element * temp = NULL;
	temp = (myList);
	while (temp -> nilai!=B){
		temp = temp -> next;
	}
	newElement -> prev = temp->next;
	newElement -> next = temp;
	temp-> prev ->next = newElement;
	temp -> prev = newElement;
	temp = NULL;
	newElement = NULL;
}
void addLast (int nilai, element *myList){
	element * newElement =creatElement (nilai);
	element * temp = NULL;
	temp = (myList);
	while (temp -> next != NULL){
		temp = temp -> next;
	}
	temp -> next = newElement;
	newElement -> prev = temp->next;
	temp = NULL;
	newElement = NULL;
}
void show(element *myList){
	element *temp = myList;
	do{
		printf("Nilai %d\n", temp->nilai);
		temp = temp->next;
	}while(temp!= NULL);
}

int main()
{
	element *nilai;
	printf("List Nilai : \n");
	nilai=creatElement(90);
	addFirst (50, &nilai);
	addLast(65, nilai);
	addFirst(84, &nilai);
	addFirst(100, &nilai);
	addAfter(70, 50, nilai);
	show(nilai);
	return 0;
}
