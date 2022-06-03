#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) //creating a constructor such that it's compulsory to pass in an argument
    {
        this->data = data;
        next = NULL;
    }
};

int main()
{
    Node n1(1);       // suppose address of n1 is 100
    Node *head = &n1; // storing the address of n1 inside head pointer

    Node n2(2); // suppose address of n2 is 780

    n1.next = &n2; // If I want to connect both nodes n1 and n2, I need to store 780(the address of n2) in "next" of n1

    cout << head->data; // head is a pointer ,"->" means that go to address stored in head, and at that address,print data

    return 0;
}