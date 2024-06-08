#include <stdio.h>

struct mahasiswa{
	char nama[100];
	char nim[20];
	int usia;
}mahasiswa1;


int main(){
	mahasiswa1;
	
	fflush(stdin);
	fgets(mahasiswa1.nama, sizeof(mahasiswa1.nama), stdin);
	scanf("%s", &mahasiswa1.nim);
	scanf("%d", &mahasiswa1.usia);
	
	
	printf("nama ; %s\n", mahasiswa1.nama);
	printf("nim ; %s\n", mahasiswa1.nim);
	printf("usia ;%d\n", mahasiswa1.usia);
	
	return 0;
}
