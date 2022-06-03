/*You have been given a head to a singly linked list of integers.
Write a function check to whether the list given is a 'Palindrome' or not.

Sample Input 1 :
1
9 2 3 3 2 9 -1

Sample Output 1 :
true*/
#include <bits/stdc++.h>
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
// Divide the ll in two parts, reverse the 2nd ll and check it with the 1st for matching elements
// Recursion won't work, neither will normal approach to solve palindrome
// Since ll is singly-linked
bool isPalindrome(Node *head)
{
    //Write your code here
    Node *slow = head;

    stack<int> s;

    while (slow != NULL)
    {
        s.push(slow->data);
        slow = slow->next;
    }

    while (head != NULL)
    {
        int i = s.top();

        s.pop();

        if (head->data != i)
        {
            return false;
        }
        head = head->next;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        bool ans = isPalindrome(head);

        if (ans)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }

    return 0;
}