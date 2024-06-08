#include<stdio.h>
#include<stdlib.h>


void tukar(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int main(){
	int mat[4][2];
	int tot[4]={0,0,0,0};
	float total1=0, total2=0, total;
	int i, n=4,j,jmlTukar;
	char name[4][20]={"Ana", "Diana","Cahya","Bambang"};
	
	for(i = 0; i < 4; i++){
		printf("Masukan Nilai ujian 1 dan 2 orang ke-%d\n", i+1);
		for(j =0; j < 2; j++){
			printf("Ujian ke-%d :",j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(j=0; j< n;j++){
		total1 = total1 + mat[j][0];
	}
	for(j=0; j< n;j++){
		total2 = total2 + mat[j][1];
	}
	
	total1 = total1 / 4;
	total2 = total2 /4; 
	
	for(i = 0; i < 4;i++){
		for(j = 0;j<2;j++){
			tot[i]+= mat[i][j] ;
		}
	}
	
	printf("\n\n----------------------------------------------------------------------------------");
	printf("\nSoal A nomor 4\n");
	if( total1 < total2){
		printf("Ujian 1 lebih sulit karena memiliki rata-rata nilai ujian %.2f dibanding rata-rata nilai ujian 2 %.2f", total1, total2);
	}else{
		printf("Ujian 2 lebih sulit karena memiliki rata-rata nilai ujian %.2f dibanding rata-rata nilai ujian 2 %.2f", total2, total1);
	}
	printf("\n\n----------------------------------------------------------------------------------");
	printf("\nSoal b nomor 4\n");
	
	for (i=0;i<n-1;i++){
		jmlTukar=i;
		for(int j=i+1;j<n;j++){
			if(tot[j]>tot[jmlTukar]){
				jmlTukar=j;
			}
		}
		tukar(tot[i],tot[jmlTukar]);
	}
	for (int k=0;k<n;k++){
			printf("%s nilai rata-rata : ",name[k]);
    		printf("%d\n",tot[k]/2);
    		
		}
}