//soal a

#include <stdio.h>

int main(){
	int n,i,j;
	char h;
	
	printf("banyak huruf :");
	scanf("%d",&n);
	printf("input huruf :");
	scanf(" %c",&h);
	
	char pola[n][n]; 
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			pola[i][j]=' ';
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n-i; j++){
			pola[i+j][j]=h;
		}
	}
	
	for(i=0;i<=n;i++){
		for(j=n;j>0;j--){
			printf("%c",pola[i][j]);
		}
		printf("\n");   
	}
	return 0;
}
