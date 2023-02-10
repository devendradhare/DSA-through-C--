//               Assignment-13: Deque
#include <iostream>
using namespace std;

class node
{
public:
    node *prev;
    int data;
    node *next;
    node()
    {
        prev = next = NULL;
        data = 0;
    }
};

class Deque
{
private:
    node *front; // 1. a class Deque with node type pointers front and rear as member variables. Implement queue using doubly linked list.
    node *rear;

public:
    Deque();                   // 2. constructor to initialise member variables
    void insert_at_front(int); // 3. method to insert a new element at the front
    void insert_at_rear(int);  // 4. method to insert a new element at the rear.
    void delete_front();       // 5. method to delete front element
    void delete_rear();        // 6. method to delete rear element
    int get_front();           // 7. method to get front element.
    int get_rear();            // 8. method to get rear element
    ~Deque();                  // 9. destructor to deallocate the memory.
    bool is_empty();           // 10.method to check if deque is empty.

    void show_deque();
};
bool Deque::is_empty()
{
    return front == NULL;
}
Deque::~Deque()
{
    while (front)
        delete front;
}
int Deque::get_rear()
{
    return rear ? rear->data : -1;
}
int Deque::get_front()
{
    return front ? front->data : -1;
}
void Deque::delete_rear()
{
    if (rear)
    {
        if (front == rear)
        {
            delete rear;
            front = rear = NULL;
        }
        else
        {
            rear = rear->prev;
            delete rear->next;
            rear->next = NULL;
        }
    }
}
void Deque::delete_front()
{
    if (front)
    {
        if (front == rear)
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            delete front->prev;
            front->prev = NULL;
        }
    }
}
void Deque::insert_at_rear(int data)
{
    if (rear == NULL)
    {
        front = rear = new node;
        front->data = data;
    }
    else
    {
        rear->next = new node;
        rear->next->prev = rear;
        rear = rear->next;
        rear->data = data;
    }
}
void Deque::insert_at_front(int data)
{
    if (front == NULL)
    {
        front = rear = new node;
        front->data = data;
    }
    else
    {
        front->prev = new node;
        front->prev->next = front;
        front = front->prev;
        front->data = data;
    }
}

Deque::Deque()
{
    front = rear = NULL;
}
void Deque::show_deque()
{
    node *t = front;
    cout << "\n";
    while (t)
    {
        cout << " " << t->data;
        t = t->next;
    }
}