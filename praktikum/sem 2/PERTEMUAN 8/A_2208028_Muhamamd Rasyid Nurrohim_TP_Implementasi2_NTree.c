#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree{
	char huruf[20]; 
	struct tree *child;
	struct tree *sibling;
}ntree;

ntree *createTree(char huruf[]){
	ntree *New = (ntree*)malloc(sizeof(ntree));
	strcpy(New->huruf, huruf); 
	New->child = NULL;
	New->sibling = NULL;
	return New;
}

ntree *findData(char huruf[], ntree *root){
	ntree *result = NULL;
	if(root == NULL){
		return result; 
	}
	if(strcmp(root->huruf, huruf)== 0){
		result = root;
	}
	else{
		result = findData(huruf, root->child);
		if(result == NULL){ 
			result = findData(huruf, root->sibling); 
		}
	}
	return result;
}

void addChild(ntree *parent, char huruf[]) {
	if(parent->child == NULL) {
		parent->child = createTree(huruf);
	}
    else {
        ntree *temp = parent->child;
        while (temp->sibling!=NULL){
			temp = temp->sibling;
        }
		temp->sibling = createTree(huruf);
    }
}


void preorder(ntree *tree){
	if(tree == NULL){
		return; 
	}
	printf("%s ", tree->huruf);
	preorder(tree->child);
	preorder(tree->sibling);
}
void inorder(ntree *tree){
	if(tree == NULL){
		return; 
	}
	inorder(tree->child);
	printf("%s ", tree->huruf);
	inorder(tree->sibling);
}
void postorder(ntree *tree){
	if(tree == NULL){
		return;
	}
	postorder(tree->child);
	postorder(tree->sibling);
	printf("%s ", tree->huruf);
}

void main() {
	ntree *tree = createTree("A");

	addChild(tree, "B");
	addChild(findData("B", tree), "A");
	addChild(findData("B", tree), "D");
	addChild(findData("B", tree), "E");
	addChild(findData("E", tree), "L");

	addChild(tree, "F");
	
	addChild(tree, "G");
	addChild(findData("G", tree), "H");
	addChild(findData("G", tree), "I");

	addChild(findData("I", tree), "J");
	addChild(findData("I", tree), "K");
	
	printf("implemenatsi ke 2\n");
	printf("preorder : ");
	preorder(tree);
	printf("\ninorder : ");
	inorder(tree);
	printf("\npostorder : ");
	postorder(tree);
}
