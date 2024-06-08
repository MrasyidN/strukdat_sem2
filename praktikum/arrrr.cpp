#include <stdio.h>

int main() {
  int n, i, j, k;
  char arr[k][k];
  char inputChar;
  
  scanf("%d\n", &k);
  scanf("%c", &inputChar);
  
  // mengisi array dengan karakter yang diinputkan
  for (i = 0; i < k; i++) {
    for (j = 0; j < k; j++) {
      arr[i][j] = inputChar;
    }
  }

  // menampilkan array yang membentuk pola
  for (i = 0; i < k; i++) {
    for (j = k-1; j >= i; j--) {
      printf("%c ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}