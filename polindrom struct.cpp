#include <stdio.h>

typedef struct dataSiswa{
    char nim[10];
    char nama[100];
    int usia;
    int kelas[10];
    
}dataSiswa;

int main(){
    dataSiswa mahasiswa[3];
    
    for(int i=0;i<3;i++){
    
        scanf("%s", &mahasiswa[i].nim);
       // strcpy(mahasiswa.nim, "%d",nim);
        scanf("%s", &mahasiswa[i].nama);
        //strcpy(mahasiswa.nama,"%d",nama);
        scanf("%d", &mahasiswa[i].usia);
        //strcpy(mahasiswa.usia,"%d",usia);
        scanf("%d", &mahasiswa[i].kelas);
       // strcpy(mahasiswa.kelas);
    }
    
   for(int i=0;i<3;i++){
       printf("Data Mahasiswa ke-%d:\n", i+1);
       printf("NIM  : %d\n", mahasiswa[i].nim);
       printf("Nama : %s\n", mahasiswa[i].nama);
       printf("Usia : %d\n", mahasiswa[i].usia);
       printf("Kelas: %s\n", mahasiswa[i].kelas);
       printf("\n");
   }return 0;
}

/*
#include <stdio.h>

typedef struct dataSiswa{
    char nim[10];
    char nama[100];
    int usia;
    int kelas[10];
    
}dataSiswa;

int main(){
    dataSiswa mahasiswa[3];
    
    for(int i=0;i<3;i++){
    printf("Data Mahasiswa ke-%d:\n", i+1);
        printf("NIM  : %d\n", mahasiswa[i].nim);
        scanf("%s", &mahasiswa[i].nim);
        
       // strcpy(mahasiswa.nim, "%d",nim);
       printf("Nama : %s\n", mahasiswa[i].nama);
        scanf("%s", &mahasiswa[i].nama);
        //strcpy(mahasiswa.nama,"%d",nama);
        printf("Usia : %d\n", mahasiswa[i].usia);
        scanf("%d", &mahasiswa[i].usia);
        //strcpy(mahasiswa.usia,"%d",usia);
        printf("Kelas: %s\n", mahasiswa[i].kelas);
        scanf("%d", &mahasiswa[i].kelas);
       // strcpy(mahasiswa.kelas);
    }
/*
   for(int i=0;i<3;i++){
       printf("Data Mahasiswa ke-%d:\n", i+1);
       printf("NIM  : %d\n", mahasiswa[i].nim);
       printf("Nama : %s\n", mahasiswa[i].nama);
       printf("Usia : %d\n", mahasiswa[i].usia);
       printf("Kelas: %s\n", mahasiswa[i].kelas);
       printf("\n");
   }return 0;
   
*/   
}


*/