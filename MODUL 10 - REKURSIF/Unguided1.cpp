#include <iostream>
using namespace std;

int faktorial(int n);

int main() {
    int angka, hasil;
    cout << "Menghitung faktorial dari: ";
    cin >> angka;

    hasil = faktorial(angka);
    cout << "\nNilai faktorialnya adalah: " << hasil << endl;

    return 0;
}

int faktorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * faktorial(n - 1);
    }
}
