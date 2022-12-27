// 1.  Define a function to sort elements of the array.
// 2.  Define a function to find the greatest element in the array
// 3.  Define a function to find the smallest element in the array
// 4.  Define a function to search an element in the array
// 5.  Define a function to calculate sum of all the elements of an array.
// 6.  Define a function to calculate average of all the elements of an array.
// 7.  Define a function to rotate an array towards right by one position
// 8.  Define a function to remove duplicate elements in the array.
// 9.  Define a function to find the second largest element in the array.
// 10. Define a function to swap elements with specified indices in the array.

#include <iostream>
#include "Array_Mode.cpp"
using namespace std;

int main()
{
    Array_Mode Arr(5);
    Arr.Append(5);
    Arr.Append(4);
    Arr.Append(3);
    Arr.Append(2);
    Arr.Append(1);
    Arr.Display();

    Arr.sort();
    Arr.Display();

    cout << "\nGretest element in Array is  = " << Arr.gretest_elm();
    cout << "\nSmallest element in Array is = " << Arr.smallest_elm();

    cout << "\n3 is avilable at index " << Arr.search(3);
    cout << "\n9 is avilable at index " << Arr.search(9);

    cout << "\nsum of all elements is = " << Arr.sum();

    cout << "\naverage of array       = " << Arr.average();

    Arr.rotate_right();
    cout << "\nArray after rotate ";
    Arr.Display();

    Arr.Edit(1, 3);
    Arr.Edit(4, 5);
    Arr.Display();

    cout << "\nArray after remove duplicates ";
    Arr.remove_duplicates();
    Arr.Display();

    Arr.Append(1);
    Arr.Append(0);
    Arr.Display();
    cout << "\nsecond largest element is = " << Arr.second_largest();

    cout << "swap 2, 4";
    Arr.swap(3,4);
    Arr.Display();
    cout << "<end>";
    return 0;
}