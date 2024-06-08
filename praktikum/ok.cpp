#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    char nama[50];
    int nilai;
    struct Node* next;
} LinkedList;

LinkedList* createNode(char nama[], int nilai) {
    LinkedList* node = (LinkedList*) malloc(sizeof(LinkedList));
    static int id = 1;
    node->id = id++;
    strcpy(node->nama, nama);
    node->nilai = nilai;
    node->next = NULL;
    return node;
}

LinkedList* addNode(LinkedList* head, char nama[], int nilai) {
    LinkedList* node = createNode(nama, nilai);
    if (head == NULL) {
        head = node;
    } else {
        LinkedList* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    return head;
}

LinkedList* deleteNode(LinkedList* head, int id) {
    if (head == NULL) {
        printf("Linked list kosong\n");
    } else {
        LinkedList* temp = head;
        LinkedList* prev = NULL;
        while (temp != NULL && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Node dengan id %d tidak ditemukan\n", id);
        } else {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Node dengan id %d berhasil dihapus\n", id);
        }
    }
    return head;
}

LinkedList* updateNode(LinkedList* head, int id, int nilai) {
    if (head == NULL) {
        printf("Linked list kosong\n");
    } else {
        LinkedList* temp = head;
        while (temp != NULL && temp->id != id) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Node dengan id %d tidak ditemukan\n", id);
        } else {
            temp->nilai = nilai;
            printf("Nilai siswa dengan id %d berhasil diubah menjadi %d\n", id, nilai);
        }
    }
    return head;
}

// Fungsi untuk mencetak semua node yang masih ada di linked list
void printNodes(LinkedList* head) {
    if (head == NULL) {
        printf("Linked list kosong\n");
    } else {
        printf("Data siswa yang masih ada di linked list:\n");
        printf("ID\tNAMA\tNILAI\n");
        LinkedList* temp = head;
        while (temp != NULL) {
            printf("%d\t%s\t%d\n", temp->id, temp->nama, temp->nilai);
            temp = temp->next;
        }
    }
}

int main() {
    typedef struct Node Siswa;

    Siswa* head = NULL;
    int choice, id, nilai;
    char nama[50];

    do {
        printf("\n");
        printf("Menu:\n");
        printf("[0] Keluar\n");
        printf("[1] Input \n");
        printf("[2] Panggil siswa\n");
        printf("[3] Mengubah nilai\n");
        printf("[4] Tampilkan\n");
        printf("Pilihan anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Terima kasih telah menggunakan program ini\n");
                break;
            case 1:
    printf("Masukkan jumlah siswa yang ingin diinput: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Masukkan nama siswa: ");
        scanf("%s", nama);
        printf("Masukkan nilai siswa: ");
        scanf("%d", &nilai);
        head = addNode(head, nama, nilai);
    }
    break;

            case 2:
                printf("Masukkan id siswa yang ingin dihapus: ");
                scanf("%d", &id);
                head = deleteNode(head, id);
                break;
            case 3:
                printf("Masukkan id siswa yang ingin diubah nilai nya: ");
                scanf("%d", &id);
                printf("Masukkan nilai baru untuk siswa tersebut: ");
                scanf("%d", &nilai);
                head = updateNode(head, id, nilai);
                break;
            case 4:
                printNodes(head);
                break;
            default:
                printf("Pilihan tidak valid\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
