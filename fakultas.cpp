#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct simpul{
	char Fakultas[10];
	struct edge *jalur;
	struct simpul *next;
};

struct edge{
	char jarak[10];
	struct edge *next_jalur;
	struct simpul *tujuan;
};

struct Graph{
	struct simpul *first;
};

void createGraph(struct Graph *G){
	G->first = NULL;
}

void *createSimpul(struct Graph *G, char fakultas[10]){
	struct simpul *simpulBaru;
	simpulBaru=(struct simpul*)malloc(sizeof(struct simpul));
	strcpy(simpulBaru->Fakultas, fakultas);
	simpulBaru->next=NULL;
	simpulBaru->jalur=NULL;
	if(G->first==NULL){
		G->first = simpulBaru;
	}else{
		struct simpul *akhir = G->first;
		while(akhir->next != NULL){
			akhir = akhir->next;
		}
		akhir->next = simpulBaru;
	}
}

void addEdge(struct simpul *awal, struct simpul *akhir, char jarak[10]){
	struct edge* newEdge = (struct edge*)malloc(sizeof(struct edge));
	strcpy(newEdge->jarak, jarak);
	newEdge->next_jalur = NULL;
	newEdge->tujuan = akhir;
	if(awal->jalur == NULL){
		awal->jalur = newEdge;
	}else{
		struct edge *jalurAkhir = awal->jalur;
		while(jalurAkhir->next_jalur != NULL){
			jalurAkhir = jalurAkhir->next_jalur;
		}
		jalurAkhir->next_jalur = newEdge;
	}
}

void cetakGraph(struct Graph *G){
	struct simpul *tempSimpul = G->first;
	if(tempSimpul != NULL){
		while(tempSimpul != NULL){
			printf("\nFakultas yang langsung terhubung ke %s :\n", tempSimpul->Fakultas);
			struct edge *tempEdge = tempSimpul->jalur;
			while(tempEdge != NULL){
				printf("- %s dengan jarak %s\n", tempEdge->tujuan->Fakultas, tempEdge->jarak);
				tempEdge = tempEdge->next_jalur;
			}
			tempSimpul = tempSimpul->next;
		}
	}else{
		printf("Graph Kosong\n");
	}
}

struct simpul *cariSimpul(char c[10], struct Graph G){
	struct simpul *hasil = NULL;
	struct simpul *bantu = G.first;
	
	int ketemu = 0;
	
	while((bantu != NULL) && ketemu == 0){
		int cmp = strcmp(bantu->Fakultas, c);
		if(cmp == 0){
			hasil = bantu;
			ketemu = 1;
		}else{
			bantu = bantu->next;
		}
	}
	return hasil;
}

int main(){
	struct Graph upi;
	struct simpul *FPMIPA, *FPIPS, *FPSD, *FPEB, *FPTK, *FPOK, *FPBS, *FIP;
	
	createGraph(&upi);
	
	createSimpul(&upi, "FPMIPA");
	createSimpul(&upi, "FPIPS");
	createSimpul(&upi, "FPSD");
	createSimpul(&upi, "FPEB");
	createSimpul(&upi, "FPTK");
	createSimpul(&upi, "FPOK");
	createSimpul(&upi, "FPBS");
	createSimpul(&upi, "FIP");
	
	FPMIPA = cariSimpul("FPMIPA", upi);
	FPIPS = cariSimpul("FPIPS", upi);
	FPSD = cariSimpul("FPSD", upi);
	FPEB = cariSimpul("FPEB", upi);
	FPTK = cariSimpul("FPTK", upi);
	FPOK = cariSimpul("FPOK", upi);
	FPBS = cariSimpul("FPBS", upi);
	FIP = cariSimpul("FIP", upi);
	
	addEdge(FPMIPA,FIP,"90 Meter");
	addEdge(FPMIPA,FPOK,"250 Meter");
	
	addEdge(FPOK,FPMIPA, "250 Meter");
	addEdge(FPOK,FIP, "140 Meter");
	addEdge(FPOK,FPEB, "270 Meter");
	
	addEdge(FIP,FPMIPA, "90 Meter");
	addEdge(FIP,FPOK, "140 Meter");
	addEdge(FIP,FPIPS, "240 Meter");
	addEdge(FIP,FPSD, "270 Meter");
	
	addEdge(FPEB,FPOK, "270 Meter");
	addEdge(FPEB,FPIPS, "150 Meter");
	
	addEdge(FPIPS,FPEB, "150 Meter");
	addEdge(FPIPS,FIP, "260 Meter");
	addEdge(FPIPS,FPSD, "100 Meter");
	addEdge(FPIPS,FPBS, "50 Meter");
	
	addEdge(FPSD,FIP, "270 Meter");
	addEdge(FPSD,FPIPS, "100 Meter");
	addEdge(FPSD,FPBS, "150 Meter");
	addEdge(FPSD,FPTK, "250 Meter");
	
	addEdge(FPTK,FPSD, "250 Meter");
	
	addEdge(FPBS,FPIPS, "50 Meter");
	addEdge(FPBS,FPSD, "150 Meter");
	
	cetakGraph(&upi);
	return 0;
}
