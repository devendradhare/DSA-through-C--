#include <iostream>
using namespace std;
#include "Data_structure/CDLL.cpp"

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