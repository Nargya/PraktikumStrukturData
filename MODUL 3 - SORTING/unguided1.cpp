#include <iostream>
#include <algorithm>
using namespace std;

void selection(double arr[], int size)
{
    for(int i =0; i< size; i++)
    {
        int maxIndex = i;
        for(int j = i+1; j < size; j++)
        {
            if(arr[maxIndex] < arr[j])
            {
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
    }
}

int main()
{
    double arr[] = {3.8, 2.9, 3.3, 4.0, 2.4};
    int size = sizeof(arr)/sizeof(arr[0]);
    selection(arr, size);
    for(int i =0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}