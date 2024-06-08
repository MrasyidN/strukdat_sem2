#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

typedef struct{
    char data[MAX];
    int top;
}Stack;

void push(Stack *s, char n){
    s->top++;
    s->data[s->top] = n;
}

char pop(Stack *s){
    char n = s->data[s->top];
    s->top--;
    return n;
}

int check(char *str){
    Stack s;
    s.top = -1;
    int i, len = strlen(str);
    
    for(i = 0; i < len; i++){
        push(&s, str[i]);
    }
    for(i = 0; i < len; i++){
        if(str[i]!= pop(&s)){
            return 0;
        }
    }
    return 1;
}

int main(){
    char str[MAX];
    scanf("%s",str);
    int len = strlen(str);
    
    printf("\n %d \n", len);
    if(check(str)){
        printf("palindrom");
    }else{
        printf("bukan palindrom");
    }
}

