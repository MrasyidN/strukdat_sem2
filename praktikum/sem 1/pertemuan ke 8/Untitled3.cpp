#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// bikin struk data
typedef struct{
	int angka;
}pendaftaran;

//buat tipe data baru elemen
typedef struct E{
	pendaftaran data;
	struct E *next;
}elemen;

//buat tipe data queue
typedef struct{
	elemen *head;
	elemen *tail;
}queue;

//ini untuk mengosongkan queue
void createEmpty(queue *Q){
	(*Q).head = NULL;
	(*Q).tail = NULL;
}

//periksa queue kosong atau engga
bool isEmpty(queue Q){
	return Q.head == NULL;
}

//menghitung element yang ada dalam queue
int countElement(queue Q) {
	int hasil = 0;
	if(isEmpty(Q) == 0) {  //jika Queue nya tidak kosong
		elemen *temp;
		temp = Q.head;
		
		while(temp != NULL) {
			hasil++;
			temp = temp->next;
		}
		free(temp);
	}
	return hasil;
}

//masukan data baru dalam queue
void enqueue(int angka, queue *Q) {
	elemen *baru;
	baru = (elemen*)malloc(sizeof(elemen));
	baru->data.angka = angka;
	baru->next = NULL;
	
	if (isEmpty(*Q)){
		(*Q).head = baru;
	}
	else{
		(*Q).tail->next = baru;
	}
	(*Q).tail = baru;
	
	
	baru = NULL;
}

//hapus data dalam queue
void dequeue(queue *Q){
	if(!isEmpty(*Q)){
		elemen *temp = (*Q).head;
		
		if(countElement(*Q) == 1){
			(*Q).head = NULL;
			(*Q).tail = NULL;
		}
		else{
			(*Q).head = (*Q).head->next;
			temp->next = NULL;
		}
		
		free(temp);
	}
	else{
		printf("Kosong! \n\n");
	}
}


//print data queue
void print(queue Q){
	if(!isEmpty(Q)){
		elemen *bantu = Q.head;
		
		printf("\nList Data Antrian\n\n");
		
		while(bantu != NULL){
			printf("Angka : %d\n",bantu->data.angka);
			bantu = bantu->next;
		}
	}
	else{
		printf("Kosong!\n\n");
	}
}

int main(){
	int angka;
	queue Q;
	
	//Membuat queue kosong
	createEmpty(&Q);
	printf("Data sebelum ditambahkan\n");
	print(Q);
	
	// Mengisi data queue
	printf(" Angka : ");scanf("%d",&angka);
	enqueue(angka,&Q);
	printf(" Angka : ");scanf("%d",&angka);
	enqueue(angka,&Q);
	printf(" Angka : ");scanf("%d",&angka);
	enqueue(angka,&Q);
	
	printf("Data setelah ditambahkan\n");
	print(Q);
	
	dequeue(&Q);
	printf("Data setelah dipanggil\n");
	print(Q);
				
	
	
	return 0;
}
