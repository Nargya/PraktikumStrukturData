# <h1 align="center">Laporan Praktikum Modul PRIORITY QUEUE DAN HEAPS</h1>
<p align="center">Naufal Alif Anargya</p>
<p align="center">2311110041</p>

## Dasar Teori
### Priority Queue
Priority queue adalah bentuk suatu struktur data yang berbasiskan struktur queue. Pada dasarnya priority queue memiliki tiga jenis prioritas yaitu tinggi, sedang, dan rendah. Priority queue umumnya diikuti dengan beberapa set instruksi, seperti insert dan delete, serta mencari nilai maksimum atau minimum. Algoritma ini dapat dijalankan secara parelel untuk mencapai kecepatan waktu eksekusi yang tinggi dari sebuah struktur data. Algoritma priority queue bekerja berdasarkan prinsip Higher Priority In First Out (HPIFO) dimana pekerjaan yang memiliki prioritas tertinggi akan diselesaikan lebih dulu. Terdapat dua jenis algoritma priority queue, yaitu:
- Ascending Priority Queue, dimana data diurutkan dengan prioritas naik
- Descending Priority Queue, dimana data diurutkan dengan prioritas menurun
Selain itu terdapat dua operasi dasat yang digunakan untuk mengubah data pada algoritma priority queue, yaitu :
- Enqueue, yaitu proses menambahkan data ke akhir urutan data.
- Dequeue, yaitu proses menghapus data pada awal urutan data [1].

**Contoh program priority queue sederhana** :
```C++
#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout << "Elemen-elemen dari priority queue: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop(); 
    }
    cout << endl;

    return 0;
}
```

**Penjelasan :**  
Program tersebut merupakan contoh penggunaan priority_queue. Pertama, kita membuat objek priority_queue yang menyimpan bilangan bulat. Kemudian, kita menambahkan beberapa elemen ke dalam priority queue menggunakan fungsi push(). Setelah itu, kita mencetak elemen-elemen dari priority queue dengan menggunakan fungsi top() untuk mendapatkan elemen dengan prioritas tertinggi dan pop() untuk menghapus elemen tersebut. Hasil cetakan menunjukkan elemen-elemen yang terurut secara menurun berdasarkan prioritas, di mana elemen dengan nilai tertinggi muncul terlebih dahulu.

## Heaps
HeapSort adalah struktur data yang berbentuk pohon yang memenuhi sifat-sifat heap yaitu jika B adalah anak dari A, maka nilai yang tersimpan di simpul A lebih besar atau sama dengan nilai yang tersimpan di simpul B. Hal ini mengakibatkan elemen dengan nilai terbesar selalu berada pada posisi akar, dan heap ini disebut max heap (bila perbandingannya diterbalikkan, yaitu elemen terkecilnya selalu berada di simpul akar, heap ini disebut adalah min heap). Karena itulah, heap biasa dipakai untuk mengimplementasikan priority queue.
Operasi-operasi yang digunakan untuk heap adalah :
1. Delete-max atau delete-min: menghapus simpul akar dari sebuah max- atau minheap.
2. Increase-key atau decrease-key : mengubah nilai yang tersimpan di suatu simpul.
3. Insert: menambahkan sebuah nilai ke dalam heap.
4. Merge: menggabungkan dua heap untuk membentuk sebuah heap baru yang berisi semua elemen pembentuk heap tersebut [2].

Karakteristik dari algoritma pengurutan heap sort
adalah bahwa dalam implementasinya heap sort
menggunakan heap tree agar dapat diselesaikan
secara heap sort. Oleh karena itu, untuk
mengimplementasikan algoritma pengurutan heap
sort dalam suatu program aplikasi, dibutuhkan
adanya alokasi dinamis dengan menggunakan
struktur data tree (pohon).

Heapsort hampir setara dengan quick sort,
algoritma pengurutan data lain berdasarkan
perbandingan yang sangat efisien.
Quick sort sedikit lebih cepat, karena cache dan
faktor-faktor lain, tetapi pada kasus terburuk
kompleksitasnya O(n2
), yang sangat lambat untuk
data yang berukuran sangat besar. Lalu karena
heap sort memiliki Θ(N log N) maka sistem yang
memerlukan pengamanan yang ketat biasa
memakai heap sort sebagai algoritma
pengurutannya. Heap sort juga sering dibandingkan dengan merge
sort, yang mempunyai kompleksitas algoritma
yang sama, tetapi kompleksitas ruang nya Ω(n)
yang lebih besar dari heap sort. Heap sort juga
lebih cepat pada mesin dengan cache data yang
kecil atau lambat [3].

## Jenis-jenis heap 
- Binary heap  
Binary heap adalah heap yang dibuat dengan menggunakan pohon biner. 

- Binomial heap  
Binomial heap adalah heap yang dibuat dengan menggunakan pohon binomial. Pohon binomial bila didefinisikan secara rekursif adalah:
  1. Sebuah pohon binomial dengan tinggi 0 adalah simpul tunggal
  2. Sebuah pohon binomial dengan tinggi k mempunyai sebuah simpul akar yang anak-anaknya adalah akar-akar pohonpohon binomial dengan tinggi k-1,k2,…,2,1,0. 

- Fibonacci Heap  
Fibonacci heap adalah kumpulan pohon yang membentuk minimum heap. Pohon dalam struktur data ini tidak memiliki bentuk yang tertentu dan pada kasus yang ekstrim heap ini memiliki semua elemen dalam pohon yang berbeda atau sebuah pohon tunggal dengan tinggi n. Keunggulan dari Fibonacci heap adalah ketika menggabungkan heap cukup dengan menggabungkan dua list pohon [3]. 

**Contoh program :**
```C++
#include <iostream>
#include <algorithm>

using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array sebelum diurutkan: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n);

    cout << "Array setelah diurutkan: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
```

**Penjelasan :**  
Program tersebut merupakan implementasi algoritma Heap Sort. Algoritma ini menggunakan struktur data heap (tumpukan) untuk mengurutkan array secara menaik. Fungsi heapify() digunakan untuk membangun tumpukan maksimum, di mana setiap elemen di posisi i akan ditukar dengan salah satu anaknya yang lebih besar jika ada, untuk menjaga sifat tumpukan maksimum. Fungsi buildHeap() digunakan untuk membuat tumpukan maksimum dari array, sementara heapSort() melakukan ekstraksi elemen terbesar dari tumpukan maksimum secara berulang dan memperbaiki sisa array yang belum diurutkan dengan heapify(). Program kemudian mencetak array sebelum diurutkan, mengurutkan array menggunakan algoritma Heap Sort, dan mencetak array setelah diurutkan.

## Guided 

```C++
#include  <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i- 1) /2;
}

int leftChild(int i) {
    return ((2 * 1) + 1);
}

int rightChild(int i) {
return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }

int r = rightChild(i);
if (r <= heapSize && H[r] > H[maxIndex]) {
    maxIndex = r;
}

if (i != maxIndex) {
    std::swap(H[i], H[maxIndex]);
    shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}
int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "Node with maximum priority : " << extractMax() << "\n";
    
    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    
    std::cout << "\n";
    
    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    
    std::cout << "\n";
    remove(3);
    
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```

### Output : 
![Screenshot 2024-05-20 140410](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/18726965-9f19-4d4b-b9cc-abf70b9e1c25)

**Penjelasan :**  
Code tersebut merupakan implementasi struktur data priority queue menggunakan tumpukan maksimum (max-heap). Program ini mendefinisikan operasi-operasi dasar seperti insert, extractMax, changePriority, dan remove untuk menambahkan elemen ke dalam priority queue, menghapus elemen dengan prioritas tertinggi, mengubah prioritas elemen, dan menghapus elemen tertentu. Fungsi shiftUp dan shiftDown digunakan untuk memastikan bahwa sifat tumpukan maksimum terjaga saat operasi-insert dan operasi-remove dilakukan. Program menguji implementasi ini dengan menambahkan beberapa elemen ke dalam priority queue, mengekstrak elemen dengan prioritas tertinggi, mengubah prioritas sebuah elemen, dan menghapus sebuah elemen. Hasil operasi-operasi tersebut kemudian dicetak untuk memverifikasi keberhasilan dari implementasi priority queue.

### Full Code screenshot : 
![Screenshot 2024-05-20 140515](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/71bba474-58c2-4cd3-8480-95bb57afbb71)

## Unguided 
1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user
```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }

    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }

    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n;
    std::cout << "Masukkan jumlah elemen: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int p;
        std::cout << "Masukkan elemen ke-" << i+1 << ": ";
        std::cin >> p;
        insert(p);
    }

    std::cout << "Antrian Prioritas: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "Node dengan prioritas tertinggi: " << extractMax() << "\n";
    
    std::cout << "Antrian prioritas setelah mengambil elemen tertinggi: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    
    std::cout << "\n";
    
    int index, prioritas;
    std::cout << "Masukkan indeks dan prioritas baru: ";
    std::cin >> index >> prioritas;
    changePriority(index, prioritas);
    std::cout << "Antrian prioritas setelah perubahan prioritas : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    
    std::cout << "\n";
    
    std::cout << "Masukkan indeks elemen yang ingin dihapus: ";
    std::cin >> index;
    remove(index);
    
    std::cout << "Antrian prioritas setelah menghapus elemen: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```

### Output :
![Screenshot 2024-05-20 140023](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/a169f21e-7596-4455-a196-c284be222384)

**Penjelasan :**  
Kode tersebut melaksanakan struktur data antrian prioritas (priority queue) dengan tumpukan maksimum (max-heap). Memasukkan banyak elemen ke dalam antrian prioritas dan kemudian melakukan hal-hal seperti mengambil elemen dengan prioritas tertinggi, mengubah prioritas suatu elemen, dan menghapus elemen tertentu dari antrian prioritas dengan aplikasi ini. Fungsi seperti "insert", "extractMax", "changePriority", dan "remove" melakukan semua operasi. Fungsi-fungsi ini menggunakan sifat tumpukan maksimum untuk menjaga urutan prioritas yang tepat. Sebelum dan setelah setiap operasi, program mencetak antrian prioritas untuk memastikan bahwa operasi tersebut berhasil.

### Full code screenshot :
![Screenshot 2024-05-20 140209](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/20aa6da7-0f8a-488f-a52e-21600834097a)

## Referensi 
[1] Mohammad Iqbal Nurhadi, Randy Erfa Saputra S.T., M.T., Casi Serianingsih S.T., M.T.,"MANAJEMEN DAN KENDALI BEBAN PERANGKAT ELEKTRONIK
BERBASIS WEB DENGAN ALGORITMA PRIORITY QUEUE", e-Proceeding of Engineering, vol.5, no.2, April 2021.

[2] Fenisa Lourence Tobing, Fenina Adline Twince Tobing, Jimmy Peranginangin, "Implementasi Algoritma Heapsort dalam Game Pembelajaran Algoritma Sorting", Jurnal Widya, vol.3, no.2, Oktober 2022.

[3] Firdi Mulia, "Penerapan Pohon Dalam Heap Sort", Jurnal Teknik Informatika ITB, 2009.
