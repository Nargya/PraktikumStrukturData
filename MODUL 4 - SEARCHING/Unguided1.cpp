#include <iostream>
#include <algorithm> 
#include <string>

bool binarySearch(const std::string& sentence, char target) {
    return std::binary_search(sentence.begin(), sentence.end(), target);
}

int main() {
    std::string sentence;
    char target;

    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, sentence);

    std::cout << "Masukkan huruf yang ingin Anda cari: ";
    std::cin >> target;

    std::sort(sentence.begin(), sentence.end());

    bool found = binarySearch(sentence, target);

    if (found) {
        std::cout << "Huruf '" << target << "' ditemukan dalam kalimat." << std::endl;
    } else {
        std::cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << std::endl;
    }

    return 0;
}
