#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Identitas {
    char nama[100];
    int usia;
} identitas_pengunjung;

typedef struct antrian {
    identitas_pengunjung data;
    struct antrian* next;
} antrian;

typedef struct{
	antrian *head = NULL;
	antrian *tail = NULL;
}queue;

void tambahkan_antrian(char nama[], int usia, queue *Q) {
    IdentitasPengunjung pengunjung;
    printf("Masukkan nama pengunjung: ");
    scanf("%s", pengunjung.nama);
    printf("Masukkan usia pengunjung: ");
    scanf("%d", &pengunjung.usia);
    
    antrian* New = (antrian*) malloc(sizeof(antrian));
    New->data = pengunjung;
    New->next = NULL;

    if (head == NULL && tail == NULL) {
        head = tail = New;
    } else {
        tail->next = New;
        tail = New;
    }
    
    printf("[berhasil menanbahkan antrian: %s, %d ]\n", pengunjung.nama, pengunjung.usia);
}

void panggil_nama(queue *Q) {
    if (head == NULL && tail == NULL) {
        printf("Antrian kosong\n");
        return;
    }
    
    IdentitasPengunjung pengunjung = head->data;
    printf("Panggilan untuk pengunjung dengan nama %s\n", pengunjung.nama);
    
    antrian* temp = head;
    head = head->next;
    free(temp);
    
    if (head == NULL) {
        tail = NULL;
    }
    
    int jumlah_antrian = 0;
    temp = head;
    while (temp != NULL) {
        jumlah_antrian++;
        temp = temp->next;
    }
    printf("Jumlah antrian yang tersisa: %d\n", jumlah_antrian);
}

void lihat_antrian() {
    if (head == NULL && tail == NULL) {
        printf("Antrian kosong\n");
        return;
    }
    
    printf("Data antrian Puskesmas:\n");
    antrian* temp = head;
    while (temp != NULL) {
        IdentitasPengunjung pengunjung = temp->data;
        printf("Nama: %s, Usia: %d\n", pengunjung.nama, pengunjung.usia);
        temp = temp->next;
    }
}

int main() {
    int pilihan;
    do {
        printf("\nMenu:\n");
        printf("0. Keluar\n");
        printf("1. Tambahkan Antrian\n");
        printf("2. Panggil Nama\n");
        printf("3. Lihat Antrian\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 0:
                printf("Terima kasih telah menggunakan program ini\n");
                break;
            case 1:
                tambahkan_antrian();
                break;
            case 2:
                panggil_nama();
                break;
            case 3:
                lihat_antrian();
                break;
            default:
               
            printf("Pilihan tidak tersedia\n");
            break;
    }
} while (pilihan != 0);

return 0;
}
