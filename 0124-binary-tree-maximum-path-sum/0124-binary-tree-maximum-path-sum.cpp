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
    int f(TreeNode*root, int &maxi){
        if(root==NULL)return 0;
        int lt = max(f(root->left,maxi),0);
        int rt = max(f(root->right,maxi),0);
        int curr_sum = root->val+lt+rt;
        maxi=max(maxi,curr_sum);
        return root->val+max(lt,rt);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int ans = f(root, maxi);
        return maxi;
    }
};