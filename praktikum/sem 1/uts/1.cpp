#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,i;
	float r=0;
	float t;
	float rt;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%f",&t);
		r+=t;
	}
	rt=r/n;
	printf("%.2f", rt);
	return 0;
	
}
