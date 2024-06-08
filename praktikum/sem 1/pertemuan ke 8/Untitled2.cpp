#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Deklarasi tipe data identitas_pengunjung
typedef struct {
    char nama[50];
    int usia;
} identitas_pengunjung;

// Deklarasi struktur node untuk queue
typedef struct node {
    identitas_pengunjung data;
    struct node *next;
} node;

// Deklarasi queue
typedef struct {
    node *front;
    node *rear;
} queue;

// Fungsi untuk membuat queue baru
void createQueue(queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// Fungsi untuk menambahkan data ke dalam queue
void enqueue(queue *q, identitas_pengunjung data) {
    node *newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->front == NULL) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }

    q->rear = newNode;
}

// Fungsi untuk mengeluarkan data dari queue
identitas_pengunjung dequeue(queue *q) {
    if (q->front == NULL) {
        printf("Antrian kosong\n");
        identitas_pengunjung empty = {"", 0};
        return empty;
    }

    node *temp = q->front;
    identitas_pengunjung data = temp->data;

    q->front = q->front->next;
    free(temp);

    return data;
}

// Fungsi untuk menampilkan seluruh data antrian
void displayQueue(queue *q) {
    if (q->front == NULL) {
        printf("Antrian kosong\n");
        return;
    }

    node *temp = q->front;

    printf("Daftar Antrian:\n");
    while (temp != NULL) {
        printf("Nama: %s\tUsia: %d\n", temp->data.nama, temp->data.usia);
        temp = temp->next;
    }
}

int main() {
    queue q;
    createQueue(&q);

    int choice;
    identitas_pengunjung pengunjung;

    do {
        printf("\nMenu:\n");
        printf("0. Keluar\n");
        printf("1. Tambahkan Antrian\n");
        printf("2. Panggil Nama\n");
        printf("3. Lihat Antrian\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printf("Program selesai.\n");
                break;

            case 1:
                printf("Masukkan nama pengunjung: ");
                scanf("%s", pengunjung.nama);
                printf("Masukkan usia pengunjung: ");
                scanf("%d", &pengunjung.usia);
                enqueue(&q, pengunjung);
                printf("Data pengunjung telah ditambahkan ke dalam antrian.\n");
                break;

            case 2:
                pengunjung = dequeue(&q);
                if (strcmp(pengunjung.nama, "") != 0) {
                    printf("Panggilan untuk %s\n", pengunjung.nama);
                    printf("Sisa antrian: %d\n", countQueue(&q));
                }
                break;

            case 3:
                displayQueue(&q);
                break;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi
    }

} while (choice != 0);

return 0;

