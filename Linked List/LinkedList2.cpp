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

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL) // if we directly do "head != NULL",we will lose the address of the first node,which is a wrong practise
    {                    // Therefore store the address inside temp pointer
        cout << temp->data << " ";
        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    /*
    cout << head->data;   // would print data of head
    head = head->next     // head points towards the next of Node
    cout << head->data;
    head = head->next
    .
    .
    . 
    */
}

int main()
{
    Node n1(10);
    Node *head = &n1;

    Node n2(20);
    n1.next = &n2;

    Node n3(30);
    n2.next = &n3;

    Node n4(40);
    n3.next = &n4;

    Node n5(50);
    n4.next = &n5;

    print(head);

    return 0;
}