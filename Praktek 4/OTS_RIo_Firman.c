#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mendefinisikan panjang maksimum dan minimum untuk teks
#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

// Fungsi untuk kasus di mana panjang teks kurang dari yang dibutuhkan
void lessThanRequired(char *longtext) {
    int length = strlen(longtext);
    printf("The length of your text is less than specified, please update your text\n");
    printf("Length before: %i", length);
    
    // Loop untuk meningkatkan panjang hingga mencapai panjang minimum yang dibutuhkan
    while (length < MIN_LENGTH) {
        length++;
    }
    printf("\nThe Length is updated to %i", length);
}

// Fungsi untuk kasus di mana panjang teks sama dengan yang dibutuhkan
void equalThanRequired() {
    printf("Thank you, Your text length is correct");
}

// Fungsi untuk kasus di mana panjang teks lebih dari yang dibutuhkan
void moreThanRequired(char *longtext) {
    int length = strlen(longtext);
    puts("Your text is too long, please reduce the text");

    printf("Length before: %i", length);
    // Loop untuk mengurangi panjang hingga mencapai panjang maksimum yang dibutuhkan
    while (length > MAX_LENGTH) {
        length--;
    }
    
    printf("\nThe Length is updated to %d", length);
}

// Fungsi untuk memeriksa apakah panjang teks memenuhi persyaratan
int checkLengthRequirement(char* text) {
    int length = strlen(text);
    if (length < MIN_LENGTH)       // Jika panjang kurang dari minimum
        return 0;
    else if (length == MIN_LENGTH) // Jika panjang sama dengan minimum
        return 1;
    else                           // Jika panjang lebih dari minimum
        return 2;
}

int main() {
    int selectOption;
    FILE *fptr = NULL;
    char text[3000];

    // Membuka file untuk dibaca
    fptr = fopen("file.txt", "r");

    if (fptr == NULL) {
        printf("Error");
        exit(1);
    }

    // Membaca teks dari file
    fgets(text, 3000, fptr);
    fclose(fptr);

    // Memeriksa persyaratan panjang dan memilih fungsi yang sesuai untuk dipanggil
    selectOption = checkLengthRequirement(text);
    void (*callfunction[3])() ={lessThanRequired, equalThanRequired, moreThanRequired};
    callfunction[selectOption](text); // Memanggil fungsi yang sesuai berdasarkan persyaratan panjang
    return 0;
}
