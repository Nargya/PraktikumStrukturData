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
