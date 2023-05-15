class Solution {
private:
    int len(ListNode *head){
        ListNode *t = head;
        int cnt=0;
        while(t!=NULL){
            cnt++;
            t=t->next;
        }
        return cnt;
    }
    
    ListNode* kNodefromBack(ListNode* head, int k)
    {
        ListNode *t = head;
        int cnt=len(head)-k;
        while(cnt>0){
            t=t->next;
            cnt--;
        }
        return t;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL)return NULL;
        ListNode *temp1 = head;
        ListNode *temp2 = kNodefromBack(head, k);
        int i=1;
        while(i<k){
            temp1=temp1->next;
            i++;
        }
        int val = temp1->val;
        temp1->val = temp2->val;
        temp2->val = val;
        return head;
    }
};
