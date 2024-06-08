// penggunaan adt biasa

#include <stdio.h>

typedef int angka;
typedef double pecahan;
typedef char kalimat[50];

int main(){
	kalimat output = "Hasilnya adalah\n";
	angka bulat = 10;
	pecahan koma = 2.5, hasil;
	
	hasil = bulat/koma;
	
	printf("%s",output);
	printf("%.2f",hasil);
	
	return 0;
	
}