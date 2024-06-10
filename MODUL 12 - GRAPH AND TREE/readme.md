# <h1 align="center">Laporan Praktikum Modul GRAPH and TREE</h1>
<p align="center">Naufal Alif Anargya</p>
<p align="center">2311110041</p>

## Dasar Teori
### Graph
Graf adalah suatu himpunan tidak kosong dari simpul-simpul (Vertice atau node) dan sisi (edges
atau arcs) yang menghubungkan simpul tersebut, ditulis dengan notasiG=(V,E).Sisi pada graf
dapat mempunyai orientasi arah.Graf yang sisinya tidak mempunyai orientasi arah disebut graf
tak-berarah.Pada graf tak-berarah, urutan pasangan simpul yang dihubungkan oleh sisi tidak
diperhatikan. Jadi, (u, v) = (v,u) adalah sisi yang sama. Graf yang setiap sisinya diberikan
orientasi arah disebut graf berarah. Pada graf berarah, (u, v) dan (v,u) menyatakan dua buah sisi
yang berbeda, dengan kata lain (u, v) ≠ (v,u). Untuk sisi (u, v), simpul u dinamakan simpul asal
(unitial vertex) dan simpul v dinamakan simpul terminal (terminal vertex) [1]. 

![Screenshot 2024-06-10 054527](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/68428920-a8d3-42da-97e8-8283fce5dc6b)

Graf yang dapat digambarkan pada bidang datar dengan sisi-sisi yang tidakberpotongan disebut
graf planar.Representasi graf planar yang digambarkan dengan sisi-sisi yang tidak saling
berpotongan disebut graf bidang.Sisi-sisi pada graf bidang membagi bidang datar menjadi
beberapa wilayah (region) atau muka (face). Banyaknya wilayah pada graf bidang dapat dihitung
dengan rumus Euler yaitu n – e + f = 2, dengan n adalah banyaknya simpul, e adalah banyaknya
sisi dan f adalah banyaknya wilayah [1]. 

### Jenis Graph
1. *Graph Sederhana*
   
Graf sederhana G adalah graf yang ∀ simpul (V) ∄
sisi (E) yaitu sisi gelang dan sisi ganda.
Misalkan graf sederhana direpresentasikan
seperti pada Gambar 1 sebagai 𝐺1 (contoh penerapan
dalam bentuk jaringan telepon). Untuk simpul –
simpul 1,2,3 dan 4 berwarna biru menyatakan telepon,
sedangkan sisi – sisi berwarna hitam menyatakan
saluran telepon untuk berkomunikasi . Terlihat jelas
bahwa setiap simpul yang terhubung oleh setiap sisi
tidak memiliki sisi gelang dan sisi ganda [2].

![Screenshot 2024-06-10 055704](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/302150b2-c42e-4d4c-8180-db4428d61ff2)


2. *Graph Tidak Sederhana*
    
Graf tidak sederhana G adalah graf yang ∀ simpul
(V), ∃ sisi gelang atau sisi ganda maupun keduanya.
Dengan kata lain graf tidak sederhana G = (V, E)
terdiri dari himpunan tidak kosong simpul (V) dan sisi
(E) adalah himpunan-ganda (multiset) yang
mengandung sisi ganda atau sisi gelang maupun
keduanya. Ada dua macam graf tak sederhana, yaitu
graf ganda (multigraph) dan graf semu
(pseudograph). Graf ganda adalah graf yang
mengandung sisi ganda. Sedangkan graf semu adalah
graf yang mengandung sisi gelang (loop). Misalkan
graf ganda direpresentasikan seperti pada Gambar 2
sebagai 𝐺2. Untuk sisi - sisi ganda berwarna kuning
yang menghubungkan sepasang simpul – simpul
berwarna biru antara simpul 1 dan 2, dan antara
simpul 2 dan 3 masing – masing terdapat sisi ganda.
Sisi ganda jumlahnya dapat lebih dari dua buah dan
dapat diasosiasikan sebagai pasangan tak-terurut yang
sama [2].

![Screenshot 2024-06-10 055742](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/46cafa05-79c5-4078-8922-1410a292b32f)


3. *Graph Tidak Berarah*
    
Graf tidak berarah G adalah graf yang sisinya sama
dimana (u, v) = (v, u).
Dengan kata lain sisinya tidak mempunyai
orientasi arah dan urutan pasangan simpul yang
dihubungkan oleh sisi tidak diperhatikan . Misalkan
tiga buah graf direpresentasikan seperti pada Gambar
1, Gambar 2 dan Gambar 3 sebagai contoh graf takberarah. Untuk 𝐺1, 𝐺2,𝐺3 dapat dikatakan sebagai graf
tidak berarah karena setiap sisi yang terhubung antara
setiap simpul (u, v) = (v, u) adalah sisi yang sama [2].


4. *Graph Berarah*
   
Graf berarah G adalah graf yang sisinya tidak sama
dan diberi arah dimana (u, v) ≠ (v, u).
Misalkan graf berarah direpresentasikan seperti
pada Gambar 4. Untuk sisi(E) berwarna merah
diberikan orientasi arah disebut juga busur (arc)
dimana (u, v) dan (v, u) adalah dua buah unsur yang
berbeda dan untuk simpul u dinamakan simpul asal
(initial vertex) dan simpul v dinamakan simpul
terminal (terminal vertex). Pada Gambar 4 dimisalkan
simpul u = 1 dan simpul v = 3 , maka (u, v) = (1, 3)
sebagai sisi yang arahnya ke simpul 3 dan (v, u) = (3, 1)
sebagai sisi yang arahnya ke simpul 1. Oleh karena itu,
graf pada Gambar 4 disebut sebagai graf yang berarah
dimana (1, 3)≠(3, 1). Graf berarah penerapannya
sering dipakai dalam kehidupan sehari – hari untuk
menggambarkan aliran proses, peta lalu lintas suatu
kota (jalan searah atau dua arah), dan sebagainya [2].

![Screenshot 2024-06-10 055858](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/f2a17dc5-71d6-413f-a2ef-a73166a65bb3)


5. *Graph lengkap*
   
Graf lengkap G adalah graf yang ∀ simpul (V) , ∃
sisi (E) yang terhubung antara setiap dua simpul dan
dinotasikan dengan 𝐾𝑛 [2].
Untuk graf lengkap 𝐾𝑛 , dimisalkan n sebagai
jumlah simpul untuk setiap n ∈ bilangan asli 𝛮.
Misalkan graf lengkap direpresentasikan seperti pada
Gambar 5. Untuk 𝐾1 merupakan isolated vertex
dimana jumlah simpulnya = 1 atau n = 1 dan tak
memiliki sisi. Untuk 𝐾2, memiliki 1 sisi dan jumlah
simpulnya = 2 atau n = 2. Untuk 𝐾3, memiliki jumlah
simpul = 3 atau n = 3 dan sisinya = 3. Untuk 𝐾4,
memiliki jumlah simpul = 4 atau n = 4 dan sisinya = 6.
Dan untuk 𝐾5, memiliki jumlah simpul = 5 atau n = 5
dan sisinya = 10 [2].

![Screenshot 2024-06-10 055946](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/95a2ea1d-af7a-4695-b147-121d4daa1d9b)

6. *Graph Terhubung*
   
Graf terhubung G adalah graf tidak berarah G jika
∀ pasang simpul u dan v dalam himpunan V ∃ lintasan
dari u ke v dan jika tidak, maka G disebut sebagai
(disconnected graph) atau graf tidak – terhubung [2].

### Tree
Pohon didefinisikan sebagai suatu graf tak
berarah terhubungkan (connected undirected
graph) yang tidak mengandung rangkaian
sederhana. Pohon adalah bentuk khusus dari
suatu graf yang banyak diterapkan untuk
berbagai keperluan. Misalnya struktur organisasi
suatu perusahaan, silsilah suatu keluarga, skema
sistem gugur suatu pertandingan, dan ikatan
kimia suatu molekul adalah jenis graf yang
tergolong sebagai pohon. Pada pohon, simpulsimpul yang berderajat satu dinamakan daun
(leave), sedangkan simpul yang derajatnya lebih
besar daripada satu dinamakan simpul cabang
(branch node) atau simpul internal (internal
node) dan kumpulan pohon-pohon yang
terpisahkan satu sama lain disebut hutan (forest) [3].


## Guided
### 1. Program Graph

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph(){
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")"; 
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```
#### *Ouput*
![Screenshot 2024-06-10 060214](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/9ad960b4-2901-4cf2-bd97-550928a43940)

#### *Penjelasan*
Kode ini membuat representasi graf berarah menggunakan matriks bobot. Graf tersebut memiliki 7 simpul yang masing-masing merepresentasikan kota tertentu. Matriks busur digunakan untuk menyimpan jarak antar kota yang diwakili oleh simpul. Fungsi tampilGraph akan mencetak daftar semua kota (simpul) dan untuk setiap kota, mencetak kota-kota tujuan langsung beserta jaraknya. Kode ini memberikan cara visual untuk melihat hubungan dan jarak antar kota dalam bentuk graf berarah.

### 2.	Program Tree

```C++
#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    TNode (int value){
        data = value;
        left = NULL;
        right = NULL;

    }
};

void preOrder(TNode *node){
    if (node != NULL){
        cout << node->data << " ";
        preOrder (node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node){
    if (node != NULL){
        inOrder (node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node){
    if (node != NULL){
        postOrder (node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

int main (){
    TNode *zero = new TNode (0);

    TNode *one = new TNode (1);
    TNode *five = new TNode (5);
    TNode *seven = new TNode (7);
    TNode *eight = new TNode (8);
    TNode *nine = new TNode (9);

    seven -> left = one;

    seven -> right = nine;

    one -> left = zero;

    one -> right = five;

    nine -> left = eight;

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;

    return 0;
}
```
#### *Output*
![Screenshot 2024-06-10 062415](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/d8909131-3281-45f1-a5f7-4d1b51e9dbe9)

#### *Penjelasan*
Kode di atas adalah implementasi pohon biner yang mengandung beberapa simpul dengan data integer. Struktur TNode mendefinisikan simpul pohon dengan dua anak, left dan right, serta sebuah nilai data. Fungsi preOrder, inOrder, dan postOrder adalah fungsi rekursif untuk melakukan traversal pohon dalam urutan pre-order, in-order, dan post-order. Di dalam fungsi main, beberapa simpul dibuat dan dihubungkan membentuk pohon biner. Pohon ini kemudian ditelusuri menggunakan ketiga fungsi traversal tersebut, dan hasilnya ditampilkan di konsol. Traversal pre-order mengunjungi node dalam urutan 7, 1, 0, 5, 9, 8; traversal in-order mengunjungi node dalam urutan 0, 1, 5, 7, 8, 9; dan traversal post-order mengunjungi node dalam urutan 0, 5, 1, 8, 9, 7.

## Unguided
### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

int main() {
    int numSimpul;
    std::cout << "Silakan masukan jumlah simpul: ";
    std::cin >> numSimpul;

    std::vector<std::string> simpul(numSimpul);
    std::cout << "Silakan masukan nama simpul\n";
    for (int i = 0; i < numSimpul; ++i) {
        std::cout << "Simpul " << i + 1 << " : ";
        std::cin >> simpul[i];
    }

    std::vector<std::vector<int>> bobot(numSimpul, std::vector<int>(numSimpul, 0));
    std::cout << "Silakan masukkan bobot antar simpul\n";
    for (int i = 0; i < numSimpul; ++i) {
        for (int j = 0; j < numSimpul; ++j) {
            if (i != j) {
                std::cout << simpul[i] << "--> " << simpul[j] << " = ";
                std::cin >> bobot[i][j];
            }
        }
    }

    std::cout << std::setw(10) << " ";
    for (int i = 0; i < numSimpul; ++i) {
        std::cout << std::setw(10) << simpul[i];
    }
    std::cout << "\n";
    
    for (int i = 0; i < numSimpul; ++i) {
        std::cout << std::setw(10) << simpul[i];
        for (int j = 0; j < numSimpul; ++j) {
            std::cout << std::setw(10) << bobot[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}
```

#### *Output* 
![Screenshot 2024-06-10 064530](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/7cf7830e-7aa4-405a-bd75-2edd78f536d1)

#### *Penjelasan :*
Kode di atas adalah implementasi program untuk membuat dan menampilkan matriks bobot dari sebuah graf berarah berdasarkan input pengguna. Program meminta pengguna untuk memasukkan jumlah simpul, lalu nama-nama simpul tersebut. Setelah itu, pengguna diminta untuk mengisi bobot antar simpul yang menggambarkan jarak atau hubungan langsung antar simpul. 

1. *Input Jumlah Simpul*: Pengguna diminta untuk memasukkan jumlah simpul yang ada dalam graf.
2. *Input Nama Simpul*: Pengguna memasukkan nama-nama dari setiap simpul.
3. *Input Bobot Antar Simpul*: Pengguna memasukkan bobot (nilai integer) untuk setiap pasangan simpul yang menggambarkan bobot busur dari simpul satu ke simpul lainnya. Bobot antar simpul yang sama diisi dengan nilai 0.
4. *Output Matriks Bobot*: Program kemudian mencetak matriks bobot dengan nama simpul sebagai header untuk baris dan kolom, serta bobot antar simpul sesuai dengan input yang telah diberikan.

Kode menggunakan vector dari C++ Standard Library untuk menyimpan nama simpul dan matriks bobot secara dinamis, serta menggunakan setw dari iomanip untuk format keluaran yang rapi.

#### *Fullcode Screenshot*
![Screenshot 2024-06-10 065249](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/67c85c13-6092-4ca0-bb03-142a1af4c02c)

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    TNode (int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

TNode* findNode(TNode* root, int value) {
    if (root == NULL) return NULL;
    if (root->data == value) return root;
    TNode* leftResult = findNode(root->left, value);
    if (leftResult != NULL) return leftResult;
    return findNode(root->right, value);
}

void displayChildren(TNode* root, int value) {
    TNode* node = findNode(root, value);
    if (node != NULL) {
        cout << "Children of " << value << ": ";
        if (node->left != NULL) cout << node->left->data << " ";
        if (node->right != NULL) cout << node->right->data << " ";
        if (node->left == NULL && node->right == NULL) cout << "No children";
        cout << endl;
    } else {
        cout << "Node " << value << " not found." << endl;
    }
}

void displayDescendants(TNode* root, int value) {
    TNode* node = findNode(root, value);
    if (node != NULL) {
        cout << "Descendants of " << value << ": ";
        queue<TNode*> q;
        q.push(node);
        bool hasDescendants = false;
        while (!q.empty()) {
            TNode* current = q.front();
            q.pop();
            if (current != node) {
                cout << current->data << " ";
                hasDescendants = true;
            }
            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }
        if (!hasDescendants) cout << "No descendants";
        cout << endl;
    } else {
        cout << "Node " << value << " not found." << endl;
    }
}

void addNode(TNode*& root, int parentValue, int childValue, char childSide) {
    TNode* parentNode = findNode(root, parentValue);
    if (parentNode != NULL) {
        if (childSide == 'L' || childSide == 'l') {
            if (parentNode->left == NULL) {
                parentNode->left = new TNode(childValue);
            } else {
                cout << "Left child already exists for node " << parentValue << endl;
            }
        } else if (childSide == 'R' || childSide == 'r') {
            if (parentNode->right == NULL) {
                parentNode->right = new TNode(childValue);
            } else {
                cout << "Right child already exists for node " << parentValue << endl;
            }
        } else {
            cout << "Invalid child side. Use 'L' for left and 'R' for right." << endl;
        }
    } else {
        cout << "Parent node " << parentValue << " not found." << endl;
    }
}

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Add node\n";
    cout << "2. Display children of a node\n";
    cout << "3. Display descendants of a node\n";
    cout << "4. Display Pre-Order traversal\n";
    cout << "5. Display In-Order traversal\n";
    cout << "6. Display Post-Order traversal\n";
    cout << "7. Exit\n";
}

int main() {
    TNode* root = new TNode(7); // Default root node with value 7
    int choice;
    int parentValue, childValue;
    char childSide;
    int nodeValue;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter parent node value: ";
                cin >> parentValue;
                cout << "Enter child node value: ";
                cin >> childValue;
                cout << "Enter child side (L/R): ";
                cin >> childSide;
                addNode(root, parentValue, childValue, childSide);
                break;
            case 2:
                cout << "Enter node value to display children: ";
                cin >> nodeValue;
                displayChildren(root, nodeValue);
                break;
            case 3:
                cout << "Enter node value to display descendants: ";
                cin >> nodeValue;
                displayDescendants(root, nodeValue);
                break;
            case 4:
                cout << "Pre-Order traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "In-Order traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 6:
                cout << "Post-Order traversal: ";
                postOrder(root);
                cout << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
```

#### *Output :*
![Screenshot 2024-06-10 070640](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/48397c11-7ba9-404b-b7d1-3addd636c4c6)

#### *Penjelasan :*
Program di atas adalah sebuah implementasi dari struktur data binary tree dalam C++. Program ini memungkinkan pengguna untuk menambahkan node baru ke dalam pohon, menampilkan anak-anak dan keturunan dari suatu node, serta melakukan tiga jenis penelusuran: pre-order, in-order, dan post-order. Struktur data binary tree direpresentasikan dengan menggunakan struktur TNode yang memiliki data integer, pointer ke anak kiri, dan pointer ke anak kanan. Fungsi findNode digunakan untuk mencari node dengan nilai tertentu dalam pohon. Fungsi displayChildren menampilkan anak-anak dari suatu node, sementara displayDescendants menampilkan semua keturunan dari suatu node. Ada juga fungsi addNode untuk menambahkan node baru ke dalam pohon. Program utama berjalan dalam loop tak terbatas, menampilkan menu yang memungkinkan pengguna untuk memilih operasi yang diinginkan, termasuk penelusuran dan manipulasi struktur pohon.

#### *Fullcode Screenshot :*
![Screenshot 2024-06-10 070720](https://github.com/Nargya/PraktikumStrukturData/assets/161468671/f219664b-bd0e-4714-a0a0-d4b1e2aea0be)

## Kesimpulan
Graph adalah struktur data yang terdiri dari kumpulan simpul (nodes) yang terhubung oleh sisi (edges). Setiap sisi dapat memiliki arah (directed) atau tidak (undirected), dan dapat memiliki bobot atau tidak. Graph digunakan untuk merepresentasikan hubungan antar objek, seperti jaringan sosial, rute transportasi, atau hubungan antar data dalam komputer. Kelebihannya adalah kemampuannya untuk merepresentasikan hubungan yang kompleks dan fleksibilitasnya dalam modelasi berbagai masalah. Namun, kelemahannya adalah kompleksitas dalam operasi seperti penelusuran dan analisis struktur. 

Tree adalah jenis khusus dari graph yang tidak memiliki siklus (cycle), artinya tidak ada jalur kembali ke simpul yang sama dari simpul tertentu. Tree biasanya digunakan untuk representasi hierarki, seperti struktur direktori dalam sistem operasi atau struktur data dalam pemrograman. Kelebihannya adalah struktur yang mudah dipahami dan efisien dalam operasi seperti penelusuran. Kekurangannya adalah keterbatasan dalam merepresentasikan hubungan yang lebih kompleks seperti yang dapat dilakukan oleh graph umum.

Perbedaan utama antara graph dan tree adalah bahwa graph dapat memiliki siklus dan hubungan yang lebih kompleks, sedangkan tree adalah jenis khusus dari graph yang tidak memiliki siklus dan digunakan untuk representasi hierarki. Implementasi graph dan tree dalam struktur data biasanya melibatkan penggunaan struktur data seperti array, linked list, atau struktur data khusus seperti adjacency list atau adjacency matrix untuk merepresentasikan hubungan antar simpul.

## Referensi

[1] Tri Sutrisno, "APLIKASI GRAF DALAM REKAYASA PERANGKAT LUNAK", Jurnal Muara, Vol. 1, No. 1, April 2017. 

[2] Roy A. M. Makalew, Chriestie E. J. C. Montolalu, Mans. L. Mananohas, "Lintasan Hamiltonian pada Graf 4-Connected", Jurnal Matematika dan Aplikasi, Vol. 9, No. 2, September 2020.

[3] Amir Muntaha, Graf Pohon dan Implementasinya dalam beberapa persoalan, 2007
