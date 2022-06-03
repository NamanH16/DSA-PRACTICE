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

Node *takeInput() // will take input
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

void print(Node *head) // will print the ll
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void PrintIthNode(Node *head, int i) // will print data present at the ith node
{
    Node *temp = head;
    int k = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        k++;
        if (i == k)
        {
            cout << temp->data << endl;
        }
    }
}

int Length(Node *head) // will print the length of ll
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    Node *head = takeInput();
    print(head);

    cout << Length(head) << endl;
    PrintIthNode(head, 6);

    return 0;
}