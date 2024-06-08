#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct stack {
	int data [MAX];
	int top;
}stack;

void push (stack *S, int A){
	//periksa dulu stacknya penuh atau tidak//
if (S->top < MAX-1){ //jika topnya belum mencapai nilai maksimal array//
		S->top++; //topnya naikin dulu//
		S->data [S->top]=A;//data diisi pada indeks ke top//
	}else{
		printf (" Stack penuh \n");
	}
}

 void pop (stack *S){
    //periksa dulu stacknya kosong atau tidak//
    if (S->top != -1){//kalau stacknya tidak kosong
    	printf("%d\n", S->data [S-> top]);
    	S->top--;
	}else{
    	printf ("Stack kosong\n");
	}
}

void cetakStack (stack *S){
	int top = MAX -1; // isinya 4
	while (top!= -1){ // terus berulang dampai top nya 0
		printf("\n [Indeks ke-%d] --> %d",top,S->data[top]);  
		top--; // topnya dikurangin 1
	}
}

//cara nge cek stack kosong
bool isEmpty(stack S){ // tidak pakai pointer karena tidak butuh alamat dari pointer(cuma ngecek saja)
	if(S.top<=-1){ //posisi top nya ada di -1 atau kurung dari itu
		return true; // keluar nilai 1 kalau benar
	}else{
		return false; // keluar nilai 0 kalau salah (ada isinya)
	}
}

// cara mengecek stacknya full
bool isFull(stack S){
	if(S.top == MAX-1){
		return true;
	}else{
		return false;
	}
}


int main (){
    stack S;
    S.top = -1;
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
  	push(&S, 6);
   cetakStack (&S);
	printf("\nApakah stacknya kosong?\n");
	printf("%d", isEmpty(S));
	printf("\nApakah stacknya penuh?\n");
	printf("%d", isFull(S));
    return 0;
}
