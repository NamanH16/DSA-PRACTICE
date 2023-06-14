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
public:
    int inorder(TreeNode *root, int &value ,int &ans){
        if(root->left!=NULL){
            inorder(root->left, value, ans);
        }
        if(value>=0){
            ans = min(ans, root->val - value);
        }
        value = root->val;
        if(root->right!=NULL){
            inorder(root->right, value, ans);
        }
        return ans;
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, value = -1;
        return inorder(root, value, ans);
    }
};