/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Approach 1: Using hashmap
        // unordered_map<ListNode*, int>mp;
        // ListNode*temp=head;
        // while(temp!=NULL){
        //     mp[temp]+=1;
        //     temp=temp->next;
        //     if(mp[temp]>1){
        //         return true;
        //     }
        // }
        // return false;

        // Approach 2: Floyd-Hare Algo
        if(head==NULL || head->next==NULL)return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL) fast=fast->next;
            slow = slow->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};