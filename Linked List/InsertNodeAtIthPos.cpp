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

Node *InsertNode(Node *head, int i, int data) // insert a new node at index 'i'
{
    Node *temp = head;
    Node *newNode = new Node(data);
    int count = 0;
    if (i == 0) // taking care of the corner case when i = 0
    {
        newNode->next = head;
        head = newNode; // updating the head as the newly added element
        return head;
    }

    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    } // when we come outta this loop,'temp' will have the address of 'i-1'th node

    if (temp != NULL)
    {
        Node *a = temp->next; // a has the address of (i + 1)th node
        temp->next = newNode; // Now connect the new node between i-1 and i+1 nodes
        newNode->next = a;
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    int i, data;
    cin >> i >> data;
    head = InsertNode(head, i, data);
    print(head);

    return 0;
}