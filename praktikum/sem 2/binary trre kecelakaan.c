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
    
    root = CreateTree("kecelakaan");
	root->left = CreateTree("kesalahan pengemudi");
	root->right = CreateTree("kondisi jalan");
    root->left->left  = CreateTree("keadaan mabuk");
    root->left->right = CreateTree("memainkan ponsel");
    root->right->left = CreateTree("jalanan licin");
    root->right->right = CreateTree("jalanan berlubang");
    root->left->left->left = CreateTree("serius");
    root->left->left->right = CreateTree("ringan");
    root->left->right->left = CreateTree("serius");
    root->left->right->right = CreateTree("ringan");
    root->right->left->left = CreateTree("serius");
    root->right->left->right = CreateTree("ringan");
    root->right->right->left = CreateTree("serius");
    root->right->right->right = CreateTree("ringan");
    

    printf("\n============== PREORDER ==============\n\n");
    preorder(root);
    
    printf("\n============== INORDER ==============\n\n");
    inorder(root);
    
    printf("\n============== POSTORDER ==============\n\n");
    postorder(root);

    return 0;
}

