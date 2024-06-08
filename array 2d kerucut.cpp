#include <stdio.h>

int main() {
    int n;
    char c;
	int i,j;
		
    scanf("%d", &n);
    scanf("%c", &c);
        
    char arr[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            arr[i][j] = ' ';
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-i; j++) {
            arr[i+j][j] = c;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c", arr[i][j]);
        }printf("\n");
    }

    return 0;
}
