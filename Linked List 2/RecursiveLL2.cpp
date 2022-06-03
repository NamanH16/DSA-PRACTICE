// When we have to return multiple values in a function, simply make a class
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
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

class Pair
{
public:
    Node *head;
    Node *tail;
};

Pair reverseLL_Better(Node *head) // Time Complexity : O(n)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallans = reverseLL_Better(head->next);
    smallans.tail->next = head;
    head->next = NULL;

    Pair ans;
    ans.head = smallans.head;
    ans.tail = head;

    return ans;
}

Node *reverseLL(Node *head)
{
    return reverseLL_Better(head).head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = takeInput();
    head = reverseLL(head);
    print(head);

    return 0;
}