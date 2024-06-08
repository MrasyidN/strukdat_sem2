#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data untuk merepresentasikan satu data kendaraan
struct Kendaraan {
    int tahun;
    char jenis[20];
    char plat[10];
};

// Struktur data untuk merepresentasikan sebuah simpul pada linked list
struct Node {
    struct Kendaraan data;
    struct Node* next;
};

// Fungsi untuk membuat linked list kosong dengan ukuran awal yang ditentukan
struct Node* createList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    for (int i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->next = head;
        head = temp;
    }
    return head;
}

// Fungsi untuk menambahkan data kendaraan pada akhir linked list
void AddListAkhir(int tahun, char jenis[], char plat[], struct Node* head) {
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    struct Kendaraan kendaraan;
    kendaraan.tahun = tahun;
    strcpy(kendaraan.jenis, jenis);
    strcpy(kendaraan.plat, plat);
    temp->data = kendaraan;
}

// Fungsi untuk menambahkan data kendaraan pada awal linked list
void AddListAwal(int tahun, char jenis[], char plat[], struct Node** head) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Kendaraan kendaraan;
    kendaraan.tahun = tahun;
    strcpy(kendaraan.jenis, jenis);
    strcpy(kendaraan.plat, plat);
    temp->data = kendaraan;
    temp->next = *head;
    *head = temp;
}

// Fungsi untuk mencetak isi linked list
void CetakList(struct Node* head) {
    printf("Isi Linked List:\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d %s %s\n", temp->data.tahun, temp->data.jenis, temp->data.plat);
        temp = temp->next;
    }
}

int main(){
    //bikin list awal dengan nama ListUtama;
    struct Node* ListUtama = createList(5);
    
    //tambahkan beberapa kendaraan ke dalam linked list
    AddListAkhir(2010, "Sedan", "B 1234 CD", ListUtama);
    AddListAkhir(2015, "SUV", "D 5678 EF", ListUtama);
    AddListAwal(2020, "Hatchback", "F 9012 GH", &ListUtama);
    AddListAkhir(2005, "Pick-up", "H 3456 IJ", ListUtama);
    AddListAwal(2018, "Coupe", "J 7890 KL", &ListUtama);
    
    /*
	cetak isi linked list
    
	
    AddListAkhir(8,"bmw", "D 1122 A", ListUtama);
    AddListAwal(9,"bmw", "D 2221 A",&ListUtama);
    AddListAkhir(7, "bmw", "D 1333 A",ListUtama);
    AddListAwal(19, "bmw", "D 1131 A",&ListUtama);
   
    */
	CetakList(ListUtama);
}
    //beberapa contoh operasi yang bisa dilakukan pada linked list seperti menghapus, mencari, atau mengubah data
    //bisa ditambahkan sendiri sesuai kebutuhan
    //cont

