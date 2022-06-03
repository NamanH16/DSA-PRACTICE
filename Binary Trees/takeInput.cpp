#include <iostream>
#include "BinaryTreeNodeClass.h"
using namespace std;

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
// Sample Input
//1 2 -1 -1 3 -1 -1
// 1 2 4 -1 -1 5 -1 -1 3 -1 -1
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data: ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData); // creating a new tree node
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printTree(root);
    delete root;

    return 0;
}