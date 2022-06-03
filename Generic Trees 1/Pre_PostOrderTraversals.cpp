#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

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

void printPreOrder(TreeNode<int> *root)
{
    /*Sample Input 1:
    10 3 20 30 40 2 400 50 0 0 0 0 

    Sample Output 1:
    10 20 400 50 30 40*/

    // Write your code here
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";

    for (int i = 0; i < root->children.size(); i++)
    {
        printPreOrder(root->children[i]);
    }
}

void printPostOrder(TreeNode<int> *root)
{
    /*Sample Input 1:
    10 3 20 30 40 2 400 50 0 0 0 0 

    Sample Output 1:
    400 50 20 30 40 10*/

    // Write your code here
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printPostOrder(root->children[i]);
    }
    cout << root->data << " ";
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printPreOrder(root);
    cout << '\n';
    printPostOrder(root);
    delete root; // when I use 'delete', I am basically calling up for destructor.
    // The destructor designed by me will delete the whole tree, when I try to delete root
}