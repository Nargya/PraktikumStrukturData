#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void bubbleSort(string names[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (names[j] > names[j+1])
            {
                swap(names[j], names[j+1]);
            }
        }
    }
}

int main()
{
    string names[10] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
    int n = sizeof(names)/sizeof(names[0]);
    bubbleSort(names, n);
    for(int i =0; i < n; i++)
    {
        cout << names[i] << " ";
    }
    return 0;
}