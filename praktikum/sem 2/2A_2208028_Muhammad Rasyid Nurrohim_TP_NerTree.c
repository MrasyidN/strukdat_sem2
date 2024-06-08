#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char nama[1000];
	struct Node* parent;
	struct Node* child[3];
}Node;


Node* findNode(Node *root,const char* daerah){
	int i;
	if(root == NULL)
		return NULL;
	if(strcmp(root->nama, daerah) == 0)
		return root;
	Node* temp = NULL;
	for(i=0;i<3;i++){
		temp = findNode(root->child[i], daerah);
		if(temp!=NULL)
			return temp;
	}
	for(i=0;i<3;i++){
		temp = findNode(root->child[i], daerah);
		if(temp!=NULL)
			return temp;
	}
	return NULL;
}

void print(Node* Node) {
	int i;
    if (Node == NULL) {
        printf ("daerah Tidak Ditemukan\n");
        return;
    }
    if (Node -> parent != NULL)
        printf ("\nparent : %s\n", Node -> parent -> nama);
    printf ("\nchild :\n");
    int childCount = 0;
    for (i = 0; i < 3; i++) {
        if (Node -> child[i] != NULL) {
            printf ("%s\n", Node -> child[i] -> nama);
            childCount++;
        }
    }
    if (childCount == 0 && Node->child[0] == NULL)
        printf ("Tidak memiliki child\n");    
}


void preorder (Node* Node){
    if (Node == NULL)
        return;
    printf("%s\n", Node -> nama);
    int i;
    for (i = 0; i < 3; i++) {
        preorder (Node -> child[i]);
    }
}

void postorder (Node* Node){
    if (Node == NULL)
        return;
    int i;
    for (i = 0; i < 3; i++){
        postorder (Node -> child[i]);
    }
    printf("%s\n", Node -> nama);
}


int main(){
	int a, n;
	
    Node* provJawaTengah = (Node*)malloc(sizeof(Node));
	strcpy (provJawaTengah -> nama, "Prov. Jawa Tengah");
	provJawaTengah -> parent = NULL; 
	
	Node* kabTegal = (Node*)malloc(sizeof(Node));
	strcpy (kabTegal->nama, "Kab. Tegal");
	kabTegal->parent = provJawaTengah;
	
	Node* kecMargasari = (Node*)malloc(sizeof(Node));
	strcpy (kecMargasari -> nama, "Kec. Margasari");
	kecMargasari -> parent = kabTegal;
	
	Node* desaMargasari = (Node*)malloc(sizeof(Node));
	strcpy (desaMargasari -> nama, "Desa Margasari");
	desaMargasari -> parent = kabTegal;
	
	Node* desajembayat = (Node*)malloc(sizeof(Node));
	strcpy (desajembayat -> nama, "Desa jembayat");
	desajembayat -> parent = kabTegal;
	
	Node* desaKarangdawa  = (Node*)malloc(sizeof(Node));
	strcpy (desaKarangdawa -> nama, "Desa Karangdawa");
	desaKarangdawa -> parent = kabTegal;
	
	kabTegal -> child[0] = desaMargasari;
	kabTegal -> child[1] = desajembayat;
	kabTegal -> child[2] = desaKarangdawa;
	
	Node* kecBumijawa = (Node*)malloc(sizeof(Node));
	strcpy (kecBumijawa -> nama, "Kec. Bumijawa");
	kecBumijawa -> parent = kabTegal;
	
	Node* desaTraju = (Node*)malloc(sizeof(Node));
	strcpy (desaTraju -> nama, "Desa Traju");
	desaTraju -> parent = kecBumijawa;
	
	Node* desaSokasari = (Node*)malloc(sizeof(Node));
	strcpy (desaSokasari -> nama, "Desa Sokasari");
	desaSokasari -> parent = kecBumijawa;
	
	Node* desaBegawat = (Node*)malloc(sizeof(Node));
	strcpy (desaBegawat -> nama, "Desa Begawat");
	desaBegawat -> parent = kecBumijawa;
	
	kecBumijawa -> child[0] = desaTraju;
	kecBumijawa -> child[1] = desaSokasari;
	kecBumijawa -> child[2] = desaBegawat;
	
	Node* kecBojong = (Node*)malloc(sizeof(Node));
	strcpy (kecBojong -> nama, "Kec. Bojong");
	kecBojong -> parent = kabTegal;
	
	Node* desaBojong = (Node*)malloc(sizeof(Node));
	strcpy (desaBojong -> nama, "Desa Bojong");
	desaBojong -> parent = kecBojong;

    Node* desaRembul = (Node*)malloc(sizeof(Node));
    strcpy (desaRembul -> nama, "Desa Rembul");
    desaRembul -> parent = kecBojong;

    Node* desaTowel= (Node*)malloc(sizeof(Node));
    strcpy (desaTowel -> nama, "Desa Towel");
    desaTowel -> parent = kecBojong;

    kecBojong -> child[0] = desaBojong;
    kecBojong -> child[1] = desaRembul;
    kecBojong -> child[2] = desaTowel;

    kabTegal-> child[0] = kecMargasari;
    kabTegal-> child[1] = kecBumijawa;
    kabTegal-> child[2] = kecBojong;

    Node* kabWonogiri = (Node*)malloc(sizeof(Node));
    strcpy (kabWonogiri -> nama, "Kab. Wonogiri");
    kabWonogiri -> parent = provJawaTengah;

    Node* kecBaturetno = (Node*)malloc(sizeof(Node));
    strcpy (kecBaturetno -> nama, "Kec. Baturetno");
    kecBaturetno -> parent = kabWonogiri;

    Node* desaBaturetno = (Node*)malloc(sizeof(Node));
    strcpy (desaBaturetno -> nama, "Desa Baturetno");
    desaBaturetno -> parent = kecBaturetno;

    Node* desaBalepanjang = (Node*)malloc(sizeof(Node));
    strcpy (desaBalepanjang -> nama, "Desa Balepanjang");
    desaBalepanjang -> parent = kecBaturetno;

    Node* desaWatuagung = (Node*)malloc(sizeof(Node));
    strcpy (desaWatuagung -> nama, "Desa Watuagung");
    desaWatuagung -> parent = kecBaturetno;

    kecBaturetno -> child[0] = desaBaturetno;
    kecBaturetno -> child[1] = desaBalepanjang;
    kecBaturetno -> child[2] = desaWatuagung;

    Node* kecBulukerto = (Node*)malloc(sizeof(Node));
    strcpy (kecBulukerto -> nama, "Kec. Bulukerto");
    kecBulukerto -> parent = kabWonogiri;

    Node* desaGeneng = (Node*)malloc(sizeof(Node));
    strcpy (desaGeneng -> nama, "Desa Geneng");
    desaGeneng -> parent = kecBulukerto;

    Node* desaBulurejo = (Node*)malloc(sizeof(Node));
    strcpy (desaBulurejo -> nama, "Desa Bulurejo");
    desaBulurejo -> parent = kecBulukerto;

    Node* desaTanjung = (Node*)malloc(sizeof(Node));
    strcpy (desaTanjung -> nama, "Desa Tanjung");
    desaTanjung -> parent = kecBulukerto;

    kecBulukerto -> child[0] = desaGeneng;
    kecBulukerto -> child[1] = desaBulurejo;
    kecBulukerto -> child[2] = desaTanjung;

    Node* kecErokomo = (Node*)malloc(sizeof(Node));
    strcpy (kecErokomo -> nama, "Kec. Erokomo");
    kecErokomo -> parent = kabWonogiri;

    Node* desaPucung = (Node*)malloc(sizeof(Node));
    strcpy (desaPucung -> nama, "Desa Pucung");
    desaPucung -> parent = kecErokomo;

    Node* desaBasuhan = (Node*)malloc(sizeof(Node));
    strcpy (desaBasuhan -> nama, "Desa Basuhan ");
    desaBasuhan -> parent = kecErokomo;

    Node* desaPanukan = (Node*)malloc(sizeof(Node));
    strcpy (desaPanukan -> nama, "Desa Panukan");
    desaPanukan -> parent = kecErokomo;

    kecErokomo -> child[0] = desaPucung;
    kecErokomo -> child[1] = desaBasuhan;
    kecErokomo -> child[2] = desaPanukan;

    kabWonogiri -> child[0] = kecBaturetno;
    kabWonogiri -> child[1] = kecBulukerto;
    kabWonogiri -> child[2] = kecErokomo;

    Node* kabJepara = (Node*)malloc(sizeof(Node));
    strcpy (kabJepara -> nama, "Kab. Jepara");
    kabJepara -> parent = provJawaTengah;

    Node* kecKeling = (Node*)malloc(sizeof(Node));
    strcpy (kecKeling -> nama, "Kec. Keling");
    kecKeling -> parent = kabJepara;

    Node* desaKlepu = (Node*)malloc(sizeof(Node));
    strcpy (desaKlepu -> nama, "Desa Klepu");
    desaKlepu ->parent = kecKeling;

    Node* desaKunir = (Node*)malloc(sizeof(Node));
    strcpy (desaKunir -> nama, "Desa Kunir");
    desaKunir -> parent = kecKeling;

    Node* desaTempur = (Node*)malloc(sizeof(Node));
    strcpy (desaTempur -> nama, "Desa Tempur");
    desaTempur -> parent = kecKeling; 
    
    kecKeling -> child[0] = desaKlepu;
    kecKeling -> child[1] = desaKunir;
    kecKeling -> child[2] = desaTempur;

    Node* kecBangsri = (Node*)malloc(sizeof(Node));
    strcpy (kecBangsri->nama, "Kec. Bangsri");
    kecBangsri -> parent = kabJepara;

    Node* desaKepuk = (Node*)malloc(sizeof(Node));
    strcpy (desaKepuk->nama, "Desa Kepuk");
    desaKepuk -> parent = kecBangsri;

    Node* desaPapasan = (Node*)malloc(sizeof(Node));
    strcpy (desaPapasan->nama, "Desa Papasan");
    desaPapasan -> parent = kecBangsri;

    Node* desaGuyangan = (Node*)malloc(sizeof(Node));
    strcpy (desaGuyangan->nama, "Desa Guyangan");
    desaGuyangan -> parent = kecBangsri;

    kecBangsri -> child[0] = desaKepuk;
    kecBangsri -> child[1] = desaPapasan;
    kecBangsri -> child[2] = desaGuyangan;

    Node* kecKedung = (Node*)malloc(sizeof(Node));
    strcpy (kecKedung -> nama, "Kec. Kedung");
    kecKedung -> parent = kabJepara;

    Node* desaRau = (Node*)malloc(sizeof(Node));
    strcpy (desaRau-> nama, "Desa Rau");
    desaRau -> parent = kecKedung;

    Node* desaBugel = (Node*)malloc(sizeof(Node));
    strcpy (desaBugel -> nama, "Desa Bugel");
    desaBugel -> parent = kecKedung;

    Node* desaKerso = (Node*)malloc(sizeof(Node));
    strcpy (desaKerso -> nama, "Desa Kerso");
    desaKerso -> parent = kecKedung;

    kecKedung -> child[0] = desaRau;
    kecKedung -> child[1] = desaBugel;
    kecKedung -> child[2] = desaKerso;

    kabJepara -> child[0] = kecKeling;
    kabJepara -> child[1] = kecBangsri;
    kabJepara -> child[2] = kecKedung;

    provJawaTengah -> child[0] = kabTegal;
    provJawaTengah -> child[1] = kabWonogiri;
    provJawaTengah -> child[2] = kabJepara;

    Node* petaProvinsi = provJawaTengah;
        
    do {
        printf("[1] Cetak Pre-order\n");
        printf("[2] Cetak Post-order\n");
        printf("[3] Temukan Kabupaten/Kota, Kecamatan, Kelurahan/Desa\n");
        printf("[0] Keluar\n\n");
        printf("Masukkan Pilihan Menu : ");
        scanf("%d", &a);
        system("CLS");
        switch (a) {
            case 1:
                printf("-----------------------------PRE-ORDER---------------------------\n");
                preorder(petaProvinsi);
                printf("-------------------------------------------------------------------\n\n");
                system("PAUSE");
        		system("CLS");
                break;
            case 2:
                printf("------------------------------POST-ORDER---------------------------\n");
                postorder(petaProvinsi);
                printf("-------------------------------------------------------------------\n\n");
                system("PAUSE");
        		system("CLS");
                break;
            case 3:
                getchar();
                printf("\n---------------------------CARI LOKASI----------------------------\n");
                printf("Contoh cara memasukkan nama tempat:\n");
                printf("[1] Provinsi, Ketik: Prov. Jawa Tengah\n");
                printf("[2] Kab/Kota, Ketik: Kab. Jepara\n");
                printf("[3] Kecamatan, Ketik: Kec. Keling\n");
                printf("[4] Desa, Ketik: Desa jembayat\n");
                printf("Masukkan nama tempat : ");

                char namaTempat[1000];
                fgets(namaTempat, sizeof(namaTempat), stdin);
                namaTempat[strcspn(namaTempat, "\n")] = 0;

                Node* hasilPencarian = findNode(petaProvinsi, namaTempat);
                print(hasilPencarian);
                printf("\n");
                system("PAUSE");
        		system("CLS");
                break;
        }
    } while (a != 0);

    return 0;
}



