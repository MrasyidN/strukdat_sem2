#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int id;
    char nama[50];
    struct Data* next;
    struct Data* prev;
} Data;

Data* head = NULL;

Data* createData(int id, char* nama) {
    Data* newData = (Data*) malloc(sizeof(Data));
    newData->id = id;
    strcpy(newData->nama, nama);
    newData->next = NULL;
    newData->prev = NULL;
    return newData;
}

void addAwal(int id, char* nama) {
    Data* newData = createData(id, nama);
    if (head == NULL) {
        head = newData;
    } else {
        newData->next = head;
        head->prev = newData;
        head = newData;
    }
}

void addAkhir(int id, char* nama, int id2) {
    Data* newData = createData(id, nama);
    if (head == NULL) {
        head = newData;
    } else {
        Data* temp = head;
        while (temp != NULL && temp->id != id2) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Data dengan id %d tidak ditemukan\n", id2);
        } else {
            newData->next = temp->next;
            newData->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newData;
            }
            temp->next = newData;
        }
    }
}

void hapus(int id) {
    if (head == NULL) {
        printf("List kosong\n");
    } else {
        Data* temp = head;
        while (temp != NULL && temp->id != id) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Data dengan id %d tidak ditemukan\n", id);
        } else {
            if (temp->prev == NULL) {
                head = temp->next;
            } else {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
        }
    }
}

void cetak() {
    if (head == NULL) {
        printf("List kosong\n");
    } else {
        Data* temp = head;
        while (temp != NULL) {
            printf("%d\n", temp->id);
            printf("%s\n", temp->nama);
            temp = temp->next;
        }
    }
}

int main() {
    int n, id, id2;
    char nama[50];
    while (1) {
        scanf("%d", &n);
        switch (n) {
            case 0:
                return 0;
            case 1:
                scanf("%d", &id);
                scanf("%s", nama);
                addAwal(id, nama);
                break;
            case 2:
                scanf("%d", &id);
                scanf("%s", nama);
                scanf("%d", &id2);
                addAkhir(id, nama, id2);
                break;
            case 3:
                scanf("%d", &id);
                hapus(id);
                break;
            case 4:
                cetak();
                break;
                default:
                printf("Pilihan tidak valid\n");
            }
        }
    return 0;
    }






