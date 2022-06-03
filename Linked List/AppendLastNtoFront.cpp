/*You have been given a singly linked list of integers along with an integer 'N'. 
Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.
Sample Input 1
2
1 2 3 4 5 -1
3
10 20 30 40 50 60 -1
5

Sample Output 1
3 4 5 1 2
20 30 40 50 60 10*/
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
Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    if (!head || !head->next || n <= 0)
    {
        return head;
    }

    // Here temp is acting as the tail
    // and t is for the original address
    Node *temp = head, *t = head;
    int i = -n;

    while (temp->next != NULL)
    {
        if (i >= 0)
        {
            t = t->next;
        }
        temp = temp->next;
        i++;
    }
    temp->next = head;
    head = t->next;
    t->next = NULL;
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int n;
        cin >> n;
        head = appendLastNToFirst(head, n);
        print(head);
    }
    return 0;
}