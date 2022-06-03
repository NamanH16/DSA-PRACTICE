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

Node *merge(Node *half1, Node *half2)
{
    Node *fh = NULL;
    Node *ft = NULL;

    if (half1 == NULL)
    {
        return half2;
    }
    else if (half2 == NULL)
    {
        return half1;
    }

    while (half1 != NULL && half2 != NULL)
    {
        if (half1->data < half2->data)
        {
            if (fh == NULL)
            {
                fh = half1;
                ft = half1;
            }
            else
            {
                ft->next = half1;
                ft = half1;
            }
            half1 = half1->next;
        }
        else
        {
            if (fh == NULL)
            {
                fh = half2;
                ft = half2;
            }
            else
            {
                ft->next = half2;
                ft = half2;
            }
            half2 = half2->next;
        }
    }

    if (half1 != NULL)
    {
        ft->next = half1;
    }

    if (half2 != NULL)
    {
        ft->next = half2;
    }
    return fh;
}

Node *getMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mid = getMid(head);
    Node *half1 = head;
    Node *half2 = mid->next;
    mid->next = NULL;
    half1 = mergeSort(half1);
    half2 = mergeSort(half2);

    Node *newhead = merge(half1, half2);
    return newhead;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        head = mergeSort(head);
        print(head);
    }

    return 0;
}