#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int id;
    char nama[20];
    struct node*next;
} node;

node * createNode(int ID,char NAMA[20])
{
    node*newNode = NULL;
    newNode = (node*)malloc(sizeof(node));
    newNode->id=ID;
    strcpy(newNode->nama,NAMA);
    newNode->next=NULL;
    return newNode;
}

void addAwal(int ID, char NAMA[20],node**myNode)
{
    node*newNode = createNode(ID,NAMA);
    newNode->next=(*myNode);
    (*myNode)=newNode;
    newNode=NULL;
}

void addTengah(int ID,char NAMA[20],int a, node*myNode)
{
    node*newNode=createNode(ID,NAMA);
    node*temp=NULL;
    temp=myNode;
    while(temp->id!=a)
    {
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    newNode=NULL;
}

void addAkhir(int ID,char NAMA[20], node*myNode)
{
    node*newNode=createNode(ID,NAMA);
    node*temp=NULL;
    temp=myNode;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode=NULL;
}

void show (node*myNode)
{
    node*temp=myNode;
    do
    {
        printf("id : %d\nNama : %s\n",temp->id,temp->nama);
        temp=temp->next;
    } while (temp!=NULL);
    
}

int main()
{
    node*data;
    data=createNode(8,"ujang");
    addAwal(1,"Asep",&data);
    addTengah(9,"Koswara",8,data);
    addAkhir(10,"Udin",data);
    show(data);
}