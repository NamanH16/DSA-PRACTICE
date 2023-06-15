/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // we need to maintain a distance of n between slow and fast
        // when fast reaches the last node, slow pointer would be on the node that needs to be deleted
        if(head==NULL)return head;
        ListNode *slow = head, *fast = head;
        for(int i=0;i<n;i++)fast=fast->next;
        if(fast==NULL)return head->next;
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};