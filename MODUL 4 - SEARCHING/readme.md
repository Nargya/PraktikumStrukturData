# <h1 align="center">Laporan Praktikum Modul Algoritma Searching</h1>
<p align="center">Naufal Alif Anargya</p>
<p align="center">2311110041</p>

## Dasar Teori
#### Algoritma Searching
Algoritma searching adalah metode untuk mencari data yang sesuai dengan kriteria yang diinginkan dalam kumpulan data.Tujuan dari algoritma searching adalah untuk menemukan posisi di mana elemen yang dicari berada dalam kumpulan data tersebut. Algoritma searching sangat penting dalam dunia komputer karena sering digunakan dalam berbagai aplikasi, seperti pemrosesan data, basis data, kecerdasan buatan, dan sebagainya.

Terdapat beberapa jenis algoritma searching yang umum digunakan, di antaranya adalah:
1. Sequential Search
2. Binary Search 

## Sequential Search
Algoritma sequential searching yang biasanya disebut sebagai pendekatan pencarian secara beruntun merupakan pencarian yang diawali dari elemen awal sampai dengan elemen akhir secara beruntun hingga bisa menemukan elemen yang akan dikunjungi. Algoritma ini mampu melakukan pencarian dengan array yang data-datanya tidak perlu melalui pengurutan data sebelumnya. Cara kerja algoritma ini adalah dengan melakukan perbandingan antara data yang ada dengan data yang akan dicari satu per satu secara berurutan sampai dapat menemukan datanya [1].

## Binary Search
Pencarian   Biner   (binary   Search)   adalah   metode pencarian  data  pada  array  yang  telah terurut,  metode  ini lebih  effisien  dari  pada  metode  pencarian  linier  dimana semua  elemen  di  dalam  array  diuji  satu  persatu  sampai ditemukan elemen yang diinginkan .Algoritma  ini  bekerja  dengan  cara  memilih  record dengan  indeks  tengah  dari  tabel  dan  membandingkannya dengan  record  yang  hendak  dicari.  Jika  record  tersebut lebih  rendah  atau  lebih  tinggi,  maka  tabel  tersebut  dibagi dua  dan  bagian  tabel  yang  bersesuaian  akan  diproses kembali secara rekursif [2]. 

## Guided 

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data. Source code:

```C++
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    
    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    }
    
    cout << "\t Program Sequential Search Sederhana\n" << endl;
    cout << " data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    
    if (ketemu) {
        cout << "\n angka " << cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    
    return 0;
}
```

### Output : 
![Screenshot 2024-04-08 031210](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/20c59be2-270c-4fa1-94a3-6e404efa60ff)

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search

```C++
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
```

### Output : 
 ![Screenshot 2024-04-08 031642](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/39e76014-2d11-4e51-918b-99b4da5d6b67)

## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <algorithm> 
#include <string>

bool binarySearch(const std::string& sentence, char target) {
    return std::binary_search(sentence.begin(), sentence.end(), target);
}

int main() {
    std::string sentence;
    char target;

    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, sentence);

    std::cout << "Masukkan huruf yang ingin Anda cari: ";
    std::cin >> target;

    std::sort(sentence.begin(), sentence.end());

    bool found = binarySearch(sentence, target);

    if (found) {
        std::cout << "Huruf '" << target << "' ditemukan dalam kalimat." << std::endl;
    } else {
        std::cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << std::endl;
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-04-08 032950](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/a9711dc9-1949-48fc-9b47-74b7a8de9fe8)

Program yang ditampilkan adalah sebuah program dalam bahasa C++ yang memanfaatkan algoritma Binary Search untuk mencari sebuah huruf dalam sebuah kalimat yang dimasukkan oleh pengguna. Fungsi binarySearch sendiri adalah untuk menerima sebuah string (sentence) dan sebuah karakter (target) yang ingin dicari dengan menggunakan fungsi `std::binary_search` dari library `<algorithm>` untuk melakukan pencarian biner pada string sentence terhadap karakter target. Jika huruf ditemukan, program akan memberitahu pengguna bahwa huruf tersebut ditemukan dalam kalimat. Jika tidak ditemukan, program akan memberitahu pengguna bahwa huruf tersebut tidak ditemukan dalam kalimat. Program tersebut memanfaatkan konsep algoritma Binary Search untuk meningkatkan efisiensi pencarian dalam sebuah kalimat.

#### Full code Screenshot:
![Screenshot 2024-04-08 033132](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/3790b01b-e602-4cc3-8144-1514b93ece8b)

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
#include <iostream>
#include <string>
#include <cctype>

int countVowels(std::string str) {
    int count = 0;
    for (char c : str) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    std::string input;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    int vowelCount = countVowels(input);

    std::cout << "Number of vowels in the sentence: " << vowelCount << ".\n";

    return 0;
}
```
#### Output:
![Screenshot 2024-04-08 033851](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/4b9ba89b-8df9-4d7a-8a37-3ecb2e6d8354)

Program di atas adalah program C++ sederhana yang dapat menghitung berapa banyak huruf vokal yang dimasukkan oleh pengguna dalam sebuah kalimat. Pertama, fungsi `std::getline` digunakan oleh program untuk meminta pengguna memasukkan kalimat. Setelah itu, kalimat yang dimasukkan disimpan dalam variabel "input". Selanjutnya, program memanggil fungsi "countVowels" untuk menghitung berapa banyak huruf vokal yang ada dalam kalimat. Ini melakukan ini dengan menggunakan loop "for-each" untuk mengiterasi setiap karakter dalam kalimat. Serangkaian kondisional "if" digunakan untuk menentukan apakah setiap karakter adalah huruf vokal, baik huruf besar maupun huruf kecil. Jika ditemukan bahwa karakter tersebut adalah huruf vokal, variabel "count" akan ditambah satu. Menghitung selesai, fungsi "countVowels" mengembalikan jumlah huruf vokal.
Program ini kemudian menggunakan `std::cout` untuk menampilkan hasil perhitungan jumlah huruf vokal tersebut. Ini juga menunjukkan cara menggunakan loop dan kondisional dalam C++ untuk menghitung jumlah karakter tertentu dalam string.


#### Full code Screenshot:
![Screenshot 2024-04-08 034354](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/6fb8a9c0-231c-4890-8361-e7fcabbdc6e1)

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
#include <iostream>

int sequentialSearch(int arr[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 4;

    int count = sequentialSearch(data, size, target);

    std::cout << "Number of occurrences of " << target << " in the array: " << count << ".\n";

    return 0;
}
```
#### Output:
![Screenshot 2024-04-08 034738](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/882547eb-9981-4c81-98c8-c8c91e51b2fb)

Program di atas adalah program sederhana yang menggunakan algoritma pencarian sekuensial untuk menghitung jumlah kemunculan bilangan integer tertentu dalam sebuah array. Pertama, program mendefinisikan fungsi "sequentialSearch" dengan tiga parameter: array integer (arr), ukuran array (size), dan angka target. Fungsi ini melakukan pencarian sekuensial dalam array untuk menghitung jumlah kali angka target muncul. Fungsi menentukan apakah nilai pada indeks array saat ini sama dengan nilai target dalam setiap iterasi loop "for". Jika itu benar, variabel "jumlah" akan bertambah satu. Fungsi mengembalikan nilai "count" setelah iterasi selesai.

Sebuah array "data" yang berisi angka tertentu telah ditetapkan pada fungsi "main". Ukuran satu elemen dalam array—ukuran "int"—dibagi dengan ukuran total array. Kemudian, ukuran array ini dapat dihitung. Selanjutnya, nilai target dan jumlah kemunculannya juga ditetapkan. Selanjutnya, fungsi sequentialSearch dihubungkan ke array data, ukuran array, dan nilai target. Dengan menggunakan `std::cout`, jumlah angka target yang muncul di layar ditampilkan.

Program ini menggunakan algoritma pencarian sekuensial untuk memberikan informasi tentang berapa kali angka target muncul dalam array yang diberikan. Ini juga dapat digunakan sebagai contoh penggunaan algoritma pencarian sekuensial dalam praktik, dan memberikan pemahaman tentang bagaimana loop dan fungsi dapat digunakan untuk mencapai tujuan tertentu dalam pemrograman C++.

#### Full code Screenshot:
![Screenshot 2024-04-08 034857](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/6b5743d2-8921-483f-aab2-5e5eba27c2db)

## Kesimpulan
Metode untuk mencari elemen tertentu dalam kumpulan data dikenal sebagai algoritma searching. Tujuannya adalah untuk menemukan lokasi elemen tersebut atau memastikan bahwa elemen tersebut tidak ada dalam kumpulan data. Selain digunakan dalam berbagai aplikasi seperti basis data, pengolahan string, dan pemrograman komputer secara umum, algoritma searching sangat penting dalam pemrosesan data. Kelebihan algoritma searching adalah kemampuannya untuk membantu kita menemukan informasi yang kita cari dalam jumlah data yang besar. Namun, kelemahan algoritma searching adalah kinerjanya yang dapat menjadi lambat jika data tidak terurut, dan dia tidak dapat menangani jenis data tertentu seperti data terstruktur yang kompleks. Oleh karena itu, sangat penting untuk memilih algoritma searching yang tepat untuk memenuhi kebutuhan dan fitur unik dari setiap masalah pencarian yang dihadapi.

## Referensi
[1] Rahmanto, Y., Alfian, J., Damayanti, D., & Borman, R. I. (2021). Penerapan Algoritma Sequential Search pada Aplikasi Kamus Bahasa Ilmiah Tumbuhan. Jurnal Buana Informatika, 12(1), 21-30.

[2] Toyib, R., Darnita, Y., & Deva, A. R. S. (2021). Penerapan Algoritma Binary Search Pada Aplikasi E-Order. Jurnal Media Infotama, 17(1).