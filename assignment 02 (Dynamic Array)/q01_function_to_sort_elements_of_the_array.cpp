// 1. Define a function to sort elements of the array.
#include <iostream>
using namespace std;

void Sort(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void ShowArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];
}
int main()
{
    int size = 10;
    int arr[size] = {7, 8, 9, 10, 5, 4, 3, 2, 1, 6};
    cout << "\nArray                = ";
    ShowArray(arr, size);

    Sort(arr, size);
    cout << "\nArray after sorting  = ";
    ShowArray(arr, size);
    return 0;
}