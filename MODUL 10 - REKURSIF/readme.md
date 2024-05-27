# <h1 align="center">Laporan Praktikum Modul REKURSIF</h1>
<p align="center">Naufal Alif Anargya</p>
<p align="center">2311110041</p>

## Dasar Teori
### Rekursif
Iteratif dan rekursif adalah sebuah algoritma yang memiliki ciri yang sama yaitu mengulangi
langkah-langkah yang diinginkan. Namun, rekursif agak berbeda dari iterasi. Rekursif adalah sebuah
algoritma yang berisi pemanggilan dirinya sendiri sehingga menghasilkan looping. Harus ada batasan
di dalam rekursif sehingga looping dapat dibatalkan, jika tidak maka akan terjadi infinity loop dan
dapat menyebabkan memori penuh. Rekursi adalah suatu proses dengan salah satu langkah dalam prosedur tersebut menjalankan
prosedur itu sendiri. Dalam pemrograman komputer, rekursi dicontohkan saat sebuah fungsi
didefinisikan dalam bentuk sederhana, bahkan versi terkecil dari dirinya. Solusi dari permasalahan
kemudian dirancang dengan menggabungkan solusi-solusi yang didapat dari versi sederhana dari
permasalahan.[1]

Fungsi rekursif adalah fungsi yang mengacu pada
dirinya sendiri. Fungsi rekursif disusun atas dua
bagian, yaitu basis dan rekurens.
Basis berisi nilai awal yang tidak mengacu pada
dirinya sendiri. Bagian ini berfungsi untuk
memberikan nilai yang terdefinisi pada fungsi rekursif
dan sekaligus menghentikan proses rekursi.
Rekurens merupakan bagian fungsi yang
mendefinisikan argumen fungsi dalam terminologi
dirinya sendiri. Setiap kali fungsi tersebut melakukan
bagian rekurens maka argumen dari fungsi tersebut
harus lebih dekat pada basisnya.
Fungsi rekursif merupakan salah satu konsep yang
penting untuk dikuasai. Hal ini dikarenakan fungsi ini
memiliki sangat banyak implementasi, yang dalam hal
ini adalah implementasi dalam algoritma.
Fungsi rekursif dan fungsi iteratif memiliki kelebihan
dan kelemahan masing-masing. Secara umum fungsi
rekursif memiliki algoritma yang lebih mudah
dipahami dan dibuat tetapi membutuhkan penggunaan
memori yang besar.
Berikut adalah perbandingan secara umum algoritma
yang dibuat dengan menggunakan konsep rekursif dan
iteratif:
- **Fungsi rekursif :**
  1. Algoritma biasanya lebih ringkas dan mudah dipahami
  2. Membutuhkan alokasi yang besar (kecuali pada "Tail Recursive")
  3. Tidak cocok ketika kinerja tinggi diperlukan, karena terjadi overhead pemanggilan fungsi dalam jumlah yang relatif besar.

- **Fungsi Iteratif :**
  1. Kode program lebih
panjang, untuk
beberapa kasus solusi
iteratif lebih sulit
diterapkan
  2. Relatif lebih kecil
alokasi memorinya
  3. Cocok diterapkan
ketika kinerja aplikasi
harus diterapkan (hanya
ada satu kali
pemanggilan fungsi)

Itu adalah perbedaan atau perbandingan antara fungsi rekursif dan fungsi iteratif.[2]

### Rekursi Langsung 
Rekursi langsung adalah jenis rekursi di mana suatu fungsi memanggil dirinya sendiri secara langsung dalam blok kodenya sendiri . Artinya, fungsi tersebut muncul sebagai bagian dari definisi fungsi, dan fungsi tersebut memanggil dirinya sendiri untuk menjalankan tugasnya.

Fungsi rekursif langsung untuk menghitung faktorial suatu bilangan adalah contoh rekursi langsung. Faktorial suatu bilangan diperoleh dengan mengalikan semua bilangan bulat positif yang kurang dari atau sama dengan bilangan tersebut. Misalnya, jika kita mengambil bilangan 6, maka faktorial dari 6 (ditulis 6!) adalah 6x5x4x3x2x1=720.
Ada beberapa keuntungan menggunakan rekursi langsung. Salah satu keuntungannya adalah menulis dan memahami fungsi rekursif langsung seringkali lebih mudah , karena kasus dasar dan kasus rekursif didefinisikan dengan jelas dalam fungsi yang sama.Selain itu, dalam skenario tertentu, penggunaan rekursi langsung dapat meningkatkan efisiensi, karena menghindari overhead pemanggilan fungsi tambahan.
Namun, ada juga beberapa kelemahan menggunakan rekursi langsung. Salah satu kelemahannya adalah hal ini dapat menimbulkan kesulitan yang lebih besar untuk men-debug fungsi rekursif langsung , karena tumpukan panggilan bisa menjadi sangat besar dan kemungkinan besar menjadi sulit untuk melacak eksekusi fungsi tersebut. Selain itu, rekursi langsung dapat menghabiskan banyak memori jika rekursi tidak dihentikan dengan benar, karena setiap panggilan rekursif menambahkan lapisan baru ke tumpukan panggilan.
Secara keseluruhan, sangat penting untuk mengevaluasi keseimbangan antara kesederhanaan, efisiensi, dan debugging ketika memutuskan apakah akan menggunakan rekursi langsung dalam situasi tertentu.
[3]

**Contoh** 
```C++
#include <iostream>
using namespace std;

// Fungsi rekursi untuk mencetak angka dari 1 hingga n
void cetakAngka(int n) {
    if (n == 0) {
        return;
    } else {
        cetakAngka(n - 1); // Rekursi: panggil fungsi dengan n - 1
        cout << n << " "; // Cetak nilai n setelah kembali dari rekursi
    }
}

int main() {
    int n;
    cout << "Masukkan sebuah bilangan bulat positif: ";
    cin >> n;

    cout << "Angka dari 1 hingga " << n << " adalah: ";
    cetakAngka(n);
    cout << endl;

    return 0;
}
```
Dalam contoh ini, fungsi `cetakAngka` mencetak angka dari 1 hingga n menggunakan rekursi langsung. Saat memanggil dirinya sendiri dengan argumen n - 1, ia mencetak angka dari 1 hingga n - 1 terlebih dahulu sebelum mencetak nilai n. Ini adalah contoh yang sederhana namun berguna dari rekursi langsung dalam C++.

### Rekursi tidak langsung
Dalam rekursi tidak langsung, suatu fungsi memanggil fungsi lain yang kemudian memanggil kembali fungsi pertama . Rekursi berakhir ketika kasus dasar terpenuhi, dan pada saat itulah proses berhenti. Salah satu keuntungan dari rekursi tidak langsung adalah seringkali lebih mudah untuk dipahami dan di-debug , karena kasus dasar dan kasus rekursif didefinisikan dalam fungsi terpisah. Selain itu, rekursi tidak langsung dapat meningkatkan efisiensi dalam kasus tertentu, karena memungkinkan struktur yang lebih modular dan dapat mengurangi ukuran tumpukan panggilan. Namun, ada juga beberapa kelemahan menggunakan rekursi tidak langsung. Salah satu kelemahannya adalah penulisan dan pemahamannya bisa lebih rumit , karena logikanya terbagi menjadi dua fungsi. Selain itu, rekursi tidak langsung dapat menghabiskan lebih banyak memori dalam beberapa kasus, karena memerlukan pembuatan pemanggilan fungsi tambahan. Sangat penting untuk mengevaluasi keseimbangan antara kompleksitas, efisiensi, dan modularitas dengan cermat ketika memutuskan apakah akan menggunakan rekursi tidak langsung dalam situasi tertentu.[3]

**Contoh**
```C++
#include <iostream>
using namespace std;

// Fungsi rekursi yang tidak langsung untuk menghitung pangkat
int pangkat(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * pangkat(base, exponent - 1); // Panggil fungsi rekursi
    }
}

int main() {
    int base, exponent;

    cout << "Masukkan basis: ";
    cin >> base;
    cout << "Masukkan eksponen: ";
    cin >> exponent;

    // Panggil fungsi rekursi
    int hasil = pangkat(base, exponent);

    cout << "Hasil " << base << "^" << exponent << " adalah: " << hasil << endl;

    return 0;
}
```
Dalam contoh ini, fungsi `pangkat` menggunakan rekursi tidak langsung. Meskipun ia menggunakan dirinya sendiri secara rekursif, panggilan rekursif terjadi melalui perantaraan fungsi yang sama, yaitu `pangkat`. Ini adalah contoh yang sederhana dari rekursi tidak langsung dalam C++.

## Guided
### 1. Rekursif Langsung (Direct Recursion)
```C++
#include <iostream>
using namespace std;

//Code ini berfungsi untuk melakukan hitung mundur
//dari angka yang diinputkan

void countdown(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursi Langsung: ";
    countdown(5); //5 merupakan input nya
    cout << endl;
    return 0;
}

```
#### **Ouput**
![Screenshot 2024-05-28 031616](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/950c41ce-5ef4-4788-85da-4a99ae6063c6)

#### **Penjelasan**
Fungsi countdown menerima satu parameter yang merupakan angka yang akan dihitung mundur. Saat fungsi dipanggil dengan nilai parameter yang lebih besar dari 0, fungsi tersebut mencetak nilai parameter tersebut, kemudian memanggil dirinya sendiri dengan argumen yang lebih kecil satu unit. Proses ini terus berulang hingga parameter mencapai nilai 0, saat itulah rekursi berhenti. Karena setiap panggilan rekursif langsung memanggil fungsi itu sendiri tanpa melalui fungsi lain sebagai perantara, maka code tersebut termasuk sebagai rekursi langsung. Dalam kasus ini, setiap panggilan rekursif countdown(n - 1) terjadi secara langsung dalam fungsi countdown itu sendiri, tanpa membutuhkan fungsi lain sebagai perantara.

### 2.	Rekursif Tidak Langsung (Indirect Recursion)
```C++
#include <iostream>
using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1); // Panggilan rekursif tidak langsung
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2); // Panggilan rekursif tidak langsung
    }
}

int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
}

```
#### **Output**
![Screenshot 2024-05-28 031901](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/4a1d85b9-3c71-44f0-a37f-b2cd8a07a5b0)

#### **Penjelasan**
Fungsi functionA dan functionB saling memanggil satu sama lain secara bergantian melalui panggilan rekursif, tanpa memanggil diri sendiri langsung. Saat fungsi functionA dipanggil dengan nilai parameter yang lebih besar dari 0, ia mencetak nilai parameter tersebut, kemudian memanggil functionB dengan argumen n - 1. Kemudian, saat functionB dipanggil, ia mencetak nilai parameter dan memanggil functionA dengan argumen n / 2. Proses ini terus berulang secara bergantian antara kedua fungsi hingga kondisi terminasi terpenuhi. Karena rekursi terjadi melalui pemanggilan fungsi lain sebagai perantara dan tidak secara langsung memanggil dirinya sendiri, maka code tersebut termasuk sebagai rekursi tidak langsung.

## Unguided
### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
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
```

#### **Output** 
![Screenshot 2024-05-28 032844](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/12570832-6a88-48a5-8a62-6a7a6c0e8824)

#### **Penjelasan :**
Code tersebut adalah code yang menghitung nilai faktorial dari sebuah bilangan bulat positif yang dimasukkan oleh pengguna. Fungsi faktorial merupakan contoh dari rekursi langsung, di mana fungsi tersebut memanggil dirinya sendiri secara langsung dengan nilai argumen yang lebih kecil hingga mencapai kondisi terminasi (ketika n kurang dari atau sama dengan 1). Algoritma faktorial menggunakan rekursi langsung untuk menghitung hasil faktorial dari angka yang dimasukkan pengguna. Output dari program ini akan mencetak nilai faktorial dari angka yang dimasukkan oleh pengguna. Misalnya, jika pengguna memasukkan angka 5, program akan menghitung faktorial dari 5, yaitu 5! = 5 * 4 * 3 * 2 * 1 = 120, dan output yang dihasilkan akan menjadi "Nilai faktorialnya adalah: 120".

#### **Fullcode Screenshot**
![Screenshot 2024-05-28 032931](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/f70d3e73-2306-4aee-98a5-8a24141e2e9d)

### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!

```C++
#include <iostream>
using namespace std;

int faktorial(int n);
int main(){
    int angka, hasil;
    cout << "menghitung faktorial dari : ";
    cin >> angka;

    hasil = faktorial(angka);
    cout << "\nnilai faktorialnya adalah : " << hasil << endl;

    cin.get();
    return 0;
}

int faktorial(int n){
    if (n <= 1){
        cout << n;
        return n;
    }else{
        cout << n << "*";
        return n * faktorial(n - 1);
    }
}
```

#### **Output**
![Screenshot 2024-05-28 033031](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/94ec8dc9-67c7-4d97-a5be-e5eee075a356)

#### **Penjelasan :**
Kode ini menggunakan rekursi tidak langsung untuk menghitung nilai faktorial dari bilangan bulat positif yang dimasukkan. Dalam kode ini, fungsi "faktorial" mencetak setiap nilai "n" dalam perhitungan faktorial secara berurutan, kemudian melakukan pemanggilan rekursif untuk menghitung faktorial dari nilai "n - 1". Proses ini berulang hingga kondisi terminasi di mana nilai "n" kurang dari atau sama dengan 1. Oleh karena itu, kode ini dimasukkan sebagai rekursi tidak langsung. Seluruh langkah-langkah perhitungan faktorial akan dicetak hingga mencapai hasil akhir program. Misalnya, program akan mencetak langkah-langkah perhitungan dalam bentuk "5*4*3*2*1" ketika pengguna memasukkan angka 5. Output akhirnya akan menjadi "nilai faktorialnya adalah: 120". Perbedaan utama antara code ini dengan code sebelumnya adalah pada penanganan output dan cara perhitungan faktorial. Code sebelumnya hanya mencetak hasil akhir dari perhitungan faktorial, sedangkan code ini mencetak setiap langkah perhitungan faktorial hingga mencapai hasil akhir.

#### **Fullcode Screenshot**
![Screenshot 2024-05-28 033111](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/b0383454-4f90-4512-9dbf-77fbff017e42)

## Kesimpulan
Dalam pemrograman, rekursi adalah ketika fungsi dapat memanggil dirinya sendiri untuk menyelesaikan tugas tertentu. Rekursi bergantung pada pemecahan masalah yang dapat dipecahkan menjadi kasus yang lebih kecil dari masalah awal. Ketika sebuah fungsi memanggil dirinya sendiri secara langsung, itu disebut rekursi langsung. Ketika sebuah fungsi memanggil fungsi lain dan kemudian memanggil kembali fungsi pertama, itu disebut rekursi tidak langsung. Rekursi memiliki kemampuan untuk menyederhanakan logika program dan menyelesaikan masalah dengan elegan. Namun, rekursi memiliki kelemahan, termasuk penggunaan memori yang lebih besar dan kemungkinan stack overflow jika tidak dihentikan dengan benar. Pemilihan antara menggunakan rekursi atau pendekatan iteratif sering kali bergantung pada kompleksitas masalah, preferensi pribadi, dan kinerja program yang diinginkan.

## Referensi

[1] Fenina Adline Twince Tobing, Prayogo, Alex Chandra, "*Analisis Perbandingan Fibonacci dengan Iterasi dan
Rekursi Terhadap Efektifitas Waktu*", Jurnal Sains dan Teknologi Widya, vol.1, no.2, Juli 2022

[2] Erba Lutfina, Nur Inayati, Galuh Wilujeng Saraswati, "*Analisis Perbandingan Kinerja Metode Rekursif dan Metode Iteratif dalam
Algoritma Linear Search*", Komputika: Jurnal Sistem Komputer, Volume 11, Nomor 2, Oktober 2022.

[3] Antonius Petrus, Grzegorz Piwowarek, "*Rekursi: Langsung vs Tidak Langsung*", Maret 2024.
