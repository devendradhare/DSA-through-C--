//                   Assignment-12: Queue using linked list
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node()
    {
        next = NULL;
        data = 0;
    }
};

// 1. a class Queue with node type pointers front and rear as member variables. Implement queue using Singly linked list.
class Queue
{
private:
    node *front;
    node *rear;
    int cnt;

public:
    Queue();          // 2. constructor to initialise member variable.
    void insert(int); // 3. method to insert a new element at the rear in the queue.
    int get_rear();   // 4. method to view rear element in the queue.
    int get_front();  // 5. method to view front element in the queue.
    void Delete();    // 6. method to delete the front elernent Of the queue.
    ~Queue();         // 7. destructor to deallocates the memory.
    int count();      // 8. method to count number of elements present in the queue.
                      // 9. program to sort a queue, using queue operations only.
                      // 10.program to sort a queue in descending order, using queue operations only.

    void show_queue();
};

int Queue::count()
{
    return cnt;
}

Queue::~Queue()
{
    while (front)
        delete front;
}

void Queue::Delete()
{
    if (front)
    {
        cnt--;
        if (front == rear)
        {
            delete front;
            front = rear = NULL;
            return;
        }

        node *t = front;
        front = front->next;
        delete t;
    }
}

int Queue::get_front()
{
    return !front ? -1 : front->data;
}

int Queue::get_rear()
{
    return !rear ? 0 : rear->data;
}

void Queue::insert(int data)
{
    cnt++;
    if (!rear)
    {
        rear = new node;
        rear->data = data;
        front = rear;
    }
    else
    {
        rear->next = new node;
        rear->next->data = data;
        rear = rear->next;
    }
}

Queue::Queue()
{
    front = rear = NULL;
    cnt = 0;
}

void Queue::show_queue()
{
    node *t = front;
    cout << "\n";
    while (t)
    {
        cout << " " << t->data;
        t = t->next;
    }
}