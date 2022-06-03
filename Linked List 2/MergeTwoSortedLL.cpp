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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    Node *fh = NULL;
    Node *ft = NULL;

    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (fh == NULL)
            {
                fh = head1;
                ft = head1;
            }
            else
            {
                ft->next = head1;
                ft = head1;
            }
            head1 = head1->next;
        }
        else
        {
            if (fh == NULL)
            {
                fh = head2;
                ft = head2;
            }
            else
            {
                ft->next = head2;
                ft = head2;
            }
            head2 = head2->next;
        }
    }

    if (head1 != NULL)
    {
        ft->next = head1;
    }
    if (head2 != NULL)
    {
        ft->next = head2;
    }

    return fh;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head1 = takeinput();
        Node *head2 = takeinput();
        Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
        print(head3);
    }
    return 0;
}