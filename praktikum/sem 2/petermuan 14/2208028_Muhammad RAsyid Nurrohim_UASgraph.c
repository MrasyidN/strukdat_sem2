#include <stdio.h>
#include <stdlib.h>

struct simpul{
    struct edge *jalur;
    struct simpul *next;
    char idSimpul[100];
};

struct edge{
    struct edge *next_jalur;
    struct simpul *tujuan;
    int cost;
};

struct Graph{
    struct simpul *first;
};

void createGraph(struct Graph *G){
    G->first = NULL;
}

void createSimpul(struct Graph *G, char* a){
    struct simpul *simpulBaru = (struct simpul*)malloc(sizeof(struct simpul));
    strcpy(simpulBaru->idSimpul, a);
    simpulBaru->jalur = NULL;
    simpulBaru->next=NULL;
    if(G->first == NULL){
        G->first= simpulBaru;
    }else{
        struct simpul *akhir = G->first;
        while(akhir->next!=NULL){
            akhir = akhir->next;
        }
        akhir->next = simpulBaru;
    }
}

void addEdge(struct simpul *awal, struct simpul *akhir, int nilaiJalur){
    struct edge *newEdge = (struct edge*)malloc(sizeof(struct edge));
    newEdge->cost = nilaiJalur;
    newEdge->next_jalur = NULL;
    newEdge->tujuan = akhir;
    if(awal->jalur == NULL){
        awal->jalur = newEdge;
    }else{
        struct edge *jalurAkhir = awal->jalur;
        while(jalurAkhir->next_jalur!=NULL){
            jalurAkhir = jalurAkhir->next_jalur;
        }
        jalurAkhir->next_jalur = newEdge;
    }
}

void cetakGraph(struct Graph *G){
    struct simpul *tempSimpul = G->first;
    if(tempSimpul!=NULL){
        while(tempSimpul!=NULL){
            printf("\n %s\n", tempSimpul->idSimpul);
            struct edge *tempEdge = tempSimpul->jalur;
            while(tempEdge!=NULL){
                printf("terhubung dengan %s dengan cost %d\n", tempEdge->tujuan->idSimpul, tempEdge->cost);
                tempEdge = tempEdge->next_jalur;
            }
            tempSimpul = tempSimpul->next;
        }
    }else{
        printf("Graph Kosong");
    }
}

struct simpul *cariSimpul(char* c, struct Graph G){
    struct simpul *hasil = NULL;
    struct simpul *bantu = G.first;

    int ketemu = 0;
    while ((bantu!=NULL) && ketemu == 0){
        if(strcmp(bantu->idSimpul, c) == 0){
            hasil = bantu;
            ketemu = 1;
        }else{
            bantu = bantu->next;
        }
    }
    return hasil;
}

void delAll(struct simpul *awal){
    struct edge *bantu;
    bantu = awal->jalur;
    struct edge *hapus;
    while(bantu!=NULL){
        hapus = bantu;
        bantu = bantu->next_jalur;
        awal->jalur = bantu;
        hapus->next_jalur = NULL;
        free(hapus);
    }
}

void delJalur(char* ctujuan,struct simpul *awal){
    struct edge *hapus = awal->jalur;
    if(hapus != NULL){
        struct edge *prev = NULL;
        int ketemu = 0;
        while((hapus != NULL) && (ketemu == 0)){
            if(strcmp(hapus->tujuan->idSimpul, ctujuan) == 0){
                ketemu = 1;
            }else{
                prev = hapus;
                hapus = hapus->next_jalur;
            }
        }
        if(ketemu == 1){
            if(prev == NULL){
                awal->jalur = hapus->next_jalur;
                hapus->next_jalur = NULL;
            }else{
                if(hapus->next_jalur == NULL){
                    prev->next_jalur = hapus->next_jalur;
                    hapus->next_jalur = NULL;
                }
            }
        }
        free(hapus);
    }else{
        printf("tidak ada jalur simpul tujuan \n");
    }
}

void delSimpul(char* c, struct Graph *G){
    struct simpul *hapus = (*G).first;
    if(hapus != NULL){
        struct simpul *prev = NULL;
        int ketemu = 0;
        while ((hapus != NULL) && (ketemu == 0)){
            if(strcmp(hapus->idSimpul, c) == 0){
                ketemu = 1;
            }else{
                prev = hapus;
                hapus = hapus->next;
            }
        }
        if(ketemu == 1){
            struct simpul *bantu;
            bantu = (*G).first;

            while(bantu != NULL){
                if(bantu != hapus){
                    delJalur(hapus->idSimpul, bantu);
                }
                bantu = bantu->next;
            }
            delAll(hapus);
            if(prev == NULL){
                (*G).first = hapus->next;
                hapus->next = NULL;
            }else{
                if(hapus->next == NULL){
                    prev->next = NULL;
                }else{
                    prev->next = hapus->next;
                    hapus->next = NULL;
                }
            }
            free(hapus);
        }else{
            printf("Tidak ada simpul dengan info karakter masukan\n");
        }
    }else{
        printf("Tidak ada simpul dengan info karakter masukan\n");
    }
}

int main(){
    struct Graph graphsatu;
    struct simpul *Subang, *Purwakarta, *Bandung, *Cianjur, *Majalengka, *Sumedang, *Tasikmalaya;

    createGraph(&graphsatu);

    createSimpul(&graphsatu, "Subang");
    createSimpul(&graphsatu, "Purwakarta");
    createSimpul(&graphsatu, "Bandung");
    createSimpul(&graphsatu, "Cianjur");
    createSimpul(&graphsatu, "Majalengka");
    createSimpul(&graphsatu, "Sumedang");
    createSimpul(&graphsatu, "Tasikmalaya");

    Subang = cariSimpul("Subang", graphsatu);
    Purwakarta = cariSimpul("Purwakarta", graphsatu);
    Bandung = cariSimpul("Bandung", graphsatu);
    Cianjur = cariSimpul("Cianjur", graphsatu);
    Majalengka = cariSimpul("Majalengka", graphsatu);
    Sumedang = cariSimpul("Sumedang", graphsatu);
    Tasikmalaya = cariSimpul("Tasikmalaya", graphsatu);

    addEdge(Subang, Purwakarta, 4);
    addEdge(Purwakarta, Cianjur, 2);
    addEdge(Cianjur, Bandung, 3);
    addEdge(Bandung, Purwakarta, 1);
    addEdge(Bandung, Subang, 2);
    addEdge(Majalengka, Subang, 3);
    addEdge(Majalengka, Sumedang, 1);
    addEdge(Majalengka, Tasikmalaya, 5);
    addEdge(Sumedang, Tasikmalaya, 2);
    
    int n;

    do{
    	scanf("%d", &n);
    	switch(n){
    		case 1:
				cetakGraph(&graphsatu);
			break;
			case 2:
			    delJalur("Tasikmalaya",Sumedang);
			    delJalur("Bandung",Cianjur);			    
				cetakGraph(&graphsatu);
			break;
			case 3:
	    		delSimpul("Tasikmalaya",&graphsatu);
				cetakGraph(&graphsatu);
			break;
		}
	}while(n!=0);
    

    return 0;
}

