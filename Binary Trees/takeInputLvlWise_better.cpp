#include <iostream>
#include <queue>
#include "BinaryTreeNodeClass.h"
using namespace std;

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;

    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data << " ";
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front->data << " ";
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(BinaryTreeNode<int> *root)
{
    // IN BINARY TREES, WE DO NEED BASE CASE, UNLIKE GENERIC TREES
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }

    if (root->right != NULL)
    {
        cout << " R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    cout << "Number of nodes of this binary tree: " << countNodes(root) << endl;
    delete root;

    return 0;
}