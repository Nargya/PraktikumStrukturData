#include <iostream>
#include <string> // Sertakan <string> untuk menggunakan tipe data string

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku[5];
    string pengarang[5];
    string penerbit[5];
    int tebalHalaman[5];
    int hargaBuku[5];
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam array variabel favorit
    favorit.judulBuku[0] = "The Alpha Girl's Guide";
    favorit.pengarang[0] = "Henry Manampiring";
    favorit.penerbit[0] = "Gagas Media";
    favorit.tebalHalaman[0] = 253;
    favorit.hargaBuku[0] = 79000;

    favorit.judulBuku[1] = "Laut Bercerita";
    favorit.pengarang[1] = "Leila S. Chudori";
    favorit.penerbit[1] = "Kepustakaan Populer Gramedia";
    favorit.tebalHalaman[1] = 394;
    favorit.hargaBuku[1] = 109000;

    favorit.judulBuku[2] = "Harry Potter and The Chamber of Secrets (Harry Potter dan Kamar Rahasia)";
    favorit.pengarang[2] = "J.K. Rowling";
    favorit.penerbit[2] = "Gramedia Pustaka Utama";
    favorit.tebalHalaman[2] = 272;
    favorit.hargaBuku[2] = 315000;

    favorit.judulBuku[3] = "Rich Dad Poor Dad";
    favorit.pengarang[3] = "Robert T. Kiyosaki";
    favorit.penerbit[3] = "Gramedia Pustaka Utama";
    favorit.tebalHalaman[3] = 244;
    favorit.hargaBuku[3] = 51000;

    favorit.judulBuku[4] = "Lima Sekawan: Rahasia Logam Ajaib";
    favorit.pengarang[4] = "Enid Blyton";
    favorit.penerbit[4] = "Gramedia Pustaka Utama";
    favorit.tebalHalaman[4] = 192;
    favorit.hargaBuku[4] = 38000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    for(int i = 0; i < 5; ++i) {
        cout << "\tJudul Buku : " << favorit.judulBuku[i] << endl;
        cout << "\tPengarang : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman: " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit.hargaBuku[i] << endl;
        cout << endl;
    }
 
    return 0;
}
