/*Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum.
In the sum, data of the node and data of its immediate child nodes has to be taken.*/
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

int sumNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }
    return sum;
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    if (root == NULL)
        return NULL;

    TreeNode<int> *result = root; // root node

    int maxSum = sumNode(root); // Calculate sumNode for root Node

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = maxSumNode(root->children[i]);
        int sum = sumNode(temp);
        if (sum > maxSum)
        {
            maxSum = sum;
            result = temp;
        }
    }
    return result;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = maxSumNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
}