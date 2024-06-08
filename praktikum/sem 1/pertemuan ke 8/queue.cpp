#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct antrian{
	int head;
	int tail;
	int data[MAX];
}queue;


// mengecek 
int isFull(queue *Q){
	if(Q->head == 0 && Q->tail == MAX-1){
		return 1;
	}else if(Q->head - Q->tail == 1){
		return 1;
	}else{
		return 0;
	}
}

int isEmpty(queue *Q){
	if(Q->head == -1 && Q->tail== -1){
		return 1;
	}else{
		return 0;
	}
	
}

// menghapus sebuah data
void deQueue(queue *Q){
	int dataHapus;
	if(isEmpty(Q) == 0){
		dataHapus = Q->data[Q->head];
		printf("\nDAta yang telah dihapus adalah %d\n\n", dataHapus);
		Q->data[Q->head] = 0;
		if(Q->head == Q->tail){
			Q->head = -1;
			Q->tail = -1;
		}else{
			Q->head = (Q->head + 1) % MAX;
		}
	}else{
		printf("\nAntrian kosong\n\n");
	}
}


//insert data atau mengimput sebuah data
void enQueue(queue *Q, int x){
	if(isFull (Q) == 0){
		if(Q->head == -1){			//kalau queue masih kosong
			Q->head = Q->head +1;	//  head akan ke indeks awal
		}
		Q->tail = (Q->tail +1) % MAX; // unutk kondisi tail balik lahi ke 0
		Q->data[Q->tail] = x;			// isi data indeks ke tail = x
	}else{
		printf("\nAntrian Penuh\n");
	}	
}

// mencetak
void cetak(queue *Q){
	int i;
	if(isEmpty(Q) == 0){
		for(i = 0; i<MAX; i++){
			printf("%d ", Q->data[i]);
		}
	}else{
		printf("\nAntrian Kosong\n\n");
	}
}

int main(){
	queue antrian;
	
	antrian.head = -1;
	antrian.tail= -1;
	
	enQueue(&antrian, 12);
	enQueue(&antrian, 13);
	enQueue(&antrian, 14);
	enQueue(&antrian, 15);
	enQueue(&antrian, 16);
	
	cetak(&antrian);
	printf("\n\n");
	
	deQueue(&antrian);
	cetak(&antrian);
	printf("\n");
	deQueue(&antrian);
	cetak(&antrian);
	printf("\n");
	deQueue(&antrian);
	cetak(&antrian);
	printf("\n\n");
	
	enQueue(&antrian, 100);
	
	cetak(&antrian);
	
	return 0;
}




