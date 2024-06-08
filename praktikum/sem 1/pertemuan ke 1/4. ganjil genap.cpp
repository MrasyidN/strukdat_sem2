#include <stdio.h>

int jilnap(int n){
	if(n%2 == 0){
		printf("genap",n);
	}else{
		printf("ganjil",n);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	jilnap(n);
}