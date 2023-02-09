#include "Queue_v0_1.cpp"

int main()
{
    Queue q;
    q.insert(2);
    q.insert(3);
    q.insert(4);
    q.insert(5);
    q.show_queue();
    cout << " count = " << q.count();

    cout << "\nget_rear  = " << q.get_rear();
    cout << "\nget_front = " << q.get_front();

    q.Delete();
    q.show_queue();
    cout << " count = " << q.count();

    q.Delete();
    q.show_queue();
    cout << " count = " << q.count();
    q.Delete();
    q.show_queue();
    cout << " count = " << q.count();
    q.Delete();
    q.show_queue();
    cout << " count = " << q.count();
    q.Delete();
    q.show_queue();
    cout << " count = " << q.count();

    q.insert(4);
    q.insert(5);
    q.insert(2);
    q.insert(3);
    q.insert(1);
    q.show_queue();
    cout << " count = " << q.count();
    return 0;
}