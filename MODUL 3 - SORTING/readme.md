# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Naufal Alif Anargya</p>
<p align="center">2311110041</p>

## Dasar Teori
### 1. Algoritma Sorting

Algoritma sorting adalah salah satu alogitma dasar yang  sering  digunakan  untuk  menyelesaikan  masalah pengurutan.  Pengurutan  data  atau sorting merupakan salah  satu  jenis  operasi  penting  dalam  pengolahan data.   Data   yang   sudah terurut   memiliki   beberapa keuntungan.  Selain  mempercepat  waktu  pencarian, dari  data  yang  terurut  dapat  langsung  diperoleh  nilai maksimum dan nilai minimum. Dalam    penyelesaian    algoritma sortingatau algoritma   pengurutan,   ada   beberapa   metode   yang dapat  digunakan  yaitu: bubble sort, selection sort, insertion sort.[1]

## Jenis Algoritma Sorting
### - Insertion Sort
Insert     sort     merupakan     pengurutan     sisipan     atau menyisipkan antara beberapa elemen array yang tepat sehingga elemen  array  tersebut  terurut  ascending  ataupun  descending. Insert    sort    ialah    algoritma    sederhana    untuk    pengurutan sekumpulan  data  dengan  membandingkan  semua  data    mulai dari data ke 2 dengan data ke 1  dan mulai dari  datanya terus bertambah   sampai   beberapa   jumlah   sekumpulan   data   dan dibandingkan  datanya  sampai  data  ke  i  (sampai  elemen  array terakhir) mengurutkan secara ascending ataupu descending.[2]
```C++
#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    std::vector<int> arr = {12, 11, 13, 5, 6};
    insertion_sort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}
```
### - Bubble Sort
Bubble sort merupakan salah satu jenis sorting. Ide dari algoritma ini adalah mengulang proses pembandingan antara tiap-tiap elemen array dan menukarnya apabila urutannya salah. Pembandingan elemen-elemen ini akan terus diulang hingga tidak perlu dilakukan penukaran lagi. Algoritma ini termasuk dalam golongan algoritma comparison sort, karena menggunakan perbandingan dalam operasi antar elemennya.[3]

```C++
#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& arr)
{
    bool swapped = true;
    for (int i = 0; i < arr.size() && swapped; i++)
    {
        swapped = false;
        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
    }
}

int main()
{
    std::vector<int> arr = {12, 11, 13, 5, 6};
    bubble_sort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}
```

### - Selection Sort
Selection   sort   adalah   algoritma   pengurutan   sederhana. Algoritma pengurutan ini adalah algoritma berbasis perbandingan  di  tempat  di  mana  daftar  dibagi  menjadi  dua bagian,  bagian  yang  diurutkan  di  ujung  kiri  dan  bagian  yang tidak disortir di ujung kanan. Awalnya, bagian yang diurutkan kosong dan bagian yang tidak disortir adalah seluruh daftar. Elemen terkecil dipilih dari array yang tidak disortir dan ditukar dengan elemen paling kiri, dan elemen tersebut menjadi bagian dari array yang diurutkan. Proses ini terus memindahkan batas array yang tidak disortir oleh satu elemen ke kanan.[2]

```C++
#include <iostream>
#include <vector>

void selection_sort(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int min_index = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
}

int main()
{
    std::vector<int> arr = {12, 11, 13, 5, 6};
    selection_sort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}
```

## Guided 

### 1. Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

```C++
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]){
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

void print_array(double a[], int length){
    
    for (int i=0; i<length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(){

    int length = 5;
    double a[] = {22,1,15,3,8,2,33,21,99,99};

    cout << "urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```
Kode di atas adalah implementasi algoritma pengurutan gelembung (bubble sort) untuk mengurutkan larik bilangan ganda (double). Tujuan dari kode di atas adalah untuk mengurutkan larik bilangan ganda menggunakan algoritma pengurutan gelembung dan mencetak hasil sebelum dan sesudah pengurutan.

### 2. Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort

```C++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length){
    int i,j;
    char tmp;

    for (i = 1; i < length; i++){
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]){
            tmp = arr[j];
            arr[j] = arr [j - 1];
            arr[j - 1] = tmp;
            j--;
        }//end of while loop
    }//end of for loop
}

void print_array(char a[], int length){
    for(int i=0; i < length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(){
    int length = 6;
    char a[length] = {'c','f','a','z','d','p'};
    
    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}
```
Kode di atas adalah implementasi algoritma pengurutan sisipan (insertion sort) untuk mengurutkan larik karakter (char). Tujuan dari kode di atas adalah untuk mengurutkan larik karakter menggunakan algoritma pengurutan sisipan dan mencetak hasil sebelum dan sesudah pengurutan.

## Unguided 

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort!

```C++
#include <iostream>
#include <algorithm>
using namespace std;

void selection(double arr[], int size)
{
    for(int i =0; i< size; i++)
    {
        int maxIndex = i;
        for(int j = i+1; j < size; j++)
        {
            if(arr[maxIndex] < arr[j])
            {
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
    }
}

int main()
{
    double arr[] = {3.8, 2.9, 3.3, 4.0, 2.4};
    int size = sizeof(arr)/sizeof(arr[0]);
    selection(arr, size);
    for(int i =0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-04-01 082109](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/227396cb-455b-41e4-b806-f87e80a7c336)

Dua parameter diberikan kepada fungsi pemilihan: arr, yang merupakan array double, dan size, yang merupakan ukuran array. Perulangan luar memilih setiap elemen sebagai elemen saat ini, dan perulangan dalam membandingkan setiap elemen dengan elemen saat ini dalam fungsi pemilihan. Variabel maxIndex diperbarui ke indeks elemen yang lebih besar jika elemen yang lebih besar ditemukan. Setelah perulangan dalam selesai, elemen pada indeks maxIndex akan ditukar dengan elemen saat ini. Ini akan menempatkan elemen terbesar di bagian terurut dari array. Dengan mengurutkan array secara in-place, fungsi pemilihan tidak membutuhkan memori tambahan.

Kompleksitas waktu algoritma ini adalah O(n^2) atau kompleksitas waktu kuadrat, dimana n adalah jumlah elemen dalam larik yang perlu diurutkan. Alasan yang mendasari hal ini adalah terdapat loop bersarang, serta pada setiap iterasi loop dalam, terdapat operasi pembandingan dan penukaran (jika diperlukan), yang memiliki kompleksitas waktu tetap.

#### Full code Screenshot:
![Screenshot 2024-04-01 082153](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/f6ad2138-dfb0-44b3-a696-c89cb88271cf)

### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!

```C++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void bubbleSort(string names[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (names[j] > names[j+1])
            {
                swap(names[j], names[j+1]);
            }
        }
    }
}

int main()
{
    string names[10] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
    int n = sizeof(names)/sizeof(names[0]);
    bubbleSort(names, n);
    for(int i =0; i < n; i++)
    {
        cout << names[i] << " ";
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-04-01 082449](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/ca3cf611-aa4f-42ec-a00b-7aecaea9278c)

Dua parameter diberikan kepada fungsi bubbleSort: (names) yang merupakan string array, dan (n) yang merupakan ukuran array.Fungsi bubbleSort melakukan perulangan. Perulangan dalam membandingkan setiap elemen dengan elemen berikutnya, dan perulangan luar berjalan sebanyak n-1 kali. Fungsi bubbleSort mengurutkan array secara in-place, sehingga tidak memerlukan memori tambahan. Elemen akan ditukar jika elemen saat ini lebih besar dari elemen berikutnya.

Dalam kasus terburuk, di mana n adalah jumlah elemen dalam array, kompleksitas waktu algoritma Sort Bubble adalah O(n^2) atau kompleksitas waktu kuadrat. Namun, algoritma ini tidak cocok untuk array yang besar, tetapi mudah dipahami dan digunakan. Algoritma Sort Bubble memerlukan memori terus-menerus saat mengurutkan array karena kompleksitas ruangnya adalah O(1), yang independen dari ukuran array.

#### Full code Screenshot:
![Screenshot 2024-04-01 082600](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/2d122919-c457-47c5-a78b-c5da17077a38)

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!

```C++
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::vector<char> arr(n);
    std::cout << "Enter " << n << " characters: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());
    std::cout << "Ascending order: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::sort(arr.begin(), arr.end(), std::greater<char>());
    std::cout << "\nDescending order: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-04-01 082818](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/77b55939-cd72-46e5-a0d1-413e9b09b645)

Dalam program C++ di atas, pengguna diminta untuk memasukkan sejumlah karakter, menyimpannya dalam sebuah vektor, mengurutkan karakter-karakter tersebut dalam urutan naik dan menurun, dan mencetak hasilnya. Setelah pengguna meminta berapa banyak karakter yang akan dimasukkan, program menginisialisasi sebuah vektor dengan ukuran yang sesuai dan menyimpan karakter-karakter tersebut. Kemudian, fungsi `std::sort` digunakan untuk mengurutkan vektor dalam urutan naik dan kemudian dalam urutan menurun, menggunakan pembanding `std::greater<char>()`. Hasil pengurutan ditunjukkan di layar.

Secara keseluruhan, kompleksitas waktu dari kode tersebut adalah O(n log n) atau kompleksitas waktu logaritmik, di mana 'n' adalah jumlah karakter yang dimasukkan pengguna. Hal ini disebabkan oleh kompleksitas waktu pengurutan menggunakan `std::sort`, yang dominan dalam penentuan kompleksitas keseluruhan.

#### Full code Screenshot:
![Screenshot 2024-04-01 082913](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/5ed3eba4-a6d3-4f67-b4c2-7cf25eda959c)

## Kesimpulan
Algoritma sorting merupakan teknik untuk mengurutkan data dalam suatu urutan tertentu, seperti dari yang terkecil ke yang terbesar atau sebaliknya. Berbagai jenis algoritma sorting, seperti Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, dan Merge Sort, memiliki cara kerja yang berbeda-beda serta kelebihan dan kekurangan masing-masing. Pemilihan algoritma sorting yang tepat tergantung pada karakteristik data yang akan diurutkan dan kebutuhan aplikasi. Algoritma seperti Quick Sort dan Merge Sort cenderung lebih efisien untuk jumlah data yang besar, sementara Bubble Sort dan Selection Sort lebih cocok untuk jumlah data yang kecil atau sebagai algoritma dasar untuk keperluan pendidikan.

## Referensi
[1] Tobing, F. A. T., & Tambunan, J. R. (2020). Analisis Perbandingan Efisiensi Algoritma Brute Force dan Divide and Conquer dalam Proses Pengurutan Angka. Ultimatics: Jurnal Teknik Informatika, 12(1), 52-58.

[2] YANTI, Fitri; ERIANA, Emi Sita. Algoritma Sorting dan Searching. 2024.

[3] A. Sonita and F. Nurtaneo, “ANALISIS PERBANDINGAN ALGORITMA BUBBLE SORT, MERGE SORT, DAN QUICK SORT DALAM PROSES PENGURUTAN KOMBINASI ANGKA DAN HURUF”, pseudocode, vol. 2, no. 2, pp. 75–80, Aug. 2016.
=======
# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Naufal Alif Anargya</p>
<p align="center">2311110041</p>

## Dasar Teori
### 1. Algoritma Sorting

Algoritma sorting adalah salah satu alogitma dasar yang  sering  digunakan  untuk  menyelesaikan  masalah pengurutan.  Pengurutan  data  atau sorting merupakan salah  satu  jenis  operasi  penting  dalam  pengolahan data.   Data   yang   sudah terurut   memiliki   beberapa keuntungan.  Selain  mempercepat  waktu  pencarian, dari  data  yang  terurut  dapat  langsung  diperoleh  nilai maksimum dan nilai minimum. Dalam    penyelesaian    algoritma sortingatau algoritma   pengurutan,   ada   beberapa   metode   yang dapat  digunakan  yaitu: bubble sort, selection sort, insertion sort.[1]

## Jenis Algoritma Sorting
### - Insertion Sort
Insert     sort     merupakan     pengurutan     sisipan     atau menyisipkan antara beberapa elemen array yang tepat sehingga elemen  array  tersebut  terurut  ascending  ataupun  descending. Insert    sort    ialah    algoritma    sederhana    untuk    pengurutan sekumpulan  data  dengan  membandingkan  semua  data    mulai dari data ke 2 dengan data ke 1  dan mulai dari  datanya terus bertambah   sampai   beberapa   jumlah   sekumpulan   data   dan dibandingkan  datanya  sampai  data  ke  i  (sampai  elemen  array terakhir) mengurutkan secara ascending ataupu descending.[2]
```C++
#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    std::vector<int> arr = {12, 11, 13, 5, 6};
    insertion_sort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}
```
### - Bubble Sort
Bubble sort merupakan salah satu jenis sorting. Ide dari algoritma ini adalah mengulang proses pembandingan antara tiap-tiap elemen array dan menukarnya apabila urutannya salah. Pembandingan elemen-elemen ini akan terus diulang hingga tidak perlu dilakukan penukaran lagi. Algoritma ini termasuk dalam golongan algoritma comparison sort, karena menggunakan perbandingan dalam operasi antar elemennya.[3]

```C++
#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& arr)
{
    bool swapped = true;
    for (int i = 0; i < arr.size() && swapped; i++)
    {
        swapped = false;
        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
    }
}

int main()
{
    std::vector<int> arr = {12, 11, 13, 5, 6};
    bubble_sort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}
```

### - Selection Sort
Selection   sort   adalah   algoritma   pengurutan   sederhana. Algoritma pengurutan ini adalah algoritma berbasis perbandingan  di  tempat  di  mana  daftar  dibagi  menjadi  dua bagian,  bagian  yang  diurutkan  di  ujung  kiri  dan  bagian  yang tidak disortir di ujung kanan. Awalnya, bagian yang diurutkan kosong dan bagian yang tidak disortir adalah seluruh daftar. Elemen terkecil dipilih dari array yang tidak disortir dan ditukar dengan elemen paling kiri, dan elemen tersebut menjadi bagian dari array yang diurutkan. Proses ini terus memindahkan batas array yang tidak disortir oleh satu elemen ke kanan.[2]

```C++
#include <iostream>
#include <vector>

void selection_sort(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int min_index = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
}

int main()
{
    std::vector<int> arr = {12, 11, 13, 5, 6};
    selection_sort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}
```

## Guided 

### 1. Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

```C++
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]){
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

void print_array(double a[], int length){
    
    for (int i=0; i<length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(){

    int length = 5;
    double a[] = {22,1,15,3,8,2,33,21,99,99};

    cout << "urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```
Kode di atas adalah implementasi algoritma pengurutan gelembung (bubble sort) untuk mengurutkan larik bilangan ganda (double). Tujuan dari kode di atas adalah untuk mengurutkan larik bilangan ganda menggunakan algoritma pengurutan gelembung dan mencetak hasil sebelum dan sesudah pengurutan.

### 2. Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort

```C++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length){
    int i,j;
    char tmp;

    for (i = 1; i < length; i++){
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]){
            tmp = arr[j];
            arr[j] = arr [j - 1];
            arr[j - 1] = tmp;
            j--;
        }//end of while loop
    }//end of for loop
}

void print_array(char a[], int length){
    for(int i=0; i < length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(){
    int length = 6;
    char a[length] = {'c','f','a','z','d','p'};
    
    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}
```
Kode di atas adalah implementasi algoritma pengurutan sisipan (insertion sort) untuk mengurutkan larik karakter (char). Tujuan dari kode di atas adalah untuk mengurutkan larik karakter menggunakan algoritma pengurutan sisipan dan mencetak hasil sebelum dan sesudah pengurutan.

## Unguided 

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort!

```C++
#include <iostream>
#include <algorithm>
using namespace std;

void selection(double arr[], int size)
{
    for(int i =0; i< size; i++)
    {
        int maxIndex = i;
        for(int j = i+1; j < size; j++)
        {
            if(arr[maxIndex] < arr[j])
            {
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
    }
}

int main()
{
    double arr[] = {3.8, 2.9, 3.3, 4.0, 2.4};
    int size = sizeof(arr)/sizeof(arr[0]);
    selection(arr, size);
    for(int i =0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-04-01 082109](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/227396cb-455b-41e4-b806-f87e80a7c336)

Dua parameter diberikan kepada fungsi pemilihan: arr, yang merupakan array double, dan size, yang merupakan ukuran array. Perulangan luar memilih setiap elemen sebagai elemen saat ini, dan perulangan dalam membandingkan setiap elemen dengan elemen saat ini dalam fungsi pemilihan. Variabel maxIndex diperbarui ke indeks elemen yang lebih besar jika elemen yang lebih besar ditemukan. Setelah perulangan dalam selesai, elemen pada indeks maxIndex akan ditukar dengan elemen saat ini. Ini akan menempatkan elemen terbesar di bagian terurut dari array. Dengan mengurutkan array secara in-place, fungsi pemilihan tidak membutuhkan memori tambahan.

Kompleksitas waktu algoritma ini adalah O(n^2) atau kompleksitas waktu kuadrat, dimana n adalah jumlah elemen dalam larik yang perlu diurutkan. Alasan yang mendasari hal ini adalah terdapat loop bersarang, serta pada setiap iterasi loop dalam, terdapat operasi pembandingan dan penukaran (jika diperlukan), yang memiliki kompleksitas waktu tetap.

#### Full code Screenshot:
![Screenshot 2024-04-01 082153](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/f6ad2138-dfb0-44b3-a696-c89cb88271cf)

### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!

```C++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void bubbleSort(string names[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (names[j] > names[j+1])
            {
                swap(names[j], names[j+1]);
            }
        }
    }
}

int main()
{
    string names[10] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
    int n = sizeof(names)/sizeof(names[0]);
    bubbleSort(names, n);
    for(int i =0; i < n; i++)
    {
        cout << names[i] << " ";
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-04-01 082449](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/ca3cf611-aa4f-42ec-a00b-7aecaea9278c)

Dua parameter diberikan kepada fungsi bubbleSort: (names) yang merupakan string array, dan (n) yang merupakan ukuran array.Fungsi bubbleSort melakukan perulangan. Perulangan dalam membandingkan setiap elemen dengan elemen berikutnya, dan perulangan luar berjalan sebanyak n-1 kali. Fungsi bubbleSort mengurutkan array secara in-place, sehingga tidak memerlukan memori tambahan. Elemen akan ditukar jika elemen saat ini lebih besar dari elemen berikutnya.

Dalam kasus terburuk, di mana n adalah jumlah elemen dalam array, kompleksitas waktu algoritma Sort Bubble adalah O(n^2) atau kompleksitas waktu kuadrat. Namun, algoritma ini tidak cocok untuk array yang besar, tetapi mudah dipahami dan digunakan. Algoritma Sort Bubble memerlukan memori terus-menerus saat mengurutkan array karena kompleksitas ruangnya adalah O(1), yang independen dari ukuran array.

#### Full code Screenshot:
![Screenshot 2024-04-01 082600](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/2d122919-c457-47c5-a78b-c5da17077a38)

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!

```C++
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::vector<char> arr(n);
    std::cout << "Enter " << n << " characters: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());
    std::cout << "Ascending order: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::sort(arr.begin(), arr.end(), std::greater<char>());
    std::cout << "\nDescending order: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-04-01 082818](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/77b55939-cd72-46e5-a0d1-413e9b09b645)

Dalam program C++ di atas, pengguna diminta untuk memasukkan sejumlah karakter, menyimpannya dalam sebuah vektor, mengurutkan karakter-karakter tersebut dalam urutan naik dan menurun, dan mencetak hasilnya. Setelah pengguna meminta berapa banyak karakter yang akan dimasukkan, program menginisialisasi sebuah vektor dengan ukuran yang sesuai dan menyimpan karakter-karakter tersebut. Kemudian, fungsi `std::sort` digunakan untuk mengurutkan vektor dalam urutan naik dan kemudian dalam urutan menurun, menggunakan pembanding `std::greater<char>()`. Hasil pengurutan ditunjukkan di layar.

Secara keseluruhan, kompleksitas waktu dari kode tersebut adalah O(n log n) atau kompleksitas waktu logaritmik, di mana 'n' adalah jumlah karakter yang dimasukkan pengguna. Hal ini disebabkan oleh kompleksitas waktu pengurutan menggunakan `std::sort`, yang dominan dalam penentuan kompleksitas keseluruhan.

#### Full code Screenshot:
![Screenshot 2024-04-01 082913](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/5ed3eba4-a6d3-4f67-b4c2-7cf25eda959c)

## Kesimpulan
Algoritma sorting merupakan teknik untuk mengurutkan data dalam suatu urutan tertentu, seperti dari yang terkecil ke yang terbesar atau sebaliknya. Berbagai jenis algoritma sorting, seperti Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, dan Merge Sort, memiliki cara kerja yang berbeda-beda serta kelebihan dan kekurangan masing-masing. Pemilihan algoritma sorting yang tepat tergantung pada karakteristik data yang akan diurutkan dan kebutuhan aplikasi. Algoritma seperti Quick Sort dan Merge Sort cenderung lebih efisien untuk jumlah data yang besar, sementara Bubble Sort dan Selection Sort lebih cocok untuk jumlah data yang kecil atau sebagai algoritma dasar untuk keperluan pendidikan.

## Referensi
[1] Tobing, F. A. T., & Tambunan, J. R. (2020). Analisis Perbandingan Efisiensi Algoritma Brute Force dan Divide and Conquer dalam Proses Pengurutan Angka. Ultimatics: Jurnal Teknik Informatika, 12(1), 52-58.

[2] YANTI, Fitri; ERIANA, Emi Sita. Algoritma Sorting dan Searching. 2024.

[3] A. Sonita and F. Nurtaneo, “ANALISIS PERBANDINGAN ALGORITMA BUBBLE SORT, MERGE SORT, DAN QUICK SORT DALAM PROSES PENGURUTAN KOMBINASI ANGKA DAN HURUF”, pseudocode, vol. 2, no. 2, pp. 75–80, Aug. 2016.
>>>>>>> 2951b20ed3c56ac2cd54c5c4adb3495e2f841599