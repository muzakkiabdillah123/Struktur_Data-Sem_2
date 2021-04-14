#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node*next;
};

struct node*head;

struct node *create_list(int x){
    struct node*new= (struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->prev=NULL;
    new->next=NULL;
    return new;
}

void addAwal(int x){
    struct node*new=create_list(x);
    if (head==NULL){
        head=new;
        return;
    }
    head->prev=new;
    new->next=head;
    head=new;
}

void print(){
    struct node*temp=head;
    printf("Hasil : ");
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void reverse_print(){
    struct node*temp=head;
    if (temp==NULL) return;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("Reverse : ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

int main(){
    struct node *produk;

    // create_list(2); print();
    head=NULL;
    addAwal(2); print(); 
    addAwal(4); print(); 
    addAwal(6); print();
}