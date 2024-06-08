#include <stdio.h>
#include <string.h>


int palindrom(char *kata){
	int i , j, panjang;
	
	panjang=strlen(kata); // strlen digunakan untuk menghitung panjang strting
	
	for(i=0, j=panjang-1; i<panjang/2; i++,j--){
		if(kata[i]!=kata[j]){
			return 0;
		}
	}
	return 1;
}

int main(){
	char kata[50];
	
	printf("input kata atau nomor : ");
	scanf("%d",&kata);
	
	if(palindrom(kata)){
		printf("%s merupakan palindrom", kata);
	}else{
		printf("%s bukan merupakan palindrom", kata);
	}
	return 0;
	
}