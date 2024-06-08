#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct node * alamatNode;

typedef struct node{
	char kontainer[50];
	alamatNode sibling;
	alamatNode child;
}Node;

typedef struct {
	Node* root;
}Tree;

void makeTree(char [], tree *T){
	Node *newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->kontainer, k);
	newNode->sibling = NULL;
	newNode->child = NULL;
	(*T).root = newNode;
}


void addChild(char k[]n Node *parent){
	if(parent!=NULL){
		Node *newNode = (Node*)malloc(sizeof(Node));
		strpcy(newNode->kontainer, k);
		newNode->child = NULL;
		if(parent->child == NULL){
			newNode->sibling = NULL;
			parent->child = newNode;
		}else{
			if(parent->child == NULL){
				newNode->child = parent->child;
				parent->child->sibling = newNode;
			}else{
				Node *last = parent->child;
				while(last->sibling!=parent->child){
					last = last->sibling;
				}
				newNode->sibling = parent->child;
				last->sibling = newNode;
				
			}
		}
	}
}



