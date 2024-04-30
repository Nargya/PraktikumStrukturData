# <h1 align="center">Laporan Praktikum Modul Linked list</h1>
<p align="center">Naufal Alif Anargya</p>
<p align="center">2311110041</p>

## Dasar Teori
### 1. Linked List

Linked list berguna untuk dipelajari karena dua alasan. Yang paling jelas, linked list adalah struktur data yang mungkin ingin Anda gunakan dalam program nyata. Melihat kekuatan dan kelemahan dari linked list akan memberikan Anda apresiasi terhadap beberapa masalah waktu, ruang, dan kode yang berguna untuk memikirkan struktur data secara umum. Agak kurang jelas, linked list adalah cara yang bagus untuk belajar tentang pointer. Pada kenyataannya, Anda mungkin tidak akan pernah menggunakan linked list dalam program nyata, tetapi Anda pasti akan menggunakan banyak pointer. Masalah linked list merupakan kombinasi yang bagus dari algoritma dan manipulasi pointer. +-Secara tradisional, linked list telah menjadi domain di mana para pemrogram pemula mendapatkan latihan untuk benar-benar memahami pointer.[1]

#### Linked list circular

Linked list circular adalah jenis linked list di mana simpul terakhir dari daftar menunjuk kembali ke simpul pertama, membentuk sebuah lingkaran atau perulangan. Karakteristik ini membedakannya dari daftar taut tradisional, di mana simpul terakhir biasanya menunjuk ke null, yang menunjukkan akhir daftar. Dalam daftar berantai melingkar, tidak ada penunjuk nol di bagian akhir; sebaliknya, simpul terakhir menunjuk kembali ke simpul pertama, menciptakan struktur perulangan. Perilaku perulangan ini memungkinkan penelusuran terus menerus melalui daftar.[2]
C++
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};

// Fungsi untuk mencetak linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Membuat linked list sebagai contoh
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    std::cout << "Linked List awal: ";
    printList(head);

    // Memanggil fungsi deleteDuplicates
    Solution solution;
    ListNode* newHead = solution.deleteDuplicates(head);

    std::cout << "Linked List setelah menghapus duplikat: ";
    printList(newHead);

    // Menghapus linked list untuk mencegah kebocoran memori
    ListNode* current = newHead;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}



#### Linked list non-circular

Linked list satu arah, atau yang juga dikenal sebagai singly linked list, adalah jenis linked list di mana setiap node hanya memiliki satu pointer yang menunjuk ke node berikutnya dalam urutan linear. Node terakhir dalam linked list memiliki pointer yang menunjuk ke null, menandakan akhir dari linked list. Dalam singly linked list, traversal atau perjalanan hanya bisa dilakukan dari head hingga tail, dan tidak bisa mundur ke node sebelumnya. Operasi dasar seperti penambahan dan penghapusan elemen biasanya lebih efisien dalam singly linked list.[3]

C++
#include <iostream>

// Definisi simpul (node) dalam linked list
struct ListNode {
    int val; // Nilai dari simpul
    ListNode *next; // Pointer ke simpul selanjutnya
    ListNode(int x) : val(x), next(nullptr) {} // Konstruktor untuk inisialisasi nilai dan pointer
};

// Kelas untuk merepresentasikan linked list
class LinkedList {
private:
    ListNode *head; // Pointer ke simpul pertama (head)

public:
    // Konstruktor untuk inisialisasi linked list
    LinkedList() : head(nullptr) {}

    // Fungsi untuk menambahkan simpul baru ke akhir linked list
    void append(int value) {
        // Buat simpul baru dengan nilai yang diberikan
        ListNode *newNode = new ListNode(value);

        // Jika linked list masih kosong, atur simpul baru sebagai head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Temukan simpul terakhir dalam linked list
        ListNode *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        // Tambahkan simpul baru setelah simpul terakhir
        current->next = newNode;
    }

    // Fungsi untuk mencetak seluruh isi linked list
    void printList() {
        ListNode *current = head;
        while (current != nullptr) {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destruktor untuk menghapus semua simpul dalam linked list
    ~LinkedList() {
        ListNode *current = head;
        while (current != nullptr) {
            ListNode *temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    // Membuat objek dari kelas LinkedList
    LinkedList myList;

    // Menambahkan beberapa elemen ke linked list
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);
    myList.append(5);

    // Mencetak isi linked list
    std::cout << "Linked List: ";
    myList.printList();

    return 0;
}



## Guided 

### 1. Linked list non-circular

C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    clearList();
    return 0;
}


Program tersebut adalah implementasi dari sebuah linked list non-circular dalam C++. Program ini memiliki fungsi-fungsi dasar seperti penambahan data di depan, di belakang, dan di tengah linked list, penghapusan data di depan, di belakang, dan di tengah linked list, serta pengubahan data di depan, di belakang, dan di tengah linked list. Selain itu, terdapat fungsi untuk menghitung jumlah node dalam linked list, mengecek apakah linked list kosong, serta membersihkan linked list dengan menghapus semua node. Program ini kemudian melakukan serangkaian operasi pada linked list yang dibuat, seperti menambah, menghapus, dan mengubah data, serta menampilkan isi linked list setiap kali operasi dilakukan. Akhirnya, program membersihkan linked list dan mengakhiri eksekusi.

### 2. Linked list circular

C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}



Program di atas merupakan implementasi dari sebuah doubly linked list dalam C++. Program ini memiliki kelas Node yang merepresentasikan simpul dalam linked list dan kelas DoublyLinkedList yang mengelola operasi-operasi pada linked list, seperti penambahan data di awal, penghapusan data dari awal, pengubahan data, penghapusan seluruh data, dan penampilan isi linked list. Dalam main function, program memberikan menu pilihan untuk melakukan operasi-operasi tersebut, seperti menambah data, menghapus data, mengubah data, membersihkan data, menampilkan data, dan keluar dari program. Program terus berjalan hingga pengguna memilih untuk keluar dengan memilih opsi keluar (pilihan 6).

## Unguided 

### 1. Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan  NIM mahasiswa, berikut contoh tampilan output dari nomor 1:
![Screenshot 2024-04-30 224144](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/e27c6cf3-edaa-40e3-a386-b00b6c00211c)

C++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[50];
    char nim[20];
    struct node* next;
} Node;

Node* createNode(char* name, char* nim) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->nim, nim);
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, char* name, char* nim) {
    Node* newNode = createNode(name, nim);
    newNode->next = *head;
    *head = newNode;
}

void addEnd(Node** head, char* name, char* nim) {
    Node* newNode = createNode(name, nim);
    Node* temp = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void addMiddle(Node** head, char* name, char* nim) {
    Node* newNode = createNode(name, nim);
    Node* temp = *head;
    Node* prev = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        newNode->next = prev->next;
        prev->next = newNode;
    }

    printf("Data telah ditambahkan\n");
}

void updateFront(Node** head, char* newName, char* newNim) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    strcpy((*head)->name, newName);
    strcpy((*head)->nim, newNim);
    printf("Data %s telah diganti dengan data %s\n", newName, (*head)->name);
}

void updateEnd(Node** head, char* newName, char* newNim) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    strcpy(temp->name, newName);
    strcpy(temp->nim, newNim);
    printf("Data %s telah diganti dengan data %s\n", newName, temp->name);
}

void updateMiddle(Node** head, char* newName, char* newNim, char* targetNim) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node* temp = *head;
    while (temp != NULL && strcmp(temp->nim, targetNim) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("NIM tidak ditemukan.\n");
        return;
    }

    strcpy(temp->name, newName);
    strcpy(temp->nim, newNim);
    printf("Data telah diganti untuk NIM %s\n", targetNim);
}

void deleteFront(Node** head) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    printf("Data %s berhasil dihapus\n", temp->name);
    free(temp);
}

void deleteEnd(Node** head) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node* prev = NULL;
    Node* current = *head;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }

    printf("Data %s berhasil dihapus\n", current->name);
    free(current);
}

void deleteMiddle(Node** head, char* targetNim) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node* prev = NULL;
    Node* current = *head;

    while (current != NULL && strcmp(current->nim, targetNim) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("NIM tidak ditemukan.\n");
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    printf("Data %s berhasil dihapus\n", current->name);
    free(current);
}

void freeList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("Nama: %s, NIM: %s\n", temp->name, temp->nim);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    int choice;
    char name[50], nim[20], targetNim[20];

    while (1) {
        printf("\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR\n");
        printf("1. Tambah Depan\n");
        printf("2. Tambah Belakang\n");
        printf("3. Tambah Tengah\n");
        printf("4. Ubah Depan\n");
        printf("5. Ubah Belakang\n");
        printf("6. Ubah Tengah\n");
        printf("7. Hapus Depan\n");
        printf("8. Hapus Belakang\n");
        printf("9. Hapus Tengah\n");
        printf("10. Hapus List\n");
        printf("11. TAMPILKAN\n");
        printf("0. KELUAR\n");
        printf("Pilih Operasi : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan Nama: ");
                scanf("%s", name);
                printf("Masukkan NIM: ");
                scanf("%s", nim);
                addNode(&head, name, nim);
                break;
            case 2:
                printf("Masukkan Nama: ");
                scanf("%s", name);
                printf("Masukkan NIM: ");
                scanf("%s", nim);
                addEnd(&head, name, nim);
                printf("Data telah ditambahkan\n");
                break;
            case 3:
                printf("Masukkan Nama: ");
                scanf("%s", name);
                printf("Masukkan NIM: ");
                scanf("%s", nim);
                addMiddle(&head, name, nim);
                break;
            case 4:
                printf("Masukkan Nama Baru: ");
                scanf("%s", name);
                printf("Masukkan NIM Baru: ");
                scanf("%s", nim);
                updateFront(&head, name, nim);
                break;
            case 5:
                printf("Masukkan Nama Baru: "); 
                scanf("%s", name);
                printf("Masukkan NIM Baru: ");
                scanf("%s", nim);
                updateEnd(&head, name, nim);
                break;
            case 6:
                printf("Masukkan Nama Baru: ");
                scanf("%s", name);
                printf("Masukkan NIM Baru: ");
                scanf("%s", nim);
                printf("Masukkan NIM Target: ");
                scanf("%s", targetNim);
                updateMiddle(&head, name, nim, targetNim);
                break;
            case 7:
                deleteFront(&head);
                break;
            case 8:
                deleteEnd(&head);
                break;
            case 9:
                printf("Masukkan NIM Target: ");
                scanf("%s", targetNim);
                deleteMiddle(&head, targetNim);
                break;
            case 10:
                freeList(&head);
                printf("Semua data telah dihapus.\n");
                break;
            case 11:
                displayList(head);
                break;
            case 0:
                exit(0);
            default:
                printf("Operasi tidak valid.\n");
        }
    }

    return 0;
}


#### Output:
![Screenshot 2024-04-30 224816](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/af358de6-16c3-47b8-9b1d-bf926aa8c754)

Proses di atas merupakan implementasi dari sebuah daftar link tunggal non-circular dalam bahasa C. Program ini memungkinkan berbagai operasi untuk mengelola data dalam daftar link, seperti menambah data di depan, di belakang, dan di tengah daftar, mengubah data di depan, di belakang, dan di tengah daftar, menghapus data di depan, di belakang, dan di tengah daftar, dan menampilkan isi lengkap daftar link. Pengguna melihat menu program untuk melakukan operasi tersebut. Program terus berjalan sampai pengguna memilih untuk keluar dengan memilih opsi "0".

#### Full code Screenshot:
![Screenshot 2024-04-30 225401](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/0565eb39-20b2-4370-9f9a-6ffac4c189b7)

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu  tampilkan data yang telah dimasukkan. 
![Screenshot 2024-04-30 230150](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/ed19d896-a850-4d93-bad1-62f11a99113f)

#### Output:
![Screenshot 2024-04-30 231151](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/9ef57089-d131-44a2-9646-1802ad64dfb8)

### 3. Lakukan perintah berikut: 
#### a.Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004 
![Screenshot 2024-04-30 232027](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/0b72c892-d9ef-44bb-bea6-f0ad3366a6ae)
#### b.Hapus data Denis 
![Screenshot 2024-04-30 232336](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/dc7bfb86-f561-4aa9-9a2d-e81dbd2a3307)
#### c.Tambahkan data berikut di awal: Owi 2330000 
![Screenshot 2024-04-30 232432](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/22c1a798-84a5-432e-bf6c-14dbbb1540d5)
#### d.Tambahkan data berikut di akhir: David 23300100 
![Screenshot 2024-04-30 232732](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/09a9810f-cf08-46b9-9e8c-21f0fbbb6e8d)
#### e. Ubah data Udin menjadi data berikut: Idin 23300045 
![Screenshot 2024-04-30 232847](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/063656b9-f8dc-464f-acc7-96b76bde9cc5)
#### f.Ubah data terkahir menjadi berikut: Lucy 23300101 
![Screenshot 2024-04-30 232953](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/49ca2bbb-2721-48bd-ba73-e6cf0519afec)
#### g.Hapus data awal 
![Screenshot 2024-04-30 233032](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/48cdcb7b-36cc-403c-9103-c73752789b54)
#### h.Ubah data awal menjadi berikut: Bagas 2330002 
![Screenshot 2024-04-30 233119](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/8ed06ff9-f1cb-46d4-9abe-4e3e0047e12e)
#### i.Hapus data akhir 
![Screenshot 2024-04-30 233155](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/6819b051-c5e9-46f4-ab24-51398afd52e6)
#### j.Tampilkan seluruh data
![Screenshot 2024-04-30 233412](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/0fc4db47-7d20-4b43-a3fb-b74ea832e665)

### Full Code Screenshot
![Screenshot 2024-04-30 233923](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/a51d9bd1-c27d-4d05-b816-faf530062d93)

## Kesimpulan
Untuk menyimpan dan mengelola data dalam urutan linear, daftar terkait lingkaran dan non-lingkaran digunakan. Jenis daftar terkait lingkaran memiliki pointer yang menunjuk kembali ke elemen pertama, sehingga membentuk lingkaran tertutup, sementara jenis daftar terkait tidak lingkaran memiliki pointer yang menunjuk kembali ke elemen pertama, sehingga membentuk lingkaran tertutup. Untuk aplikasi di mana data harus diakses secara berulang kali dalam siklus tertutup, seperti penjadwalan sirkular atau pengaturan buffer cincin, daftar lingkaran terhubung cocok. Sementara itu, linked list non-circular lebih sering digunakan dalam aplikasi umum di mana tidak ada kebutuhan untuk mengakses data dalam siklus tertutup, dan operasi penambahan atau penghapusan data biasanya dilakukan di ujung linked list.

## Referensi
[1] Nick Parlante. 2001, Linked List Basics, San Fransisco Bay Area: Cslibrary stanford edu.

[2] Sule-Balogun Olanrewaju Ganiu. 2024, What is a Linked list? Types of Linked List with Code Examples, Free Code Camp.

[3] Riczky Pratama. 2023, Panduan Lengkap Mengenai Linked List: Definisi, Implementasi, dan Penggunaan dalam Pemrograman, Medium.
