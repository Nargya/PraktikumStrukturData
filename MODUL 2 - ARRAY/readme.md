# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Naufal Alif Anargya</p>
<p align="center">2311110041</p>

## Dasar Teori

Array adalah suatu struktur yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama. Elemen-elemen array tersusun secara sekuensial dalam memori komputer. Semua elemem array bertipe sama. Array cocok untuk organisasi kumpulan data homogen yang ukuran atau jumlah elemen maksimumnya telah diketahui dari awal. Homogen adalah bahwa setiap elemen dari sebuah array tertentu haruslah mempunyai tipe data yang sama. [1]

#### 1.Array Satu Dimensi
Array 1 (satu) dimensi, array yang terdiri dari satu baris dan banyak kolom atau satu kolom dan banyak baris. Elemen array diproses secara beruntun melalui indeks terurut, asalkan indeks tersebut sudah terdefinisikan. Elemen array tersebut diproses mulai dari elemen pertama sampai elemen terakhir atau sebaliknya secara berurutan. Cara pendeklarasian array 1 dimensi mirip dengan cara pendeklarasian variabel dengan tipe data tertentu. Hanya terdapat penambahan tanda kurung siku (“[“ dan “]”) untuk
menunjukan jumlah maksimum data yang dapat ditampung oleh variabel array tersebut. [2] 

Contoh: 
```C++
#include <iostream>
using namespace std;

int main(){
    int number[] = {12,34,56,33,56,78,45};
    cout << number[3];
}
```

#### 2. Array Dua Dimensi 
Array dua dimensi atau yang sering dikenal dengan istilah  matriks  merupakan  Pengembangan  dari Array  satu dimensi, jika pada array satu dimensi hanya terdiri dari satu baris  dan  beberapa  kolom  saja,  maka  untuk  array  duavdimensi  ini  terdiri  lebih  dari  satu  (beberapa)  baris  dan kolom.   Dengan   demikian   array   dua   dimensi   tersusun dalam   bentuk   kolom   serta   baris,   yang   mana   indeks pertamanya dinyatakan  sebagai  baris  dan  untuk  indeks keduanya dinyatakan sebagai kolom.[3]

Contoh: 
```C++
#include <iostream>
using namespace std;

int main()
{
    //Deklarasi
    int a[5][2] = {{10,2},{20,3},{30,4},{40,5},{50,2}};

    for(int i = 0; i<5;i++){
        for(int j=0;j<2;j++){
            cout << "a[" << i << "][" << j << "] = " << a[i][j] << endl;
        }
    }
}
```

#### 3. Array Multidimensi
Suatu array yang fungsinya hampir sama dengan array satu
dimensi hanya saja pada array multi dimensi ini mewakili nilai table yang terdiri dari informasi yang diatur dalam ba ris dan kolom. Untuk mendefenisikan elemen table tertentu, kita harus menentukan dua indeks, pertama mengidentifikasi elemen baris dan yang mengidentifikasi elemen kolom. Array multidimensi memiliki lebih dari dua dimensi. [4]

Contoh:
```C++
#include <iostream>

int main() {
    // membuat array 2D (dua dimensi)
    int array_2D[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // menampilkan isi array 2D
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << array_2D[i][j] << " ";
        }
        cout << endl;
    }

    // membuat array 3D (tiga dimensi)
    int array_3D[2][3][4] = {
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        },
        {
            {13, 14, 15, 16},
            {17, 18, 19, 20},
            {21, 22, 23, 24}
        }
    };

    // menampilkan isi array 3D
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                cout << array_3D[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```

## Guided 

### 1. [Program Input Array Tiga Dimensi]

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    //Deklarasi Array
    int arr[2][3][3];
    // Input Elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```

Output:

![Screenshot 2024-03-23 000204](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/dafb9de4-d7cb-4478-987e-c980abf8ec82)

Kode diatas adalah kode untuk mengimplementasikan penggunaan array tiga dimensi dengan menginputkan dahulu nilai ke dalam array lalu menampilkannya.

### 2. [Program Mencari Nilai Maksimal Pada Array]

```C++
#include <iostream>
using namespace std;
int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i=0; i<a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array [i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```

Output: 

![Screenshot 2024-03-23 014001](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/833d69d5-835f-4dc0-a03e-6527ea34adc9)

Kode diatas adalah program untuk menampilkan nilai maksimum dari array dengan cara menginputkan nilai lalu program akan menampilkannya beserta letak dari nilai tersebut.

## Unguided 

### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!]

![Screenshot 2024-03-23 024508](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/bedbe3b9-b4f2-48d7-bee5-1c1d8e518e74)

```C++
#include <iostream>
using namespace std;

int main() {
    int array[10];
    cout << "Data Array: ";
    for (int i = 0; i < 10; i++) {
        cin >> array[i];
    }
    cout << "\nAngka Genap: ";
    for (int i = 0; i < 10; i++) {
        if (array[i] % 2 == 0) {
            cout << array[i] << " ";
        }
    }
    cout << "\nAngka Ganjil: ";
    for (int i = 0; i < 10; i++) {
        if (array[i] % 2 != 0) {
            cout << array[i] << " ";
        }
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-03-23 051429](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/6d37c863-1994-4fb4-9ec9-421ddf8032dd)

Kode di atas digunakan untuk mengelompokkan angka genap dan angka ganjil dengan menginputkan dulu nilai array nya. Program di atas meminta user untuk memasukkan 10 angka yang kemudian akan dikelompokkan antara angka genap dan ganjil. Kode yang digunakan untuk menghitung apakah angka tersebut genap atau ganjil adalah : 

- Genap : ``` if (array[i] % 2 == 0)``` maksud dari baris kode tersebut adalah apakah bilangan yang diinput hasilnya habis dibagi dua = 0, jika ya maka angka tersebut genap.
- Ganjil : ``` if (array[i] % 2 != 0)``` maksud dari baris kode tersebut adalah apabila bilangan yang diinput hasilnya tidak habis dibagi 2 alias tidak = 0, maka angka tersebut ganjil.


#### Full code Screenshot:
![Screenshot 2024-03-23 051320](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/302f3112-79df-49c3-b634-29986a97d7e6)


### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!]

```C++
#include <iostream>
using namespace std;

int main() {
    int x_size, y_size, z_size;
    
    cout << "Masukkan ukuran array tiga dimensi:" << endl;
    cout << "Ukuran dimensi x: ";
    cin >> x_size;
    cout << "Ukuran dimensi y: ";
    cin >> y_size;
    cout << "Ukuran dimensi z: ";
    cin >> z_size;

    int arr[x_size][y_size][z_size];

    cout << "Masukkan elemen-elemen array:" << endl;
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
    }

    // Output Array
    cout << "Elemen-elemen array:" << endl;
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }

    // Tampilan Array
    cout << "Tampilan Array:" << endl;
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-03-23 063201](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/21841509-34e5-472a-8ac7-94fbaaffab6b)

Kode di atas digunakan untuk memasukkan ukuran dari sebuah array tiga dimensi yang kemudian akan ditampilkan lagi. Jadi user akan diminta untuk memasukkan ukuran array pada setiap dimensi yaitu, dimensi x,y,dan z. Untuk meminta user memasukkan ukuran array maka digunakan pesan 'cout' sebanyak tiga kali. Dengan demikian, program tersebut memberikan pengguna kemampuan untuk memasukkan dan menampilkan elemen-elemen array tiga dimensi sesuai dengan ukuran yang dimasukkan.

#### Full code Screenshot:
![Screenshot 2024-03-23 063050](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/62e6e722-9258-4208-b9c7-02d2cd0c45f4)


### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]

```C++
#include <iostream>
using namespace std;

int main()
{
    int jml_index, maks, min, total = 0, nilai;
    double rata_rata;
    
    cout << "Panjang Array = ";
    cin >> jml_index;
    
    for (int a = 1; a <= jml_index; a++)
    {
        cout << "Array ke-" << a << " = ";
        cin >> nilai;
        
        total += nilai; // Menambahkan nilai ke total
        
        if (a == 1)
        {
            min = nilai;
            maks = nilai;
        }
        else 
        {
            if (nilai > maks)
            {
                maks = nilai;
            }
            if (nilai < min)
            {
                min = nilai;
            }
        }
    }
    
    rata_rata = static_cast<double>(total) / jml_index; // Menghitung rata-rata
    
    cout << "Nilai Maksimal = " << maks << endl;
    cout << "Nilai Minimal = " << min << endl;
    cout << "Rata-rata = " << rata_rata << endl;
}
```
#### Output:
![Screenshot 2024-03-23 063927](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/e6262d71-a1e7-4687-9ca7-13e1d03f7052)

Program diatas adalah program yang memungkinkan pengguna untuk mengisi atau menginput nilai yang kemudian akan ditampilkan hasil Nilai Maksimum, Nilai Minimum, dan juga Rata-rata dari nilai yang diinput. Program diatas menggunakan variabel 'jml_index' untuk menyimpan array, 'maks' dan 'min' untuk nilai maksimum dan mininum, sedangkan 'total' untuk menyimpan jumlah total nilai, dan 'nilai' untuk menyimpan nilai yang dimasukkan pengguna pada setiap iterasi. Selain itu, ada juga variabel 'rata_rata' untuk menyimpan nilai rata-rata. Untuk melakukan perhitungan rata-rata maka program akan memasukkan semua nilai dan menghitung statistik lainnya lalu program akan menghitung rata-rata dari nilai-nilai tersebut dengan membagi total dengan jumlah elemen array (jml_index).

#### Full code Screenshot:
![Screenshot 2024-03-23 063832](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/46ab66d5-9332-4981-9677-1c039efdc0bc)

## Kesimpulan
Array adalah struktur data yang terdiri dari kumpulan elemen-elemen yang serupa yang disimpan dalam lokasi memori yang terus-menerus dan diidentifikasi oleh satu nama atau variabel. Setiap elemen dalam array memiliki indeks numerik yang memungkinkan akses yang cepat ke elemen tersebut.

Kegunaan atau fungsi dari array adalah untuk menyimpan dan mengelola kumpulan data yang serupa secara terstruktur. Dengan menggunakan array, kita dapat menyimpan banyak data dengan tipe yang sama dalam satu variabel. Hal ini membuat pengelolaan data menjadi lebih efisien karena kita dapat mengakses dan memanipulasi elemen-elemen array menggunakan indeks numerik.

## Referensi
[1] Pratama, M. A. STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++, vol.2, pp. 1, Maret 2020.

[2] Junaedi, Danang. "ARRAY 1 DIMENSI.", Vol.1, pp. VII-3.

[3] Efendi, Yasin. "Buku Ajar Pendidikan Algoritma dan Struktur Data." (2022).

[4] Sudirman, Bagus. "VB. NET UNTUK PEMULA." Penerbit Yayasan Prima Agus Teknik (2021): 35.
