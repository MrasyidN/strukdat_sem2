#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char ket[50];
    int jumlah;
} TransaksiKeuangan;

typedef struct {
    TransaksiKeuangan transaksi[MAX];
    int top;
} Stack;

void push(Stack *s, char *ket, int jumlah) {
    if (s->top == MAX-1) {
        printf("Stack penuh\n");
    } else {
        s->top++;
        strcpy(s->transaksi[s->top].ket, ket);
        s->transaksi[s->top].jumlah = jumlah;
    }
}

void pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack kosong\n");
    } else {
        printf("Transaksi terakhir telah dihapus\n");
        s->top--;
    }
}

void display(Stack s) {
    if (s.top == -1) {
        printf("Daftar transaksi kosong\n");
    } else {
        printf("Daftar transaksi keuangan:\n");
        for (int i = s.top; i >= 0; i--) {
            printf("%s - Rp %d\n", s.transaksi[i].ket, s.transaksi[i].jumlah);
        }
    }
}

int main() {
    Stack s;
    s.top = -1;
    int pil, jumlah;
    char ket[50];
    do {
        printf("\n===== DAFTAR TRANSAKSI KEUANGAN =====\n");
        printf("1. Tambah transaksi\n");
        printf("2. Hapus transaksi terakhir\n");
        printf("3. Tampilkan daftar transaksi\n");
        printf("4. Keluar\n");
        scanf("%d", &pil);

        switch (pil) {
            case 1:
                scanf("%s", ket);
                scanf("%d", &jumlah);
                push(&s, ket, jumlah);
                printf("Transaksi berhasil ditambahkan\n");
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(s);
                break;
            case 4:
                printf("Keluar dari program\n");
                break;
            default:
                printf("pil tidak valid\n");
                break;
        }
    } while (pil != 4);

    return 0;
}

