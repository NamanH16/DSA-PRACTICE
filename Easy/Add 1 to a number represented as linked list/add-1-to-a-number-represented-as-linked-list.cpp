//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node *reverse(Node *head){
        if(head==NULL || head->next==NULL)return head;
        Node *prev = NULL;
        Node *curr = head;
        while(curr!=NULL){
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        if(head==NULL)return head;
        head = reverse(head);
        Node *temp = head;
        while(temp!=NULL){
            if(temp->next==NULL && temp->data==9){
                temp->data=1;
                Node *newNode = new Node(0);
                // add 0 to the end of the ll
                newNode->next=head;
                head = newNode;
                temp=temp->next;
            }else if(temp->data==9){
                temp->data = 0;
                temp=temp->next;
            }else{
                temp->data+=1;
                temp=temp->next;
                break;// since we have added 1, we have the ans ready, so just break
            }
        }
        head=reverse(head);
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends