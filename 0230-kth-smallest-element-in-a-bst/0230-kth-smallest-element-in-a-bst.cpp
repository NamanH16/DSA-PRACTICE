/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int result=0, count=0;
    void solve(TreeNode*root, int k){
        if(root==NULL)return;
        solve(root->left, k);
        count++;
        if(count==k){
            result=root->val;
            return;
        }
        solve(root->right, k);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        // inorder traversal of a bst always gives out sorted array
        solve(root,k);
        return result;
    }
};