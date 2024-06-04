# <h1 align="center">Laporan Praktikum Modul HASH TABLE</h1>
<p align="center">Naufal Alif Anargya</p>
<p align="center">2311110041</p>

## Dasar Teori
### Hash Table
Salah satu algoritma yang dapat dipergunakan untuk menyimpan dan mencari data dengan lebih cepat dan efisien adalah algoritma yang disebut dengan algoritma tabel hash atau hash table. Algoritma tabel hash sudah banyak dikembangkan dan dipergunakan di dalam berbagai bidang karena memiliki kelebihan dalam efisiensi waktu operasi dari pengarsipan dan pencarian suatu data. Beberapa bidang yang telah menggunakannya adalah bidang jaringan komputer, dimana tabel hash yang telah dikembangkan menjadi tabel hash terbuka hibrida atau hybrid open hash table digunakan untuk memproses jaringan komputer, dan banyak digunakan pada sistem jaringan ad hoc yang bergerak (mobile ad hoc networks). Selain itu tabel hash yang dikembangkan menjadi tabel hash terdistribusi atau distributed hash table dapat diimplementasikan untuk mencari dan menemukan berbagai macam web service di Internet. 

Tabel hash adalah sebuah cara untuk menyimpan suatu data pada memori ke dalam baris-baris dan kolom-kolom sehingga membentuk tabel yang dapat diakses dengan cepat. Setiap sel yang merupakan pertemuan antara baris dan kolom di dalam tabel hash dimana data diarsipkan disebut dengan slot. Sebuah tabel hash dapat dibuat dari dua bagian, yaitu sebuah larik atau array dan sebuah fungsi untuk memetakan, yang disebut dengan fungsi hash atau hash function. Fungsi hash adalah pemetaan ke dalam larik sesuai dengan kunci-kunci yang diberikan, dengan kata lain fungsi hash mendistribusikan data yang dimasukkan oleh pengguna ke dalam tabel atau larik yang telah disediakan. Salah satu cara untuk menentukan kunci tabel hash adalah dengan menggunakan sistem modulus (sisa dari pembagian dua buah bilangan) dari nilai integer pada data. Misalnya akan dibuat sebuah tabel hash yang akan memetakan huruf-huruf abjad dari A-Z, maka dapat dibuat sebuah kunci yang akan mengambil nilai ASCII dari huruf yang diinputkan, kemudian dibuat sebuah sistem modulus dari 6.[1]

Proses Hash terdiri dari dua langkah yaitu: 

- *Menghitung fungsi Hash.*  
Fungsi Hash adalah suatu fungsi yang mengubah key
menjadi alamat dalam tabel dengan memetakan key tersebut ke alamat dalam tabel.
Secara teori, key-key yang berbeda haruslah dipetakan ke alamat-alamat yang
berbeda pula. Namun kenyataannya ada kemungkinan dua atau lebih key yang
dipetakan ke alamat yang sama dalam tabel. Peristiwa ini disebut dengan tabrakan
(collision).
- *Resolusi terhadap tabrakan (collision resolution).*  
Resolusi terhadap tabrakan merupakan proses untuk menangani kejadian dua atau lebih key yang dipetakan ke alamat yang sama pada tabel. Caranya yaitu dengan mencari lokasi yang kosong dalam tabel Hash secara terurut. Atau bisa juga dengan menggunakan fungsi Hash yang lain untuk mencari lokasi yang kosong.[2]

### Teknik-teknik Hash Table
1. *Hashing*
Hashing merupakan sebuah metode yang
digunakan untuk mentransformasi suatu string
menjadi karakter yang nilainya merepresentasikan
string aslinya dengan operasi aritmatika. Dari segi
Bahasa, hashing berasal dari kata hash yang berarti
memenggal lalu menggabungkan. Dalam
penggunaannya, metode hashing dapat digunakan
sebagai metode penyimapanan data dalam sebuah
larik (array) agar penyimpanan, pencarian,
penambahan, dan penghapusan data dapat dilakukan
dengan cepat. [3]

*Contoh :*
```C++
#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    static const int hashGroups = 10; 
    list<pair<int, string>> table[hashGroups]; 

public:
    bool isEmpty() const; 
    int hashFunction(int key); 
    void insertItem(int key, string value); 
    void removeItem(int key); 
    void searchItem(int key);
    void displayTable(); 
};

bool HashTable::isEmpty() const {
    int sum = 0;
    for (int i = 0; i < hashGroups; i++) {
        sum += table[i].size();
    }
    if (!sum) {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups; 
}

void HashTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING] Kunci telah ada. Nilai diperbarui." << endl;
            break;
        }
    }
    if (!keyExists) {
        cell.emplace_back(key, value);
    }
    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "[INFO] Pasangan kunci-nilai dihapus." << endl;
            break;
        }
    }
    if (!keyExists) {
        cout << "[WARNING] Kunci tidak ditemukan. Tidak ada yang dihapus." << endl;
    }
    return;
}

void HashTable::searchItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            cout << "[INFO] Nilai yang sesuai dengan kunci " << key << ": " << bItr->second << endl;
            break;
        }
    }
    if (!keyExists) {
        cout << "[WARNING] Kunci tidak ditemukan." << endl;
    }
    return;
}

void HashTable::displayTable() {
    for (int i = 0; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;
        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            cout << "[INFO] Kunci: " << bItr->first << " Nilai: " << bItr->second << endl;
        }
    }
    return;
}

int main() {
    HashTable hash;
    hash.insertItem(905, "Adam");
    hash.insertItem(201, "John");
    hash.insertItem(332, "Daniel");
    hash.insertItem(124, "Mary");
    hash.insertItem(678, "Bob");
    hash.insertItem(510, "Jane");
    hash.insertItem(570, "Doe");
    hash.displayTable();

    hash.removeItem(201);
    hash.displayTable();

    hash.searchItem(510);
    hash.searchItem(999);

    if (hash.isEmpty()) {
        cout << "[INFO] Tabel hash kosong." << endl;
    } else {
        cout << "[INFO] Tabel hash tidak kosong." << endl;
    }
    return 0;
}
```
   

2. *LINEAR PROBING*
Linear probing merupakan skema dalam pemrograman komputer untuk menyelesaikan collision pada hash table. Dalam skema ini, setiap sel dari hash table menyimpan satu pasangan kunci-nilai. Saat fungsi hash menyebabkan collision dengan memetakan kunci baru ke sel hash table yang sudah ditempati oleh kunci lain, maka linear probing akan mencari tabel untuk lokasi bebas terdekat dan menyisipkan kunci baru. 

Pencarian dilakukan dengan cara yang sama, yaitu dengan mencari tabel secara berurutan, mulai dari posisi yang diberikan oleh fungsi hash, hingga menemukan sel dengan kunci yang cocok atau sel kosong. Hash table adalah struktur data non trivial yang paling umum digunakan. Linear probing dapat memberikan kinerja tinggi karena lokasi referensi yang baik, namun lebih sensitif terhadap kualitas fungsi hash daripada beberapa skema resolusi collision lainnya.

*Contoh* 
```C++
#include <iostream>
#include <string>
using namespace std;

class HashTable {
private:
    static const int hashGroups = 10;
    pair<int, string> *table[hashGroups];
    int currentSize;

public:
    HashTable() {
        currentSize = 0;
        for (int i = 0; i < hashGroups; i++) {
            table[i] = nullptr;
        }
    }

    int hashFunction(int key) {
        return key % hashGroups;
    }

    void insertItem(int key, string value) {
        int index = hashFunction(key);
        while (table[index] != nullptr && table[index]->first != key) {
            index = (index + 1) % hashGroups;
        }
        if (table[index] != nullptr) {
            delete table[index];
        }
        table[index] = new pair<int, string>(key, value);
        currentSize++;
    }

    string searchItem(int key) {
        int index = hashFunction(key);
        while (table[index] != nullptr && table[index]->first != key) {
            index = (index + 1) % hashGroups;
        }
        if (table[index] != nullptr && table[index]->first == key) {
            return table[index]->second;
        }
        return "Key not found";
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        while (table[index] != nullptr) {
            if (table[index]->first == key) {
                delete table[index];
                table[index] = nullptr;
                break;
            }
            index = (index + 1) % hashGroups;
        }
        currentSize--;
    }

    void displayTable() {
        for (int i = 0; i < hashGroups; i++) {
            if (table[i] != nullptr) {
                cout << "Index " << i << ": " << table[i]->first << " " << table[i]->second << endl;
            } else {
                cout << "Index " << i << ": NULL" << endl;
            }
        }
    }

    ~HashTable() {
        for (int i = 0; i < hashGroups; i++) {
            if (table[i] != nullptr) {
                delete table[i];
            }
        }
    }
};

int main() {
    HashTable hash;
    hash.insertItem(905, "Adam");
    hash.insertItem(201, "John");
    hash.insertItem(332, "Daniel");
    hash.insertItem(124, "Mary");
    hash.insertItem(678, "Bob");
    hash.insertItem(510, "Jane");
    hash.insertItem(570, "Doe");
    hash.displayTable();

    hash.deleteItem(201);
    cout << endl << "After deleting key 201:" << endl;
    hash.displayTable();

    cout << endl << "Search key 510: " << hash.searchItem(510) << endl;
    cout << "Search key 999: " << hash.searchItem(999) << endl;

    return 0;
}
```


## Guided
### 1. Guided 1
```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
        }
    }
    delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
   
    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}
```

#### *Ouput*
![Screenshot 2024-06-04 030956](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/3bbc9c61-ee42-44a8-a661-419d9c1f5340)

#### *Penjelasan*
Code tersebut adalah implementasi sederhana dari hash table menggunakan teknik chaining untuk menangani tabrakan. Dalam struktur data hash table ini, setiap elemen tabel direpresentasikan oleh pointer ke linked list. Fungsi hash digunakan untuk menghitung indeks dalam tabel berdasarkan kunci yang diberikan. Jika terjadi tabrakan, yaitu dua kunci menghasilkan indeks yang sama, data baru akan dimasukkan ke linked list yang sudah ada pada indeks tersebut. Setiap node dalam linked list memiliki dua atribut, yaitu kunci (key) dan nilai (value). Code ini memiliki fungsi untuk menyisipkan data baru (insert), mencari data berdasarkan kunci (get), menghapus data berdasarkan kunci (remove), dan menampilkan seluruh data dalam hash table (traverse).

### 2.	Guided 2
```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;
class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
    return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);
       
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name) {
    int hash_val = hashFunc(name);
    for (auto node : table[hash_val]) {
        if (node->name == name) {
            return node->phone_number;
        }
    }
    return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
                for (auto pair : table[i]) {
                if(pair != nullptr){
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
HashMap employee_map;

employee_map.insert("Mistah", "1234");
employee_map.insert("Pastah", "5678");
employee_map.insert("Ghana", "91011");

cout << "Nomer Hp Mistah : " <<employee_map.searchByName("Mistah") << endl;
cout << "Phone Hp Pastah : " <<employee_map.searchByName("Pastah") << endl;

employee_map.remove("Mistah");

cout << "Nomer Hp Mistah setelah dihapus : " <<employee_map.searchByName("Mistah") << endl << endl;

cout << "Hash Table : " << endl;

employee_map.print();

return 0;
}
```

#### *Output*
![Screenshot 2024-06-04 031403](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/98948403-dab7-44c3-a8d7-5643208c0ea0)

#### *Penjelasan*
Code di atas adalah implementasi hash map sederhana dalam bahasa C++ menggunakan teknik chaining untuk menangani tabrakan. Dalam code tersebut, terdapat dua kelas utama yaitu HashNode dan HashMap. Kelas HashNode merepresentasikan node dalam hash map yang menyimpan informasi nama dan nomor telepon. Kelas HashMap adalah kelas yang mengatur penyimpanan dan manipulasi data dalam hash map.
Kelas HashMap memiliki atribut berupa sebuah array dari vektor, yang masing-masing vektor berisi pointer ke objek-objek HashNode. Metode hashFunc digunakan untuk menghasilkan nilai hash dari sebuah kunci, yaitu nama dalam kasus ini. Metode insert digunakan untuk menyisipkan pasangan nama dan nomor telepon ke dalam hash map. Jika terjadi tabrakan, data akan disimpan dalam vektor yang sudah ada pada indeks yang sesuai dalam array. Metode remove digunakan untuk menghapus data berdasarkan nama. Metode searchByName digunakan untuk mencari nomor telepon berdasarkan nama. Metode print digunakan untuk mencetak seluruh isi hash map.
Dalam main function, objek employee_map dari kelas HashMap dibuat dan diisi dengan beberapa data. Kemudian, data dicari dan dihapus, dan isi dari hash map dicetak untuk dilihat.

## Unguided
### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai.

```C++
#include <iostream>
#include <vector>
using namespace std;

// Struktur data untuk setiap mahasiswa
struct Mahasiswa {
    int NIM;
    int nilai;
    Mahasiswa(int NIM, int nilai) : NIM(NIM), nilai(nilai) {}
};

// Struktur data untuk setiap node dalam hash table
struct HashNode {
    Mahasiswa* mahasiswa;
    HashNode* next;

    HashNode(Mahasiswa* mahasiswa) : mahasiswa(mahasiswa), next(nullptr) {}
};

// Class hash table
class HashTable {
public:
    static const int TABLE_SIZE = 10;
    vector<HashNode*> table[TABLE_SIZE];

    // Fungsi hash untuk menghasilkan indeks berdasarkan NIM
    int hashFunc(int NIM) {
        return NIM % TABLE_SIZE;
    }

    // Menambahkan data mahasiswa ke dalam hash table
    void tambahMahasiswa(int NIM, int nilai) {
        Mahasiswa* mahasiswaBaru = new Mahasiswa(NIM, nilai);
        int index = hashFunc(NIM);
        HashNode* nodeBaru = new HashNode(mahasiswaBaru);
        nodeBaru->next = table[index].empty() ? nullptr : table[index].front();
        table[index].push_back(nodeBaru);
    }

    // Menghapus data mahasiswa dari hash table berdasarkan NIM
    void hapusMahasiswa(int NIM) {
        int index = hashFunc(NIM);
        HashNode* current = table[index].front();
        HashNode* prev = nullptr;
        while (current != nullptr && current->mahasiswa->NIM != NIM) {
            prev = current;
            current = current->next;
        }
        if (current != nullptr) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                table[index].front() = current->next;
            }
            delete current->mahasiswa;
            delete current;
        }
    }

    // Mencari data mahasiswa berdasarkan NIM
    Mahasiswa* cariMahasiswaNIM(int NIM) {
        int index = hashFunc(NIM);
        HashNode* current = table[index].front();
        while (current != nullptr) {
            if (current->mahasiswa->NIM == NIM) {
                return current->mahasiswa;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Menampilkan list NIM mahasiswa beserta nilainya
    void tampilkanListMahasiswa() {
        cout << "List NIM Mahasiswa beserta Nilainya:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            HashNode* current = table[i].front();
            while (current != nullptr) {
                cout << "NIM: " << current->mahasiswa->NIM << ", Nilai: " << current->mahasiswa->nilai << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable hashTable;
    int choice;
    int NIM, nilai;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah data mahasiswa\n";
        cout << "2. Hapus data mahasiswa\n";
        cout << "3. Cari data mahasiswa berdasarkan NIM\n";
        cout << "4. Cari data mahasiswa berdasarkan rentang nilai (80 - 90)\n";
        cout << "5. Tampilkan list NIM mahasiswa beserta nilainya\n";
        cout << "6. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan NIM mahasiswa: ";
                cin >> NIM;
                cout << "Masukkan nilai mahasiswa: ";
                cin >> nilai;
                hashTable.tambahMahasiswa(NIM, nilai);
                break;
            case 2:
                cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
                cin >> NIM;
                hashTable.hapusMahasiswa(NIM);
                break;
            case 3:
                cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
                cin >> NIM;
                {
                    Mahasiswa* mhs = hashTable.cariMahasiswaNIM(NIM);
                    if (mhs != nullptr) {
                        cout << "Mahasiswa ditemukan.\n";
                        cout << "NIM: " << mhs->NIM << ", Nilai: " << mhs->nilai << endl;
                    } else {
                        cout << "Mahasiswa tidak ditemukan.\n";
                    }
                }
                break;
            case 4:
                cout << "Mahasiswa dengan nilai antara 80 - 90:\n";
                {
                    bool found = false;
                    for (int i = 0; i < HashTable::TABLE_SIZE; ++i) {
                        for (HashNode* current : hashTable.table[i]) {
                            if (current->mahasiswa->nilai >= 80 && current->mahasiswa->nilai <= 90) {
                                cout << "NIM: " << current->mahasiswa->NIM << ", Nilai: " << current->mahasiswa->nilai << endl;
                                found = true;
                            }
                        }
                    }
                    if (!found) {
                        cout << "Tidak ada mahasiswa dengan nilai antara 80 - 90.\n";
                    }
                }
                break;
            case 5:
                hashTable.tampilkanListMahasiswa();
                break;
            case 6:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
```

#### *Output* 
![Screenshot 2024-06-04 040454](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/227cf922-12ea-4e0b-954a-4f2115bf16e8)

#### *Penjelasan :*
Kode di atas adalah implementasi dari sebuah program yang menggunakan hash table untuk menyimpan informasi mahasiswa berdasarkan NIM dan nilai mereka. Dalam program ini, digunakan beberapa struktur data kunci seperti Mahasiswa untuk menyimpan data individu mahasiswa, serta HashNode untuk merepresentasikan setiap node dalam hash table. Kelas HashTable adalah inti dari program, yang mengatur logika untuk menambah, menghapus, mencari, dan menampilkan data mahasiswa. Ini menggunakan teknik chaining untuk menangani tabrakan yang mungkin terjadi saat beberapa kunci di-hash ke dalam bucket yang sama. Fungsi utama (main) mengelola antarmuka pengguna, memungkinkan pengguna untuk memilih berbagai operasi seperti menambah, menghapus, mencari, atau menampilkan data mahasiswa. Program ini dirancang untuk memberikan pengguna kontrol penuh atas data mahasiswa, dengan antarmuka yang sederhana dan intuitif.

#### *Fullcode Screenshot*
![Screenshot 2024-06-04 040400](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/9ba1700c-4bce-4f93-bfc4-1fb041a91dd1)

## Kesimpulan
Hash table adalah struktur data yang digunakan untuk menyimpan data dalam bentuk pasangan kunci-nilai, di mana kunci tersebut di-hash menggunakan fungsi hash untuk menentukan lokasi penyimpanannya di dalam tabel. Terdapat beberapa jenis hash table, di antaranya: hash table terbuka (open addressing), hash table tertutup (closed hashing), dan hash table dengan chaining. Teknik penggunaan hash table melibatkan proses hash, dimana kunci diubah menjadi indeks melalui fungsi hash, dan kemudian nilai disimpan atau diambil dari lokasi yang sesuai dalam tabel. Hash table digunakan untuk menyediakan pencarian, penyisipan, dan penghapusan data yang cepat dengan kompleksitas waktu rata-rata O(1). Kelebihan dari hash table termasuk kemampuan pencarian dan penyisipan yang cepat, bahkan dengan jumlah data besar, serta kemampuan adaptasi terhadap ukuran data yang bervariasi. Namun, kekurangan hash table dapat muncul dalam kasus tabrakan, di mana dua kunci yang berbeda menghasilkan nilai hash yang sama, memerlukan penanganan khusus seperti teknik chaining atau probing untuk menangani kasus-kasus ini dan mempertahankan kinerja yang optimal.

## Referensi

[1] Jasson Prestiliano, "*Aplikasi Tabel Hash dalam Pengarsipan dan Pencarian Data*", Jurnal Teknologi Informasi-Aiti, Vol. 4, No. 1, Februari 2007. 

[2] Viska Mutiawani, "*HASHTABLE SEBAGAI ALTERNATIF DARI ALGORITMA PENCARIAN BINER PADA APLIKASI E-ACESIA*", JURNAL INFORMATIKA, Vol. 8, No. 2, Juli 2014.

[3] Izhar Rahim, Nizirwan Anwar, Agung Mulyo Widodo, Kundang Karsono Juman, Iwan Setiawan, "*Komparasi Fungsi Hash Md5 Dan Sha256 Dalam Keamanan Gambar Dan Teks*", Jurnal IKRAITH-INFORMATIKA, Vol. 7, No. 2, Juli 2023.
