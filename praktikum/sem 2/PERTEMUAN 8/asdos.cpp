#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree {
    char huruf[20];
    struct tree *left;
    struct tree *right;
} btree;

btree *createbtree(char huruf[]) {
    btree *New = (btree*) malloc(sizeof(btree));
    strcpy(New->huruf, huruf);
    New->left = NULL;
    New->right = NULL;
    return New;
}

void insertLeft(btree *root, char huruf[]) {
    root->left = createbtree(huruf);
}

void insertRight(btree *root, char huruf[]) {
    root->right = createbtree(huruf);
}

void preorder(btree *btree) {
    if (btree == NULL) {
        return;
    }
    printf("%s ", btree->huruf);
    preorder(btree->left);
    preorder(btree->right);
}

void inorder(btree *btree) {
    if (btree == NULL) {
        return;
    }
    inorder(btree->left);
    printf("%s ", btree->huruf);
    inorder(btree->right);
}

void postorder(btree *btree) {
    if (btree == NULL) {
        return;
    }
    postorder(btree->left);
    postorder(btree->right);
    printf("%s ", btree->huruf);
}

int main() {
    btree *btree = createbtree("A");

    insertLeft(btree, "B");
    insertRight(btree, "G");

    insertLeft(btree->left, "C");
    insertRight(btree->left, "H");

    insertLeft(btree->right, "E");
    insertRight(btree->right, "I");
    insertRight(btree->right->left, "j");
    insertRight(btree->right->right, "K");

	printf("binary btree\n");
    printf("preorder : ");
    preorder(btree);
    printf("\ninorder : ");
    inorder(btree);
    printf("\npostorder : ");
    postorder(btree);

    return 0;
}

