/*Given two generic trees, return true if they are structurally identical. Otherwise return false.
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1 :
true*/
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

bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // Write your code here
    if (root1 == NULL)
    {
        if (root2 == NULL)
        {
            return true;
        }
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }
    if (root1->children.size() != root2->children.size())
    {
        return false;
    }
    for (int i = 0; i < root1->children.size(); i++)
    {
        if (!areIdentical(root1->children[i], root2->children[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    TreeNode<int> *root1 = takeInputLevelWise();
    TreeNode<int> *root2 = takeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");
}