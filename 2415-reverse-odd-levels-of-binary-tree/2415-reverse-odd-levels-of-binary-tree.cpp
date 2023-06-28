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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == NULL) return root;
        vector<int> ans;
        int level = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            if (level % 2 == 0) {
                ans.clear();
            }

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (level % 2 != 0) {
                    temp->val = ans[i];
                }

                if (temp->left) {
                    q.push(temp->left);
                    ans.push_back(temp->left->val);
                }
                if (temp->right) {
                    q.push(temp->right);
                    ans.push_back(temp->right->val);
                }
            }
            reverse(ans.begin(), ans.end());

            level++;
        }

        return root;

    }
};