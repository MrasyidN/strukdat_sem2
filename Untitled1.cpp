#include <stdio.h>
#include <stdlib.h>

void tukar (int &a, int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int main(){
	int n, temp, i, jmlTukar,u;
	printf("Masukan banyak data yang akan diurutkan: ");
	scanf("%d",&n);
	printf("Masukan data yang belum terurut: \n");
	int A[n];
	for(i=0;i<n;i++){ //untuk menyimpan array 
		scanf("%d",&A[i]);
	}
	printf("\nSELECTION SORT");
	for (i=0;i<n-1;i++){
		jmlTukar=i;
		for(int j=i+1;j<n;j++){
			if(A[j]>A[jmlTukar]){
				jmlTukar=j;
			}
		}
		tukar(A[i],A[jmlTukar]);
		printf("\niterasi ke %d : ",i+1);
    	for (int k=0;k<n;k++){
    		printf("%d ",A[k]);
		}
	}
	
    printf("\n\nSetelah diurutkan selection sort: \n");
    for (i=0;i<n;i++){
    	printf("%d ",A[i]);
	}
	printf("\n");

	return 0;
}