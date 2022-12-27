//                 Assignment-I : Array Data Structure
// 1.  Define a class Array to implement array data structure with member variables to
//     store capacity of array, last index of the last filled block of the array and a pointer to
//     hold the address of the first block of the dynamically created array.
//
// 2.  In question 1, define a parameterised constructor to create an array of specified size.
// 3.  In question 1, add a method to check whether an array is empty or not by returning True or False.
// 4.  In question 1, define a method to append a new element in the array
// 5.  In question 1, define a method to insert a new element at specified index
// 6.  In question 1, define a method to edit an element at specified index.
// 7.  In question 1, define a method to delete an element at specified index.
// 8.  In question 1, define a method to check if the array is full by returning true or false.
// 9.  In question 1, define a method to get element at specified index.
// 10. In question 1, define a method to count number of elements present in the array.
// 11. In question 1, define a destructor to deallocate the memory of array.
// 12. In question 1, define a method to find an element in the array. Return index if the element found, otherwise return -1.

#include <iostream>
#include "Array.cpp"
using namespace std;

int main()
{
    Array num(5);
    num.Is_Empty() ? cout << "\n num Array is Empty" : cout << "\n num Array is not Empty";
    num.Display();
    num.Append(1);
    num.Display();

    num.Insert(0, 3);
    num.Display();

    num.Insert(1, 2);
    num.Insert(1, 5);
    num.Insert(1, 4);
    num.Display();

    num.Insert(3, 4);
    num.Display();

    num.Edit(2, 9);
    num.Display();

    num.Delete(0);
    num.Display();

    num.Insert(2, 7);
    num.Display();
    
    num.Is_Full() ? cout << "\n num Array is Full" : cout << "\n num Array is not Full";

    cout << "\n get element of index 3 = " << num.get_element(3);

    cout << "\n Index of element 4 is " << num.find(4);
    num.Display();

    return 0;
}