#include <iostream>
using namespace std;
#include "queue_using_linked_list.cpp"

int main()
{
    Queue q;
    cout << "\nnumber of elements = " << q.count();
    q.insert(1);
    q.insert(2);
    q.insert(3);
    q.insert(4);
    q.insert(5);

    q.show_list();
    cout << "\nnumber of elements = " << q.count();

    cout << "\nget rear  = " << q.get_rear();
    cout << "\nget front = " << q.get_front();

    q.Delete();
    q.Delete();
    cout << "\nnumber of elements = " << q.count();

    q.show_list();

    cout << "\nget rear  = " << q.get_rear();
    cout << "\nget front = " << q.get_front();
    cout << "\nnumber of elements = " << q.count();

    return 0;
}