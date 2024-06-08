// materi pointer

/*

#include <stdio.h>

typedef struct Element{
	char nim [10];
	char nama[15];
	int nilai;
	struct Element*NextAlamat;
}element;


int main(){
	
	return 0;
}
==========================================================
*/

/*
// ======================================================

typedef struct Element{
	int nilai;
	char x[10];
	struct element*Nextalamat;
}element;

element*CreateElement(int a){
	element*new;
	new=(element*)malloc(sizeof(element));
	new->nilai=a;
	strcpy(new->x,"satria");
	new->NextAlamat=NULL;
	return new;
}
//=======================================================

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
	char jenis[20];
	char tahun[20];
	char plat[20];
	
}element;

/*
element*CreateElement(int a){
	element*new;
	new=(element*)malloc(sizeof(element));
	new->nilai=a;
	strcpy(nex->x,"%d",jenis)
	as
	
}
*/

void AddListAkhir (char jenis[20], char tahun[20],char plat[20],element*List){
	element*NewList=CreateElement(jenis, tahun, plat);
	element*temp=NULL;
	temp=List;
	while (temp->nextAlamat!=NULL){
		temp=temp->nextAlamat;
	}
	temp->next=NewList;
}


