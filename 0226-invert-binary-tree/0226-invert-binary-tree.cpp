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
    void swapNodes(TreeNode* root)
    {
        TreeNode*temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    
    void invert(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        invert(root->left);
        invert(root->right);
        
        if(root->left != NULL || root->right != NULL)
        {
            swapNodes(root);
        }
    }
    
    TreeNode* invertTree(TreeNode* root) 
    {
        invert(root);
        return root;
    }
};