#include <stdio.h>
	int a, b,c;
struct data{
	char nama[40];
	char  matkul[10];
}
struct data mhs[2];
void matkul(int m){
	int i,j,x;
	printf("Masukan banyak mata kuliah yang diambil");
	scanf("%d", &x);
	for(i = 0; i < x; i++){
		scanf("%s", &mhs)
	}
	
}
void nama(int n){
	for(i = 0;i<n;i++){
		printf("Masukan banyak mata kuliah yang diambil");
		scanf("%d", &c);
		printf("Masukan mahasiswa absen ke %d: ", i+1);
		scanf("%s", &mhs[i]);	
	}
}

void mk(int o){
	for(int i =0; i<o;i++){
		printf("Masukan Mata Kuliah ke %d", i+1);
		scanf("%s", &matkull[i]);
	}
}
int main(){
	printf("Masukan banyak mahasiswa");
	scanf("%d", &a);
	printf("Masukan banyak mata kuliah");
	scanf("%d", &b);
	mk(b);
	
	
}