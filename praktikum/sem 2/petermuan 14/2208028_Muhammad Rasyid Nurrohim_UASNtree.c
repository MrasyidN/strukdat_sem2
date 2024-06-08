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

ntree *caridata(char nama[], ntree *root){
	ntree *result = NULL;
	if(root == NULL){
		return result; 
	}
	if(strcmp(root->nama, nama)== 0){
		result = root;
	}
	else{
		result = caridata(nama, root->child);
		if(result == NULL){ 
			result = caridata(nama, root->sibling); 
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
	printf("%s\n", tree->nama);
	preorder(tree->child);
	preorder(tree->sibling);
}
void postorder(ntree *tree){
	if(tree == NULL){
		return; 
	}
	postorder(tree->child);
	printf("%s\n", tree->nama);
	postorder(tree->sibling);
}

int main(){
	ntree *tree = createTree("Dana");
	addChild(caridata("Dana", tree), "Ayu");
	addChild(caridata("Dana", tree), "Bima");
	addChild(caridata("Dana", tree), "Andre");
	
	addChild(tree, "Ayu");
	addChild(caridata("Ayu", tree), "Hilma");
	addChild(caridata("Ayu", tree), "Hilmi");

	addChild(tree, "Bima");
	addChild(caridata("Bima", tree), "Putra");
	addChild(caridata("Bima", tree), "Putri");
	addChild(caridata("Bima", tree), "Sinta");
	
	
	int n;
	
	do{
		scanf("%d", &n);
		switch(n){
			case 0:
				printf("Terima Kasih");
				break;
			case 1:
				preorder(tree);
				break;
			case 2:
				postorder(tree);
				break;
		}
	}while(n!=0);
	return 0;
}
