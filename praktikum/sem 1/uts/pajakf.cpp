#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
    int top;
    int data[MAX];
}stack;

bool isEmpty(stack S){
    return S.top==-1;
}

bool isFull(stack S){
    return S.top==MAX - 1;
}

void push(stack *S, int A){
    if(isFull(*S)){
        printf("Stack penuh\n");
    }else{
        S->top++;
        S->data[S->top]=A;
    }
}

int pop(stack *S){
    if(isEmpty(*S)){
        printf("Stack kosong\n");
        return -1;
    }else {
        int Ket = S->data[S->top];
        S->top--;
        return Ket;
    }
}

void printStack(stack S) {
    if(isEmpty(S)) {
        printf("Tidak ada data\n");
    }else if (S.top < MAX - 1){
        printf("Data belum lengkap\n");
    }else{
        for(int i= S.top;i>=0;i--){
            printf("%d\n", S.data[i]);
        }
    }
}

void printTax(stack S){
    if(isEmpty(S)){
        printf("Tidak ada data\n");
    }else if(S.top < MAX - 1){
        printf("Data belum lengkap\n");
    }else{
        int total = 0;
        for (int i = S.top; i >= 0; i--) {
            total += S.data[i];
        }
        int tax = total / 10;
        printf("%d\n", tax);
    }
}

int main(){
    stack S;
    S.top = -1;
    int a, b;

    do{
        scanf("%d", &a);
        switch (a){
            case 1:
                scanf("%d", &b);
                push(&S, b);
                break;
            case 2:
                b=pop(&S);
                if(b!=-1) {
                    printf("%d\n", b);
                    if (b%2==0) {
                        printf("Genap\n");
                    } else {
                        printf("Ganjil\n");
                    }
                }
                break;
            case 3:
                printStack(S);
                break;
            case 4:
                printTax(S);
                break;
            default:
                printf("Input tidak valid\n");
                break;
        }
    } while (true);

    return 0;
}

