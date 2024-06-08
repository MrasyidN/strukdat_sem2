#include <stdio.h>
#include <string.h>
#define MAX 5

int max = 5;
char buku[MAX];

int top = 0;

void input(){
	char data;
	if(top >= max){
		printf("data penuh");
	}else{
		scanf("%s", &data);
		buku[top] = data;
		top++;
	}
}

void cetak(){
	printf("data stack array : ");
	for(int i = max-1; i >= 0; i--){
		if(buku[i] != NULL){
			printf("data : %c", buku[i]);
				
		}	
	}
	printf("\n");
}

int main(){
	
	input();
	cetak();
//	input("sunda");
//	cetak();
}

