//                      DSA through C++
//              Assignment- 6: Circular Linked List
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node()
    {
        data = 0;
        next = NULL;
    }
};
class CLL
{
private:        // 1. Define a class CLL to implement Circular linked list data structure with member
    node *last; // variable last pointer of type node.

public:
    CLL() { last = NULL; }          // 2. define a constructor to initialise last pointer with NULL.
    void insert_at_first(int);      // 3. define a method to insert a data into the list at the beginning.
    void insert_at_last(int);       // 4. define a method to insert a data into the list at the end
    node *search(int);              // 5. define a method to search a node with the give item.
    void insert_after(node *, int); // 6. define a method to insert a data into the list after the specified node of the list.
    void delete_first();            // 7. define a method to delete first node from the list.
    void delete_last();             // 8. define a method to delete last node of the list.
    void delete_node(node *);       // 9. define a method to delete a specific node.
    ~CLL();                         // 10.define a destructor to deallocates memory for all the nodes in the linked list.

    void show_list();
};

CLL::~CLL()
{
    while (last != NULL)
        delete_first();
}

void CLL::delete_node(node *nod)
{
    if (last == NULL)
    {
        cout << " <delete_node: list is empty> ";
        return;
    }
    if (nod == last)
    {
        delete_last();
        return;
    }
    node *t = last;
    do
    {
        if (t->next == nod)
        {
            t->next = nod->next;
            delete nod;
            return;
        }
        t = t->next;
    } while (t->next != last);
    cout << " <delete_node: node not found> ";
}

void CLL::delete_last()
{
    if (last == NULL)
    {
        cout << " <delete_last: list is empty> ";
        return;
    }
    if (last == last->next)
    {
        delete_first();
        return;
    }
    node *t = last->next;
    while (t->next != last)
        t = t->next;
    t->next = last->next;
    delete last;
    last = t;
}

void CLL::delete_first()
{
    if (last == NULL)
    {
        cout << " <delete_first: list is empty> ";
        return;
    }
    if (last == last->next)
    {
        delete last;
        last = NULL;
        return;
    }
    node *temp = last->next;
    last->next = temp->next;
    delete temp;
}

void CLL::insert_after(node *nod, int data)
{
    if (last == NULL)
    {
        cout << " <insert_after: list is empty> ";
        return;
    }
    node *t = last->next;
    do
    {
        if (t == nod)
        {
            node *tmp_last = last;
            last = t;
            insert_at_first(data);
            last = tmp_last;
            return;
        }
        t = t->next;
    } while (t != last);
    cout << " <insert_after: node not found> ";
}

node *CLL::search(int data)
{
    if (last == NULL)
    {
        cout << " <search : list is empty> ";
        return NULL;
    }
    node *t = last->next;
    do
    {
        if (t->data == data)
            return t;
        t = t->next;
    } while (t != last->next);
    cout << " <search : node not found> ";
    return NULL;
}

void CLL::insert_at_last(int data)
{
    insert_at_first(data);
    last = last->next;
}

void CLL::insert_at_first(int data)
{
    node *n = new node;
    n->data = data;
    if (last == NULL)
    {
        last = n;
        n->next = n;
    }
    else
    {
        n->next = last->next;
        last->next = n;
    }
}

void CLL::show_list()
{
    if (last == NULL)
    {
        cout << " <show_list : list is empty> ";
        return;
    }
    node *t = last->next;
    cout << "\n";
    do
    {
        cout << " " << t->data;
        t = t->next;
    } while (t != last->next);
}