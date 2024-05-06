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
