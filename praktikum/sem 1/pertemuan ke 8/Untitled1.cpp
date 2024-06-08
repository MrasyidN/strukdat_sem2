#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct identitas{
	char nama[20];
	int usia;
}identitas_pengunjung;

typedef struct data{
	identitas_pengunjung data;
	struct data *next;
}antrian;

typedef struct queue{
	int *head;
	int *tail;
}queue;
//
void createEmpty(queue *Q){
	Q->head = NULL;
	Q->tail = NULL;
}

bool isEmpty(queue Q){
	return Q.head == NULL;

}

int countElemen(queue Q){
	int total = 0;
	if(isEmpty(Q) == 0){
		elemen *temp;
		temp = Q.head;
		while(temp!= NULL){
		total++;
		temp = temp->next;
		}
		free(temp);
	}
	return total;
}


void enqueue(char nama[], int usia, queue *Q){
	identitas_pengunjung pengungjung;
	printf("nama:");
	scanf("%s", pengunjung.nama);
	printf("usia:");
	scanf("%d", pengunjung.usia);
	
	antrian *New;
	New = (antrian*)malloc(sizeof(antrian));
	New->data.nama = nama;
	New->data.usia = usia;
	New->next = NULL;
	if(isEmpty(*Q)){
		(*Q).head = New;
	}
	else{
		(*Q).tail->next = New;
	}
	(*Q).tail = New;
	baru = New;
	
	
	printf("[berhasil menanbahkan antrian: %s, %d ]", )
}














int main(){
	printf("[0] Keluar");
	printf("[1] Tambahkan Antrian");
	printf("[2] Panggil Nama");
	printf("[3] Lihat Antrian");
}
