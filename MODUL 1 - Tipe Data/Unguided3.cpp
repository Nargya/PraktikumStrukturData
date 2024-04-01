#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Mendeklarasikan map dengan key bertipe string dan value bertipe int (umur)
    map<string, int> dataMahasiswa;

    // Menambahkan data mahasiswa ke dalam map
    dataMahasiswa["Nargya"] = 18;
    dataMahasiswa["Syamil"] = 18;
    dataMahasiswa["Bob Malik"] = 18;

    // Mengakses dan mencetak data mahasiswa
    cout << "Umur mahasiswa Nargya: " << dataMahasiswa["Nargya"] << " tahun" << endl;
    cout << "Umur mahasiswa Syamil: " << dataMahasiswa["Syamil"] << " tahun" << endl;
    cout << "Umur mahasiswa Bob Malik: " << dataMahasiswa["Bob Malik"] << " tahun" << endl;

    return 0;
}
