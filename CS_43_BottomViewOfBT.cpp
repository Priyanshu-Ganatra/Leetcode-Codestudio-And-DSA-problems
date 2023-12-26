#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

vector<int> bottomView(TreeNode<int> *root)
{
    map<int, int> hdToNode;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        pair<TreeNode<int> *, int> temp = q.front();
        q.pop();
        TreeNode<int> *frontNode = temp.first;
        int hd = temp.second;

        hdToNode[hd] = frontNode->data;

        // children
        if (frontNode->left != NULL)
        {
            q.push({frontNode->left, hd - 1});
        }
        if (frontNode->right != NULL)
        {
            q.push({frontNode->right, hd + 1});
        }
    }
    vector<int> ans;
    for (auto i : hdToNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    // considering tree as
    //      1
    //     / \
    //    2   3
    //   / \ / \
    //  4  5 6  7
    //      \   \
    //       8   9
    //          /
    //         10
    //          \
    //          11
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);

    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);

    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    root->left->right->right = new TreeNode<int>(8);

    root->right->right->right = new TreeNode<int>(9);
    root->right->right->right->left = new TreeNode<int>(10);
    root->right->right->right->left->right = new TreeNode<int>(11);

    vector<int> ans = bottomView(root);
    cout << "Bottom view of the tree is : ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    delete root;
    return 0;
}