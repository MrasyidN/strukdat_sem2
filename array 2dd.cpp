#include <stdio.h>
#include <string.h>

int main(){
	int arr[2][2];
	int i,j;
	arr[0][0]=100;
	arr[1][0]=200;
	arr[0][1]=300;
	arr[1][1]=400;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d ",arr[i][j]);
		}
	}
}