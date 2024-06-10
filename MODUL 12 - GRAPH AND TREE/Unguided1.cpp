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
