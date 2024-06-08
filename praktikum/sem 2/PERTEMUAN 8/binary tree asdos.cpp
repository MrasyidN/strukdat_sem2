#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree {
    char name[20];
    struct tree *left;
    struct tree *right;
} Tree;

Tree *createTree(char name[]) {
    Tree *new = (Tree*) malloc(sizeof(Tree));
    strcpy(new->name, name);
    new->left = NULL;
    new->right = NULL;
    return new;
}

void insertLeft(Tree *root, char name[]) {
    root->left = createTree(name);
}

void insertRight(Tree *root, char name[]) {
    root->right = createTree(name);
}

void preOrder(Tree *tree) {
    if (tree == NULL) {
        return;
    }
    printf("%s ", tree->name);
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(Tree *tree) {
    if (tree == NULL) {
        return;
    }
    inOrder(tree->left);
    printf("%s ", tree->name);
    inOrder(tree->right);
}

void postOrder(Tree *tree) {
    if (tree == NULL) {
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    printf("%s ", tree->name);
}

int main() {
    Tree *tree = createTree("A");

    insertLeft(tree, "B");
    insertRight(tree, "C");

    insertLeft(tree->left, "D");
    insertRight(tree->left, "E");

    insertLeft(tree->right, "F");
    insertRight(tree->right, "G");

    printf("PreOrder : ");
    preOrder(tree);
    printf("\nInOrder : ");
    inOrder(tree);
    printf("\nPostOrder : ");
    postOrder(tree);

    return 0;
}

