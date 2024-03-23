#include <iostream>
using namespace std;

// Fungsi untuk menghitung luas persegi
double hitungLuasPersegi(double sisi) {
    return sisi * sisi;
}

// Fungsi untuk menghitung keliling persegi
double hitungKelilingPersegi(double sisi) {
    return 4 * sisi;
}

int main() {
    double sisi;

    // Meminta pengguna memasukkan panjang sisi persegi
    cout << "Masukkan panjang sisi persegi: ";
    cin >> sisi;

    // Memanggil fungsi untuk menghitung luas dan keliling persegi
    double luas = hitungLuasPersegi(sisi);
    double keliling = hitungKelilingPersegi(sisi);

    // Menampilkan hasil perhitungan
    cout << "Luas persegi: " << luas << endl;
    cout << "Keliling persegi: " << keliling << endl;

    return 0;
}
