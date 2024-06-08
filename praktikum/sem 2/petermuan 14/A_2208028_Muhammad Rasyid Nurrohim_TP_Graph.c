#include <stdio.h>
#include <stdlib.h>

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
			printf("\nsimpul %c\n", tempSimpul->idSimpul);
			struct edge *tempEdge = tempSimpul->jalur;
			while(tempEdge!=NULL){
			printf("terhubung dengan simpul %c dengan cost %d\n", tempEdge->tujuan->idSimpul, tempEdge->cost);
			tempEdge = tempEdge->next_jalur;
			}
		tempSimpul = tempSimpul->next;
		}
	}else{
		printf("Graph Kosong");
	}
}

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
	struct simpul *A, *B, *C, *D, *E, *F;
	
	createGraph(&graphsatu);

	createSimpul(&graphsatu, 'A');
	createSimpul(&graphsatu, 'B');
	createSimpul(&graphsatu, 'C');
	createSimpul(&graphsatu, 'D');
	createSimpul(&graphsatu, 'E');
	createSimpul(&graphsatu, 'F');
	
	
	A = cariSimpul('A', graphsatu);
	B = cariSimpul('B', graphsatu);
	C = cariSimpul('C', graphsatu);
	D = cariSimpul('D', graphsatu);
	E = cariSimpul('E', graphsatu);
	F = cariSimpul('F', graphsatu);
	
	addEdge(A,B,5);
	addEdge(B,E,7);
	addEdge(B,D,3);
	addEdge(E,D,4);
	addEdge(E,F,4);
	addEdge(F,D,2);
	addEdge(D,A,8);
	addEdge(D,C,3);
	addEdge(C,A,3);
	
	
	//cetak hasil
	printf("\n----------Graph---------\n");
	cetakGraph(&graphsatu);
	
	//deljalur
	printf("\n----------Delete Jalur---------\n\n");
	delJalur('F',E);
	cetakGraph(&graphsatu);
	
	printf("\n----------Delete simpuk---------\n\n");
	delSimpul('C',&graphsatu);
	cetakGraph(&graphsatu);
	
	return 0;
}
