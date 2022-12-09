//                      DSA through C++
//            Assignment-4: Singly Linked List

// 1.  Define a class SLL to implement singly linked list data structure with member
//     variable start pointer of type node.
// 2.  In question 1, define a constructor to initialise start pointer with NULL.
// 3.  In question 1, define a method to insert a data into the list at the beginning.
// 4.  In question 1, define a method to insert a data into the list at the end
// 5.  In question 1, define a method to search a node with the give item.
// 6.  In question 1, define a method to insert a data into the list after the specified nodeof the list.
// 7.  In question 1, define a method to delete first node from the list.
// 8.  In question 1, define a rnethod to delete last node Of the list.
// 9.  In question 1, define a method to delete a specific node.
// 10. In question 1, define a destructor to deallocates memory for all the nodes in thelinked list.

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
    // ~node() { delete next; }
};

class SSL
{
private:
    node *start;     // 1.  Define a class SLL to implement singly linked list data structure with member
    node *last_node; //     variable start pointer of type node.
    int total = 0;
    int last_index = -1;

public:
    SSL() { start = NULL; }        // 2.  In question 1, define a constructor to initialise start pointer with NULL.
    void insert_at_beginning(int); // 3.  In question 1, define a method to insert a data into the list at the beginning.
    void insert_at_end(int);       // 4.  In question 1, define a method to insert a data into the list at the end
    int search(int);               // 5.  In question 1, define a method to search a node with the give item.
    void insert(int, int);         // 6.  In question 1, define a method to insert a data into the list after the specified node of the list.
    void delete_first();           // 7.  In question 1, define a method to delete first node from the list.
    void delete_last();            // 8.  In question 1, define a rnethod to delete last node Of the list.
    void delete_index(int);        // 9.  In question 1, define a method to delete a specific node.
    // 10. In question 1, define a destructor to deallocates memory for all the nodes in the linked list.
    ~SSL() {}
    void show_list();
};
void SSL::insert_at_beginning(int data)
{
    node *temp;
    temp = new node;
    temp->data = data;
    temp->next = start;
    start = temp;

    total++;
    last_index++;
}

void SSL::insert_at_end(int data)
{
    node *n = start;
    node *temp;
    for (int i = 0; i < last_index; i++)
    {
        n = n->next;
    }
    temp = new node;
    temp->data = data;
    n->next = temp;

    last_index++;
}

void SSL::show_list()
{
    node *n = start;
    cout << "\n";
    for (int i = 0; i <= last_index; i++)
    {
        cout << " " << n->data << ",";
        n = n->next;
    }
}

int SSL::search(int item)
{
    node *n = start;
    for (int i = 0; i <= last_index; i++)
    {
        if (n->data == item)
            return i;
        n = n->next;
    }
    return -1;
}

void SSL::insert(int index, int data)
{
    if (index < 0 || index > last_index)
    {
        cout << "<insert : Invalid index>";
        return;
    }
    if (index == 0)
    {
        insert_at_beginning(data);
        return;
    }
    node *temp = new node;
    temp->data = data;

    node *n = start;
    for (int i = 0; i < index; i++)
    {
        n = n->next;
    }
    node *t = n->next;
    n->next = temp;
    temp->next = t;
    last_index++;
}

void SSL::delete_first()
{
    node *temp;
    temp = start;
    start = start->next;
    delete temp;
    last_index--;
}

void SSL::delete_last()
{
    node *n = start;
    for (int i = 0; i < last_index; i++)
    {
        n = n->next;
    }
    delete n;
    last_index--;
}

void SSL::delete_index(int index)
{
    if (index < 0 || index > last_index)
    {
        cout << "<delete : Invalid index>";
        return;
    }
    if (index == 0)
        delete_first();
    node *n = start;
    for (int i = 0; i < index - 1; i++)
    {
        n = n->next;
    }
    node *temp = n->next;
    n->next = n->next->next;
    last_index--;
}

int main()
{
    SSL list;
    list.insert_at_beginning(5);
    list.insert_at_beginning(4);
    list.insert_at_beginning(2);
    list.insert_at_beginning(3);
    list.show_list();

    list.insert_at_end(6);
    list.show_list();

    cout << "\n5 is available at indax = " << list.search(5);
    cout << "\n5 is available at indax = " << list.search(5);
    cout << "\n5 is available at indax = " << list.search(999);

    list.insert(0, 1);
    list.show_list();
    list.insert(3, 8);
    list.show_list();
    list.insert(8, 10);
    list.show_list();

    list.delete_first();
    list.show_list();

    list.delete_last();
    list.show_list();

    list.delete_index(4);
    list.show_list();

    cout << "<-end of program";
    return 0;
}

// if (start == NULL)
// {
//     cout << "\nstart = NULL";
//     start = new node;
//     start->data = data;
// }
// else
// {
// }