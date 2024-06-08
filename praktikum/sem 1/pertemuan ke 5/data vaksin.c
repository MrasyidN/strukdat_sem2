#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Element{
    int id;
    char nama[20];
    char gender[20];
    int usia;
    struct Element* next;
    struct Element* prev;
}data;

data* createData(int id, char nama[], char gender[], int usia){
    data* baru;
    baru = (data*)malloc(sizeof(data));
    baru->id = id;
    strcpy(baru->nama, nama);
    strcpy(baru->gender, gender);
    baru->usia = usia;
    baru->next = NULL;
    baru->prev = NULL;
    return baru;
}

data* addAwal(int id, char nama[], char gender[], int usia, data** head){
    data* tambah;
    tambah = createData(id, nama, gender, usia);
    if ((*head) == NULL){
        *head = tambah;
    } else {
        tambah->next = *head;
        (*head)->prev = tambah;
        *head = tambah;
    }
    return tambah;
}

data* addAfter (int id, char nama[], char gender[], int usia,int id2, data** head){
    data* tambah;
    data* temp;
    tambah = createData (id, nama, gender, usia);
    temp = *head;
    while (temp->next!= NULL && temp->id!= id2) {
        temp = temp->next;
    }
    if(temp->next != NULL){
		tambah->next = temp->next;
        tambah->prev = temp;
        temp->next->prev = tambah;
        temp->next = tambah;
    }else{
        temp->next = tambah;
        tambah->prev = temp;
    }
    temp = NULL;
    tambah = NULL;
    return tambah;
}

void addBefore (int id, char nama[], char gender[], int usia,int id2, data** head){
	data* tambah;
	data* temp;
	tambah = createData (id, nama, gender, usia);
	temp = *head;
	while (temp -> next != NULL && temp -> id != id2){
		temp = temp -> next;
	}
	tambah->next = temp;
	tambah->prev = temp->prev;
	temp->prev->next = tambah;
	temp->prev = tambah;
	temp = NULL;
	tambah = NULL;
}

void addAkhir (int id, char nama[], char gender[], int usia, data** head){
    data* tambah;
    data* temp;
    tambah = createData (id, nama, gender, usia);
    temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = tambah;
    tambah->prev = temp;
    tambah = NULL;
    temp = NULL;
}

void hapus (int id, data** head) {
    data* temp = *head;
    if (temp->id == id) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp -> next!= NULL && temp->next->id!=id) {
        temp = temp->next;
    }
    if (temp!= NULL && temp->next!= NULL) {
        data* del = temp->next;
        temp->next = temp->next->next;
        free(del);
    }
}

void CetakId (data **head, int id2) {
    data * temp = *head;
    while (temp!= NULL) {
        if (temp->id == id2) {
            printf("\nid : %d\nNama : %s\nGender : %s\nUsia : %d\n\n",temp->id,temp->nama, temp->gender, temp->usia);
        }
        temp = temp->next;
    }
}

void cetakData (data **head){
    data *temp;
    temp = *head;
    while (temp!= NULL){
        printf ("\nid : %d\nNama : %s\nGender : %s\nUsia : %d\n\n", temp->id, temp->nama, temp->gender,temp->usia);
        temp = temp->next;
    }printf ("\n");
}

int main(){
	int id, id2, n; 
    char nama[20];
    char gender[20];
    int usia;
    data *head = NULL;
	
	do {
		/*
		printf ("List Menu : \n");
        printf ("[0] Keluar \n");
        printf ("[1] Add Awal \n");
        printf ("[2] Cetak Data \n");
        printf ("[3] Add After \n");
        printf ("[4] Add Before \n");
        printf ("[5] Add Akhir \n");
        printf ("[6] Hapus id \n");
        printf ("[7] Tampilkan \n");
        printf ("Masukkan pilihan : ");
        */
        scanf ("%d", &n);
        
        switch(n) {
        	case 1 :
        		printf ("Masukan id : "); scanf ("%d", &id);
        		printf ("Masukan nama : "); scanf ("%s", nama);
        		printf ("Masukan gender : "); scanf ("%s", gender);
        		printf ("Masukan usia : "); scanf ("%d", &usia);
        		addAwal(id, nama, gender, usia, &head);
        		break;
        	case 2 :
        		printf ("input id : "); scanf ("%d", &id);
        		CetakId (&head, id);
        		break;
        	case 3 :
        		printf ("id : "); scanf ("%d", &id2);
        		printf ("Masukan id : "); scanf ("%d", &id);
        		printf ("Masukan nama : "); scanf ("%s", nama);
        		printf ("Masukan gender : "); scanf ("%s", gender);
        		printf ("Masukan usia : "); scanf ("%d", &usia);
        		addAfter (id2, id, nama, gender, usia, &head);
        		break;
        	case 4 :
        		printf ("id : "); scanf ("%d", &id2);
				printf ("Masukan id : "); scanf ("%d", &id);
        		printf ("Masukan nama : "); scanf ("%s", nama);
        		printf ("Masukan gender : "); scanf ("%s", gender);
        		printf ("Masukan usia : "); scanf ("%d", &usia);
        		addBefore (id2, id, nama, gender, usia, &head);
        		break; 
        	case 5 :
        		printf ("Masukan id : "); scanf ("%d", &id);
        		printf ("Masukan nama : "); scanf ("%s", nama);
        		printf ("Masukan gender : "); scanf ("%s", gender);
        		printf ("Masukan usia : "); scanf ("%d", &usia);
        		addAkhir (id, nama, gender, usia, &head);
        		break;
        	case 6 :
        		printf ("Masukan id yang ingin di hapus : "); 
				scanf ("%d", &id);
        		hapus(id, &head);
        	case 7 :
                if (head == NULL) {
                    printf("\nDaftar List Kosong\n\n");
                } else {
                    cetakData (&head);
                }break;
        		
		}
	}while (n!= 0);
	
	return 0;
}
