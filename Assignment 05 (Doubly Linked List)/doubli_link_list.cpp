//                    DSA through C++
//          Assignment-5: Doubly Linked List

#include <iostream>
#include <stdio.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
};
class DLL
{
private:
    node *start; // 1.  Define a class DLL to implement doubli linked list data structure with member variable start pointer of type node.
    int last_index = -1;

public:
    DLL() { start = NULL; }              // 2.  define a constructor to initialise start pointer with NULL.
    void insert_beginning(int);          // 3.  define a method to insert a data into the list at the beginning.
    void insert_end(int);                // 4.  define a method to insert a data into the list at the end
    node *search_node(int);              // int search(int);            // 5.  define a method to search a node with the give item.
    int search_index(int);              //
    void insert_at_index(int, int);      // 6.  define a method to insert a data into the list after the specified node of the list.
    void insert_after_node(node *, int); //
    void delete_first();                 // 7.  define a method to delete first node from the list.
    void delete_last();                  // 8.  define a method to delete last node of the list.
    void delete_index(int);              // 9.  define a method to delete a specific node.
    void delete_node(node *);            //
    ~DLL();                              // 10. define a destructor to deallocates memory for all the nodes in the linked list.
    void show_list();
};
void DLL::show_list()
{
    node *temp = start;
    cout << "\n";
    while (temp != NULL)
    {
        cout << temp->data << ", ";
        temp = temp->next;
    }
}

void DLL::insert_beginning(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = start;
    if (start != NULL)
        start->prev = temp;
    start = temp;
    last_index++;
}

void DLL::insert_end(int data)
{
    if (start == NULL)
    {
        insert_beginning(data);
        return;
    }
    node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new node();
    temp->next->data = data;
    temp->next->prev = temp;
    last_index++;
}
node *DLL::search_node(int data)
{
    node *t = start;
    while (t != NULL)
    {
        if (t->data == data)
            return t;
        t = t->next;
    }
    return NULL;
}
int DLL::search_index(int data)
{
    node *temp = start;
    int i = 0;                 // ths is my logic.
    while (temp->data != data) // it's returns index of node.
    {
        temp = temp->next;
        i++;
    }
    return i;
}

void DLL::insert_at_index(int index, int data)
{
    if (index < 0 || index > last_index + 1)
    {
        cout << " < insert : Invalid index >";
        return;
    }
    if (index == 0)
    {
        insert_beginning(data);
        return;
    }
    if (index == last_index + 1)
    {
        insert_end(data);
        return;
    }
    node *temp = start;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    node *n = new node;
    n->data = data;
    n->next = temp;
    n->prev = temp->prev;
    temp->prev = n;
    temp->prev->prev->next = n;
    last_index++;
}
void DLL::insert_after_node(node *n, int data)
{
    if (start == NULL)
    {
        cout << "< insert_after_node : Array is empty >";
        return;
    }
    node *t = start;
    while (t != NULL)
    {
        if (t == n)
        {
            if (t->next == NULL)
            {
                insert_end(data);
                return;
            }
            node *nw = new node;
            nw->data = data;
            nw->next = t->next;
            nw->prev = t;
            t->next->prev = nw;
            t->next = nw;
            last_index++;
            return;
        }
        t = t->next;
    }
}
void DLL::delete_first()
{
    if (start == NULL)
    {
        cout << " < delete_first : Array is empty >";
        return;
    }
    node *n = start;
    start = start->next;
    delete n;
    if (start == NULL)
        return;
    start->prev = NULL;
    last_index--;
}

void DLL::delete_last()
{
    if (start == NULL)
    {
        cout << " < delete_last : Array is empty >";
        return;
    }
    if (start->next == NULL)
    {
        delete start;
        start = NULL;
        return;
    }
    node *n = start;
    while (n->next->next != NULL)
        n = n->next;
    delete n->next;
    n->next = NULL;
    last_index--;
}

void DLL::delete_index(int index)
{
    if (index < 0 || index > last_index)
    {
        cout << " < delete_ : Index out of range >";
        return;
    }
    if (index == 0)
    {
        delete_first();
        return;
    }
    if (index == last_index)
    {
        delete_last();
        return;
    }
    node *n = start;
    for (int i = 0; i < index - 2; i++)
        n = n->next;
    n->next = n->next->next;
    delete n->next->prev;
    n->next->prev = n;
    last_index--;
}

void DLL::delete_node(node *n)
{
    if (start == NULL)
    {
        cout << "< delete_node : Array is empty >";
        return;
    }
    node *t = start;
    while (t != NULL)
    {
        if (t == n)
        {
            if (t->prev == NULL)
            {
                delete_first();
                return;
            }
            else if (t->next == NULL)
            {
                delete_last();
                return;
            }
            t->prev->next = t->next;
            t->next->prev = t->prev;
            delete t;

            last_index--;
            return;
        }
        t = t->next;
    }
    cout << "< delete_node : node not found >";
}

DLL::~DLL()
{
    while (start != NULL)
        delete_first();
}

int main()
{
    DLL list;
    list.insert_beginning(1);
    list.insert_beginning(2);
    list.show_list();

    list.insert_end(4);
    list.insert_end(5);
    list.show_list();

    cout << "\n4 is avilable at index = " << list.search_index(4);
    cout << "\n5 is avilable at node  = " << list.search_index(5);

    list.insert_at_index(3, 3);
    list.show_list();

    list.delete_first();
    list.show_list();
    // list.delete_first();
    // list.show_list();
    // list.delete_first();
    // list.show_list();
    // list.delete_first();
    // list.show_list();
    // list.delete_first();
    // list.show_list();
    // list.delete_first();

    list.delete_last();
    list.show_list();

    list.delete_index(1);
    list.show_list();

    list.delete_node(list.search_node(1));
    list.show_list();

    return 0;
}