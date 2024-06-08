#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


typedef struct smp *alamatsimpul;
typedef struct smp{
	char kontainer;
	alamatsimpul sibling;
	alamatsimpul child;
}simpul;

typedef struct {
	simpul *root;
}tree;


void makeTree(char c, tree *T){
	simpul *baru;
	baru = (simpul*)malloc(sizeof(simpul));
	baru->kontainer = c;
	baru->sibling = NULL;
	baru->child = NULL;
	(*T).root = baru;
}

void addChild(char c, simpul *root){
	if(root!=NULL){
		simpul *baru;
		baru = (simpul*)malloc(sizeof(simpul));
		baru->kontainer = c;
		baru->child = NULL;
		if(root->child = NULL){
			baru->sibling = NULL;
			root->child = baru;
		}else{
			if(root->child->sibling == NULL){
				baru->sibling = root->child;
				root->child->sibling = baru;
			}else{
				simpul *last = root->child;
				while(last->sibling!=root->child){
					last = last->sibling;
				}
				baru->sibling = root->child;
				last->sibling = baru;
			}
		}
	}
}



simpul *findSimpul(char c, simpul *root){
	simpul *hasil = NULL;
	if(root!=NULL){
		if(root->kontainer == c){
			hasil = root;
		}else{
			simpul *bantu = root->child;
			if(bantu!=NULL){
				if(bantu->sibling == NULL){
					if(bantu->kontainer == c){
						hasil = bantu;
					}else{
						hasil = findSimpul(c,bantu);
					}
				}
				else{
					int ketemu = 0;
					while ((bantu->sibling!=root->child)&&(ketemu == 0)){
						if(bantu->kontainer == c){
							hasil = bantu;
							ketemu = 1;
						}
						else{
							hasil = findSimpul(c, bantu);
							bantu = bantu->sibling;
						}
					}
					if(ketemu==0){
						if(bantu->kontainer == c){
							hasil = bantu;
						}
						else{
							hasil = findSimpul(c, bantu);
						}
					}
				}
			}
		}
	}
	
	return hasil;
}


void preorder(simpul *root){
	if(root!=NULL){
		printf(" %c ", root->kontainer);
		simpul *bantu = root->child;
		if(bantu!=NULL){
			if(bantu->sibling == NULL){
				preorder(bantu);
			}
			else{
				while(bantu->sibling!=root->child){
					preorder(bantu);
					bantu = bantu->sibling;
				}
				preorder(bantu);
			}
		}
	}
}



void postorder(simpul *root){
	if(root!=NULL){
		simpul *bantu = root->child;
		if(bantu!=NULL){
			if(bantu->sibling == NULL){
				postorder(bantu);
			}
			else{
				while(bantu->sibling!=root->child){
					postorder(bantu);
					bantu = bantu->sibling;
				}
				postorder(bantu);
			}
		}
		printf(" %c ", root->kontainer);	
	}

}
