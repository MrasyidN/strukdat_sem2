#include <stdio.h>


void prima(int n){
	int i;
	int m=0;
	if(n<0){
		printf("%d bilangan negatif",n);
		return;
	}
	for(i=1;i<=n;i++){
		if(n%i == 0){
			m++;
		} 
	}
	if(m == 2){
		printf("%d merupakan bilangan prima",n);
	}else{
		printf("%d bukan merupakan bilangan prima",n);
	}
	
}

int main(){
	int n;
	printf("input nomor: ");
	scanf("%d",&n);
	
	prima(n);
}