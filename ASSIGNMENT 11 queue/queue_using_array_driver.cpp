#include <iostream>
#include "../ASSIGNMENT 11 queue/queue_using_array.cpp"
using namespace std;

int main()
{
    Queue q(5);

    q.insert(1);
    q.insert(2);
    q.insert(3);
    // q.insert(4);
    // q.insert(5);
    // q.insert(6);
    // q.insert(7);
    // q.insert(7);
    q.show_queue();

    cout << "\nq.get_rear()" << q.get_rear();
    q.show_queue();

    cout << "\nq.get_front()" << q.get_front();
    q.show_queue();

    q.delete_front();
    q.show_queue();
    q.delete_front();
    q.show_queue();
    // q.delete_front();
    // q.show_queue();
    // q.delete_front();
    // q.show_queue();

    q.insert(4);
    q.show_queue();

    q.insert(5);
    q.show_queue();

    q.insert(6);
    q.show_queue();

    q.insert(7);
    q.show_queue();

    q.insert(7);
    q.show_queue();

    cout << "\nq.get_rear()" << q.get_rear();
    q.show_queue();

    if (q.is_full())
        cout << "\nqueue is full";
    else
        cout << "\nqueue is not full";

    if (q.is_empty())
        cout << "\nqueue is empty";
    else
        cout << "\nqueue is not empty";

    cout << "\nnumber of element in queue is = " << q.count();

    return 0;
}