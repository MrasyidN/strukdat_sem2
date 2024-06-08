#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Simpul{
	char idSimpul[30];
	struct Simpul *next;
	struct Edge *jalur;
}simpul;

typedef struct Edge{
	char gemastik[20];
	struct Simpul *tujuan;
	struct Edge *next_jalur;
}edge;

typedef struct graph{
	simpul *first;
}graph;

void createGraph(graph *G){
	G->first = NULL;
}

void createSimpul(graph *G, char a[20]){
	simpul *newsimpul = (simpul*)malloc(sizeof(simpul));
	strcpy(newsimpul->idSimpul, a);
	newsimpul->jalur = NULL;
	newsimpul->next = NULL;
	
	if(G->first == NULL){
		G->first = newsimpul;
	}else{
		simpul *akhir = G->first;
		while(akhir->next!=NULL){
			akhir = akhir->next;
		}
		akhir->next = newsimpul;
	}
}

void addEdge(simpul *awal, simpul *akhir, char gemastik[20]){
	edge *newEdge = (edge*)malloc(sizeof(edge));
	strcpy(newEdge->gemastik, gemastik);
	newEdge->next_jalur = NULL;
	newEdge->tujuan = akhir;
	if(awal->jalur == NULL){
		awal->jalur = newEdge;
	}else{
		edge *JalurAkhir = awal->jalur;
		while(JalurAkhir->next_jalur!=NULL){
			JalurAkhir = JalurAkhir->next_jalur;
		}
		JalurAkhir->next_jalur = newEdge;
	}
}

void print(graph *G){
	simpul *temp = G->first;
	
	if(temp!=NULL){
		while(temp!=NULL){
			edge *tempEdge = temp->jalur;
			if(tempEdge == NULL){
				printf("tidak mengikuti lomba gemastik\n");
			}else{
				while(tempEdge!=NULL){
					printf("%s kenalan dengan %s, dan mengikuti lomba gemastik: %s\n", temp->idSimpul, tempEdge->tujuan->idSimpul, tempEdge->gemastik);
					tempEdge = tempEdge->next_jalur;
				}
				printf("\n");
			}
			temp = temp->next;
		}
	}else{
		printf("graph kosong\n");
	}
}

int main(){
	graph G;
	createGraph(&G);
	
	createSimpul(&G, "Danis");
	createSimpul(&G, "Fatih");
	createSimpul(&G, "Rasyid");
	createSimpul(&G, "Sahrul");
	createSimpul(&G, "Putra");
	
	simpul *Danis = G.first;
	simpul *Fatih = G.first->next;
	simpul *Rasyid = G.first->next->next;
	simpul *Sahrul = G.first->next->next->next;
	simpul *Putra = G.first->next->next->next->next;
	
	addEdge(Danis, Fatih, "Cyber Security");
	addEdge(Fatih, Danis, "Cyber Security");
	
	addEdge(Fatih, Rasyid, "Penambangan Data");
	addEdge(Rasyid, Fatih, "Penambangan Data");
	
	addEdge(Sahrul, Danis, "Pemrogaran");
	addEdge(Danis, Sahrul, "Pemrogaran");
	
	addEdge(Sahrul, Fatih, "UX");
	addEdge(Fatih, Sahrul, "UX");
	
	addEdge(Sahrul, Rasyid, "Kota Cerdas");
	addEdge(Rasyid, Sahrul, "Kota Cerdas");
	
	addEdge(Sahrul, Putra, "Animasi");
	addEdge(Putra, Sahrul, "Animasi");

	
	print(&G);
	return 0;
}
