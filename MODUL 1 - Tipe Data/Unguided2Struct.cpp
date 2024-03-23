#include <iostream>
using namespace std;

// Definisi struct
struct Mahasiswa {
    string nama;
    int umur;
};

int main() {
    // Membuat objek dari struct Mahasiswa
    Mahasiswa mhs1;
    
    // Mengisi data ke dalam objek
    mhs1.nama = "Naufal";
    mhs1.umur = 18;
    
    // Menampilkan data dari objek
    cout << "Nama: " << mhs1.nama << ", Umur: " << mhs1.umur << endl;
    
    return 0;
}
