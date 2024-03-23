#include <iostream>
using namespace std;

int main()
{
    int jml_index, maks, min, total = 0, nilai;
    double rata_rata;
    
    cout << "Panjang Array = ";
    cin >> jml_index;
    
    for (int a = 1; a <= jml_index; a++)
    {
        cout << "Array ke-" << a << " = ";
        cin >> nilai;
        
        total += nilai; // Menambahkan nilai ke total
        
        if (a == 1)
        {
            min = nilai;
            maks = nilai;
        }
        else 
        {
            if (nilai > maks)
            {
                maks = nilai;
            }
            if (nilai < min)
            {
                min = nilai;
            }
        }
    }
    
    rata_rata = static_cast<double>(total) / jml_index; // Menghitung rata-rata
    
    cout << "Nilai Maksimal = " << maks << endl;
    cout << "Nilai Minimal = " << min << endl;
    cout << "Rata-rata = " << rata_rata << endl;
}
