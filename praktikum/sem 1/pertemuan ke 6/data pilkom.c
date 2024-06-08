#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct identitas_mahasiswa{
	int id;
	char username[50];
    int nilai;
    char nim[20];
}identitas_mahasiswa1;

typedef struct node{
    identitas_mahasiswa1 data;
    struct node *prev;
    struct node *next;
}node1;

node1* buat_node(identitas_mahasiswa1 data) {
    node1* node = (node1*) malloc(sizeof(node1));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void tambahAwal(node1 **head, identitas_mahasiswa1 data) {
    node1* node = buat_node(data);
    if (*head == NULL) {
        *head = node;
        return;
    }
    if (strcmp((*head)->data.username, data.username) == 0) {
        printf("username sudah ada\n");
        return;
    }
    node->next = *head;
    (*head)->prev = node;
    *head = node;
}

void hapus(node1 **head, int id) {
    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }
    node1* node = *head;
    if (node->data.id == id) {
        *head = node->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(node);
        return;
    }
    while (node!= NULL && node->data.id != id) {
        node = node->next;
    }
    if (node == NULL) {
        printf("Node dengan id %d tidak ditemukan\n", id);
        return;
    }
    node->prev->next = node->next;
    if (node->next!= NULL) {
        node->next->prev = node->prev;
    }
    free(node);
}

void tampilkanData(node1 *head) {
    printf("Daftar Mahasiswa:\n");
    while (head != NULL) {
        printf("ID: %d, Username: %s, Nilai: %d, NIM: %s\n", head->data.id, head->data.username, head->data.nilai, head->data.nim);
        head = head->next;
    }
}

void ratarata(node1 *head) {
    int jumlah_data = 0;
    int total_nilai = 0;
    float rerata = 0.0;
    while (head != NULL) {
        jumlah_data++;
        total_nilai += head->data.nilai;
        head = head->next;
    }
    if (jumlah_data > 0) {
        rerata = (float) total_nilai / jumlah_data;
        printf("Jumlah Data: %d\n", jumlah_data);
        printf("Rerata Nilai: %.2f\n", rerata);
        if(rerata >= 87 && rerata <= 100){
        	printf("Indeks: A(Lulus)\n");
	    }else if(rerata >= 77 && rerata <= 86){
	        printf("Indeks: B(Lulus)\n");
	    }else if(rerata >= 65 && rerata <= 76){
	        printf("Indeks: C(Lulus)\n");
	    }else if(rerata >= 55 && rerata <= 64){
	        printf("Indeks: D(Tidak Lulus)\n");
	    }else{
	        printf("Indeks: E Tidak Lulus)\n");
	    }
	} else {
    printf("List kosong\n");
}
}

void ubah_username(node1 *head, int id, char *username_baru){
	while (head!= NULL && head->data.id != id){
	head = head->next;
	}if (head == NULL) {
		printf("Node dengan id %d tidak ditemukan\n", id);
		return;
	}if (strcmp(head->data.username, username_baru) == 0){
		printf("Username sudah ada\n");
		return;
	}
	strcpy(head->data.username, username_baru);
}

int main () {
	node1 *head = NULL;
	int pilihan;
	do {
		printf("=============== PROGRAM DOUBLE LINKED LIST DATA MAHASISWA PILKOM 2022 =====================\n");
		printf("[0] Keluar\n");
		printf("[1] Tambah Data\n");
		printf("[2] Hapus Data\n");
		printf("[3] Tampilkan Data\n");
		printf("[4] Ubah Username\n");
		printf("[5] Tampilkan Statistik Data\n");
		printf("Pilih menu : ");
		scanf("%d", &pilihan);
		switch (pilihan) {
		
			case 1: {
				identitas_mahasiswa1 mahasiswa;
				printf("ID: ");
				scanf("%d", &mahasiswa.id);
				printf("Username: ");
				scanf("%s", mahasiswa.username);
				printf("Nilai: ");
				scanf("%d", &mahasiswa.nilai);
				printf("NIM: ");
				scanf("%s", mahasiswa.nim);
				tambahAwal(&head, mahasiswa);
				break;
			}
			case 2: {
				int id;
				printf("Masukkan ID yang akan dihapus: ");
				scanf("%d", &id);
				hapus(&head, id);
				break;
			}
			case 3: {
				tampilkanData(head);
				break;}
			case 4: {
				int id;
				char username_baru[50];
				printf("Masukkan ID: ");
				scanf("%d", &id);
				printf("Masukkan Username baru: ");
				scanf("%s", username_baru);
				ubah_username(head, id, username_baru);
				break;
			}
			case 5: {
				ratarata(head);
				break;
			}
			case 6: {
				printf("Program berakhir\n");
				break;
			}
			case 0: {
				printf("Program selesai.\n");
				break;
			}
			default: {
				printf("Pilihan tidak valid\n");
				break;
			} 
		} 
	}while (pilihan != 0);
	return 0;
}
