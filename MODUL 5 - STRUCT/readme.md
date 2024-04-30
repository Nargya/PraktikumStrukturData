# <h1 align="center">Laporan Praktikum Modul STRUCT</h1>
<p align="center">Naufal Alif Anargya</p>
<p align="center">2311110041</p>

## Dasar Teori
### 1. Variabel

Variabel adalah sebuah kotak atau kontainer yang berfungsi untuk
menyimpan nilai. Dalam C++, ada berbagai jenis variabel (didefinisikan dengan kata kunci yang berbeda) sebagai contoh:
- int – menyimpan bilangan integer (semua angka) tanpa desimal seperti 123 atau -123
- double – menyimpan angka desimal seperti 19,999 atau -19,99
- char – menyimpan karakter tunggal seperti ‘a’ atau ‘B’ Nilai char dikurung dengan petik tunggal.
- string – menyimpan teks atau tulisan seperti tulisan “Halo Dunia”. Nilai string dikurung menggunakan tanda petik dobel.
- bool – menyimpan dua kondisi yaitu benar dan salah. [1]
#### Mendeklarasikan variabel C++

Untuk membuat variabel, programmer harus menuliskan jenis tidak data dan mengisinya dengan suatu nilai seperti:
```tipe_data nama_variabel = nilai;```
Dengan variabel tipe adalah tipe data variabel C++ seperti int, double,
char, string, bool dan nama_variabel adalah nama dari variabel seperti x
atau namaSaya. Tanda sama dengan (=) digunakan untuk mengisi nilai
pada suatu variabel.[1]

#### Menampilkan Variabel

Perintah objek cout digunakan bersama dengan operator << untuk
menampilkan variabel.
Untuk mengombinasi teks dan variabel, pisahkan dengan operator <<
seperti berikut.

```
#include <iostream>
using namespace std;
int usiaSaya = 35;
int main()
{
cout << "Saya berusia " << usiaSaya << " tahun.";
}
```
[1]

## 2. Struct

Struct adalah tipe data bentukan yang berisi kumpulan variabel-variabel yang bernaung dalam satu nama yang sama dan memiliki kaitan satu sama lain. Berbeda dengan array hanya berupa kumpulan variabel yang bertipe data sama, struct bisa memiliki variabel-variabel yang bertipe data sama atau berbeda, bahkan bisa menyimpan variabel yang bertipe data array atau struct itu sendiri. Variabel-variabel yang menjadi anggota struct disebut dengan elemen struct. Penggunaan/pemakaian tipe data struct dilakukan dengan membuat suatu variabel yang bertipe data struct tersebut. Pengaksesan elemen struct dilakukan secara individual dengan menyebutkan nama variabel struct diikuti dengan operator titik (.). [2]
```C++
#include <iostream>
#include <stdio.h>
using namespace std;
struct Mahasiswa
{
    char NIM[9];
    char nama[30];
    float ipk; };

int main()
{
    Mahasiswa mhs;
    system("cls");
    printf("NIM = ");scanf("%s", &mhs.NIM);
    printf("Nama = ");scanf("%s", &mhs.nama);
    printf("IPK = ");scanf("%f", &mhs.ipk);
    printf("Data Anda : \n");
    printf("NIM : %s\n", mhs.NIM);
    printf("Nama : %s\n", mhs.nama);
    printf("IPK : %f\n", mhs.ipk);
    
    return 0;
}
```

## Guided 

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.
```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}

```
Kode di atas adalah program C++ sederhana yang menggunakan struktur (struct) untuk merepresentasikan informasi tentang sebuah buku. Program ini menginisialisasi sebuah struktur bernama `buku` dengan lima anggota yang mewakili atribut-atribut buku seperti judul, pengarang, penerbit, tebal halaman, dan harga. Selanjutnya, program membuat sebuah variabel `favorit` dari tipe struktur `buku` dan mengisi informasi tentang buku favorit ke dalamnya. Terakhir, program menampilkan informasi tersebut ke layar.

### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.
![Screenshot 2024-04-29 050655](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/3843c6d0-b210-44b0-988c-38e1fba25b74)

```C++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}
```
Kode di atas mendefinisikan tiga struktur data: "hewan", "hewanDarat", dan "hewanLaut". Setiap struktur memiliki atribut yang menunjukkan informasi tentang hewan, hewan darat, dan hewan laut masing-masing. Tiga variabel dideklarasikan dalam fungsi "main()": "kelinci" dari tipe "hewanDarat", "ikan" dari tipe "hewanLaut", dan "serigala" dari tipe "hewan", masing-masing dengan informasi tentang kelinci, ikan, dan serigala. Dengan menggunakan perintah "cout", program menampilkan informasi seperti nama, jenis kelamin, cara berkembangbiak, alat pernafasan, tempat hidup, apakah hewan karnivora atau tidak, jumlah kaki (untuk hewan darat), apakah hewan menyusui atau tidak, suara (untuk hewan darat), bentuk sirip, dan bentuk pertahanan diri.

## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan

```C++
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

```
#### Output:
![Screenshot 2024-04-29 063430](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/98eade18-f4f7-4bbb-9117-496d5bfbd9a1)

Code diatas adalah code yang telah diubah dari struct menjadi Array berukuran 5 sehingga bisa memiliki kapasitas untuk menyimpan 5 elemen atau nilai. Ini berarti array tersebut dapat menampung 5 nilai atau elemen yang berbeda. Saat array dideklarasikan dengan ukuran 5, ia akan mengalokasikan ruang memori yang cukup untuk menyimpan 5 nilai tersebut secara berturut-turut. Dalam code di atas array ukuran 5 digunakan untuk menyimpan informasi tentang lima buku favorit. Setiap array di dalam struktur buku memiliki ukuran 5, yang berarti kita dapat menyimpan informasi tentang lima buku dalam struktur tersebut. Misalnya, `judulBuku[5]` memungkinkan kita untuk menyimpan judul dari lima buku yang berbeda dalam satu waktu.

#### Full code Screenshot:
![Screenshot 2024-04-29 064812](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/72a2a98c-78f0-4106-8db4-bfe88d030465)

### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I,berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?

```C++
#include <iostream>
#include <string>

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

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    for (int i = 0; i < 1; ++i) { // Loop hanya satu kali karena hanya satu buku yang diisi
        cout << "\tJudul Buku : " << favorit.judulBuku[i] << endl;
        cout << "\tPengarang : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman: " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit.hargaBuku[i] << endl;
    }
 
    return 0;
}

```
#### Output:
![Screenshot 2024-04-29 074407](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/525050cc-e86e-4f95-98f6-c822b4321fa7)

Ketika sebuah kode yang awalnya menggunakan struktur untuk menampilkan data diubah menjadi array, penyimpanan dan akses data berbeda. Dalam struktur, setiap instance menyimpan satu set lengkap atribut, sementara dalam array, semua data terkumpul dalam satu array, dengan setiap elemen mungkin hanya memiliki satu atribut atau kumpulan atribut dari beberapa entitas. Dalam array, setiap elemen memiliki akses ke data dalam struktur melalui instance. Ini berdampak pada penyusunan program, cara data dapat diakses, dan kinerja dan kejelasan kode, tergantung pada kebutuhan khusus aplikasi. Kode ini menunjukkan perubahan dalam definisi struktur buku; atribut seperti judul, pengarang, dan lain-lain diubah menjadi array berukuran 5. Selanjutnya, cara mengakses data juga berubah, di mana akses ke atribut-atribut dilakukan melalui indeks array, seperti `favorit.judulBuku[i]` untuk mengakses judul buku.

#### Full code Screenshot:
![Screenshot 2024-04-29 074503](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/4330b6dc-3213-4e1e-b81e-51312c0978ea)

## Kesimpulan
Salah satu perbedaan utama antara array dan struct adalah cara data disimpan dan diakses. Dalam array, data disimpan menjadi koleksi yang homogen dengan setiap elemen menyimpan satu nilai atau entitas, sedangkan dalam struct, data disimpan menjadi satu unit yang terdiri dari berbagai atribut. Keuntungan struct terletak pada kemampuannya untuk merepresentasikan entitas yang kompleks dengan berbagai atribut. Keuntungan array terletak pada kemampuannya untuk merepresentasikan entitas yang kompleks dengan berbagai atribut.Namun, kekurangan struct terletak pada fleksibilitas yang lebih rendah dalam mengelola data yang homogen, sedangkan kekurangan array terletak pada keterbatasannya dalam merepresentasikan entitas yang kompleks dengan atribut yang berbeda. Struct umumnya lebih sering digunakan dalam konteks yang melibatkan entitas kompleks yang memiliki atribut yang berbeda, sementara array lebih sering digunakan dalam situasi di mana data yang disimpan adalah kumpulan nilai atau entitas yang seragam.

## Referensi
[1] ALFIAN MA’ARIF, BUKU AJAR DASAR PEMROGRAMAN C++, Yogyakarta: UAD Press, 2022.

[2] Triase, ST, M. Kom, Diktat Edisi Revisi STRUKTUR DATA, hal 9-10, 2020.
