//                             DSA through C++
//                Assignment-10: Stack using linked list

#include <iostream>
#include <conio.h>
#include "../ASSIGNMENT 04 SLL/SLL.cpp"
using namespace std;

// 1.  Define a class Stack with node type pointer top as member variable. Implement stack using linked list.
class Stack : private SLL
{
private:
    node *top;

public:
    Stack() { top = get_start(); } // 2.  In question 1, define a constructor to initialise member variable.
    void push(int);                // 3.  In question 1, define a method to push a new element on to the Stack.
    int peek();                    // 4.  In question 1, define a method to peek top Of the stack.
    int pop();                     // 5.  In question 1, define a method to pop the top element of the stack.
    ~Stack() {}                    // 6.  In question 1, define a destructor to deallocates the memory.
    // done as an method           // 7.  Define a method to reverse a stack.
    // 8.  Define a method to check whether a given number is a palindrome or not using stack.
    // 9.  Define a method to convert infix to postfix expression.
    // 10. Define a method to evaluate postfix expression.

    void
    operator=(Stack &);

    void show_stack();
};

void Stack::operator=(Stack &S)
{
    SLL::operator=(S);
    node *t = get_start();
    while (t->next)
    {
        t = t->next;
    }
    top = t;
}
int Stack::pop()
{
    int temp = peek();
    delete_first();
    top = get_start();
    return temp;
}

int Stack::peek()
{
    if (top)
        return top->data;
    return 0;
}

void Stack::push(int data)
{
    insert_at_first(data);
    top = get_start();
}

void Stack::show_stack()
{
    if (top)
        show_list();
    else
        cout << " <stack is empty> ";
}

void reverse(Stack &s)
{
    Stack temp;
    cout << "\n\n\n\nstart reverseing---------";

    s.show_stack();
    while (s.peek())
    {
        temp.push(s.pop());
        s.show_stack();
    }

    cout << "\n\ns.show stack = ";
    s.show_stack();

    cout << "\n\ntemp.show stack = ";
    temp.show_stack();

    s = temp;

    cout << "\ns.show stack = ";
    s.show_stack();
}

int main()
{
    Stack s;
    s.show_stack();
    cout << "\n peek() = " << s.peek();
    s.push(1);
    s.push(2);
    s.show_stack();
    cout << "\n peek() = " << s.peek();
    s.push(3);
    s.push(4);
    s.show_stack();
    cout << "\n peek() = " << s.peek();
    // cout << "\n pop()  = " << s.pop();
    // cout << "\n pop()  = " << s.pop();
    // cout << "\n pop()  = " << s.pop();
    // cout << "\n pop()  = " << s.pop();

    s.show_stack();
    reverse(s);
    s.show_stack();

    return 0;
}

// class A
// {
//   // Class definition

// public:
//   A& operator=(const A& other)
//   {
//     if (this != &other)
//     {
//       a = other.a;
//     }
//     return *this;
//   }
// };

// class B : private A
// {
//   // Class definition

// public:
//   B& operator=(const B& other)
//   {
//     if (this != &other)
//     {
//       A::operator=(other);
//       b = other.b;
//     }
//     return *this;
//   }
// };
