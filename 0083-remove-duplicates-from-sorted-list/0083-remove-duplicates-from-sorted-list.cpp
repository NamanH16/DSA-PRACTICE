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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)return head;
        ListNode *x=head;
        while(x!=NULL && x->next!=NULL){
            if(x->val==x->next->val){
                ListNode *temp = x->next;
                x->next = x->next->next;
                delete temp;
            }else{
                x=x->next;
            }
        }
        return head;
    }
};