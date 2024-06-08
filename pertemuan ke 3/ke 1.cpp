#include <stdio.h>

void jumlah (int *a, int b){
	*a=*a+b;
}

int main(){
	int A,B;
	scanf("%d %d", &A, &B);
	jumlah(&A, B);
	printf("%d %d", A,B);
	return 0; 
	
}
