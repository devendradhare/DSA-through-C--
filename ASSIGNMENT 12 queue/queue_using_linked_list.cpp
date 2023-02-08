//                  Assignment-12: Queue using linked list
#include <iostream>
using namespace std;
#include "../ASSIGNMENT 04 SLL/SLL.cpp"

class Queue : public SLL
{
private:
    // 1. class Queue with node type pointers front and rear as member variables.
    int front; // Implement queue using Singly linked list.
    int rear;
    int count_;

public:
    Queue();          // 2. constructor to initialise member variable.
    void insert(int); // 3. method to insert a elernent at the rear in the queue.
    int get_rear();   // 4. method to view rear element in the queue.
    int get_front();  // 5. method to view front element in the queue.
    void Delete();    // 6. method to delete the front element of the queue.
    ~Queue() {}       // 7. destructor to deallocates the memory.
    int count();      // 8. method to count number of elements present in the queue.
    // 9. program to sort a queue, using queue operations only.
    // 10.program to sort a queue in descending order, using queue operations only.
};

int Queue::count()
{
    return count_;
}

void Queue::Delete()
{
    SLL::delete_first();
    count_--;
    if(get_start()==NULL)
        rear = -1;
}

int Queue::get_front()
{
    if (get_start())
        return get_start()->data;
    return -1;
}

int Queue::get_rear()
{
    return rear;
}

void Queue::insert(int data)
{
    insert_at_last(data);
    rear = data;
    count_++;
}

Queue::Queue()
{
    front = rear = -1;
    count_ = 0;
}