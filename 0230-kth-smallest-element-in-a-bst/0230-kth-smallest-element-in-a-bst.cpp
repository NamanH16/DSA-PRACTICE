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
    void solve(TreeNode *root, vector<int>&sol){
        if(root==NULL)return;
        if(root->left)solve(root->left,sol);
        sol.push_back(root->val);
        if(root->right)solve(root->right, sol);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        // inorder traversal of a bst always gives out sorted array
        vector<int> sol;
        solve(root,sol);
        return sol[k-1];
    }
};