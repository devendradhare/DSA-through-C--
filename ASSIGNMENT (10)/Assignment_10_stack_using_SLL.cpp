#include <iostream>
#include <conio.h>
#include "Data_structure/SLL.cpp"
using namespace std;

class Stack : private SLL
{
private:
    node *top;

public:
    Stack() { top = get_start(); }
    void push(int);
    int peek();
    int pop();
    ~Stack() {}

    void operator=(Stack &);

    void show_stack();
};
void Stack::operator=(Stack &S)
{
    top = S.top;
    this.SLL::operator=()
    
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
    show_list();
}

void reverse(Stack &s)
{
    Stack temp;
    cout << "\n\nreverse---------\n\n";
    // s.show_stack();
    while (s.peek())
    {
        temp.push(s.pop());
    }
    // temp.show_stack();
    s = temp;
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
    getch();
    s.show_stack();

    return 0;
}