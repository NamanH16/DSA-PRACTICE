/*Given a generic tree, find and return the node with second largest value in given tree.
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output 1 :
40*/
#include <iostream>
#include <queue>
#include "TreeNodeClass.h"
#include <climits>
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

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;

    TreeNode<int> *large = new TreeNode<int>(0);
    TreeNode<int> *secondLarge;

    if (root->children.size() < 1)
        return 0;

    q.push(root);

    while (!q.empty())
    {
        if (q.front()->data > large->data)
        {
            secondLarge = large;
            large = q.front();
        }
        else if (q.front()->data > secondLarge->data)
        {
            if (q.front()->data != large->data)
                secondLarge = q.front();
            else
                return NULL;
        }

        for (int i = 0; i < root->children.size(); i++)
            q.push(root->children[i]);

        q.pop();
        root = q.front();
    }
    return secondLarge;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = getSecondLargestNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
    else
    {
        cout << INT_MIN;
    }
}