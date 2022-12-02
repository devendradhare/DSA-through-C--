#include <iostream>
using namespace std;

// 1. Define a function to sort elements of the array.
void SortArray(int *arr, int size)
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

// 2. Define a function to find the greatest element in the array
int GreatestElement(int *arr, int size)
{
    int g = arr[0];
    for (int i = 0; i < size; i++)
        if (arr[i] > g)
            g = arr[i];
    return g;
}

// 3. Define a function to find the smallest element in the array

int SmallestElement(int *arr, int size)
{
    int sm = arr[0];
    for (int i = 0; i < size; i++)
        if (arr[i] < sm)
            sm = arr[i];
    return sm;
}
// 4. Define a function to search an element in the array

int Search(int *arr, int size, int element)
{
    int total = 0;
    cout << " Element found at ";
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            cout << " " << i;
            total++;
        }
    }
    if (total <= 0)
        cout << "nowhere";
    return total;
}

// 5. Define a function to calculate sum of all the elements of an array.

int sum(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

// 6.  Define a function to calculate average of all the elements of an array.
int average_of_arr(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum / size;
}

// 7.  Define a function to rotate an array towards right by one position
void rotate_right(int *arr, int size)
{
    int temp = arr[size - 1];
    for (int i = size - 2; i >= 0; i--)
        arr[i + 1] = arr[i];
    *arr = temp;
}
void rotate_left(int *arr, int size)
{
    int temp = arr[0];
    for (int i = 0; i < size - 1; i++)
        arr[i] = arr[i + 1];
    arr[size - 1] = temp;
}

// 8.  Define a function to remove duplicate elements in the array.
void remove_duplicates(int *arr, int &size)
{
    int s = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            if (arr[i] == arr[j])
            {
                arr[j] = 0;
                s++;
            }
        }
    }
    s--;
    SortArray(arr, size);
    for (int i = 0; i < s; i++)
        rotate_left(arr, size);
    size -= s;
}

// 9.  Define a function to find the second largest element in the array.
int second_largest_element(int *arr, int size)
{
    int b[size];
    int s = size;
    for (int i = 0; i < size; i++)
        b[i] = arr[i];
    remove_duplicates(b, s);
    return b[s];
}

// 10. Define a function to swap elements with specified indices in the array.
void swap_with_index(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int main()
{
    int size = 10;
    int arr[size] = {7, 4, 9, 10, 5, 4, 3, 4, 1, 6};

    cout << "\nArray                            = ";
    ShowArray(arr, size);

    SortArray(arr, size); //                                                          1.  Define a function to sort elements of the array.
    cout << "\nArray after sorting              = ";
    ShowArray(arr, size);

    cout << "\nGreatest Element in the array is = " << GreatestElement(arr, size); // 2.  Define a function to find the greatest element in the array
    cout << "\nSmallest Element in the array is = " << SmallestElement(arr, size); // 3.  Define a function to find the smallest element in the array

    cout << "\n search 4                        = "; //                               4.  Define a function to search an element in the array
    Search(arr, 10, 4);
    cout << "\n search 2                        = ";
    Search(arr, 10, 2);

    cout << "\n sum of the array is             = " << sum(arr, size);            // 5.  Define a function to calculate sum of all the elements of an array.
    cout << "\n average of the array is         = " << average_of_arr(arr, size); // 6.  Define a function to calculate average of all the elements of an array.

    rotate_right(arr, size); //                                                      7.  Define a function to rotate an array towards right by one position
    cout << "\n array after rotate right        = ";
    ShowArray(arr, size);

    remove_duplicates(arr, size); //                                                 8.  Define a function to remove duplicate elements in the array.
    cout << "\n array after remove duplicates   = ";
    ShowArray(arr, size);

    cout << "\n second largest element in array = " << second_largest_element(arr, size); // 9.  Define a function to find the second largest element in the array.

    swap_with_index(arr, 3, 4); //                                                  10. Define a function to swap elements with specified indices in the array.
    cout << "\n after swaping index 3 and 4     = ";
    ShowArray(arr, size);
    return 0;
}
