#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct{
    char data[MAX];
    int top;
} Stack;

void push(Stack *s, char c) {
    if (s->top == MAX-1) {
        printf("Stack penuh\n");
    } else {
        s->top++;
        s->data[s->top] = c;
    }
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack kosong\n");
        return '\0';
    } else {
        char c = s->data[s->top];
        s->top--;
        return c;
    }
}

void balikStr(char *str) {
    Stack s;
    s.top = -1;
    for (int i = 0; i < strlen(str); i++) {
        push(&s, str[i]);
    }
    for (int i = 0; i < strlen(str); i++) {
        str[i] = pop(&s);
    }
}

int main() {
    char str[MAX];
    scanf("%s", str);

    balikStr(str);

    printf("\n%s\n", str);

    return 0;
}

