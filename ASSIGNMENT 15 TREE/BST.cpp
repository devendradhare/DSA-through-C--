#include <iostream>

//              Assignment-15: Tree
class node
{
public:
    node *left, *right;
    int data;
    node() { left = right = NULL; }
};
class BST
{
private:        // 1.  Define a class BST (Binary Search Tree) with node type pointer root as member variable.
    node *root; //     Implement Binary Search Tree using linked representation.
    void preorder_t(node *);
    void inorder_t(node *);
    void postorder_t(node *);
    node *Del(node *, int);
    node *search2(node *, int);

public:
    BST()
    {
        root = NULL;
    }                                        // 2.  constructor to initialise root pointer with NULL.
    bool is_empty() { return root == NULL; } // 3.  method to check if the tree is empty.
    void insert(int);                        // 4.  method to insert a new element in the BST
    void preorder_traversing();              // 5.  method for preorder traversing of BST
    void inorder_traversing();               // 6.  method for inorder traversing of BST
    void postorder_traversing();             // 7.  method for postorder traversing of BST
    void Delete(int);                        // 8.  method to delete an element from BST
    node *search(int);                       // 9.  method to search an item in the BST
    ~BST();                                  // 10. destructor to release memory of all the nodes of BST.
};
BST::~BST()
{
    if (root)
        Del(root, root->data);
}
node *BST::search2(node *t, int data)
{
    if (t == NULL)
        return NULL;
    if (data < t->data)
        return search2(t->left, data);
    else if (data > t->data)
        return search2(t->right, data);
    else
        return t;
}
node *BST::search(int data)
{
    return search2(root, data);
}
node *BST::Del(node *rt, int data)
{
    if (rt == NULL)
        return NULL;
    else if (rt->data > data)
        rt->left = Del(rt->left, data);
    else if (rt->data < data)
        rt->right = Del(rt->right, data);
    else
    {
        // for leaf node
        if (rt->left == NULL && rt->right == NULL)
        {
            delete rt;
            return NULL;
        }
        // for if node has one child
        if (rt->left == NULL || rt->right == NULL)
        {
            node *temp = rt->left ? rt->left : rt->right;
            delete rt;
            return temp;
        }
        // for if node has two child
        node *t = rt->left;
        while (t->right)
        {
            t = t->right;
        }
        rt->data = t->data;
        rt->left = Del(rt->left, rt->data);
    }
    return rt;
}
void BST::Delete(int data)
{
    root = Del(root, data);
}
void BST::postorder_t(node *t)
{
    if (t)
    {
        postorder_t(t->left);
        postorder_t(t->right);
        cout << " " << t->data;
    }
}
void BST::postorder_traversing()
{
    cout << "\n";
    postorder_t(root);
}
void BST::inorder_traversing()
{
    cout << "\n";
    inorder_t(root);
}
void BST::inorder_t(node *t)
{
    if (t)
    {
        inorder_t(t->left);
        cout << " " << t->data;
        inorder_t(t->right);
    }
}
void BST::preorder_traversing()
{
    cout << "\n";
    preorder_t(root);
}
void BST::preorder_t(node *t)
{
    if (t)
    {
        cout << " " << t->data;
        preorder_t(t->left);
        preorder_t(t->right);
    }
}

void BST::insert(int data)
{
    node *n = new node;
    n->data = data;

    if (!root)
        root = n;
    else
    {
        node *t = root;
        while (t)
        {
            if (t->data == data)
            {
                cout << "\nduplicate values not allowed";
                return;
            }
            if (data < t->data)
            {
                if (!t->left)
                {
                    t->left = n;
                    return;
                }
                t = t->left;
            }
            else
            {
                if (!t->right)
                {
                    t->right = n;
                    return;
                }
                t = t->right;
            }
        }
    }
}
// if (root)
// {
//     node *t = root;
//     node *_t = root;
//     while (t)
//     {
//         if (t->data == data)
//             break;
//         if (data < t->data)
//         {
//             if (t->left)
//             {
//                 _t = t;
//                 t = t->left;
//             }
//             else
//             {
//                 cout << "\ndata not found";
//                 return;
//             }
//         }
//         else
//         {
//             if (t->right)
//             {
//                 _t = t;
//                 t = t->right;
//             }
//             else
//             {
//                 cout << "\ndata not found";
//                 return;
//             }
//         }
//     }
//     if (t->left == NULL && t->right == NULL)
//     {
//         if (_t->left == t)
//             _t->left = NULL;
//         else
//             _t->right = NULL;
//         delete t;
//     }
//     else if (t->left == NULL)
//     {
//         if (_t->left == t)
//             _t->left = t->right;
//         else
//             _t->right = t->right;
//         delete t;
//     }
//     else if (t->right == NULL)
//     {
//         if (_t->left == t)
//             _t->left = t->left;
//         else
//             _t->right = t->left;
//         delete t;
//     }
//     else
//     {
//         node *t1 = t->right;
//         while (t1->left)
//             t1 = t1->left;
//         t->data = t1->data;
//         if (t1->right != NULL)

//             delete t1
//     }
// }