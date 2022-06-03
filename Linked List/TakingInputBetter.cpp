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

Node *takeInput_better()
{
    int data;
    cin >> data;
    Node *head = NULL; // when head and tail both are NULL,means that the LL is empty
    Node *tail = NULL; // head pointer is used to store the address of the first node
    while (data != -1) // tail pointer is used to store the address of the last node
    {                  //(This is to remove the extra while loop on line 33 in "TakingInput.cpp" )
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode; // for the first and only node,head and tail are the same
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
            //Or
            //tail = newNode
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
}

int main()
{
    Node *head = takeInput_better();
    print(head);
}