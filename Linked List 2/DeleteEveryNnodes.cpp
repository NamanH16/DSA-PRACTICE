//You have been given a singly linked list of integers along with two integers, 'M,' and 'N.'
//Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes.
//Continue the same until the end of the linked list.
//To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
/*Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
2 2
Sample Output 1 :
1 2 5 6
Sample Input 2 :
2
10 20 30 40 50 60 -1
0 1
1 2 3 4 5 6 7 8 -1
2 3
Sample Output 2 :
1 2 6 7
Explanation of Sample Input 2 :
For the first query, we delete one node after every zero elements hence removing all the items of the list. 
Therefore, nothing got printed.
For the second query, we delete three nodes after every two nodes, resulting in the final list, 1 -> 2 -> 6 -> 7.*/
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

Node *skipMdeleteN(Node *head, int M, int N)
{
    // Write your code here
    if (head == NULL)
    {
        return head;
    }
    if (M == 0)
    {
        return NULL;
    }

    Node *t1 = head;

    while (t1 != NULL)
    {
        int c1 = 1;
        int c2 = 1;

        while (c1 < M && t1 != NULL)
        {
            t1 = t1->next;
            c1++;
        }

        if (t1 == NULL)
        {
            return head;
        }

        Node *t2 = t1->next;

        while (c2 <= N && t2 != NULL)
        {
            Node *k = t2;
            t2 = t2->next;
            delete (k);
            c2++;
        }
        t1->next = t2;
        t1 = t2;
    }
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int m, n;
        cin >> m >> n;
        head = skipMdeleteN(head, m, n);
        print(head);
    }
    return 0;
}