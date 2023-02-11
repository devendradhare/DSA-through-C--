#include <iostream>
using namespace std;
#include "Priority_queue_SLL.cpp"

int main()
{
    Pqueue p;
    p.insert(3, 2);
    p.show_PQueue();
    p.insert(4, 3);
    p.show_PQueue();
    p.insert(5, 0);
    p.show_PQueue();
    p.insert(6, 2);
    p.show_PQueue();
    p.insert(7, 2);
    p.show_PQueue();
    p.insert(7, 4);
    p.show_PQueue();
    p.insert(7, 0);
    p.show_PQueue();

    p.Delete();
    p.show_PQueue();
    p.Delete();
    p.show_PQueue();

    cout << "\nget high priority element = " << p.get_element();
    return 0;
}