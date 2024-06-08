#include <stdio.h>
#include <stdbool.h>
#define MAX 5


typedef struct stack{
	int data[MAX];
	int top;
}stack;

void push(stack *S, int A){
	if(S->top<MAX-1){
		S->top++;
		S->data[S->top]=A;
	}else{
		printf("stack penuh\n");
	}
	
}

void pop(stack *S){
	if(S->top!=-1){
		printf("&d", S->data [S->top]);
		S->top--;
	}else{
		printf("stack kosong");
	}
	
}


void cetak(stack *S){
	int top=MAX-1;
	while(top!=-1){
		printf("\nindeks %d %d", top, S->data[top]);
		top--;
	}
}


int main(){
	stack S;
	S.top=-1;
	push(&S,1);
	push(&S,2);
	push(&S,3);
	push(&S,4);
	push(&S,5);
	cetak(&S);
	pop(&S);
	cetak(&S);
	return 0;
}
