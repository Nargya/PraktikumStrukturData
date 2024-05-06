# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Naufal Alif Anargya</p>
<p align="center">2311110041</p>

## Dasar Teori
### 1. Stack

Stack adalah struktur data yang mengakses data secara LIFO (yang terakhir datang, yang awal diproses).Stack merupakan turunan dari Vector, sehingga seluruh operasi dari vector dapat digunakan di Stack. Stack digunakan untuk kasus yang memerlukan pemrosesan data dari data terakhir. Kasus yang umum menggunakan stack adalah pembuatan proses undo/redo pada program [1]. Sedangkan queue bersifat FIFO
(First In First Out) dengan cara kerja yang 16 berbanding terbalik dengan stack. Kedua struktur data tersebut dapat disajikan dalam array dan linked list. Khusus untuk stack,penyajian dalam bentuk array masih kurang tepat. Array bisa digunakan kalau elemen stack tidak melebihi batas maksimum. Tipe data yang bisa digunakan adalah record. Adapun operasi-operasi/fungsi yang dapat dilakukan pada stack adalah sebagai berikut :
1) Push : digunakan untuk menambah item
pada stack pada tumpukan paling atas
2) Pop : digunakan untuk mengambil item
pada stack pada tumpukan paling atas
3) Clear : digunakan untuk mengosongkan
stack
4) IsEmpty : fungsi yang digunakan untuk
mengecek apakah stack sudah kosong
5) IsFull : fungsi yang digunakan untuk
mengecek apakah stack sudah penuh [2]. 

Berikut adalah contoh kode deklarasi untuk fungsi stack : 
```C++
#include <iostream>
#include <stack> 

int main() {
    std::stack<int> myStack; 
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    myStack.pop();
    int topElement = myStack.top(); 
    int stackSize = myStack.size(); 
    bool isEmpty = myStack.empty(); 

    std::cout << "Elemen teratas stack: " << topElement << std::endl;
    std::cout << "Ukuran stack: " << stackSize << std::endl;
    std::cout << "Apakah stack kosong? " << (isEmpty ? "Ya" : "Tidak") << std::endl;

    return 0;
}

```

## Pendeklarasian Stack
Proses pendeklarasian stack adalah proses pembuatan struktur stack dalam memori. Karena stack dapat direpresentasikan dalam 2 cara, maka pendeklarasian stack pun ada 2 yaitu :
### a. Deklarasi menggunakan array

```C++
#include <iostream>

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE]; 
    int top; 

public:
    Stack() {
        top = -1; 
    }

    void push(int element) {
        if (top >= MAX_SIZE - 1) { 
            std::cout << "Stack overflow! Tidak bisa menambahkan elemen." << std::endl;
            return;
        }
        arr[++top] = element; 
        std::cout << "Elemen " << element << " ditambahkan ke dalam stack." << std::endl;
    }

    int pop() {
        if (isEmpty()) { 
            std::cout << "Stack underflow! Stack kosong." << std::endl;
            return -1; 
        }
        int poppedElement = arr[top--]; 
        return poppedElement; 
    }

    bool isEmpty() {
        return top == -1; 
    }
};

int main() {
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Elemen yang dihapus dari stack: " << myStack.pop() << std::endl;
    std::cout << "Elemen yang dihapus dari stack: " << myStack.pop() << std::endl;

    return 0;
}

```

Suatu stack memiliki beberapa bagian yaitu: 
- top yang menunjuk posisi data terakhir (top)
- elemen yang berisi data yang ada dalam stack. Bagian ini lah yang berbentuk
array.
- maks_elemen yaitu variable yang menunjuk maksimal banyaknya elemen
dalam stack. 

### b. Deklarasi menggunakan Linked List
Adapun stack yang menggunakan single linked list, hanya memerlukan suatu pointer yang menunjuk ke data terakhir (perhatikan proses di halaman sebelumnya). Setiap elemen linked list mempunyai 2 field yaitu elemen datanya dan pointer bawah yang menunjuk posisi terakhir sebelum proses push. [3]

```C++
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top; 
public:
    Stack() {
        top = nullptr; 
    }

    void push(int value) {
        Node* newNode = new Node(value); 
        if (isEmpty()) {
            top = newNode; 
        } else {
            newNode->next = top; 
            top = newNode; 
        }
        std::cout << "Elemen " << value << " ditambahkan ke dalam stack." << std::endl;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow! Stack kosong." << std::endl;
            return -1; 
        }
        int poppedValue = top->data; 
        Node* temp = top; 
        top = top->next; 
        delete temp; 
        return poppedValue; 
    }

    bool isEmpty() {
        return top == nullptr; 
    }
};

int main() {
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Elemen yang dihapus dari stack: " << myStack.pop() << std::endl;
    std::cout << "Elemen yang dihapus dari stack: " << myStack.pop() << std::endl;

    return 0;
}

```

## Guided 

### 1. Sourcecode (Membuat stack menggunakan elemen array)

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty(){
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else{
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku(){
    if(isEmpty()){
        cout << "Tidak ada data yang dihapus" << endl;
    }else{
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku (int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else{
        int index = top; 
        for (int i = 1; i <= posisi; i ++){
            index--;
        }
        cout << "Posisi ke " << posisi << "adalah" << arrayBuku[index] << endl; 
    }
}

int countStack(){
    return top;
}
void changeArrayBuku (int posisi, string data){
    if (posisi > top){
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++){
            index--;
        }
        arrayBuku[index] = data;
    }
}
void destroyArraybuku() {
    for (int i = top; i >= 0; i--){
        arrayBuku[i] = "";
    }
    top = 0;
}
void cetakArraybuku () {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--){
            cout << arrayBuku[i] << endl;
        }
    }
}
int main(){
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArraybuku();
    cout << "\n";

    cout << "Apakah data stack penuh?" << isFull() << endl;
    cout <<"Apakah data stack kosong?" << isEmpty () << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya Data =" << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArraybuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus:" << top << endl;

    cetakArraybuku();
    return 0;
}

```
Kode di atas merupakan implementasi sederhana dari stack menggunakan array dalam bahasa C++. Ini menyediakan fungsi-fungsi dasar untuk operasi yang biasa dilakukan pada stack, seperti menambahkan elemen (push), menghapus elemen (pop), melihat elemen teratas (peek), menghitung jumlah elemen dalam stack, mengubah data pada posisi tertentu, dan menghapus semua data dalam stack.

## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
#include <iostream>
#include <stack>
#include <string>
#include <locale>

std::string cleanAndLowercase(std::string str) {
    std::string cleanedStr;
    std::locale loc;

    for (char c : str) {
        if (std::isalpha(c, loc)) { 
            cleanedStr += std::tolower(c, loc); 
        }
    }

    return cleanedStr;
}

bool isPalindrome(std::string str) {
    std::stack<char> charStack;

    str = cleanAndLowercase(str);
    int length = str.length();
    int halfLength = length / 2;
    for (int i = 0; i < halfLength; ++i) {
        charStack.push(str[i]);
    }

    int i = (length % 2 == 0) ? halfLength : halfLength + 1;
    while (i < length) {
        if (str[i] != charStack.top()) {
            return false; 
        }
        charStack.pop();
        ++i;
    }

    return true; 
}

int main() {
    std::string input;
    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "Kalimat tersebut adalah palindrom." << std::endl;
    } else {
        std::cout << "Kalimat tersebut bukan palindrom." << std::endl;
    }

    return 0;
}

```
#### Output:
![Screenshot 2024-05-06 022339](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/90aa18f3-cbf7-4dab-a259-6701ccfaf0a8)

Program tersebut merupakan program C++ untuk menentukan apakah sebuah kalimat yang dimasukkan pengguna merupakan palindrom atau tidak. Pertama, program membersihkan kalimat dari karakter non-alfabet dan mengubahnya menjadi huruf kecil. Kemudian, program membagi kalimat menjadi dua bagian dan memasukkan bagian pertama ke dalam stack. Setelah itu, program membandingkan setiap karakter dalam bagian kedua dengan karakter-karakter yang dikeluarkan dari stack. Jika semua karakter cocok, maka kalimat tersebut adalah palindrom. Jika tidak, maka kalimat tersebut bukan palindrom.

#### Full code Screenshot:
![Screenshot 2024-05-06 022442](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/329335e2-08a8-490d-941a-9d7e4cb47a5b)

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

```C++
#include <iostream>
using namespace std;

int main() {
    string input, output = " ";

    cout << "Masukkan kalimat : ";
    getline(cin, input);

    for(int i = input.length() - 1; i >= 0; i--){
        output = output + input[i];
    }

    cout << "Kalimat sebelum dibalik : " << input << endl;
    cout << "Kalimat setelah dibalik : " << output << endl;   
}

```
#### Output:
![Screenshot 2024-05-06 030020](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/9c57460a-b498-4bb5-aa53-9755722a1315)

Code diatas adalah code untuk melakukan pembalikan kalimat dengan menggunakan loop `for` yang dimana pengguna diminta untuk memasukkan kalimat yang akan dioperasikan (dibalik). Contoh output yang dapat terjadi adalah apabila kita ingin memasukkan kalimat seperti "aku suka apel" maka code tersebut akan membaliknya menjadi "lepa akus uka". 
Berikut adalah source code dan operasi/fungsi yang dibuat:

- Input Kalimat: Pengguna diminta untuk memasukkan sebuah kalimat menggunakan getline(cin, input).
- Pembalikan Kalimat: Program menggunakan loop `for` untuk membalikkan kalimat. Dimulai dari karakter terakhir hingga karakter pertama, setiap karakter dari kalimat dimasukkan ke dalam string output. Ini dilakukan dengan mengakses karakter dalam string input menggunakan indeks i yang diturunkan dari panjang kalimat.
- Output: Setelah pembalikan selesai, program mencetak kalimat asli (input) dan kalimat yang sudah dibalik (output).

Dan ini adalah operasi atau fungsi yang terdapat pada program : 
- `getline(cin,input)` : kita menggunakan ini karena jika menggunakan `cin` biasa maka hanya kata depan saja yang akan dibalik karena `cin` menganggap bahwa spasi atau space sebagai enter.


#### Full code Screenshot:
![Screenshot 2024-05-06 030054](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/faa86466-4d5e-49fe-a51e-ac9c231aa1a1)

## Kesimpulan
Stack dapat digunakan dalam berbagai konteks, seperti pemrograman, komputasi, dan algoritma. Stack dapat diimplementasikan menggunakan array atau linked list, masing-masing dengan kelebihan dan kekurangannya. Namun, stack adalah struktur data yang sederhana yang sangat berguna untuk memproses data secara terstruktur sesuai dengan aturan LIFO. Stack memiliki banyak keuntungan, salah satunya adalah strukturnya yang sederhana, yang memungkinkan operasi dasar seperti push, pop, dan peek dilakukan dengan cepat dan efisien. Selain itu, penggunaan stack sangat berguna dan efisien dalam beberapa algoritma, seperti rekursi dan evaluasi ekspresi matematika.

Namun, kekurangan stack adalah kapasitasnya yang terbatas (pada stack berbasis array) dan tidak efisien dalam penggunaan memori jika tidak digunakan dengan baik (pada stack berbasis link list). Selain itu, dalam beberapa situasi, penggunaan stack juga dapat menyebabkan overflow stack jika terjadi rekursi yang terlalu dalam atau alokasi memori yang berlebihan.

## Referensi
[1] R. Selamet, "IMPLEMENTASI STRUKTUR DATA LIST, QUEUE DAN STACK DALAM JAVA", Media Informatika, vol. 15, no. 3, hal. 22-24, 2016.

[2] J. Sihombing, "PENERAPAN STACK DAN QUEUE PADA ARRAY DAN LINKED LIST DALAM JAVA", hal.18, Februari 2020.

[3] Mr. QWERTY, "STACK(TUMPUKAN)", Repository Unikom, 8 Mei 2007, [Online]. Tersedia : 
https://repository.unikom.ac.id/35662/1/STACK.pdf