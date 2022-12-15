#include <iostream>
#include "../SLL_MODE.CPP"
using namespace std;

int main()
{
    SLL_MODE list;
    list.insert_at_first(5);
    list.insert_at_first(4);
    list.insert_at_first(3);
    list.insert_at_first(2);
    list.insert_at_first(1);
    list.show_list();

    cout << "\ntotal element in the list = " << list.count();
    return 0;
}