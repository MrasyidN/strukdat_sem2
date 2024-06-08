#include <stdio.h>

typedef struct kantin{
	char nama[50];
	int jumlah;
	float harga;
	int banyak;
	
}kantin;

int main(){
	int i,n,b;
	
	int total = 0;
	scanf("%d", &n);
	
	kantin m[n];
	for(i=0;i<n;i++){
		fflush(stdin);
		fgets(m[i].nama, sizeof(m[i].nama), stdin);
		
		scanf("%f",&m[i].harga);
		scanf("%d", m[i].banyak);
		total+=m[i].harga*m[i].banyak;
	}
	
	
	printf("&d", total);
}
