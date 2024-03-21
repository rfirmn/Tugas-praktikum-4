#include <stdio.h>

// Fungsi untuk menukar dua nilai
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk mengonversi kartu menjadi nilai numerik
int valuekartu(char kartu[], int i) {
    if (kartu[0] == 'J' || kartu[0] == 'j') {
        return 11;
    } else if (kartu[0] == 'Q' || kartu[0] == 'q') {
        return 12;
    } else if (kartu[0] == 'K' || kartu[0] == 'k') {
        return 13;
    } else {
        return kartu[0] - '0';
    }
}

// Fungsi partisi untuk algoritma quicksort
int partition(int arr[], int low, int high, int *steps) {
    int pivot = arr[high]; // Mengambil pivot sebagai elemen terakhir
    int i = (low - 1);

    // Iterasi melalui elemen-elemen array
    for (int j = low; j <= high - 1; j++) {
        // Jika elemen saat ini lebih kecil dari pivot, tukar dengan elemen yang lebih besar
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]); // Menukar elemen
            (*steps)++; // Menghitung langkah pertukaran
            printf("Pertukaran %d: ", *steps);
            for (int k = 0; k <= high; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
    }
    swap(&arr[i + 1], &arr[high]); // Tukar elemen pivot ke posisi yang tepat
    return (i + 1); // Kembalikan indeks pivot
}

// Fungsi rekursif untuk quicksort
void quickSort(int arr[], int low, int high, int *steps) {
    if (low < high) {
        // Bagi array dan dapatkan indeks partisi
        int pi = partition(arr, low, high, steps);
        // Panggil quickSort untuk bagian kiri dan kanan dari partisi
        quickSort(arr, low, pi - 1, steps);
        quickSort(arr, pi + 1, high, steps);
    }
}

int main() {
    int jumlah;
    scanf("%i", &jumlah);

    char kartu[50][2];
    int value[50];

    // Meminta input kartu
    for (int i = 0; i < jumlah; i++) {
        scanf("%s", kartu[i]);
        // Konversi kartu menjadi nilai numerik
        if (kartu[i][0] == '1' && kartu[i][1] == '0') {
            value[i] = 10;
        } else {
            value[i] = valuekartu(kartu[i], i);
        }
    }

    int langkah = 0;
    // Panggil quickSort untuk mengurutkan nilai numerik
    quickSort(value, 0, jumlah - 1, &langkah);

    printf("%i", langkah);
    return 0;
}