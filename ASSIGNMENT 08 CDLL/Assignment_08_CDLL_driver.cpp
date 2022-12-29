#include <iostream>
using namespace std;
#include "CDLL.cpp"

int main()
{
    CDLL list;
    // list.insert_at_first(5);
    // list.insert_at_first(4);
    // list.insert_at_first(3);
    list.insert_at_first(2);
    list.insert_at_first(1);
    list.show_list();

    // list.insert_at_last(4);
    // list.insert_at_last(5);
    // list.insert_at_last(3);
    // list.show_list();

    // cout << "\n3 is avilable at node = " << list.search(3) << " = " << list.search(3)->data;
    // cout << "\n2 is avilable at node = " << list.search(2) << " = " << list.search(2)->data;

    list.insert_after(list.search(1), 3);
    list.show_list();

    // list.delete_first();
    // list.show_list();
    // list.delete_first();
    // list.show_list();
    // list.delete_first();
    // list.show_list();
    // list.delete_first();
    // list.show_list();

    // list.delete_last();
    // list.show_list();
    // list.delete_last();
    // list.show_list();
    // list.delete_last();
    // list.show_list();

    list.delete_node(list.search(1));
    list.show_list();
    list.delete_node(list.search(2));
    list.show_list();
    list.delete_node(list.search(3));
    list.show_list();
    return 0;
}

// 1.  Define a class CDLL to implement Circular Doubly linked list data structure
//     with member variable start pointer of type node.
// 2.  constructor to initialise start pointer with NULL.
// 3.  method to insert a data into the list at the beginning.
// 4.  method to insert a data into the list at the end
// 5.  method to search a node with the give item.
// 6.  method to insert a data into the list after the specified node of the list.
// 7.  method to delete first node from the list.
// 8.  method to delete last node of the list.
// 9.  method to delete a specific node.
// 10. destructor to deallocates memory for all the nodes in thelinked list.