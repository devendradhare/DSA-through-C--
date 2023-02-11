//                   Assignment-14: Priority Queue
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    int priority;
    node *next;
    node()
    {
        data = 0;
        priority = -1;
        next = NULL;
    }
};

class Pqueue
{
private:
    node *front; // 1. class PriorityQueue with node type pointer start as member variable. Implement PriorityQueue using singly linked list.
    node *rear;

public:
    Pqueue();                   // 2. a constructor to initialise member variable.
    void insert(int, int);      // 3. a method to insert new item in the Priority Queue according to the priority number
    void Delete();              // 4. a method to delete highest priority element
    int get_element();          // 5. a method to get highest priority element
    int get_highest_priority(); // 6. a method to get highest priority number.
    ~Pqueue();                  // 7. a destructor to deallocate the memory.
    bool is_empty();            // 8. a method to check if Priority Queue is empty
                                // 9. logic to implement priority queue using 2 dimensional arrays
                                // 10.logic to implement min priority queue and max priority queue in the same data structure.

    // ~Pqueue() {}
    void show_PQueue();
};
bool Pqueue::is_empty()
{
    return front == NULL;
}
Pqueue::~Pqueue()
{
    while (front)
        Delete();
}
int Pqueue::get_highest_priority()
{
    if (front)
        return front->priority;
    cout << "\npriority queue is empty";
    return 0;
}
int Pqueue::get_element()
{
    if (front)
        return front->data;
    cout << "\npriority queue is empty";
    return 0;
}
void Pqueue::Delete()
{
    if (front == rear)
    {
        delete front;
        front = rear = NULL;
    }
    else
    {
        node *temp = front;
        front = front->next;
        delete temp;
    }
}
void Pqueue::show_PQueue()
{
    node *t = front;
    cout << "\n\n d p";
    while (t)
    {
        cout << "\n " << t->data << " " << t->priority;
        t = t->next;
    }
}
void Pqueue::insert(int data, int priority)
{
    node *n = new node;
    n->data = data;
    n->priority = priority;

    if (!front)
        front = rear = n;
    else
    {
        if (front->priority < priority)
        {
            n->next = front;
            front = n;
            return;
        }
        node *t = front;
        while (t->next)
        {
            if (t->next->priority < priority)
            {
                n->next = t->next;
                t->next = n;
                return;
            }
            t = t->next;
        }
        rear->next = n;
        rear = rear->next;
    }
}
Pqueue::Pqueue()
{
    front = NULL;
    rear = NULL;
}