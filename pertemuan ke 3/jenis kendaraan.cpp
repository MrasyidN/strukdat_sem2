int main(){
    element *head = NULL;
    element *baru = NULL;
    int i;
    
    for(i=0; i<1; i++){
    baru = (element*)malloc(sizeof(element));
    printf("Jenis kendaraan : ");
    scanf("%s", baru->jenis);
    printf("Tahun kendaraan : ");
    scanf("%s", baru->tahun);
    printf("Nomor plat      : ");
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

return 0;
}
