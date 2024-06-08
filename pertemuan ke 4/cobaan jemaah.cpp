#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct data jamaah
typedef struct Jamaah {
    char nama[50];
    char gender[10];
    int usia;
    struct Jamaah *next;
} Jamaah;

// Fungsi untuk membuat node baru
Jamaah *buatJamaah(char *nama, char *gender, int usia) {
    Jamaah *node = (Jamaah *)malloc(sizeof(Jamaah));
    strcpy(node->nama, nama);
    strcpy(node->gender, gender);
    node->usia = usia;
    node->next = NULL;
    return node;
}

// Fungsi untuk menambahkan node jamaah ke dalam linked list sesuai dengan spesifikasi
void tambahJamaah(Jamaah **head, char *nama, char *gender, int usia) {
    Jamaah *node = buatJamaah(nama, gender, usia);
    if (*head == NULL) {
        *head = node;
        return;
    }
    Jamaah *current = *head;
    Jamaah *prev = NULL;
    while (current != NULL) {
        if (node->usia > current->usia) {
            break;
        }
        if (node->usia == current->usia) {
            if (strcmp(node->gender, "Perempuan") == 0 && strcmp(current->gender, "Laki-laki") == 0) {
                break;
            }
        }
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        node->next = *head;
        *head = node;
    } else {
        prev->next = node;
        node->next = current;
    }
}

// Fungsi untuk mencetak linked list
void printList(Jamaah *head) {
    if (head == NULL) {
        printf("Daftar List Kosong <tidak ada data yang masuk>\n");
        return;
    }
    Jamaah *current = head;
    while (current != NULL) {
        printf("%s\n", current->nama);
        printf("%s\n", current->gender);
        printf("%d\n", current->usia);
        current = current->next;
    }
}

// Fungsi untuk menghapus node jamaah pertama dalam linked list
void hapusJamaah(Jamaah **head) {
    if (*head == NULL) {
        return;
    }
    Jamaah *temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main() {
    int code = 1; // default code untuk mendaftar
    int n; // jumlah jamaah yang ingin mendaftar atau dipanggil
    char nama[50];
    char gender[10];
    int usia;
    Jamaah *head = NULL; // inisialisasi linked list kosong
    while (code != 0) {
        scanf("%d", &code);
        switch (code) {
            case 1: // mendaftar
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    scanf("%s", nama);
                    scanf("%s", gender);
                    scanf("%d", &usia);
                    tambahJamaah(&head, nama, gender, usia);
                }
                break;
            case 2: // dipanggil
            printList
            
    // Jika tidak ada data
    if (temp == NULL) {
        printf("Daftar List Kosong <tidak ada data yang masuk>\n");
    }
    else {
        // Menampilkan data
        while (temp != NULL) {
            printf("%s\n%s\n%d\n", temp->nama, temp->gender, temp->usia);
            temp = temp->next;
        }
    }
}

return 0;

}

return 0;

