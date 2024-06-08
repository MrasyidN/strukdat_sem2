#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


struct mahasiswa{
	char nama[50];
	char nim[20];
	int usia;
};


int main(){
	int i,datamhs1;
	int usiamhs=0;
	float ratausia;
	scanf("%d",&datamhs1);
	
	struct mahasiswa datamhs [datamhs1];
	
	for(i=0;i<datamhs1;i++){
		scanf("%s", &datamhs[i].nama);
		scanf("%s", &datamhs[i].nim);
		scanf("%d", &datamhs[i].usia);
	}
	for(i=0;i<datamhs1;i++){
		printf("Data Mahasiswa ke-%d\n",i+1);
		printf("Nama : %s\n",datamhs[i].nama);
		printf("NIM : %s\n",datamhs[i].nim);
		printf("Usia : %d\n",datamhs[i].usia);
	}
	
	for(i=0;i<datamhs1;i++){
		usiamhs+=datamhs[i].usia;
	}
	ratausia=usiamhs/datamhs1;
	printf("Rerata Usia Mahasiswa : %.2f\n",ratausia);
    return 0;
}
