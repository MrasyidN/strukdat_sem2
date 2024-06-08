#include <stdio.h>

int main() {
   int i, j, n;
   printf("Masukkan ukuran pola: ");
   scanf("%d", &n);
   
   char pola[n][n];

   // inisialisasi seluruh elemen array dengan karakter yang diinginkan
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         pola[i][j] = '?';
      }
   }

   // membentuk pola mengerucut ke bawah
   for (i = 1; i < n; i++) {
      for (j = n; j > i; j--) {
         pola[i][j] = ' ';
      }
   }

   // menampilkan pola yang terbentuk
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         printf("%c", pola[i][j]);
      }
      printf("\n");
   }

   return 0;
}
