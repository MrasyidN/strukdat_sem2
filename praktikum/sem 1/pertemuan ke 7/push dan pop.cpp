#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct stack{
	int data[MAX];
	int top;
}stack;


void push(stack *S, int A){
	//perisak dulu ya stack penuh apa engga
	if(S->top < MAX-1){  //jika topnya belum mencapai nilai maksimum
		S->top++;   // top naikin dlu
		S->data[S->top] = A; // data diisi pada indeks  ke top
	}else{
		printf("Stack penuh\n");
	}
}

void pop(stack *S){
	//periksa dulu stacknya kosong atau tidak?
	if(S->top != -1){  // kalau stacknya tidak kosong
		printf("%d\n", S->data[S->top]);
		S->top--;
	}else{
		printf("Stack kosong\n");
	}
}
	
int main(){
	stack S;
	S.top = -1;
	push(&S, 1);
	push(&S, 2);
	push(&S, 3);
	push(&S, 4);
	push(&S, 5);
	pop(&S);
	
	return 0;
}	

	
	

