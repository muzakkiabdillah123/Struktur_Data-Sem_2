/*
Nama    : Muzakki Abdillah
NIM     : 2000532 

Soal :
1. Mengimplementasikan struktur tree yang ditugaskan pada pertemuan sebelumnya dengan menggunakan bahasa Tree.
2. Lakukan penelusuran inorder, preorder dan postorder.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    struct Node*left;
    struct Node*right;
    char data[1];
} node;

node * create_tree(char data[1])
{
    node * tree;
    tree = (node*) malloc(sizeof(node));
    strcpy(tree->data,data);
    tree->right = NULL;
    tree->left = NULL;
    return tree;
}

void preorder (node *p)
{
    if (p==NULL) return;
    printf("%s ", p->data);
    preorder(p->left);
    preorder(p->right);
}

void inorder (node *p)
{
    if (p==NULL) return;
    inorder(p->left);
    printf("%s ", p->data);
    inorder(p->right);
}

void postorder (node*p)
{
    if (p==NULL) return;
    postorder(p->left);
    postorder(p->right);
    printf("%s ", p->data);
}

int main()
{
    node * tree = NULL;
    tree = create_tree("A");

    node * subtree_L;    
    subtree_L = create_tree("B");
    tree->left = subtree_L;

    node * subtree_R;
    subtree_R = create_tree("E");
    tree->right = subtree_R;

    node * subtree_L_L;
    subtree_L_L = create_tree("C");
    tree->left->left = subtree_L_L;

    node * subtree_L_R;
    subtree_L_R = create_tree("D");
    tree->left->right = subtree_L_R;

    node * subtree_R_L;
    subtree_R_L = create_tree("F");
    tree->right->left = subtree_R_L;

    node * subtree_R_R;
    subtree_R_R = create_tree("H");
    tree->right->right = subtree_R_R;

    node * subtree_R_L_L;
    subtree_R_L_L = create_tree("G");
    tree->right->left->left = subtree_R_L_L;

    node * subtree_R_R_L;
    subtree_R_R_L = create_tree("I");
    tree->right->right->left = subtree_R_R_L;

    node * subtree_R_R_R;
    subtree_R_R_R = create_tree("J");
    tree->right->right->right = subtree_R_R_R;

    printf("Preorder :\n");
    preorder(tree);
    printf("\nInorder :\n");
    inorder(tree);
    printf("\nPostorder :\n");
    postorder(tree);

    return 0;
}