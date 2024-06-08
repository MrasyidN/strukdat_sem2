#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char nama[50];
    struct node *right;
    struct node *left;
} node;


node *CreateTree(char nama){
    node *Tree = (node*)malloc(sizeof(node));
    strcpy(Tree->nama, nama);
    Tree->left = NULL;
    Tree->right = NULL;
    return Tree;
}

void insertorder(char *nama, node **p){
    if((*p) == NULL){
        (*p) = CreateTree(*nama);
    }else if(*nama <= (*p)->nama){
        insertorder(nama, &((*p)->left));
    }else{
        insertorder(nama, &((*p)->right));
    }
}

void preorder(node *root){
    if(root!=NULL){
        printf("%s ", root->nama);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%s ", root->nama);
        inorder(root->right);
    }
}

void postorder(node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->nama);
    }
}

int main(){
    node *tree = NULL;

    insertorder("ucup", &tree);
    insertorder("udin", &tree);
    insertorder("esih", &tree);
    insertorder("andi", &tree);
    insertorder("budi", &tree);
    insertorder("ujang", &tree);
    insertorder("imam", &tree);
    insertorder("ani", &tree);
    insertorder("arif", &tree);
    insertorder("lita", &tree);
    insertorder("cici", &tree);


    printf("\n============== PREORDER ==============\n\n");
    preorder(tree);
    printf("\n============== INORDER ==============\n\n");
    inorder(tree);
    printf("\n============== POSTORDER ==============\n\n");
    postorder(tree);

    return 0;
}

