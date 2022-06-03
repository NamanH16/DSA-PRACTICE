/*Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
7

Sample Output 1:
true

Explanation For Output 1:
Clearly, we can see that 7 is present in the tree. So, the output will be true.

Sample Input 2:
2 3 4 -1 -1 -1 -1
10

Sample Output 2:
false*/
#include <iostream>
#include <queue>
#include "BinaryTreeNodeClass.h"
using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    // Write your code here
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }
    else
    {
        return (isNodePresent(root->left, x) || isNodePresent(root->right, x));
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int x;
    cin >> x;
    cout << ((isNodePresent(root, x)) ? "true" : "false");
}