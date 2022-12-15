// //                  DSA through C++
// //          Assignment-7: Problems on Linked List
#include <iostream>
#include "SLL"
using namespace std;
class SLL_MODE : public SLL
{
public:
    SLL_MODE() {}
    ~SLL_MODE() {}

    int count();    // 1.  method to count number of list items in the singly linked list.
    void reverse(); // 2.  method to reverse a singly linked list
                    // 3.  method to find middle node of the singly linked list.
                    // 4.  method to check whether a linked list has a cycle or not.
                    // 5.  method to count length of the cycle in the linked list
                    // 6.  method to sort a linked list.
                    // 7.  method to merge two sorted linked list
                    // 8.  Polynomial class to implement polynomial using linked list
                    // 9.  method to add two polynomials.
                    // 10. You are given two non-empty linked lists representing two non-negative integers.
                    //     The digits are stored in reverse order, and each of their nodes contains a single
                    //     digit. Add the two numbers and return the sum as a linked list. You may assume the
                    //     two numbers do not contain any leading zero, except the number 0 itself.
};
void SLL_MODE::reverse()
{
    node temp_list;
}
int SLL_MODE::count()
{
    int count = 0;
    node *t = get_start();
    while (t != NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}
