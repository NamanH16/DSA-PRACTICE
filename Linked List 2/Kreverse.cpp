/*Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
'k' is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
Sample Input 1 :
1
1 2 3 4 5 6 7 8 9 10 -1
4
Sample Output 1 :
4 3 2 1 8 7 6 5 10 9
Sample Input 2 :
2
1 2 3 4 5 -1
0
10 20 30 40 -1
4
Sample Output 2 :
1 2 3 4 5 
40 30 20 10 */
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

class Pair
{
public:
    Node *head;
    Node *tail;
};

Pair reverseLL(Node *head) // Time Complexity : O(n)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallans = reverseLL(head->next);
    smallans.tail->next = head;
    head->next = NULL;

    Pair ans;
    ans.head = smallans.head;
    ans.tail = head;

    return ans;
}

Node *kReverse(Node *head, int k)
{
    Node *temp = head, *h1 = head, *t1 = head;
    if (k == 0 || k == 1)
    {
        return head;
    }
    int count = 1;
    if (head == NULL)
    {
        return head;
    }

    //Write your code here
    while (t1 != NULL && count < k)
    {
        t1 = t1->next;
        count++;
    }
    if (t1 == NULL)
    { // what if there're 2 nodes and k = 5,in that case t1==null
        Node *ans = reverseLL(head).head;
        return ans;
    }
    else
    {
        Node *h2 = t1->next;
        t1->next = NULL;
        Node *fh = reverseLL(head).head;
        Node *ft = reverseLL(head).tail;
        Node *ans = kReverse(h2, k);
        ft->next = ans;

        return fh;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int k;
        cin >> k;
        head = kReverse(head, k);
        print(head);
    }

    return 0;
}