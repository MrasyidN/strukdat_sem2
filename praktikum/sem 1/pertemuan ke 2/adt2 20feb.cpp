#include <stdio.h>
struct mahasiswa{
	char nama[50];
	char nim[20];
	int usia;
};


int main(){
	struct mahasiswa mahasiswa1;
	
	fflush(stdin); // fflush menjadi tempat perulangan
	fgets(mahasiswa1.nama, sizeof(mahasiswa1.nama), stdin);  // stdin tempat penyimpanan
	scanf("%s", &mahasiswa1.nim);
	scanf("%d", &mahasiswa1.usia);
	
	
	printf("Nama : %s",mahasiswa1.nama);
	printf("Nim	 : %s\n",mahasiswa1.nim);
	printf("Usia : %d\n",mahasiswa1.usia);
	
	return 0;
}