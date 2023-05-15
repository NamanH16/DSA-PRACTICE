/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        while(root!=NULL){
            int val = root->val;
            if(val<p->val && val<q->val){
                root=root->right;
            }else if(val>p->val && val>q->val){
                root=root->left;
            }else{
                return root;
            }
        }
        return NULL;
    }
};