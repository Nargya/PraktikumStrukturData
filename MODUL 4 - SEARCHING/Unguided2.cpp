#include <iostream>
#include <string>
#include <cctype>

int countVowels(std::string str) {
    int count = 0;
    for (char c : str) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    std::string input;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    int vowelCount = countVowels(input);

    std::cout << "Number of vowels in the sentence: " << vowelCount << ".\n";

    return 0;
}