/*You are given a generic tree. You have to replace each node with its depth value.
You just have to update the data of each node, there is no need to return or print anything.
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output 1:
0 
1 1 1 
2 2*/
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

void printLevelATNewLine(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        for (int i = 0; i < first->children.size(); i++)
        {
            q.push(first->children[i]);
        }
    }
}

void helper(TreeNode<int> *root, int depth)
{
    if (root == nullptr)
    {
        return;
    }

    root->data = depth;

    for (int i = 0; i < root->children.size(); i++)
    {
        helper(root->children[i], depth + 1);
    }
}

void replaceWithDepthValue(TreeNode<int> *root)
{
    // Write your code here
    helper(root, 0);
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    replaceWithDepthValue(root);
    printLevelATNewLine(root);
}