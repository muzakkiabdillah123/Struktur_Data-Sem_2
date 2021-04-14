#include <stdio.h>
#include <stdlib.h>

typedef struct node {   //buat node
    int value;
    struct node* next;
}node_t;

void printlist(node_t*head) {           //untuk print
    node_t *temporary = head;           //membuat varibal temp yang di pointer ke head

    while (temporary != NULL) {             //perulangan, selama temp(pointer ke head) tidak NULL
        printf("%d - ", temporary->value);  //maka akan print value
        temporary = temporary->next;        //temp mencari ke next selanjutnya
    }
    printf("\n");
}

node_t *create_new_node(int value) {
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

int main() {
    node_t *head=NULL;      //coret =NULL , jika tidak pake for
    node_t *tmp;

    for (int i=1; i<=25; i++) {
        tmp = create_new_node(i);
        tmp->next = head;
        head = tmp;
    }

    // tmp = create_new_node(1);    //isi node 1,2,3
    // head = tmp;
    // tmp = create_new_node(2);
    // tmp->next = head;
    // head = tmp;
    // tmp = create_new_node(3);
    // tmp->next = head;
    // head = tmp;

    printlist(head);
    
    return 0;
}