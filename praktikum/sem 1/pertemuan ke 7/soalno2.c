#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 1000

typedef struct {
    int top;
    int data[MAX];
} Stack;

void push(Stack *s, int n) {
    s->top++;
    s->data[s->top] = n;
}

int pop(Stack *s) {
    int n = s->data[s->top];
    s->top--;
    return n;
}

int ubah(char *binner) {
    Stack s;
    s.top = -1;
    int i, len = strlen(binner);
    int a = 0;
    int bit;
    for (i = 0; i < len; i++) {
        bit = binner[i] - '0';
        push(&s, bit);
    }
    for (i = 0; i < len; i++) {
        bit = pop(&s);
        a += bit * pow(2, i);
    }
    return a;
}

int main() {
    char binner[MAX];
    int bit;
    scanf("%s", binner);
    bit = ubah(binner);
    printf("\n%d\n", bit);
    return 0;
}

