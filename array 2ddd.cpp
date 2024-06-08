#include <stdio.h>
#include <string.h>
int main (){
	int i,j;
	char nama [3][4][20] = {
		"AC Milan","Barcelona","Porto","Monaco",
		"Livervool","Real Madrid","CSK Moskow","PSG",
		"rasyid","rhisma","rio","gerald",
	};
	for(i=0;i<3;i++){
		for(j=0;i<4;j++){
			printf("%s ",nama[i][j]);
		}
		
	}
}