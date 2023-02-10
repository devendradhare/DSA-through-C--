#include <iostream>
using namespace std;
#include "Deque_using_DLL.cpp"

int main()
{
    Deque dq;

    dq.insert_at_front(3);
    dq.show_deque();

    dq.insert_at_front(4);
    dq.show_deque();

    dq.insert_at_front(5);
    dq.show_deque();

    dq.insert_at_rear(6);
    dq.show_deque();

    dq.delete_front();
    dq.show_deque();

    dq.delete_rear();
    dq.show_deque();

    cout << "\nget front = " << dq.get_front();
    cout << "\nget rear  = " << dq.get_rear();
    return 0;
}