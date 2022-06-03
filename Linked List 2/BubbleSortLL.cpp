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

int getLen(Node *head)
{
    Node *temp = head;
    Node *curr = NULL, *prev = NULL;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

Node *bubbleSort(Node *head)
{
    Node *temp = head;
    int count = getLen(head);

    int i = 0;
    while (i < count)
    {
        temp = head;

        //check greater node
        while (temp != NULL && temp->next != NULL)
        {
            if (temp->data > temp->next->data)
            {
                swap(temp->data, temp->next->data);
            }
            temp = temp->next;
        }
        i++;
    }
    return head;
}

int main()
{
    Node *head = takeinput();
    head = bubbleSort(head);
    print(head);
}