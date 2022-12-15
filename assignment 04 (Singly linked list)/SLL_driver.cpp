//                      DSA through C++
//            Assignment-4: Singly Linked List

#include <iostream>
#include "../SLL"
using namespace std;

int main()
{
    SLL list;
    // list.insert_at_first(5);
    // list.insert_at_first(4);
    // list.insert_at_first(2);
    // list.insert_at_first(3);
    // list.show_list();

    list.insert_at_last(1);
    list.show_list();
    list.insert_at_last(2);
    list.show_list();
    list.insert_at_last(3);
    list.show_list();
    list.insert_at_last(4);
    list.show_list();

    cout << "\n2 is available at indax = " << list.search_index(2);
    cout << "\n3 is available at node  = " << list.search_node(3) << "->data = " << list.search_node(3)->data;
    // cout << "\n5 is available at indax = " << list.search_index(999);

    // list.insert_at_index(0, 0);
    // list.show_list();
    // list.insert_at_index(5, 8);
    // list.show_list();

    // list.delete_first();
    // list.show_list();
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
    // list.delete_last();
    // list.show_list();
    // list.delete_last();
    // list.show_list();

    // list.delete_index(0);
    // list.show_list();
    // list.delete_index(2);
    // list.show_list();
    // list.delete_index(1);
    // list.show_list();
    // list.delete_index(0);
    // list.show_list();

    list.delete_node(list.search_node(4));
    list.show_list();
    list.delete_node(list.search_node(1));
    list.show_list();
    list.delete_node(list.search_node(3));
    list.show_list();
    list.delete_node(list.search_node(2));
    list.show_list();

    cout << "<-end of program";
    return 0;
}

// 1.  Define a class SLL to implement singly linked list data structure with member
//     variable start pointer of type node.
// 2.  In question 1, define a constructor to initialise start pointer with NULL.
// 3.  In question 1, define a method to insert a data into the list at the lastinsert_at_first.
// 4.  In question 1, define a method to insert a data into the list at the end
// 5.  In question 1, define a method to search a node with the give item.
// 6.  In question 1, define a method to insert a data into the list after the specified nodeof the list.
// 7.  In question 1, define a method to delete first node from the list.
// 8.  In question 1, define a rnethod to delete last node Of the list.
// 9.  In question 1, define a method to delete a specific node.
// 10. In question 1, define a destructor to deallocates memory for all the nodes in thelinked list.
