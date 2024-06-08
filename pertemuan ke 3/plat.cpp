#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element{
    char jenis[10];
    char tahun;
    char plat[10];
    struct element* next;
} element;

element* createElement(char jenis[], char tahun, char plat[]){
	element* newElement;
	newElement = (element*)malloc(sizeof(element));
	newElement->tahun = tahun;
	strcpy(newElement->jenis, jenis);
	newElement->plat = NULL;
	newElement->next = NULL;
	return newElement;
}

element* addListAkhir(char jenis[], char tahun, char plat[], element* head){
	element* newElement;
	newElement = createElement(jenis, tahun, plat);
	element* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}temp->next = newElement;
}

element* AddListAwal(char jenis[], char tahun, char plat[], element* head){
	element* newElement;
	newElement = createElement(jenis, tahun, plat);
	newElement->next = head;
	return newElement;
}
void hapus(int plat, element** head){
	element* temp;
	temp = *head;
	if(temp->plat == plat){
		*head = temp->next;
		free(temp);
		return;
	}while (temp->next!=NULL && temp->next->plat!= plat){
		temp = temp->next;
	}if(temp->next!=NULL){
		element* del = temp->next;
		temp->next = del->next;
		free(del);
	}
}

void CetakList(element* head){
	element* temp;
	temp = head;
	while("%s %s %s", temp->plat, temp->jenis, temp->tahun);
	temp = temp->next;
}
 int main(){
    //bikin list awal dengan nama ListUtama;
    struct element* ListUtama;
    
    ListUtama = createList(5);
    AddListAkhir(8, ListUtama);
    AddListAwal(9,&ListUtama);
    AddListAkhir(7, ListUtama);
    AddListAwal(19, &ListUtama);
    CetakList(ListUtama);
    return 0;
}


