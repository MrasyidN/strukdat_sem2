#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree{
	char nama[20]; 
	struct tree *child;
	struct tree *sibling;
}ntree;

ntree *createTree(char nama[]){
	ntree *New = (ntree*)malloc(sizeof(ntree));
	strcpy(New->nama, nama); 
	New->child = NULL;
	New->sibling = NULL;
	return New;
}

ntree *findData(char nama[], ntree *root){
	ntree *result = NULL;
	if(root == NULL){
		return result; 
	}
	if(strcmp(root->nama, nama)== 0){
		result = root;
	}
	else{
		result = findData(nama, root->child);
		if(result == NULL){ 
			result = findData(nama, root->sibling); 
		}
	}
	return result;
}

void addChild(ntree *parent, char nama[]) {
	if(parent->child == NULL) {
		parent->child = createTree(nama);
	}
    else {
        ntree *temp = parent->child;
        while (temp->sibling!=NULL){
			temp = temp->sibling;
        }
		temp->sibling = createTree(nama);
    }
}


void preorder(ntree *tree){
	if(tree == NULL){
		return; 
	}
	printf("%s \n", tree->nama);
	preorder(tree->child);
	preorder(tree->sibling);
}
void postorder(ntree *tree){
	if(tree == NULL){
		return; 
	}
	postorder(tree->child);
	printf("%s \n", tree->nama);
	postorder(tree->sibling);
}

int main() {
	ntree *tree = createTree("Dana");

	addChild(tree, "Ayu");
	addChild(findData("Ayu", tree), "Hilma");
	addChild(findData("Ayu", tree), "Hilmi");

	addChild(tree, "Bima");
	addChild(findData("Bima", tree), "Putra");
	addChild(findData("Bima", tree), "Putri");
	addChild(findData("Bima", tree), "Sinta");

	addChild(tree, "Andre");


	printf("----------[PRE ORDER]---------- \n");
	preorder(tree);
	printf("\n---------[POST ORDER]----------\n");
	postorder(tree);

}
