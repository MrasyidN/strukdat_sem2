#include <stdio.h>
#include <stdlib.h>

//deklarasi struct simpul dan edge dalam graph
struct simpul{
	struct edge *jalur;
	struct simpul *next;
	char idSimpul;
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

void *createSimpul(struct Graph *G, char a){
	struct simpul *simpulBaru = (struct simpul*)malloc(sizeof(struct simpul));
	simpulBaru->idSimpul = a;
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

//tambah edge
void addEdge(struct simpul *awal, struct simpul *akhir, int nilaiJalur){
	//buat new edge
	struct edge *newEdge = (struct edge*)malloc(sizeof(struct edge));
	// instalasi dan masukan nilai edge
	newEdge->cost = nilaiJalur;
	newEdge->next_jalur = NULL;
	newEdge->tujuan = akhir;
	//periksa awal->jalur
	//jila belum, tambahkan newEdge ke simpul awal
	if(awal->jalur == NULL){
		awal->jalur = newEdge;
	}else{
		//jika sudah periksa jalur akhir pada simpuk awal tsb
		struct edge *jalurAkhir = awal->jalur;
		while(jalurAkhir->next_jalur!=NULL){
			jalurAkhir = jalurAkhir->next_jalur;
		}
		//tambahkan jalur akhir diujung jalur
		jalurAkhir->next_jalur = newEdge;
		
	}
}


//fungsi jalur
void cetakGraph(struct Graph *G){
	struct simpul *tempSimpul = G->first;
	//jika graph tidak kosong lakukan penulusan
	if(tempSimpul!=NULL){
		while(tempSimpul!=NULL){
			//perint simpul
			printf("\nsimpul %c\n", tempSimpul->idSimpul);
			//lakukan pengecekan dan penelusuran edge
			struct edge *tempEdge = tempSimpul->jalur;
			while(tempEdge!=NULL){
			//print setiap jalur dan simpul akhir jalur
			printf("terhubung dengan simpul %c dengan cost %d", tempEdge->tujuan->idSimpul, tempEdge->cost);
			tempEdge = tempEdge->next_jalur;
			}
		tempSimpul = tempSimpul->next;
		}

	}else{
		//selesainya graph kosong
		printf("Graph Kosong");
	}
}


//fungsi cari simpul
struct simpul *cariSimpul(char c, struct Graph G){
	struct simpul *hasil = NULL;
	struct simpul *bantu = G.first;
	
	int ketemu = 0;
	while ((bantu!=NULL) && ketemu == 0){
		if(bantu->idSimpul== c){
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


void delJalur(char ctujuan,struct simpul *awal){
	struct edge *hapus = awal->jalur;
	if(hapus != NULL){
		struct edge *prev = NULL;
		int ketemu = 0;
		while((hapus != NULL) && (ketemu == 0)){
			if(hapus->tujuan->idSimpul == ctujuan){
				ketemu = 1;
			}
			else{
				prev = hapus;
				hapus = hapus->next_jalur;
			}
		}
		if(ketemu == 1){
			if(prev == NULL){
				awal->jalur = hapus->next_jalur;
				hapus->next_jalur = NULL;
			}
			else{
				if(hapus->next_jalur == NULL){
					prev->next_jalur = hapus->next_jalur;
					hapus->next_jalur = NULL;
				}
			}
		}
		free(hapus);
	}
	else{
		printf("tidak ada jalur simpul tujuan \n");
	}
}


void delSimpul(char c, struct Graph *G){
	struct simpul *hapus = (*G).first;
	if(hapus != NULL){
		struct simpul *prev = NULL;
		int ketemu = 0;
		while ((hapus != NULL) && (ketemu == 0)){
			if(hapus->idSimpul == c){
				ketemu = 1;
			}
			else{
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
			}
			else{
				if(hapus->next == NULL){
					prev->next = NULL;
				}
				else{
					prev->next = hapus->next;
					hapus->next = NULL;
				}
			}
			free(hapus);
		}
		else{
			printf("Tidak ada simpul dengan info karakter masukan\n");
		}
	}
	else{
		printf("Tidak ada simpul dengan info karakter masukan\n");
	}
}

int main(){
	struct Graph graphsatu;
	struct simpul *A, *B, *C;
	
	//buat graph
	createGraph(&graphsatu);
	
	//buat simpul
	createSimpul(&graphsatu, 'A');
	createSimpul(&graphsatu, 'B');
	createSimpul(&graphsatu, 'C');
	
	//cari simpul
	A = cariSimpul('A', graphsatu);
	B = cariSimpul('B', graphsatu);
	C = cariSimpul('C', graphsatu);
	
	
	//buat edge
	addEdge(A,B,3);
	addEdge(B,C,5);
	
	//cetak hasil
	cetakGraph(&graphsatu);
}

