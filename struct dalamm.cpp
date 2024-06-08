#include<stdio.h>
#include<string.h>

struct Titik {
  int X;
  int Y;
}t;

struct Garis {
  struct Titik awal;
  struct Titik akhir;
}g;

struct Persegi {
  struct Garis Garis1;
  struct Garis Garis2;
  struct Garis Garis3;
  struct Garis Garis4;
}p;

int main() {
  struct Persegi ;
  scanf("%d %d", &p.Garis1.awal.X, &p.Garis1.awal.Y);
  scanf("%d %d", &p.Garis1.akhir.X, &p.Garis1.akhir.Y);
  
  scanf("%d %d", &p.Garis2.awal.X, &p.Garis2.awal.Y);
  scanf("%d %d", &p.Garis2.akhir.X, &p.Garis2.akhir.Y);
  
  scanf("%d %d", &p.Garis3.awal.X, &p.Garis3.awal.Y);
  scanf("%d %d", &p.Garis3.akhir.X, &p.Garis3.akhir.Y);
  
  scanf("%d %d", &p.Garis4.awal.X, &p.Garis4.awal.Y);
  scanf("%d %d", &p.Garis4.akhir.X, &p.Garis4.akhir.Y);

  
  printf("Garis 1: (%d,%d) - (%d,%d)\n", p.Garis1.awal.X, p.Garis1.awal.Y, p.Garis1.akhir.X, p.Garis1.akhir.Y);
  printf("Garis 2: (%d,%d) - (%d,%d)\n", p.Garis2.awal.X, p.Garis2.awal.Y, p.Garis2.akhir.X, p.Garis2.akhir.Y);
  printf("Garis 3: (%d,%d) - (%d,%d)\n", p.Garis3.awal.X, p.Garis3.awal.Y, p.Garis3.akhir.X, p.Garis3.akhir.Y);
  printf("Garis 4: (%d,%d) - (%d,%d)\n", p.Garis4.awal.X, p.Garis4.awal.Y, p.Garis4.akhir.X, p.Garis4.akhir.Y);


return 0;
}