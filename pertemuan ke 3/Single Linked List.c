#include<stdio.h>
#include<stdlib.h>

typedef struct element{
    char jenis[10];
    char tahun[10];
    char plat[10];
    struct element* NextAlamat;
} element;

void AddListAkhir(char jenis[10], char tahun[4], char plat[10], element* List){
    element* NewList = (element*)malloc(sizeof(element));
    strcpy(NewList->jenis, jenis);
    strcpy(NewList->tahun, tahun);
    strcpy(NewList->plat, plat);
    NewList->NextAlamat = NULL;

    element* temp = List;
    while (temp->NextAlamat != NULL){
        temp = temp->NextAlamat;
    }
    temp->NextAlamat = NewList;
}

int main(){
    element *head = NULL;
    int i, n;
    printf("Jumlah Kendaraan : "); scanf("%d",&n);
    for(i = 0; i < n; i++){
        element *baru = (element*)malloc(sizeof(element));
        printf("Jenis Kendaraan : ");
        scanf("%s", baru->jenis);
        printf("Tahun Kendaraan : ");
        scanf("%s", baru->tahun);
        printf("Nomor Plat      : ");
        scanf("%s", baru->plat);
        baru->NextAlamat = NULL;

        if(head == NULL){
            head = baru;
        }
        else{
            element *temp = head;
            while(temp->NextAlamat != NULL){
                temp = temp->NextAlamat;
            }
            temp->NextAlamat = baru;
        }
    }

    element *temp = head;
    while(temp != NULL){
        printf("\nJenis Kendaraan : %s", temp->jenis);
        printf("\nTahun Kendaraan : %s", temp->tahun);
        printf("\nNomor Plat      : %s\n", temp->plat);
        temp = temp->NextAlamat;
    }

    return 0;
}

