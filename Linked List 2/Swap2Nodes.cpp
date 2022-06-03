#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *swapNodes(Node *head, int i, int j)
{
    if (i == j)
    {
        return head;
    }
    Node *temp = head, *prev = NULL;
    Node *p1 = NULL, *c1 = NULL, *p2 = NULL, *c2 = NULL;
    int a = 0;

    while (temp != NULL)
    {
        if (a == i)
        {
            p1 = prev;
            c1 = temp;
        }
        else if (a == j)
        {
            p2 = prev;
            c2 = temp;
        }
        prev = temp;
        temp = temp->next;
        a++;
    }

    if (p1 != NULL)
    {
        p1->next = c2;
    }
    else
    {
        head = c2;
    }

    if (p2 != NULL)
    {
        p2->next = c1;
    }
    else
    {
        head = c1;
    }
    // whenever swapping, always take a third variable to do the action
    Node *d1 = c2->next;

    c2->next = c1->next;
    c1->next = d1;
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int i, j;
        Node *head = takeinput();
        cin >> i;
        cin >> j;
        head = swapNodes(head, i, j);
        print(head);
    }
    return 0;
}