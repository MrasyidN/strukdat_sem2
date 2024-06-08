#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int data;
	struct element *right;
	struct element *left;
}element;


element *createTree(int data){
	element *tree = (element*)malloc(sizeof(element));
	tree->data;
	tree->right;
	tree->left;
	tree->right = NULL;
	tree->left = NULL;
	return tree;
}

void insert(int data, element **node){
	if(*node) == NULL{
	(*node ) = createTree(data);
	
	}else if(data <= (*node)->data){
		insert(data, &(node)->left);
	}else{
		insert(data, &(*node)->right);
	}
}

void preorder(element *node){
	if(node == NULL) return;
	peintf("cek data %d", node->data);
	preorder(node->left);
	preorder(node->right);
}


int main(){
	
	return 0;
}
