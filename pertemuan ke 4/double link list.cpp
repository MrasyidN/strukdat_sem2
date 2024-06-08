#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int data;
	struct element * next;
	struct element * prev;
}element;

element * CreateElement(int a){
	element *New;
	New = (element*)malloc(sizeof(element));
	New->data = a;
	New->next = NULL;
	New->prev = NULL;
	return New;
}

void addAkhir(int a, mylist){
	element *New;
	element *temp;
	New = CreateElement(a);
	temp = mylist;
	while (temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = New;
	New->prev = temp;
	New = NULL;
	temp = NULL;
}

element *addbefore (int a, int data2, mylist){
	element *New;
	element *temp;
	New = CreateElement(a);
	temp = mylist;
	while(temp->next! = NULL && temp->data! = data2){
		temp = temp->next;
	}
	if(temp->data == data2){
		New->next = temp;
		New->prev = temp->prev;
		temp->prev->next = New;
		temp->prev = New;
	}else{
		printf("data tidak ditemukan ");
	}
}

void addAfter(int a, *mylist){
	element *New;
	element *temp;
	New = CreateElement(a);
	temp = mylist;
	while(temp->next!=NULL && temp->data!= data;){
		temp = temp->next;
	}
		if(temp->data == data){
			New->next = temp->next;
			temp->next->prev = New;
			temp->next = New;
			New->prev = temp;
		}
		temp = NULL;
		New = NULL; 
		else{
			("data tidak ditemukan ");
		}
}

void cetak(element *mylist){
	element *temp;
	temp = mylist;
	while(temp! = NULL){
		printf("%d", temp->data);
		temp = temp->next;
	}
}


int main (){
	int
	
	return 0;
}
