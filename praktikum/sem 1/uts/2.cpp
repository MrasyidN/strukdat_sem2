#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nama[20];
	int usia;
	char nim[6];
	
}mhs;

void balik(mhs arr[], int n){
	for(int i=n-1;i>=0;i++){
		printf("%s", arr[i].nama);
		printf("%d", arr[i].usia);
		printf("%s", arr[i].nim);
	}
	
}

int main(){
	int i,n;
	mhs arr[50];
	
	scanf("%d", &n);
	dor(i=0;i<n;i++){
		scanf("%s". arr[i].nama);
		scanf("%d". &arr[i].usai);
		scanf("%s". arr[i].nim);
		
	}
	
	balik(arr,n);
	return 0;
}


4
Rebina
19
2102372
Dwi
22
2102211
Galvin
20
2102168
Hilmi
20
2102643
