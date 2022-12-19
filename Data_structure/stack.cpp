//                         DSA through C++
//                 Assignment-9: Stack using arrays
#include "Array.cpp"

class Stack : private Array
{ // 1.  class Stack with capacity, top and ptr pointer as member variables. Implement stack using array.
private:
public:
    Stack(int);       // 2.  parameterzied constructor to initialise member variables.
    void push(int);   // 3.  method to push a new element on to the Stack.
    int peek();       // 4.  method to peek top element of the stack.
    int pop();        // 5.  method to pop the top element of the stack.
    ~Stack() {}       // 6.  destructor to deallocates the memory.
    bool overflow();  // 7.  method to check stack overflow
    bool underflow(); // 8.  method to check stack underflow.
    void reverse();   // 9.  method to reverse a stack.
                      // 10. solution to keep track of minimum value element in the stack.

    void show_stack();
};

void Stack::reverse()
{
    int temp;
    int upto = no_of_elements() / 2;
    for (int i = 0; i < upto; i++)
    {
        temp = get_element(i);
        Edit(i, get_element(no_of_elements() - 1 - i));
        Edit(no_of_elements() - i - 1, temp);
    }
}
bool Stack::underflow()
{
    return Is_Empty();
}
bool Stack::overflow()
{
    return Is_Full();
}
int Stack::pop()
{
    int temp = peek();
    if (Is_Empty())
        cout << " stack underflow";
    else
        Delete(no_of_elements() - 1);
    return temp;
}
int Stack::peek()
{
    if (!Is_Empty())
        return get_element(no_of_elements() - 1);
    return 0;
}
Stack::Stack(int size) : Array(size)
{
}
void Stack::push(int data)
{
    if (Is_Full())
        cout << "\n stack overflow";
    else
        Append(data);
}
void Stack::show_stack()
{
    Display();
}

// int main()
// {
//     Stack s(5);
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.show_stack();

//     cout << "\n s.peek = " << s.peek();

//     s.pop();
//     s.show_stack();
//     s.pop();
//     s.pop();
//     s.show_stack();

//     s.underflow() ? cout << "\n Stack underflow" : cout << "\n Stack is not underflow";
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     s.push(5);
//     s.push(6);
//     s.show_stack();

//     s.overflow() ? cout << "\n Stack overflow" : cout << "\n Stack is not overflow";

//     s.reverse();
//     s.show_stack();

//     return 0;
// }
