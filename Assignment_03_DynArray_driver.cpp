//                          Assignment-3: Dynamic Arrays

#include <iostream>
#include "Data_structure/DynArray.cpp"
using namespace std;

int main()
{
    // 2.  In question 1, define a parameterised constructor to create an array of specified size.
    DynArray d(5);
    d.append(1);
    d.append(3);
    d.append(2);
    d.append(4);
    d.append(5);
    d.show_Array();

    // 3.  In question 1, define a method doubleArray() to increase the size of the array by double of its size.
    d.append(7);
    d.append(7);
    d.show_Array();

    // 4.  In question 1, define a method halfArray() to decrease the size of the array by half of its size.
    d.delete_elm(1);
    d.delete_elm(1);
    d.show_Array();

    // 5.  In question 1, define a method which returns the current capacity of the array.
    // 6.  In question 1, add a method to check whether an array is empty or not by returning True or False.
    // 7.  In question 1, define a method to append a new element in the array
    // 8.  In question 1, define a method to insert a new element at specified index
    d.insert(-3, 5);
    d.show_Array();

    // 9.  In question 1, define a method to edit an element at specified index.
    d.edit(10, 4);
    d.edit(1, 999);
    d.show_Array();

    // 10. In question 1, define a method to delete an element at specified index.
    d.delete_elm(1);
    d.show_Array();

    // 11. In question 1, define a method to check if the array is full by returning true or false.
    if (d.is_full())
        cout << "\narray is full";
    else
        cout << "\narray is not full";

    // 12. In question 1, define a method to get element at specified index.
    cout << "\n get_element(0) = " << d.get_element(0);
    cout << "\n get_element(10) = " << d.get_element(10);

    // 13. In question 1, define a method to count number of elements present in the array.
    if (d.is_empty())
        cout << "\narray is empty";
    else
        cout << "\ntotal elements in array is = " << d.total_element();

    // 15. In question 1, define a method to find an element in the array. Return index if the element found, otherwise return -1 .
    if (d.find(4) != -1)
        cout << "\n4 is found at index " << d.find(4);
    else
        cout << "\n4 is not found in the array";

    // 14. In question 1, define a destructor to deallocate the memory of array.
    return 0;
}