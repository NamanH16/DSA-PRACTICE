//Given a singly linked list of integers and an integer n,
//find and return the index for the first occurrence of 'n' in the linked list. -1 otherwise.
//Follow a recursive approach to solve this.
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
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

int findNodeRec(Node *head, int n)
{
    //Write your code here
    if (head == NULL)
    {
        return -1;
    }

    if (head->data == n)
    {
        return 0;
    }

    int smallans = findNodeRec(head->next, n);

    if (smallans == -1)
    { // if element not present
        return -1;
    }

    return smallans + 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int val;
        cin >> val;
        cout << findNodeRec(head, val) << endl;
    }
}