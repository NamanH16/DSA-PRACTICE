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

Node *takeinput()
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

Node *insertNode(Node *head, int pos, int data)
{
    Node *temp = head;
    if (head == NULL)
    {
        return head;
    }

    if (pos == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = temp;
        head = newNode;
    }

    Node *ans = insertNode(head->next, pos - 1, data);
    head->next = ans;
    return head;
}
/*Node* deleteNodeRec(Node *head, int i) {
  
    Node *a = NULL;
    if(head == NULL)
    {
        return head; 
    }
    if(i==0)
    {
        a = head->next;
        return a;
    }
    Node *temp = deleteNodeRec(head->next,i-1);
    head->next = temp;  
    return head;
    
}*/

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int pos, data;
        cin >> pos >> data;
        head = insertNode(head, pos, data);
        print(head);
    }

    return 0;
}