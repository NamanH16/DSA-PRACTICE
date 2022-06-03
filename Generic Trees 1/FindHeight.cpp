/*Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output 1:
3*/
#include <iostream>
#include <queue>
#include "TreeNodeClass.h"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int getHeight(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int curr = getHeight(root->children[i]);
        if (ans < curr)
        {
            ans = curr;
        }
    }
    return ans + 1;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << getHeight(root);
}