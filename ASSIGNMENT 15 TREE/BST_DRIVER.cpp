#include <iostream>
#include <stdio.h>
using namespace std;
#include "BST.cpp"

int main()
{
    BST bst;
    bst.insert(50);
    bst.insert(25);
    bst.insert(75);
    bst.insert(10);
    bst.insert(35);
    bst.insert(60);
    bst.insert(80);
    bst.insert(5);
    bst.insert(15);
    bst.insert(11);
    bst.insert(30);
    bst.insert(45);
    bst.insert(47);
    bst.insert(46);
    bst.insert(48);

    cout << "\n\npreorder traversing = ";
    bst.preorder_traversing();
    cout << "\n\ninorder traversing = ";
    bst.inorder_traversing();
    cout << "\n\npostorder traversing = ";
    bst.postorder_traversing();

    bst.Delete(51);
    cout << "\n\ninorder traversing = ";
    bst.inorder_traversing();

    bst.Delete(47);
    cout << "\n\ninorder traversing = ";
    bst.inorder_traversing();

    node *s = bst.search(45);
    if (s)
        cout << "\ndata = " << s->data << "\nleft = " << (s->left ? s->left->data : 0) << "\nright = " << (s->right ? s->right->data : 0);
    else
        cout << "\n45 not found";

    return 0;
}