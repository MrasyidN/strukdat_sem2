#include <stdio.h>

/*
syarat matriks perkalian
jika ada matriks a x c dan matriks c x b
maka akan menghasilkan matriks a x b
*/

int main()
{
	int i, j, a, b, c,d, jumlah=0, k;
	
	printf("masukan banyak baris matriks pertama:");
	scanf ("%d", &a);
	printf("masukan banyak kolom matriks pertama:");
	scanf ("%d", &b);
	printf("masukan banyak kolom matriks kedua:");
	scanf ("%d", &c);
	printf("Masukan lama tahun");
	scanf ("%d", &d);
	
	int A[a][b];
	int B[b][c];
	int C[100][100];

	for (i=0; i<a; i++)//baris
	{
		for (j=0; j<b; j++)//kolom
		{
			scanf ("%d", &A[i][j]);
		}
	}
	
	for (i=0; i<b; i++)//baris
	{
		for (j=0; j<c; j++)
		{
			scanf ("%d", &B[i][j]);
		}
	}
	printf ("\n");
	
	for (i=0; i<a; i++)
	{
		for (j=0; j<b; j++)
		{
			printf ("%d ", A[i][j]);
		}
	printf ("\n");
	}
	
	printf ("\n");
	for (i=0; i<b; i++)
	{
		for (j=0; j<c; j++)
		{
			printf ("%d ", B[i][j]);
		}
	printf ("\n");
	}
	printf ("\n");
	for (i=0; i<a; i++)
	{
		for (j=0; j<c; j++)
		{
			for (k=0; k<b; k++)
			{
				jumlah = jumlah + A[i][k]*B[k][j];
			
		C[i][j]=jumlah;
		jumlah=0;
		}
	}
}
	printf ("\n");
	
	for (i=0; i<a; i++)
	{
		for (j=0; j<c; j++)
		{
			printf ("%d ", C[i][j]);
		}
	printf ("\n");
	}
	
	return 0;
}
