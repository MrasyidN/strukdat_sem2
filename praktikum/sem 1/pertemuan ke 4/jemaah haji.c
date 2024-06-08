#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct jamaah{
	char nama [25];
	char gender [10];
	int umur;
	struct jamaah *next;
}haji;

haji *head;

haji *createjamaah(char nama [25], char gender [10], int umur){
	haji *New;
	New = (haji*) malloc (sizeof(haji));
	strcpy (New->nama,nama);
	strcpy (New->gender,gender);
	New->umur = umur;
	return New;
}

void input(char nama [25], char gender [10], int umur){
	haji *add;
	haji *temp;
 	add = createjamaah (nama, gender, umur);
	if(head==NULL || (add->umur > (head)->umur) || (add->umur == head->umur && strcmp(add->gender, "Perempuan")==0)){
		add->next=head;
		head=add;
	}else {
		haji *temp=head;
		while (temp->next != NULL && (temp->next->umur > add->umur || 
		(temp->next->umur == add->umur && strcmp(add->gender, "Laki-laki") == 0 && strcmp(temp->next->gender, "Laki-laki") == 0) ||
		(temp->next->umur == add->umur && strcmp(add->gender, "Laki-laki") == 0 && strcmp(temp->next->gender, "Perempuan") == 0) || 
		(temp->next->umur == add->umur && strcmp(add->gender, "Perempuan") == 0 && strcmp(temp->next->gender, "Perempuan") == 0))){
			temp=temp->next;
		}
		add->next=temp->next;
		temp->next=add;
	}
}

void deleteAwal(){
	haji *temp;
	haji *del;
	del = head;
	temp = head;
	head = temp->next;
	del->next = NULL;
	free(del);
	temp = NULL;
}

void printList(){
	if(head==NULL){
		printf("jamaah List Kosong\n");
	}else{
		haji *temp = head;
		int i=1;
		while(temp != NULL){
			printf("%s\n", temp->nama);
			printf("%s\n", temp->gender);
			printf("%d\n", temp->umur);
			temp = temp->next;
			i++;
		}
	}
}

int main (){
	int menu, n, i, umur;
	char nama[25], gender[10];
	
	do{
		scanf("%d" ,&menu);
		switch(menu){
			case 0:
				exit(0);
				break;
			case 1:
				scanf("%d", &n);
				for(i = 0; i < n; i++){
					scanf(" %[^\n]", &nama);
					scanf("%s", &gender);
					scanf("%d", &umur);
					input(nama, gender, umur);
				}
				break;
			case 2:
				scanf("%d", &n);
				for(i = 0; i < n; i++){
					if (head == NULL){
					printf("\njamaah List Kosong");
					}else{
						deleteAwal();	
					}
				}
				break;
			case 3:
				printf("\n");
				printList();
				break;
		}
	}while(menu!=0);
	
	
	return 0;
}
