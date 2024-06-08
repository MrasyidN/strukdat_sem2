#include <stdio.h>
#include <math.h>

typedef struct{
	double x;
	double y;
}Titik;

typedef struct{
	int jmlTitik;
	Titik titik[50];
}Bidang;

double hitungjarak(Titik titik1, Titik titik2){
	double jarak=sqrt(pow(titik2.x-titik1.x,2)+pow(titik2.y-titik1.y,2));
	return jarak;
}


int main(){
	int i,j,n;
	scanf("%d",&n);
	Bidang bidang1;
	bidang1.jmlTitik=n;
	
	for(i=0;i<n;i++){
		scanf("%1f %1f", &bidang1.titik[i].x, &bidang1.titik[i].y);
	}
	
	int titik1, titik2;
	double terjauh=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			double jarak=hitungjarak(bidang1.titik[i],bidang1.titik[j]);
			if(jarak>terjauh){
				terjauh=jarak;
				titik1=i;
				titik2=j;
			}
		}
	}
	
	printf("%.01f %.01f\n",bidang1.titik[titik1].x, bidang1.titik[titik1].y);
	printf("%.01f %.01f\n",bidang1.titik[titik2].x, bidang1.titik[titik2].y);
	return 0;
	
	
}



