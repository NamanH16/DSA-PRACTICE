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

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp1 = head->next;
    Node *temp2 = head;

    while (temp1 != NULL)
    {
        if (temp2->data != temp1->data)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        else
        {
            Node *a = temp1;
            temp2->next = temp1->next;
            temp1 = temp1->next;
            delete a;
        }
    }
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        head = removeDuplicates(head);
        print(head);
    }
    return 0;
}