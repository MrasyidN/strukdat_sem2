#include <stdio.h>
#include <string.h>

int isPalindrome(char *kata) {
    int i, j, panjang;
    
    panjang = strlen(kata);
    
    for (i = 0, j = panjang - 1; i < panjang / 2; i++, j--) {
        if (kata[i] != kata[j]) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    char kata[100];
    
    printf("Masukkan sebuah kata atau kalimat: ");
    scanf("%s", kata);
    
    if (isPalindrome(kata)) {
        printf("%s adalah palindrom.\n", kata);
    } else {
        printf("%s bukan palindrom.\n", kata);
    }
    
    return 0;
}
