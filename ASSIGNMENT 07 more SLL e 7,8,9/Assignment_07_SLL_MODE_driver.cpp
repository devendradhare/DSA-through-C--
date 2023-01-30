#include <iostream>
#include "SLL_MODE.cpp"
using namespace std;

int main()
{
    SLL_MODE list;
    list.insert_at_first(4);
    list.insert_at_first(3);
    list.insert_at_first(10);
    list.insert_at_first(9);
    list.insert_at_first(5);
    list.show_list();

    cout << "\ntotal element in the list = " << list.count();

    list.reverse();
    list.show_list();

    cout << "\nmiddle node of the list = " << list.middle_node()->data;

    // list.sort();
    list.show_list();

    SLL_MODE list2;
    list2.insert_at_first(8);
    list2.insert_at_first(1);
    list2.insert_at_first(6);
    list2.insert_at_first(2);
    list2.insert_at_first(7);
    list2.show_list();

    list.merge(list2);
    list.show_list();

    return 0;
}