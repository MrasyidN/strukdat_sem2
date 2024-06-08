#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data{
    int id;
    char nama[15];
    int nilai;
    struct Data* next;
}data;

data* createData (int id, char nama[15], int nilai){
	data* New = (data*)malloc(sizeof(data));
	New -> id = id;
	strcpy(New -> nama, nama);
	New -> nilai = nilai;
	New -> next = NULL;
	return New;
}

data *addAwal(int id, char nama[50], int nilai, data **head){
	data *add;
	add = createData(id, nama, nilai);
	add -> next = *head;
	*head = add;
	
	return add;
}

void deleteAkhir(data **head){
	data *help, *del;
	if(*head == NULL){
		printf("tidak ada data");
	}else{
		help = *head;
		del = help;
		while(del -> next != NULL){
			help = del;
			del = del->next;
		}
		help -> next = NULL;
		free(del);
	}
}

data* updateData(int id, int nilai, data* head) {
    if (head == NULL) {
        printf("Linked list kosong\n");
    } else {
        data* temp = head;
        while (temp != NULL && temp -> id != id) {
            temp = temp -> next;
        }
        if (temp == NULL) {
            printf("Node dengan id %d tidak ditemukan\n", id);
        } else {
            temp -> nilai = nilai;
            printf("Nilai siswa dengan id %d berhasil diubah menjadi %d\n", id, nilai);
        }
    }
    return head;
}

void cetakData (data* head) {
    data* temp = head;
    while (temp != NULL) {
        printf("%d %s %d\n", temp -> id, temp -> nama, temp -> nilai);
        temp = temp -> next;
    }
}

int main(){
    typedef struct Data mhs;
    int id = 0;
    mhs* head = NULL;
    int n, nilai, i, m;
    char nama[50];
    
    do {
        printf ("Menu : \n");
        printf ("[0] Keluar \n");
        printf ("[1] Input \n");
        printf ("[2] Panggil \n");
        printf ("[3] Ubah Nilai \n");
        printf ("[4] Tampilkan \n");
        printf ("Masukkan pilihan : ");
        scanf ("%d", &n);
        
        switch (n){
            case 0 :
                printf ("keluar");
            break;
            
            case 1 :
                printf ("Masukkan jumlah siswa : "); scanf ("%d", &m);
                for (i = 0; i < m; i++){
                    id++;
                    printf ("Masukan Nama : "); scanf ("%s", nama);
                    printf ("Masukan Nilai : "); scanf ("%d", &nilai);
                    if (i == 0){
                        head = createData(id, nama, nilai);
                    } else {
                        head = addAwal(id, nama, nilai, &head);
                    }
            }
                break;
            case 2 :
                deleteAkhir(&head);
                break;
                
            case 3 :
                printf("id yang ingin diubah : ");
                scanf("%d", &id);
                printf("Nilai baru : ");
                scanf("%d", &nilai);
                head = updateData(id, nilai, head);
                break;
            
            case 4 :
                cetakData(head);
                break;
            default :
            printf ("...");
            break;
        }
    }while  (n != 0);
    
    return 0;
}
