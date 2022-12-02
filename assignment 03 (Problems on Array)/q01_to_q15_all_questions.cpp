//                          Assignment-3: Dynamic Arrays
// 1.  Define a class DynArray to implement dynamic array data structure with member
//     variables to store capacity of array, last index of the last filled block of the array and
//     a pointer to hold the address of the first block of the dynamically created array.
// 2.  In question 1, define a parameterised constructor to create an array of specified size.
// 3.  In question 1, define a method doubleArray() to increase the size of the array by double of its size.
// 4.  In question 1, define a method halfArray() to decrease the size of the array by half of its size.
// 5.  In question 1, define a method which returns the current capacity of the array.
// 6.  In question 1, add a method to check whether an array is empty or not by returning True or False.
// 7.  In question 1, define a method to append a new element in the array
// 8.  In question 1, define a method to insert a new element at specified index
// 9.  In question 1, define a method to edit an element at specified index.
// 10. In question 1, define a method to delete an element at specified index.
// 11. In question 1, define a method to check if the array is full by returning true or false.
// 12. In question 1, define a method to get element at specified index.
// 13. In question 1, define a method to count number of elements present in the array.
// 14. In question 1, define a destructor to deallocate the memory of array.
// 15. In question 1, define a method to find an element in the array. Return index if the element found, otherwise return -1 .

#include <iostream>
using namespace std;

class DynArray
{
private:
    int capacity;
    int last_index = -1;
    int *ptr;

public:
    DynArray(int Array_size);
    void doubleArray();
    void halfArray();
    int get_capacity() { return capacity; }
    bool is_empty() { return last_index == -1; }
    void append(int);
    void insert(int, int);
    void edit(int, int);
    void delete_elm(int);
    bool is_full() { return last_index + 1 == capacity; }
    int get_element(int);
    int total_element() { return last_index + 1; }
    int find(int);

    void show_Array();
    ~DynArray()
    {
        delete[] ptr;
    }
};
DynArray::DynArray(int Array_size)
{
    ptr = new int[Array_size];
    capacity = Array_size;
}
void DynArray::doubleArray()
{
    int *newPtr = new int[capacity *= 2];
    for (int i = 0; i < capacity; i++)
        newPtr[i] = ptr[i];
    delete[] ptr;
    ptr = newPtr;
}
void DynArray::halfArray()
{
    int *newPtr = new int[capacity /= 2];
    for (int i = 0; i < capacity; i++)
        newPtr[i] = ptr[i];
    delete[] ptr;
    ptr = newPtr;
}
void DynArray::append(int element)
{
    if (last_index == capacity - 1)
        doubleArray();
    ptr[++last_index] = element;
}
void DynArray::show_Array()
{
    cout << "\n";
    for (int i = 0; i <= last_index; i++)
        cout << " " << ptr[i];
    cout << "\t\t capacity = " << capacity;
    cout << " last index = " << last_index;
}
void DynArray::insert(int index, int element)
{
    if (last_index == capacity - 1)
        doubleArray();
    if (index < 0)
    {
        cout << "\n<insert : Invalid index>";
        return;
    }
    if (index > last_index)
        append(element);
    for (int i = last_index; i >= index; i--)
        ptr[i + 1] = ptr[i];
    last_index++;
    ptr[index] = element;
}
void DynArray::edit(int index, int element)
{
    if (index > last_index || index < 0)
        cout << "\n<edit : Invalid index>";
    else
        ptr[index] = element;
}
void DynArray::delete_elm(int index)
{
    if (index < 0 || index > last_index)
    {
        cout << "\n<delete_elm : Invalid index>";
        return;
    }
    for (int i = index; i < last_index; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    last_index--;
}
int DynArray::get_element(int index)
{
    if (index < 0 || index > last_index)
    {
        cout << "\n<get element : Invalid index>";
        return 0;
    }
    return ptr[index];
}
int DynArray::find(int element)
{
    for (int i = 0; i <= last_index; i++)
        if (ptr[i] == element)
            return i;
    return -1;
}
int main()
{
    DynArray d(5);
    d.append(1);
    d.append(3);
    d.append(2);
    d.append(4);
    d.append(5);
    d.append(7);
    d.append(7);
    d.show_Array();

    d.insert(-3, 5);
    d.show_Array();

    d.edit(10, 4);
    d.show_Array();

    d.delete_elm(1);
    d.show_Array();

    cout << "\n get_element(0) = " << d.get_element(0);
    cout << "\n get_element(10) = " << d.get_element(10);

    if (d.find(4) != -1)
        cout << "\n4 is found at index " << d.find(4);
    else
        cout << "\n4 is not found in the array";

    return 0;
}