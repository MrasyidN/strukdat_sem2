#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


typedef struct Data{
	int id;
	int nama[50];
	struct Data* next;
	
}data;

data* createData (int id, char nama[]){
	data* New = (data*)malloc(sizeof(data));
	New->id = id;
	strcpy(New->nama, nama);
	New->next = NULL;
	return New;
}

void addAkhir (int id, char nama[], data **head){
    data* New = createData (id, nama);
    if (*head == NULL){
        *head = New;
    }else{
        data* temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = New;
    }
}


void addAwal(int id, char nama[], data **head){
    data *New = createData (id, nama);
    New->next = *head;
    *head = New;
}


void addBefore(int id, char nama[], int id2, data **head){
    data *New = createData (id, nama);
    data *temp = *head;
    if (*head == NULL){
        *head = New;
    } else {
        while(temp!=NULL && temp->next!=NULL && temp->next->id!=id2){
            temp = temp->next;
        }
        New->next = temp->next;
        temp->next = New;
    }
}

void hapus(int id, data** head){
    if (*head == NULL){
        return;
    }
    data* temp = *head;
    if (temp->id == id){
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!=NULL && temp->next!=NULL && temp->next->id!= id){
        temp = temp->next;
    }
    if (temp!=NULL && temp->next!=NULL){
        data* deleted=temp->next;
        temp->next = temp->next->next;
        free(deleted);
    }
}

void cetakData (data **head){
    data* temp;
    temp = *head;
    while (temp!=NULL){
        printf ("%d",temp->id);
        printf("%s", temp->nama);
        temp = temp->next;
    }
    printf ("\n");
}



int main(){
    int id, id2, n; 
    char nama[15];
    data *head = NULL;
    do{
        scanf ("%d", &n); 
        switch(n){
            case 1:
                if(head == NULL){
                    scanf ("%d", &id);
                    scanf ("%s", nama);
                    addAwal (id, nama, &head);
                }else{
                    scanf ("%d", &id);
                    scanf ("%s", nama);
                    addAkhir (id, nama, &head);
                }
                break;
            case 2 :
                scanf ("%d", &id);
                scanf ("%s", nama);
                scanf ("%d", &id2);
                addBefore (id, nama, id2, &head);
                break;
            case 3 :
                scanf ("%d", &id);
                hapus (id, &head);
                break;
            case 4 : 
                if (head == NULL) {
                    printf("\nKosong\n");
                } else {
                    cetakData (&head);
                    return 0;
                }
                break;
        }
    } while (n != 0);
    
    return 0;
}

