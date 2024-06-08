#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element{
	int id;
	char nama[20];
	struct Element *next;
	struct Element *prev;
}data;

data *createElement(int id, char nama[]){
	data *baru;
	baru = (data*)malloc(sizeof(data));
	strcpy(baru->nama, nama);
	baru->id = id;
	baru->next = NULL;
	baru->prev = NULL;
	return baru;
}

data *addAwal(int id, char nama[], data **head){
	data *tambah;
	tambah = createElement(id, nama);
	if((*head)== NULL){
		createElement(id, nama);
	}else{
		tambah->next = *head;
		(*head)->prev = tambah;
		*head = tambah;
	}
	return tambah;
}
data addAkhir(int id, char nama[], data **head){
	data *tambah;
	data *temp;
	tambah = createElement(id, nama);
	temp = *head;
	while(temp->next!= NULL){
		temp = temp->next;
	}
	temp->next = tambah;
	tambah->prev = temp;
	tambah = NULL;
	temp = NULL;
}

void addBefore(int id, char nama[], data **head, int id2){
	data *tambah;
	data *temp;
	tambah = createElement(id, nama);
	temp = *head;
	while(temp->next!=NULL && temp->id!= id2){
		temp = temp->next;
	}	
	tambah->next = temp;
	tambah->prev = temp->prev;
	temp->prev->next = tambah;
	temp->prev = tambah;
	tambah = NULL;
	temp = NULL;
}

void addAfter(int id, char nama[], data **head, int id2){
	data *tambah;
	data *temp;
	tambah = createElement(id, nama);
	temp = *head;
	while (temp->next!=NULL && temp->id!=id2){
		temp = temp->next;
	}
	tambah->next = temp->next;
	tambah->prev = temp;
	temp->next->prev = tambah;
	temp->next = tambah;
	temp = NULL;
	tambah = NULL;
}

void hapusAwal(data **head){
	data *hapus;
	hapus = *head;
	*head = hapus->next;
	hapus->next->prev = NULL;
	hapus->next = NULL;
	free(hapus);
}

void hapusAkhir(data **head){
	data *hapus;
	hapus = *head;
	while(hapus->next!=NULL){
		hapus = hapus->next;
	}
	hapus->prev->next = NULL;
	hapus->prev = NULL;
	free(hapus);
}


void hapusTengah(int id2, data *head){
	data *head;
	data *temp;
	while(temp->next!=NULL && temp->id!=id2){
		temp = temp->next;
	}
	if(temp->id == id2){
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		temp->next = NULL;
		temp->prev = NULL;
		free(hapus);
	}else{
		printf("Tidak Ada id");
	}
	
}
void cetakList(data **head){
	data *temp;
	temp = *head;
	while(temp!= NULL){
		printf("id = %d\nNama = %s\n", temp->id, temp->nama);
		temp = temp->next;
	}
	printf("\n");
	
}

int main(){
	int id, id2;
	char nama[20];
	data *head = NULL;
	
	scanf("%d", &id);
	scanf("%s", &nama);
	head = createElement(id, nama);
	printf("Setelah Create\n");
	cetakList(&head);
	
	
	scanf("%d", &id);
	scanf("%s", &nama);
	head = addAwal(id, nama, &head);
	printf("Setelah Add Awal\n");
	cetakList(&head);
	
	scanf("%d", &id);
	scanf("%s", &nama);
	addAkhir(id, nama, &head);
	printf("Setelah Add Akhir\n");
	cetakList(&head);
	
	scanf("%d", &id);
	scanf("%s", &nama);
	scanf("%d", &id2);
	addBefore(id, nama, &head, id2);
	printf("Setelah Add Before\n");
	cetakList(&head);

	scanf("%d", &id);
	scanf("%s", &nama);
	scanf("%d", &id2);
	addAfter(id, nama, &head, id2);
	printf("Setelah Add After\n");
	cetakList(&head);
	
	hapusAwal(&head);
	printf("Setelah Hapus Awal\n");
	cetakList(&head);
	
	hapusAkhir(&head);
	printf("Setelah Hapus Akhir\n");
	cetakList(&head);
	
	hapusTengah(&head);
	printf("Setelah Hapus Tengah\n");
	cetakList(&head);
	
	return 0;	
}
