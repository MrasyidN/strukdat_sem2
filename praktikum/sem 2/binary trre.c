#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char data[50];
    struct node *right;
    struct node *left;
} node;

node *CreateTree(char* data){
    node *Tree = (node*)malloc(sizeof(node));
    strcpy(Tree->data, data);
    Tree->left = NULL;
    Tree->right = NULL;
    return Tree;
}

void preorder(node *root){
    if(root!=NULL){
        printf("%s-", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%s-", root->data);
        inorder(root->right);
    }
}

void postorder(node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%s-", root->data);
    }
}

int main(){
    node *root;
    
    root = CreateTree("ucup");
    root->left = CreateTree("udin");
    root->right = CreateTree("ujang");
    root->left->left = CreateTree("esih");
    root->left->right = CreateTree("andi");
    root->left->right->left = CreateTree("budi");
    root->right->left = CreateTree("iman");
    root->right->right = CreateTree("cici");
    root->right->left->left = CreateTree("ani");
    root->right->left->right = CreateTree("arif");
    root->right->left->right->left = CreateTree("lita");


    printf("\n============== PREORDER ==============\n\n");
    preorder(root);
    
    printf("\n============== INORDER ==============\n\n");
    inorder(root);
    
    printf("\n============== POSTORDER ==============\n\n");
    postorder(root);

    return 0;
}

