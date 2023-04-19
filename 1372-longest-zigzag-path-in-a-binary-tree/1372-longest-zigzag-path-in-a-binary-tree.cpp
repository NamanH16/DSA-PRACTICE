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
    int mxlen=0;
    void solve(TreeNode* root,bool leftDir,int currPathSteps){
        if(root==NULL)return;
        mxlen=max(mxlen,currPathSteps);
        if(leftDir){
            solve(root->left,false,currPathSteps+1);
            solve(root->right,true,1);
        }else{
            solve(root->right,true,currPathSteps+1);
            solve(root->left,false,1);
        }
        return;
    }
    int longestZigZag(TreeNode* root) {
        solve(root,true,0);
        solve(root,false,0);
        return mxlen;
    }
};