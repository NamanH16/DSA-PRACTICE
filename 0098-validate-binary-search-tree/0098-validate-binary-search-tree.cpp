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
    bool solve(TreeNode*root, long long int mn, long long int mx){
        if(root==NULL)return true;
        if(root->val>=mx || root->val<=mn)return false;
        return solve(root->left, mn, root->val) && solve(root->right, root->val, mx);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        // for every node, we'll give a low and high range
        return solve(root, LONG_MIN, LONG_MAX); // don't use INT_MAX && INT_MIN
    }
};