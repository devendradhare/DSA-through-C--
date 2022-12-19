//                         DSA through C++
//                 Assignment-9: Stack using arrays
#include <iostream>
using namespace std;
#include "Data_structure/stack.cpp"

int main()
{
    cout << " ;asjf ";
    cout << " ;asdfj ";

    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.show_stack();

    cout << "\n s.peek = " << s.peek();

    s.pop();
    s.show_stack();
    s.pop();
    s.pop();
    s.show_stack();

    s.underflow() ? cout << "\n Stack underflow" : cout << "\n Stack is not underflow";
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.show_stack();

    s.overflow() ? cout << "\n Stack overflow" : cout << "\n Stack is not overflow";

    s.reverse();
    s.show_stack();

    return 0
}