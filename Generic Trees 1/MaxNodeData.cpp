/*Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output 1:
50*/
#include <iostream>
#include <queue>
#include "TreeNodeClass.h"
using namespace std;

TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return root;
    }

    TreeNode<int> *max = root;

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *ans = maxDataNode(root->children[i]);

        if (max->data < ans->data)
        {
            max = ans;
        }
    }
    return max;
}

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

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    TreeNode<int> *ans = maxDataNode(root);

    if (root != NULL)
    {
        cout << ans->data;
    }
}