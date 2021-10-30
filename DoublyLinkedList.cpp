#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};
class node *head;

node *create_node(int x);
void insert_at_head(int x);
void print(node *p);
void insert_at_tail(int x);

int main()
{
    head = NULL;
    int n, x, l;
    cout << "\nNumber of elements: ";
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        cout << "\nInsert next element: ";
        cin >> x;
        insert_at_tail(x);
    }
    cout << "List is: ";
    print(head);
}

node *create_node(int x)
{
    node *newnode = new node();
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insert_at_head(int x)
{
    node *temp = create_node(x);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void print(node *p)
{
    if (p == NULL)
        return;

    cout << p->data << " ";
    print(p->next);
}

void insert_at_tail(int x)
{
    node *newnode = create_node(x);
    if (head == NULL)
    {
        newnode->data = x;
        newnode->next = NULL;
        newnode->prev = head;
        head = newnode;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
}
