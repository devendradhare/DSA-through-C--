// //              Assignment-II: Queue using arrays
#include <iostream>
using namespace std;
#include "../ASSIGNMENT 01 Array/Array.cpp"

class Queue : private Array
{
private:
    int capacity; // Queue with capacity, front, rear and ptr pointer as member variables. Implement queue using array.
    int front;
    int rear;
    int *ptr;

public:
    Queue(int);          // parameterzied constructor to initialise member variables.
    void insert(int);    // method to insert a new element at the rear in the queue.
    int get_rear();      // method to view rear element of the queue.
    int get_front();     // method to view front element of the queue.
    void delete_front(); // method to delete the front element of the queue.
    ~Queue() {}          // destructor to deallocates the memory.
    bool is_full();      // method to check queue overflow
    bool is_empty();     // method to check queue underflow.
    int count();         // method to count number of elements present in the queue

    void show_queue();
};

int Queue::count()
{
    if (rear == -1)
        return -1;
    else if (rear == front)
        return 1;
    else if (rear > front)
        return rear - front + 1;
    else
        return capacity - (front - rear - 1);
}

bool Queue::is_full()
{
    return front == 0 && rear == capacity || rear + 1 == front;
}

bool Queue::is_empty()
{
    return rear == -1;
}

void Queue::delete_front()
{
    if (front == rear)
    {
        rear = front = -1;
        return;
    }
    front++;
    if (front >= capacity)
        front = front % capacity;
}

int Queue::get_front()
{
    return get_element(front);
}

int Queue::get_rear()
{
    return get_element(rear);
}

void Queue::show_queue()
{
    int f = front;
    if (rear == -1)
    {
        cout << "\nQueue is empty";
        return;
    }
    cout << "\n";

    do
    {
        cout << " " << get_element(f % capacity);
    } while ((f++ % capacity) != rear);
}

void Queue::insert(int data)
{
    // cout << "\n(rear + 1) % capacity = " << (rear + 1) % capacity;
    if (rear == -1)
        front = rear = 0;
    else if ((rear + 1) % capacity == front && rear != front)
    {
        cout << "\nQueue is full";
        return;
    }
    else
        rear++;

    Edit(rear % capacity, data);
    if (rear >= capacity)
        rear = rear % capacity;
    cout << "\nrear = " << rear << " front = " << front << " capacity = " << capacity;
}

Queue::Queue(int cap) : Array(cap)
{
    capacity = cap;
    front = rear = -1;
    ptr = get_ptr();

    for (int i = 0; i < capacity; i++)
        Append(0);
}

// int main()
// {
//     int rear = 0;
//     for (int i = 0; i <= 23; i++)
//     {
//         if (rear > 5)
//         {
//             rear = rear % 5;
//         }
//         cout << rear % 5 << " ";
//         rear++;
//     }
//     return 0;
// }