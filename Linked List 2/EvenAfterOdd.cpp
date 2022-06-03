//For a given singly linked list of integers
//arrange the elements such that all the even numbers are placed after the odd numbers.
//The relative order of the odd and even terms should remain unchanged.
/*Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 

Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1
Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40*/
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

Node *evenAfterOdd(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *OH = NULL;
    Node *OT = NULL;
    Node *EH = NULL;
    Node *ET = NULL;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            if (EH == NULL)
            {
                EH = temp;
                ET = temp;
            }
            else
            {
                ET->next = temp;
                ET = temp;
            }
        }
        else
        {
            if (OH == NULL)
            {
                OH = temp;
                OT = temp;
            }
            else
            {
                OT->next = temp;
                OT = temp;
            }
        }
        temp = temp->next;
    }
    if (OH == NULL)
    {
        return EH;
    }
    else
    {
        if (EH != NULL)
        {
            OT->next = EH;
            ET->next = NULL;
            return OH;
        }
        else
        {
            return OH;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        head = evenAfterOdd(head);
        print(head);
    }
    return 0;
}