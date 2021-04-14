/*
Nama    : Muzakki Abdillah
NIM     : 2000532

Soal :
3. Implementasikan struktur tree dengan insert yang terorder data berikut secara berurut:
   40, 30,25, 16,7,17,5,100
 lakukan penelusuran tree nomor 3 dengan preorder, inorder dan postorder
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    struct Node*left;
    struct Node*right;
    int data;
} node;

node * create_tree(int data)
{
    node * tree;
    tree = (node*) malloc(sizeof(node));
    tree->data = data;
    tree->right = NULL;
    tree->left = NULL;
    return tree;
}

void preorder (node *p)
{
    if (p==NULL) {
        return;
    }
    printf("%d ", p->data);
    preorder(p->left);
    preorder(p->right);
}

void inorder (node *p)
{
    if (p==NULL) {
        return;
    }
    inorder(p->left);
    printf("%d ", p->data);
    inorder(p->right);
}

void postorder (node*p)
{
    if (p==NULL) {
        return;
    }
    postorder(p->left);
    postorder(p->right);
    printf("%d ", p->data);
}

void insert_order_data (int data, node ** tree)
{
    if ((*tree) == NULL) {
        (*tree) =  create_tree(data);
    } else if (data <= ((*tree)->data)) {
        insert_order_data(data, &((*tree)->left));
    } else {
        insert_order_data(data, &((*tree)->right));
    }
}

int main()
{
    node * tree=NULL;

    insert_order_data(40,&tree);
    insert_order_data(30,&tree);
    insert_order_data(25,&tree);
    insert_order_data(16,&tree);
    insert_order_data(7,&tree);
    insert_order_data(17,&tree);
    insert_order_data(5,&tree);
    insert_order_data(100,&tree);

    printf("Preorder :\n");
    preorder(tree);
    printf("\nInorder :\n");
    inorder(tree);
    printf("\nPostorder :\n");
    postorder(tree);

    return 0;
}