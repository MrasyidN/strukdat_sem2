#include<stdio.h>

int main(){
	int c,i,j;
	scanf("%d",&c);
	if(c==1){
		char A[1][1][20]={{""}};
			for(i=0; i<1; i++){
				for(j=0; j<c; j++){
					scanf("%s",&A[i][j]);
				}
			}
			printf("\n");
			for(i=0; i<1; i++){
				for(j=0; j<1; j++){
					printf("%s",A[i][j]);
				}
				printf ("\n");
			}
	}else if(c>1 && c<5){
		char A[2][2][20]={{"",""},{"",""}};
			for(i=0; i<1; i++){
				for(j=0; j<c; j++){
					scanf("%s", &A[i][j]);
				}
			}
			printf("\n");
			for(i=0; i<2; i++){
				for(j=0; j<2; j++){
					printf(" %s",A[i][j]);
				}
				printf ("\n");
			}
	}else if(c>3 && c<10){
		char A[3][3][20]={{"","",""},{"","",""},{"","",""}};
			for(i=0; i<1; i++){
				for(j=0; j<c; j++){
					scanf(" %s",&A[i][j]);
				}
			}
			printf("\n");
			for(i=0; i<3; i++){
				for(j=0; j<3; j++){
					printf(" %s",A[i][j]);
				}
				printf ("\n");
			}
	}
	
}
