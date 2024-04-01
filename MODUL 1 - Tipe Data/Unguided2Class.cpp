#include <iostream>
using namespace std;

// Definisi class
class Mahasiswa {
public:
    string nama;
    int umur;
    
    void display() {
        cout << "Nama: " << nama << ", Umur: " << umur << endl;
    }
};

int main() {
    // Membuat objek dari class Mahasiswa
    Mahasiswa mhs1;
    
    // Mengisi data ke dalam objek
    mhs1.nama = "Nargya";
    mhs1.umur = 18;
    
    // Memanggil metode display dari objek
    mhs1.display();
    
    return 0;
}
