#include <stdio.h>
#include <math.h>

typedef struct{
    double x;
    double y;
}Titik;

double jarak(Titik A, Titik B){
    double jarak=sqrt(pow(B.x-A.x,2)+pow(B.y-A.y,2));
    return jarak;
}
void TitikPotong(Titik titik[], int n){
    int i, j;
    double jarakJauh=0;
    Titik titik1,titik2;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            double d=jarak(titik[i], titik[j]);
            if (d>jarakJauh){
                jarakJauh=d;
                titik1=titik[i];
                titik2=titik[j];
            }
        }
    }
    printf("\n%.0lf %.0lf\n%.0lf %.0lf", titik1.x, titik1.y, titik2.x, titik2.y);
}

int main(){
    int i, n;
    scanf("%d", &n);
    Titik titik[n];
    for(i=0;i<n;i++){
        scanf("%lf %lf", &titik[i].x, &titik[i].y);
    }
    TitikPotong(titik,n);
    return 0;
}
