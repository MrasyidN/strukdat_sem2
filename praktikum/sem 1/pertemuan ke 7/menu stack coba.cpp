#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct stack {
    int data[MAX];
    int top;
} stack;

void push(stack *S, int A) {
    //periksa dulu stacknya penuh atau tidak//
    if (S->top < MAX - 1) { //jika topnya belum mencapai nilai maksimal array//
        S->top++; //topnya naikin dulu//
        S->data[S->top] = A;//data diisi pada indeks ke top//
    }
    else {
        printf("Stack penuh\n");
    }
}

int pop(stack *S) {
    //periksa dulu stacknya kosong atau tidak//
    if (S->top != -1) {//kalau stacknya tidak kosong
        int data = S->data[S->top];
        S->top--;
        return data;
    }
    else {
        printf("Stack kosong\n");
        return -1;
    }
}

void cetakStack(stack *S) {
    int top = S->top; // isinya 4
    while (top != -1) { // terus berulang dampai top nya 0
        printf("\n[Indeks ke-%d] --> %d", top, S->data[top]);
        top--; // topnya dikurangin 1
    }
}

//cara nge cek stack kosong
bool isEmpty(stack S) { // tidak pakai pointer karena tidak butuh alamat dari pointer(cuma ngecek saja)
    if (S.top <= -1) { //posisi top nya ada di -1 atau kurung dari itu
        return true; // keluar nilai 1 kalau benar
    }
    else {
        return false; // keluar nilai 0 kalau salah (ada isinya)
    }
}

// cara mengecek stacknya full
bool isFull(stack S) {
    if (S.top == MAX - 1) {
        return true;
    }
    else {
        return false;
    }
}


int main() {
    stack S;
    S.top = -1;

    int choice, data;
    while (1) {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Print Stack");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter data to push: ");
            scanf("%d", &data);
            push(&S, data);
            break;

        case 2:
            data = pop(&S);
            if (data != -1) {
                printf("\nPopped data: %d", data);
            }
            break;

        case 3:
            printf("\nStack contents:\n");
            cetakStack(&S);
            break;

        case 4:
            printf("\nExiting program.\n");
            return 0;

        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

