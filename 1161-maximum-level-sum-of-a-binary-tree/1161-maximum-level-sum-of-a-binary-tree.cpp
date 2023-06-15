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
    int maxLevelSum(TreeNode* root) {
        int ans = -1, lvl=0, mxsum=INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            lvl++;
            int size = q.size();
            int sum=0;
            for(int i=0;i<size;i++){
                TreeNode *node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(sum>mxsum){
                ans=lvl;
                mxsum=sum;
            }
        }
        return ans;
    }
};