#include <stdio.h>
#include <string.h>

int main(){
	int nomorAntrian[2][2]={{12,13},{100,200}};
	int i,j;
	for(i=0;i<2;i++){
		for (j=0;j<2;j++){
			printf("%d ",nomorAntrian[i][j]);
		}
	}
	return 0;
}