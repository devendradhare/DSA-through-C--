#include "Array.cpp"
class Array_Mode : public Array
{
private:
public:
    Array_Mode(int s) : Array(s) {}
    void sort();              // 1.  Define a function to sort elements of the array.
    int gretest_elm();        // 2.  Define a function to find the greatest element in the array
    int smallest_elm();       // 3.  Define a function to find the smallest element in the array
    int search(int);          // 4.  Define a function to search an element in the array
    int sum();                // 5.  Define a function to calculate sum of all the elements of an array.
    int average();            // 6.  Define a function to calculate average of all the elements of an array.
    void rotate_right();      // 7.  Define a function to rotate an array towards right by one position
    void remove_duplicates(); // 8.  Define a function to remove duplicate elements in the array.
    int second_largest();     // 9.  Define a function to find the second largest element in the array.
    void swap(int, int);      // 10. Define a function to swap elements with specified indices in the array.
};
// 1.  Define a function to sort elements of the array.

void Array_Mode::sort()
{
    if (Is_Empty())
    {
        std::cout << "< sort : Array is Empty >";
        return;
    }
    int temp;
    for (int i = 0; i < no_of_elements() - 1; i++)
    {
        for (int j = 0; j < no_of_elements() - i - 1; j++)
        {
            if (get_element(j) > get_element(j + 1))
            {
                temp = get_element(j);
                Edit(j, get_element(j + 1));
                Edit(j + 1, temp);
            }
        }
    }
}

// 2.  Define a function to find the greatest element in the array
int Array_Mode::gretest_elm()
{
    if (Is_Empty())
    {
        std::cout << "< get_element : Array is Empty >";
        return 0;
    }
    int temp = get_element(0);
    for (int i = 1; i < no_of_elements(); i++)
    {
        if (get_element(i) > temp)
            temp = get_element(i);
    }
    return temp;
}

// 3.  Define a function to find the smallest element in the array
int Array_Mode::smallest_elm()
{
    if (Is_Empty())
    {
        std::cout << "< smallest_elm : Array is Empty >";
        return 0;
    }
    int temp = get_element(0);
    for (int i = 1; i < no_of_elements(); i++)
    {
        if (temp > get_element(i))
            temp = get_element(i);
    }
    return temp;
}

// 4.  Define a function to search an element in the array
int Array_Mode::search(int element)
{
    return find(element);
}

// 5.  Define a function to calculate sum of all the elements of an array.
int Array_Mode::sum()
{
    if (Is_Empty())
    {
        std::cout << "< sum : Array is Empty >";
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < no_of_elements(); i++)
        sum += get_element(i);
    return sum;
}

// 6.  Define a function to calculate average of all the elements of an array.
int Array_Mode::average()
{
    if (Is_Empty())
    {
        std::cout << "< average : Array is empty >";
        return 0;
    }
    return sum() / no_of_elements();
}

// 7.  Define a function to rotate an array towards right by one position
void Array_Mode::rotate_right()
{
    if (Is_Empty())
    {
        std::cout << "< rotate_right : Array is Empty >";
        return;
    }
    int temp = get_element(no_of_elements() - 1);
    for (int i = no_of_elements() - 1; i > 0; i--)
    {
        Edit(i, get_element(i - 1));
    }
    Edit(0, temp);
}

// 8.  Define a function to remove duplicate elements in the array.
void Array_Mode::remove_duplicates()
{
    for (int i = 0; i < no_of_elements() - 1; i++)
    {
        for (int j = i + 1; j < no_of_elements(); j++)
            if (get_element(j) == get_element(i))
                Delete(j);
    }
}

// 9.  Define a function to find the second largest element in the array.
int Array_Mode::second_largest()
{
    int a, b;
    b = smallest_elm();
    a = gretest_elm();
    for (int i = 0; i < no_of_elements(); i++)
    {
        if (get_element(i) < a && get_element(i) > b)
        {
            b = get_element(i);
        }
    }
    return b;
}

// 10. Define a function to swap elements with specified indices in the array.
void Array_Mode::swap(int i1, int i2)
{
    int temp = get_element(i1);
    Edit(i1, get_element(i2));
    Edit(i2, temp);
}

// int main()
// {
//     Array_Mode Arr(5);
//     Arr.Append(5);
//     Arr.Append(4);
//     Arr.Append(3);
//     Arr.Append(2);
//     Arr.Append(1);
//     Arr.Display();

//     Arr.sort();
//     Arr.Display();

//     std::cout << "\nGretest element in Array is  = " << Arr.gretest_elm();
//     std::cout << "\nSmallest element in Array is = " << Arr.smallest_elm();

//     std::cout << "\n3 is avilable at index " << Arr.search(3);
//     std::cout << "\n9 is avilable at index " << Arr.search(9);

//     std::cout << "\nsum of all elements is = " << Arr.sum();

//     std::cout << "\naverage of array       = " << Arr.average();

//     Arr.rotate_right();
//     std::cout << "\nArray after rotate ";
//     Arr.Display();

//     Arr.Edit(1, 3);
//     Arr.Edit(4, 5);
//     Arr.Display();

//     std::cout << "\nArray after remove duplicates ";
//     Arr.remove_duplicates();
//     Arr.Display();

//     Arr.Append(1);
//     Arr.Append(0);
//     Arr.Display();
//     std::cout << "\nsecond largest element is = " << Arr.second_largest();

//     std::cout << "swap 2, 4";
//     Arr.swap(3,4);
//     Arr.Display();
//     std::cout << "<end>";
//     return 0;
// }