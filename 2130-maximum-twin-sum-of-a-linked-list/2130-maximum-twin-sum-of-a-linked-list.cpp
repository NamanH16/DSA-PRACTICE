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
    int pairSum(ListNode* head) {
        vector<int>v;
        ListNode *temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n = v.size();
        int i=0, j=n-1;
        int m = i+j/2;
        int mx=INT_MIN;
        while(i<=m){
            int s=0;
            s+=v[i]+v[n-i-1];
            mx=max(mx,s);
            i++;
        }
        return mx;
    }
};