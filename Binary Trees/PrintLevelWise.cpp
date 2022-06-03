/*Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 1:
1:L:2,R:3
2:L:4,R:5
3:L:6,R:7
4:L:-1,R:-1
5:L:-1,R:-1
6:L:-1,R:-1
7:L:-1,R:-1

Sample Input 2:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

Sample Output 2:
8:L:3,R:10
3:L:1,R:6
10:L:-1,R:14
1:L:-1,R:-1
6:L:4,R:7
14:L:13,R:-1
4:L:-1,R:-1
7:L:-1,R:-1
13:L:-1,R:-1
*/
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

void printLevelWise(BinaryTreeNode<int> *root)
{ // Write your code here
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout << front->data << ":";

        if (root->left != NULL)
        {
            cout << "L:" << root->left->data << ",";
            q.push(root->left);
        }
        else
        {
            cout << "L:"
                 << "-1"
                 << ",";
        }

        if (root->right != NULL)
        {
            cout << "R:" << root->right->data;
            q.push(root->right);
        }
        else
        {
            cout << "R:"
                 << "-1";
        }
        cout << endl;
        root = q.front();
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printLevelWise(root);
}