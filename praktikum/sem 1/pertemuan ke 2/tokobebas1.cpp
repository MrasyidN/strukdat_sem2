#include <stdio.h>

typedef struct tokobebas{
    char nama[100];
    int jumlah;
    float harga;
    int banyak;
}toko;

int main(){
    int i, n, b;
    int total=0;
    scanf("%d", &n);
    
    toko m[n];
    for(i=0;i<n;i++){
    	fflush(stdin);
    	fgets(m[i].nama,sizeof(m[i].nama),stdin);
        //scanf("%s", &m[i].nama);
        scanf("%f", &m[i].harga);
        scanf("%d", &m[i].banyak);
        total+=m[i].harga*m[i].banyak;
	}
	
	printf("%d",total);

    return 0;
}
