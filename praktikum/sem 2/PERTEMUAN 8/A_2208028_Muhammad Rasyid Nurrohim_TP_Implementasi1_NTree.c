#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree {
    char huruf[20];
    struct tree *child;
} ntree;

ntree *createTree(char huruf[]) {
    ntree *New = (ntree *) malloc(sizeof(ntree));
    strcpy(New->huruf, huruf);
    New->child = NULL;
    return New;
}

ntree *findData(char huruf[], ntree *root) {
    ntree *result = NULL;
    if (root == NULL) {
        return result;
    }
    if (strcmp(root->huruf, huruf) == 0) {
        result = root;
    } else {
        result = findData(huruf, root->child);
    }
    return result;
}

void addChild(ntree *parent, char huruf[]) {
    if (parent->child == NULL) {
        parent->child = createTree(huruf);
    } else {
        addChild(parent->child, huruf);
    }
}

void printChild(ntree *tree) {
    if (tree == NULL) {
        return;
    }
    printf("Vertex %s memiliki child:\n", tree->huruf);
    ntree *child = tree->child;
    while (child != NULL) {
        printf("Vertex %s\n", child->huruf);
        child = child->child;
    }
    printf("\n");
}

int main() {
    ntree *tree = createTree("A");

    //addChild(findData("A", tree), "B");
    //addChild(findData("A", tree), "F");
    //addChild(findData("A", tree), "G");
    printChild(findData("A", tree));
    
    addChild(tree, "B");
    addChild(findData("B", tree), "C");
    addChild(findData("B", tree), "D");
    addChild(findData("B", tree), "E");
    printChild(findData("B", tree));
    
    addChild(findData("E", tree), "L");
    printChild(findData("E", tree));
    
    addChild(tree, "F");

    addChild(tree, "G");
    addChild(findData("G", tree), "H");
    addChild(findData("G", tree), "I");
    printChild(findData("G", tree));
    
    addChild(findData("I", tree), "J");
    addChild(findData("I", tree), "K");
    printChild(findData("I", tree));
    


    printf("\n");

    return 0;
}

