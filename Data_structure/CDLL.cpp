//                         DSA through C++
//             Assignment-8: Circular Doubly Linked List
class node
{

public:
    node *prev;
    int data;
    node *next;
    node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }
};

using namespace std;
class CDLL
{
private:         // 1.  Define a class CDLL to implement Circular Doubly linked list data structure
    node *start; // with member variable start pointer of type node.

public:
    CDLL() { start = NULL; }        // 2.  constructor to initialise start pointer with NULL.
    void insert_at_first(int);      // 3.  method to insert a data into the list at the beginning.
    void insert_at_last(int);       // 4.  method to insert a data into the list at the end
    node *search(int);              // 5.  method to search a node with the give item.
    void insert_after(node *, int); // 6.  method to insert a data into the list after the specified node of the list.
    void delete_first();            // 7.  method to delete first node from the list.
    void delete_last();             // 8.  method to delete last node of the list.
    void delete_node(node *);       // 9.  method to delete a specific node.
    ~CDLL() {}                      // 10. destructor to deallocates memory for all the nodes in thelinked list.

    void show_list();
};
CDLL::~CDLL()
{
    while (start != NULL)
        delete_first();
}
void CDLL::delete_node(node *nod)
{
    if (!start)
        return;
    node *t = start;
    do
    {
        if (t == nod)
        {
            if (start == nod)
                delete_first();
            else
            {
                t = start;
                start = nod;
                delete_first();
                start = t;
            }
            return;
        }
        t = t->next;
    } while (t != start);
}
void CDLL::delete_last()
{
    start = start->prev;
    delete_first();
}
void CDLL::delete_first()
{
    if (!start)
        return;
    if (start == start->next)
    {
        delete start;
        start = NULL;
        return;
    }
    start = start->next;
    start->prev = start->prev->prev;
    delete start->prev->next;
    start->prev->next = start;
}
void CDLL::insert_after(node *nod, int data)
{
    if (!start)
        return;
    node *t = start;
    do
    {
        if (t == nod)
        {
            node *s = start;
            start = t->next;
            insert_at_first(data);
            start = s;
            return;
        }
        t = t->next;
    } while (t != start);
}
node *CDLL::search(int data)
{
    if (!start)
        return NULL;
    node *t = start;
    do
    {
        if (t->data == data)
            return t;
        t = t->next;
    } while (t != start);
    return NULL;
}
void CDLL::insert_at_last(int data)
{
    insert_at_first(data);
    start = start->next;
}
void CDLL::insert_at_first(int data)
{
    node *temp = new node;
    temp->data = data;
    if (!start)
    {
        temp->next = temp->prev = temp;
        start = temp;
    }
    else
    {
        temp->next = start;
        temp->prev = start->prev;
        start->prev = temp;
        temp->prev->next = temp;
        start = temp;
    }
}
void CDLL::show_list()
{
    node *t = start;
    if (t == NULL)
        return;
    cout << "\n";
    do
    {
        cout << " " << t->data << ",";
        t = t->next;
    } while (t != start);
}