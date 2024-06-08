#include <stdio.h>

int main (){
	int i,j,n;
	
	char h;
	
	scanf("%d\n",&n);
	scanf("%c",&h);
	
	char arr[n][n];
	
	for(i=0; i<n; i++){
		for (j=0; j<n; j++){
			arr[i][j]=h;
    	}
	}
	for(i=0; i<n; i++){
		for(j=n-1; j>=i; j--){
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}

}