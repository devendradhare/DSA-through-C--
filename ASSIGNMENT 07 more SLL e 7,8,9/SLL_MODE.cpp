// //                  DSA through C++
// //          Assignment-7: Problems on Linked List
#include <iostream>
#include "../ASSIGNMENT 04 SLL/SLL.cpp"
using namespace std;
class SLL_MODE : public SLL
{
public:
    SLL_MODE() {}
    ~SLL_MODE() {}

    int count();         // 1.  method to count number of list items in the singly linked list.
    void reverse();      // 2.  method to reverse a singly linked list
    node *middle_node(); // 3.  method to find middle node of the singly linked list.
    bool is_cycle();     // 4.  method to check whether a linked list has a cycle or not.
    int cycle_len();     // 5.  method to count length of the cycle in the linked list
    void sort();         // 6.  method to sort a linked list.
    void merge(SLL &);   // 7.  method to merge two sorted linked list
};
// class polynomial
// {
// private:
//     struct node
//     {
//         int coeff;
//         int deg;
//         node *next;
//     }; // 8.  Polynomial class to implement polynomial using linked list
//     node *start;

// public:
//     // 9.  method to add two polynomials.62
//     void insert(int c, int d);
// };
// void polynomial::insert(int c, int d)
// {
//     node *n = new node;
//     n->coeff = c;
//     n->deg = d;
//     if(start == NULL)
//     n->
// }
// 10. You are given two non-empty linked lists representing two non-negative integers.
//     The digits are stored in reverse order, and each of their nodes contains a single
//     digit. Add the two numbers and return the sum as a linked list. You may assume the
//     two numbers do not contain any leading zero, except the number 0 itself.

void SLL_MODE::merge(SLL &l2)
{
    SLL *temp = new SLL;
    while (get_start() != NULL && l2.get_start() != NULL)
    {
        if (get_start()->data < l2.get_start()->data)
        {
            temp->insert_at_last(get_start()->data);
            delete_first();
        }
        else
        {
            temp->insert_at_last(l2.get_start()->data);
            l2.delete_first();
        }
    }
    while (l2.get_start() != NULL)
    {
        temp->insert_at_last(l2.get_start()->data);
        l2.delete_first();
    }
    while (get_start() != NULL)
    {
        temp->insert_at_last(get_start()->data);
        delete_first();
    }
    set_start(temp->get_start());
}

void SLL_MODE::sort()
{
    node *t2;
    t2 = get_start();
    if (t2 == NULL)
        return;
    int flag = 1;
    while (flag)
    {
        flag = 0;
        t2 = get_start();
        while (t2->next != NULL)
        {
            if (t2->data > t2->next->data)
            {
                int temp = t2->data;
                t2->data = t2->next->data;
                t2->next->data = temp;
                flag = 1;
            }
            t2 = t2->next;
        }
    }
}

int SLL_MODE::cycle_len()
{
    if (!is_cycle())
        return 0;

    node *t1, *t2;
    t1 = t2 = get_start();
    do
    {
        t1 = t1->next;
        t2 = t2->next->next;
    } while (t1 != t2);
    int count = 1;
    while (t1->next != t2)
    {
        count++;
        t1 = t1->next;
    }
    return count;
}

bool SLL_MODE::is_cycle()
{
    if (!get_start())
        return false;

    node *t1, *t2;
    t1 = get_start();
    t2 = t1;
    while (t2 != NULL && t2->next != NULL)
    {
        t1 = t1->next;
        t2 = t2->next->next;
        if (t1 == t2)
            return true;
    }
    return false;
}

node *SLL_MODE::middle_node()
{
    node *t1, *t2;
    t1 = get_start();
    t2 = t1;
    while (t2 != NULL && t2->next != NULL)
    {
        t1 = t1->next;
        t2 = t2->next->next;
    }
    return t1;
}

void SLL_MODE::reverse()
{
    SLL *temp = new SLL;
    while (get_start() != NULL)
    {
        temp->insert_at_first(get_start()->data);
        delete_first();
    }
    set_start(temp->get_start());
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
