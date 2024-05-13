#include <iostream>
#include <stack>
#include <string>
#include <locale>

std::string cleanAndLowercase(std::string str) {
    std::string cleanedStr;
    std::locale loc;

    for (char c : str) {
        if (std::isalpha(c, loc)) { 
            cleanedStr += std::tolower(c, loc); 
        }
    }

    return cleanedStr;
}

bool isPalindrome(std::string str) {
    std::stack<char> charStack;

    str = cleanAndLowercase(str);
    int length = str.length();
    int halfLength = length / 2;
    for (int i = 0; i < halfLength; ++i) {
        charStack.push(str[i]);
    }

    int i = (length % 2 == 0) ? halfLength : halfLength + 1;
    while (i < length) {
        if (str[i] != charStack.top()) {
            return false; 
        }
        charStack.pop();
        ++i;
    }

    return true; 
}

int main() {
    std::string input;
    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "Kalimat tersebut adalah palindrom." << std::endl;
    } else {
        std::cout << "Kalimat tersebut bukan palindrom." << std::endl;
    }

    return 0;
}