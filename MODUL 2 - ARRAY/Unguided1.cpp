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