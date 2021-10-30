#include <iostream>
#include <algorithm>

using namespace std;

class node
{
public:
    int data;
    node *next;
};
node *top = NULL;
node *top2 = NULL;

void push(int x);
void pop();
int Top();
bool IsEmpty();
void print(node *top);

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    print(top);
    int c;
    for (int i = 0; i < 5; i++)
    {
    }
    pop();
    print(top);
    print(top2);
    cout << endl;
    pop();
    print(top);
    print(top2);

    return 0;
}

void push(int x)
{
    node *temp = new node;
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop()
{
    if (top == NULL)
    {
        cout << "\nNo elements to pop.";
        return;
    }
    node *temp = top;
    top = top->next;

    temp->next = top;
    top = temp;
}

bool IsEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
        return false;
}

int Top()
{
    if (IsEmpty())
    {
        cout << "No elements present in stack.";
        return 0;
    }
    else
    {
        return top->data;
    }
}
void print(node *top)
{
    node *temp = top;
    if (top == NULL)
    {
        cout << "\nStack empty.";
        return;
    }
    cout << "\nStack elements are: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
