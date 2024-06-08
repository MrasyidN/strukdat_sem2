#include <stdio.h>

typedef struct titik{
	int x;
	int y;
}t;

typedef struct garis{
	t awal;
	t akhir;
}g;

typedef struct persegi{
	g garis1;
	g garis2;
	g garis3;
	g garis4;
}p;


int main(){
	persegi p;
	
	scanf("%d", &persegi.garis1);
	scanf("%d", &persegi.garis2);
	scanf("%d", &persegi.garis3);
	scanf("%d", &persegi.garis4);
	

}