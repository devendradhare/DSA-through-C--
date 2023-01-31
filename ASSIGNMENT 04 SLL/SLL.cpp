//                      DSA through C++
//            Assignment-4: Singly Linked List
class node
{
public:
    int data;
    node *next;
    node()
    {
        data = 0;
        next = NULL;
    }
};

class SLL
{
private:
    node *start;         // 1.  Define a class SLL to implement singly linked list data structure with member
    int last_index = -1; //     variable start pointer of type node.
protected:
    void set_start(node *nod) { start = nod; } // some required functions for the assignment 07 ->

public:
    SLL() { start = NULL; }              // 2.  In question 1, define a constructor to initialise start pointer with NULL.
    void insert_at_first(int);           // 3.  In question 1, define a method to insert a data into the list at the beginning.
    void insert_at_last(int);            // 4.  In question 1, define a method to insert a data into the list at the end
    int search_index(int);               // 5.  In question 1, define a method to search a node with the give item.
    node *search_node(int);              //
    void insert_at_index(int, int);      // 6.  In question 1, define a method to insert a data into the list after the specified node of the list.
    void insert_after_node(node *, int); //
    void delete_first();                 // 7.  In question 1, define a method to delete first node from the list.
    void delete_last();                  // 8.  In question 1, define a rnethod to delete last node Of the list.
    void delete_index(int);              // 9.  In question 1, define a method to delete a specific node.
    void delete_node(node *);            //
    ~SLL();                              // 10. In question 1, define a destructor to deallocates memory for all the nodes in the linked list.
    void show_list();

    // some required functions for the assignment 07 ->
    node *get_start() { return start; }

    void operator=(SLL &);
};
void SLL::operator=(SLL &sl)
{
    node *t = sl.get_start();
    while (start)
    {
        delete_last();
    }
    while (t)
    {
        insert_at_last(t->data);
        t = t->next;
    }
}
void SLL::insert_at_first(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = start;
    start = temp;

    last_index++;
}

void SLL::insert_at_last(int data)
{
    if (start == NULL)
    {
        insert_at_first(data);
        return;
    }
    node *t = start;
    while (t->next != NULL)
        t = t->next;
    node *temp = new node;
    temp->data = data;
    t->next = temp;

    last_index++;
}

void SLL::show_list()
{
    node *t = start;
    std::cout << "\n";
    while (t != NULL)
    {
        std::cout << " " << t->data << ",";
        t = t->next;
    }
}

int SLL::search_index(int data)
{
    node *t = start;
    int i = 0;
    while (t != NULL)
    {
        if (t->data == data)
            return i;
        t = t->next;
        i++;
    }
    return -1;
}

node *SLL::search_node(int data)
{
    node *t = start;
    while (t != NULL)
    {
        if (t->data == data)
            return t;
        t = t->next;
    }
    return NULL;
}

void SLL::insert_at_index(int index, int data)
{
    if (index < 0 || index > last_index)
    {
        std::cout << " <insert_at_index: Invalid index> ";
        return;
    }
    if (index == 0)
    {
        insert_at_first(data);
        return;
    }

    node *n = start;
    for (int i = 0; i < index - 1; i++)
        n = n->next;

    node *temp = new node;
    temp->data = data;
    temp->next = n->next;
    n->next = temp;
    last_index++;
}

void SLL::insert_after_node(node *nod, int data)
{
    node *t = start;
    while (t != NULL)
    {
        if (t == nod)
        {
            node *nw = new node;
            nw->data = data;
            nw->next = t->next;
            t->next = nw;
            last_index++;
            return;
        }
        t = t->next;
    }
    std::cout << " <insert_after_node: node not found> ";
}

void SLL::delete_first()
{
    if (start == NULL)
    {
        std::cout << " <delete_first: list is empty> ";
        return;
    }
    node *temp = start;
    start = start->next;
    delete temp;
    last_index--;
}

void SLL::delete_last()
{
    if (start == NULL)
    {
        std::cout << "< delete_last : Array is Empty >";
        return;
    }
    if (start->next == NULL)
    {
        delete start;
        start = NULL;
        last_index--;
        return;
    }
    node *t = start;
    while (t->next->next != NULL)
        t = t->next;
    delete t->next;
    t->next = NULL;
    last_index--;
}

void SLL::delete_index(int index)
{
    if (index < 0 || index > last_index)
    {
        std::cout << " <delete : Invalid index> ";
        return;
    }
    if (index == 0)
    {
        delete_first();
        return;
    }
    node *n = start;
    for (int i = 0; i < index - 1; i++)
    {
        n = n->next;
    }
    node *temp = n->next;
    n->next = n->next->next;
    last_index--;
}
void SLL::delete_node(node *nod)
{
    if (start == nod)
    {
        delete_first();
        return;
    }
    node *t = start;
    while (t != NULL)
    {
        if (t->next == nod)
        {
            t->next = nod->next;
            delete nod;
            last_index--;
            return;
        }
        t = t->next;
    }
    std::cout << " <delete_node: node not found> ";
}

SLL::~SLL()
{
    while (start != NULL)
        delete_first();
}