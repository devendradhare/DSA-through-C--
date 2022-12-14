#include <iostream>
#include "../CLL.CPP"
using namespace std;

int main()
{
    CLL list;
    list.insert_at_first(3);
    list.show_list();
    // list.insert_at_first(2);
    // list.show_list();
    // list.insert_at_first(1);
    // list.show_list();

    list.insert_at_last(5);
    list.show_list();
    list.insert_at_last(6);
    list.show_list();
    // list.insert_at_last(7);
    // list.show_list();

    cout << "\n search 6 = " << list.search(6) << " = " << list.search(6)->data;
    // cout << "\n search 9 = " << list.search(9) << " = " << list.search(9) ? list.search(9)->data : 0;
    cout << "\n";

    list.insert_after(list.search(5), 55);
    list.show_list();

    // list.delete_first();
    // list.show_list();
    // list.delete_first();
    // list.show_list();
    // list.delete_first();
    // list.show_list();

    list.delete_last();
    list.show_list();
    // list.delete_last();
    // list.show_list();
    // list.delete_last();
    // list.show_list();
    // list.delete_last();
    // list.show_list();
    // list.delete_last();
    // list.show_list();

    list.delete_node(list.search(55));
    list.show_list();
    list.delete_node(list.search(5));
    list.show_list();
    list.delete_node(list.search(3));
    list.show_list();
    list.delete_node(list.search(8));
    list.show_list();

    return 0;
}