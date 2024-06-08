#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 5

typedef struct Stack{
    int top;
    int data[MAX];
} stack;

bool isEmpty(stack S){
    if(S.top <= -1){
        return true;
    }else{
        return false;
    }
}

bool isFull(stack S){
    if(S.top>=MAX-1){
        return true;
    }else{
        return false;
    }
}

void push(stack* S, int A){
    if (S->top<MAX-1){
        S->top++;
        S->data[S->top]=A;
    } else {
        printf("Stack penuh\n");
    }
}

int pop(stack* S) {
    if (S -> top != -1) {
        int Ket = S -> data[S -> top];
        S -> top--;
        return Ket;
    } else {
        printf("Stack kosong\n");
        return -1;
    }
}

int pajak (stack* S) {
    int i;
    if (S -> top == MAX - 1) {
        int total = 0;
        for (i = 0; i <= S -> top; i++) {
            total += S -> data[i];
        }
        return total * 0.1;
    } else if (S -> top == -1){
        printf("Tidak ada data\n");
        return 0;
    } else {
        printf("Data belum lengkap\n");
        return -1;
    }
}

void cetak(stack* S){
    if(isFull(*S)){
        int top =S->top;
        while(top!=-1) {
            printf("%d\n",S->data[top]);
            top--;
        }
        printf("\n");
    }else if (isEmpty(*S)){
        printf("Tidak ada data\n");
    }else {
        printf("Data belum lengkap\n");
    }
}

int main(){
    stack S;
    S.top = -1;
    int a, b;
    int Ket;
    int pajak2;
    do {
        scanf("%d", &a);
        switch (a) {
            case 1 :
                scanf("%d", &b);
                push(&S, b);
                break;

            case 2 :
                Ket = pop(&S);
                if (Ket != -1) {
                    if (Ket % 2 == 0) {
                        printf ("%d\n", Ket);
                        printf ("Genap\n");
                    } else {
                        printf("%d\n", Ket);
                        printf ("Ganjil\n");
                    }
                } else {
                	exit (0);
				}
				exit (0);
                break;

            case 3 :
                cetak(&S);
                exit (0);
                break;

            case 4 :
                pajak2 = pajak(&S);
                if (pajak != -1) {
                    printf("%d\n", pajak);
                }
                break;
        }
    } while (a != 0);

    return 0;
}
