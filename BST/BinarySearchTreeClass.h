#include <iostream>
#include "BinaryTreeNodeClass.h"
class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

    void deleteData(int data)
    {
    }

private:
    void insert(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->data < data)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            root->left = newNode;
        }
    }

public:
    void insert(int data)
    {
        insert(root, data);
    }

private:
    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }

        if (node->data == data)
        {
            return true;
        }
        else if (node->data > data)
        {
            return hasData(data, node->left);
        }
        else
            return hasData(data, root->right);
    }

public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }
};