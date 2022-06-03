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
        next = NULL;
    }
};

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
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

Node *DeleteNode(Node *head, int pos)
{
    Node *temp = head;
    Node *prev = NULL;
    int count = 0;

    if (pos == 0)
    {
        head = temp->next;
        delete (temp);
    }
    else
    {

        while (count < pos - 1 && temp != NULL)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }

        if (temp != NULL)
        {
            prev->next = temp->next;
            delete (temp);
        }
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    int i;
    cin >> i;
    DeleteNode(head, i);
    print(head);

    return 0;
}