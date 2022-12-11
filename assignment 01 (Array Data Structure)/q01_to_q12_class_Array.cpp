//                 Assignment-I : Array Data Structure

#include <iostream>
using namespace std;

class Array
{                                                     // 1.  Define a class Array to implement array data structure with member variables to
private:                                              //     store capacity of array, last index of the last filled block of the array and a pointer to
    int *ptr = NULL, size = 0, last_index = -1;       //     hold the address of the first block of the dynamically created array.
public:                                               //
    Array(int size);                                  // 2.  In question 1, define a parameterised constructor to create an array of specified size.
    bool Is_Empty() { return last_index == -1; }      // 3.  In question 1, add a method to check whether an array is empty or not by returning True or False.
    void Append(int element);                         // 4.  In question 1, define a method to append a new element in the array
    void Insert(int index, int element);              // 5.  In question 1, define a method to insert a new element at specified index
    void Edit(int index, int element);                // 6.  In question 1, define a method to edit an element at specified index.
    void Delete(int index);                           // 7.  In question 1, define a method to delete an element at specified index.
    bool Is_Full() { return last_index == size - 1; } // 8.  In question 1, define a method to check if the array is full by returning true or false.
    int get_element(int index) { return ptr[index]; } // 9.  In question 1, define a method to get element at specified index.
    int no_of_elements() { return last_index + 1; }   // 10. In question 1, define a method to count number of elements present in the array.
    ~Array() { delete ptr; }                          // 11. In question 1, define a destructor to deallocate the memory of array.
    int find(int element);                            // 12. In question 1, define a method to find an element in the array. Return index if the element found, otherwise return -1.
    void Display();
};

Array::Array(int size)
{
    ptr = new int(size);
    this->size = size;
}

void Array::Append(int element)
{
    if (size == last_index + 1)
        cout << "\n< Array is full > ";
    else
    {
        ptr[++last_index] = element;
    }
}

void Array::Delete(int index)
{
    if (index < 0 || index > last_index)
    {
        cout << "\n< Delete : Index out of range >";
        return;
    }
    int temp;
    for (int i = index; i <= last_index; i++)
    {
        temp = ptr[i];
        ptr[i] = ptr[i + 1];
        ptr[i + 1] = temp;
    }
    --last_index;
}

int Array::find(int element)
{
    for (int i = 0; i < size; i++)
        if (element == ptr[i])
            return i;
    return -1;
}

void Array::Edit(int index, int element)
{
    if (index < 0 || index > last_index)
        cout << "\n< Edit : Index is out of rang >";
    else
        ptr[index] = element;
}

void Array::Insert(int index, int element)
{
    if (size == last_index + 1)
        cout << "\n< Insert : Array is full > ";
    else if (index < 0 || index > last_index)
        cout << "\n< Insert : Index is out of rang > ";
    else
    {
        int temp;
        for (int i = last_index; i >= index; i--)
            ptr[i + 1] = ptr[i];
        ptr[index] = element;
        last_index++;
    }
}

void Array::Display()
{
    cout << "\n";
    for (int i = 0; i <= last_index; i++)
        cout << " " << ptr[i];
}

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