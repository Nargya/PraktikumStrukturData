# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Naufal Alif Anargya</p>
<p align="center">2311110041</p>

## Dasar Teori
### 1. Queue

Queue/antrian adalah ordered list dengan penyisipan di satu ujung, sedang penghapusan di ujung lain. Ujung penyisipan biasa disebutrear/tail, sedang ujung penghapusa disebut front/head. Fenomena yang muncul adalah elemen yang lebih dulu disisipkan akan juga lebih dulu diambil. Queue berdisiplin FIFO (First In, First Out). First-In First-Out (FIFO) adalah sebuah metode pemecahan dalam masalah antrian yang dapat diterapkan dengan cara laporan pengaduan yang pertama kali masuk diasumsikan keluar pertama kali. Hal ini sudah berjalan sesuai dengan mekanisme antrian pada umumnya, dimana antrian yang pertama kali masuk akan diselesaikan atau dilayani terlebih dahulu [1]. 
Queue merupakan kasus khusus ordered list. Dengan karakteristik terbatas itu maka kita dapat melakukan optimasi representasi ADT Queue untuk memperoleh kerja paling optimal. Misalnya Queue Q= (a1,a2,a3…,an), maka
1.Elemen a1 adalah elemen paling depan
2.Elemen ai adalah diatas elemen ai-1, di mana 1<i<n.
3.Elemen an adalah elemen paling belakang
Head (atau front) menunjuk ke awal antrian Q (atau elemen terdepan), sedangkan tail ( rear) menunjuk akhir antrian Q (atau elemen paling belakang).Disiplin FIFO pada Queue berimplikasi jika elemen A, B, C, D, E dimasukkan ke Queue, maka penghapusan/pengambilan elemen akan terjadi dengan urutan A, B, C, D, E. 
Sebuah queue dalam program setidaknya harus mengandung tiga variabel, yakni: head untuk penanda bagian depan antrian, tail untuk penanda bagian belakang antrian, dan array data untuk menyimpan data-data yang dimasukkan ke dalam queue tersebut. [2].

## 2. Karakteristik Queue

Karakteristik penting antrian sebagai berikut :
1.Elemen antrian yaitu item-item data yang terdapat di elemen antrian.
2.Head/front (elemen terdepan dari antrian ).
3.Tail/rear (elemen terakhir dari antrian ).
4.Jumlah elemen pada antrian (count).
5.Status/kondisi antrian.
Kondisi antrian yang menjadi perhatian adalah :
- Penuh
Bila elemen di antrian mencapai kapasitas maksimum antrian. Pada kondisi ini, tidak mungkin dilakukan penambahan ke antrian. Penambahan elemen menyebabkan kondisi kesalahan Overflow.
- Kosong
Bila tidak ada elemen di antrian. Pada kondisi ini, tidak mungkin dilakukan pengambilan elemen dari antrian. Pengambilan elemen menyebabkan kondisi kesalahan Underflow [2]. 

## 3.Operasi pada Queue

Pada queue ada operasi – operasi dasar, yaitu: prosedur create untuk membuat queue baru yang kosong, fungsi IsEmpty untuk mengecek queue tersebut kosong atau tidak, fungsi IsFull untuk mengecek queue tersebut penuh atau tidak, prosedur EnQueue untuk memasukkan data kedalam queue, prosedur DeQueue untuk mengeluarkan sebuah elemen pada posisi head dari queue, fungsi clear untuk menghapus elemen queue, dan prosedur tampil untuk menampilkan elemen yang ada pada queue. 

- Operasi Insertion
Menambahkan elemen data ke dalam antrian di bagian belakang disebut Memasukkan (Insertion). Berikut ini adalah Algoritma untuk Memasukkan (insertion). Untuk ini, pertimbangkan sebuah larik QUEUE[S] yang mengimplementasikan sebuah antrean dengan ukuran S. Variabel Front dan Rear melacak nilai posisi dari elemen-elemen Depan dan Belakang dari dari antrian tersebut. 

Step 1: If (REAR== -1) Then ( For checking Empty Queue)

Step 2: FRONT=REAR=0

Step 3: QUEUE[REAR]=Val

Step 4: Else If(REAR < S) Then

Step 5: REAR=REAR+1

Step 6: QUEUE[REAR]=Val

Step 7: Else

Step 8: Print “Queue Overflow”

Step 9: End of if 

- Operasi Penghapusan
Penghapusan item data dari ujung depan antrian adalah disebut operasi Penghapusan. Berikut ini adalah algoritma untuk Operasi Penghapusan. Untuk ini, pertimbangkan sebuah larik QUEUE[S] yang mengimplementasikan sebuah antrian dengan ukuran S. Variabel Front dan Belakang melacak nilai posisi dari elemen Front dan Rear elemen-elemen dari antrian [3].

Step 1: If (FRONT. -1 AND FRONT < REAR) Then (For checking Empty Queue)

Step 2 : Val=QUEUE[FRONT]

Step 3 : FRONT=FRONT+1

Step 4 : Else

Step 5 : Print “Queue Underflow”

Step 6 : End of If

Step 7: If (FRONT>REAR) Then (last element deletion checking)

Step 8: FRONT=REAR= -1

Step 9 : End of if 


### Contoh sederhana Queue

```C++
#include <iostream>
#include <queue>

using namespace std;

int main() {

  // create a queue of string
  queue<string> animals;

  // push elements into the queue
  animals.push("Cat");
  animals.push("Dog");
  
  cout << "Queue: ";

  // print elements of queue
  // loop until queue is empty
  while(!animals.empty()) {

    // print the element
    cout << animals.front() << ", ";

    // pop element from the queue
    animals.pop();
  }

  cout << endl;
 
  return 0;
}
```

Dalam contoh di atas, telah dibuat queue serangkaian string yang disebut binatang. Di sini menggunakan push() metode untuk menambahkan elemen ke akhir antrian. Daripada langsung mencetak isi antrian, maka digunakan while loop dan berbagai metode antrian. Hal ini karena antrean STL adalah Adaptor Kontainer STL yang menyediakan akses terbatas agar berperilaku seperti struktur data antrean standar. Akibatnya, tidak dapat melakukan iterasi melalui antrian seperti melakukan iterasi melalui vektor atau container lainnya.
Sebagai gantinya dicetaklah bagian depannya dan kemudian memunculkan elemen berulang kali di dalam satu lingkaran hingga antriannya kosong.

## Guided 

### 1. Source Code

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrian
int back = 0; // Penanda
string queueTeller[5]; // Fungsi pengecekan

bool isFull () {
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian (string data) {
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { 
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() {
    cout << "Data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i +1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl; 
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

Dalam code di atas, array digunakan untuk menampilkan antrian. Dalam skenario ini, "enqueueAntrian" menambahkan elemen baru ke belakang antrian dan "dequeueAntrian" menghapus elemen pertama. Meskipun demikian, metode ini memiliki beberapa kelemahan. Pertama, operasi "menghapus antrian" mengharuskan penggeseran elemen-elemen dalam array setiap kali elemen pertama dihapus. Kedua, ukuran maksimum antrian ditentukan secara statis, yang dapat menjadi batasan jika antrian perlu tumbuh atau menyusut secara dinamis. Untuk menghindari kesalahan, perhatikan juga situasi khusus seperti antrian kosong atau penuh. Struktur data seperti daftar terkait atau deque mungkin lebih sesuai karena dapat menangani perubahan ukuran antrian yang berubah dengan lebih efisien dan menghindari penggeseran elemen yang berlebihan saat menghapus.

## Unguided 

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* front = nullptr; // Front of the queue
Node* back = nullptr; // Back of the queue

bool isEmpty() {
    return front == nullptr;
}

void enqueueAntrian(string data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue() {
    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

void viewQueue() {
    cout << "Data antrian teller: " << endl;
    Node* current = front;
    int index = 1;
    while (current != nullptr) {
        cout << index << ". " << current->data << endl;
        current = current->next;
        index++;
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}
```


#### Output:
![Screenshot 2024-05-13 033215](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/49869ca4-2b31-4a4f-b308-6bb1b245e2be)

Kode di atas menjalankan struktur data antrian (queue) dengan pointer di bahasa C++. Antrian ini dapat menyimpan data dalam bentuk string dan memiliki berbagai fungsi, termasuk menambahkan data ke antrian (enqueue), menghapus data dari antrian (dequeue), menghitung jumlah data di antrian (countQueue), mengosongkan antrian (clearQueue), dan menampilkan data di antrian (viewQueue). Pada fungsi main, kode ini menguji coba antrian dengan menambahkan dua data "Andi" dan "Maya", kemudian menampilkan data di antrian, menghapus data pertama, menampilkan data lagi, mengosongkan antrian, dan menampilkan data lagi untuk memastikan bahwa antrian telah kosong. Pada code di Unguided1 ini berbeda dengan code pada Guided yang dimana salah satu perbedaan utama adalah cara elemen antrian disimpan dan diakses. Pada Guided menggunakan array statis, yang membatasi ukuran antrian dan memerlukan penggeseran elemen saat penghapusan, sehingga kinerjanya kurang optimal, terutama saat antrian besar. Sebaliknya, Unguided1 menggunakan daftar terhubung, yang memungkinkan penambahan dan penghapusan elemen dengan cepat tanpa perlu menggeser elemen lainnya, tetapi memerlukan lebih banyak memori untuk menyimpannya. Daftar yang terhubung juga memungkinkan antrian untuk berkembang atau menyusut tanpa batasan ukuran statis.

#### Full code Screenshot:
![Screenshot 2024-05-13 033315](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/967ebb40-8bdb-41be-82e8-2f7ef50dad0c)

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string NIM;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

Node* front = nullptr; // Front of the queue
Node* back = nullptr; // Back of the queue

bool isEmpty() {
    return front == nullptr;
}

void enqueueAntrian(string nama, string NIM) {
    Node* newNode = new Node;
    newNode->data.nama = nama;
    newNode->data.NIM = NIM;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue() {
    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

void viewQueue() {
    cout << "Data antrian mahasiswa: " << endl;
    Node* current = front;
    int index = 1;
    while (current != nullptr) {
        cout << index << ". Nama: " << current->data.nama << ", NIM: " << current->data.NIM << endl;
        current = current->next;
        index++;
    }
}

int main() {
    enqueueAntrian("Andi", "666666");
    enqueueAntrian("Maya", "777777");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}
```


#### Output:
![Screenshot 2024-05-13 033411](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/2a0f9a8b-9c82-4c40-a678-ac2ad298ebde)

Struktur antrian yang digunakan dalam kode ini menggunakan list linked C++. Setiap elemen dalam antrian diwakili oleh node yang berisi data siswa (nama dan NIM), bersama dengan pointer ke node berikutnya. Fungsi seperti "enqueueAntrian", "dequeueAntrian", "countQueue", "clearQueue", "viewQueue" dan "enqueueAntrian" menambahkan elemen baru ke belakang antrian, "dequeueAntrian" menghapus elemen pertama, dan "viewQueue" menampilkan data dari setiap elemen antrian. Untuk menambah, menghapus, membersihkan, dan menampilkan antrian beserta jumlah elemennya, beberapa operasi antrian dapat dilakukan pada function "main".

#### Full code Screenshot:
![Screenshot 2024-05-13 033457](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/85c11297-fc6c-4be5-933c-2c6d57c10ecf)

## Kesimpulan

Antrian, juga dikenal sebagai queue, adalah struktur data yang mengatur elemennya berdasarkan prinsip "First In, First Out" (FIFO), di mana elemen yang pertama dimasukkan akan menjadi yang pertama dihapus. Queue berbeda dengan struktur data lain seperti stack dalam cara elemen dapat diakses dan dihapus: pada queue, elemen pertama yang dimasukkan yang dihapus. Dalam situasi di mana urutan masuk sangat penting, seperti manajemen pesan antar proses, penjadwalan tugas, atau antrian pelanggan, antrinya biasanya digunakan. Konsepnya sederhana dan dapat digunakan dengan array atau linked list. Namun, kelemahannya termasuk kinerja yang kurang optimal (terutama ketika menggunakan array), pemborosan memori jika ukuran maksimum antrian sudah ditentukan, dan overhead memori tambahan pada linked list.

## Referensi
[1] N. Adlaimi, "SRUKTUR DATA MAJEMUK", Queue, hal. 20, Maret 2019. 

[2] R. Gunawan, H.Yuana, dan S.Kirom, "JATI (Jurnal Mahasiswa Teknik Informatika), IMPLEMENTASI METODE QUEUE PADA SISTEM ANTRIAN ONLINE
BERBASIS WEB STUDI KASUS UPTD PUSKESMAS SANANWETAN, vol. 7, no. 3, Juni 2023. 

[3] R.Maliyekkel S, Anila M, "International Research Journal of Engineering and Technology (IRJET)", Comparison of Stack and Queue Data structures, vol. 06, no. 06, Juni 2019
