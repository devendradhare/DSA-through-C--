//                    DSA through C++
//          Assignment-5: Doubly Linked List

#include <iostream>
#include <stdio.h>
#include "DLL.cpp"
using namespace std;

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