#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::vector<char> arr(n);
    std::cout << "Enter " << n << " characters: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());
    std::cout << "Ascending order: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::sort(arr.begin(), arr.end(), std::greater<char>());
    std::cout << "\nDescending order: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}