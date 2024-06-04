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
