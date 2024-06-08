#include <stdio.h>

typedef struct Titik {
    int x;
    int y;
}t;

typedef struct Bidang {
    t titik[4];
}b;

int main() {
    b bidang1, bidang2;

    printf("Masukkan data bidang 1:\n");
    for (int i = 0; i < 4; i++) {
        printf("Titik %d:\n", i+1);
        printf("x: ");
        scanf("%d", &bidang1.titik[i].x);
        printf("y: ");
        scanf("%d", &bidang1.titik[i].y);
    }

    printf("Masukkan data bidang 2:\n");
    for (int i = 0; i < 4; i++) {
        printf("Titik %d:\n", i+1);
        printf("x: ");
        scanf("%d", &bidang2.titik[i].x);
        printf("y: ");
        scanf("%d", &bidang2.titik[i].y);
    }

    printf("Bidang 1:\n");
    for (int i = 0; i < 4; i++) {
        printf("Titik %d:\n", i+1);
        printf("x: %d\n", bidang1.titik[i].x);
        printf("y: %d\n", bidang1.titik[i].y);
    }

    printf("Bidang 2:\n");
    for (int i = 0; i < 4; i++) {
        printf("Titik %d:\n", i+1);
        printf("x: %d\n", bidang2.titik[i].x);
        printf("y: %d\n", bidang2.titik[i].y);
    }

    return 0;
}
