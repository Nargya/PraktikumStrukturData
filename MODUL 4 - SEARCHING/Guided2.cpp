#include <iostream>
#include <iomanip>

int data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for (i = 0; i < 7; i++) {
        min = i;
        for (j = i + 1; j < 7; j++) {
            if (data[j] < data[min]) {
                min = j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binarysearch() {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 7;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if (data[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah - 1;
    }
    if (b_flag == 1)
        std::cout << "\n Data ditemukan pada index ke- " << tengah << std::endl;
    else
        std::cout << "\n Data tidak ditemukan\n";
}

int main() {
    std::cout << "\t BINARY SEARCH " << std::endl;
    std::cout << "\n Data : ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++)
        std::cout << std::setw(3) << data[x];
    std::cout << std::endl;

    std::cout << "\n Masukkan data yang ingin Anda cari : ";
    std::cin >> cari;

    std::cout << "\n Data diurutkan : ";
    // Urutkan data dengan selection sort
    selection_sort();

    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++)
        std::cout << std::setw(3) << data[x];
    std::cout << std::endl;

    binarysearch();

    return EXIT_SUCCESS;
}
