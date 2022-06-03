#include <vector>
using namespace std;
// we have a root node and the root node has children
// the addresses of children will be stored inside a vector
// Since we're storing the addresses of 'TreeNode', therefore pointer will of Treenode type as well
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children; // suppose if T is int type,so by default it's assumed that vector also is taking addresses of int
    // if parent is of int type, then children is of int type

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};