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

void getLeftBoundary(TreeNode<int> *root, vector<int> &ans)
{
    // if root is a leaf node then return as we don't need to add leaf node in the
    // left boundary
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    // push the data of the current node
    ans.push_back(root->data);

    // if left child is not NULL then move to the left child
    if (root->left != NULL)
    {
        getLeftBoundary(root->left, ans);
    }
    // if left child is NULL then move to the right child
    else
    {
        getLeftBoundary(root->right, ans);
    }
}

void getRightBoundary(TreeNode<int> *root, vector<int> &ans)
{
    // if root is a leaf node then return as we don't need to add leaf node in the
    // right boundary
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    // if right child is not NULL then move to the right child
    if (root->right != NULL)
    {
        getRightBoundary(root->right, ans);
    }
    // if right child is NULL then move to the left child
    else
    {
        getRightBoundary(root->left, ans);
    }

    // push the data of the current node when the recursive stack unwinds
    // resulting in the right boundary from bottom to top
    ans.push_back(root->data);
}

void getLeaves(TreeNode<int> *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // if root is a leaf node then push the data of the current node
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }

    // move to the left child and right child recursively to find the leaf nodes
    getLeaves(root->left, ans);
    getLeaves(root->right, ans);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // ans will store the boundary order traversal
    vector<int> ans;
    // push the root node
    ans.push_back(root->data);

    // get the left boundary
    if (root->left != NULL)
    {
        getLeftBoundary(root->left, ans);
    }

    // get the leaves
    getLeaves(root, ans);

    // get the right boundary
    if (root->right != NULL)
    {
        getRightBoundary(root->right, ans);
    }

    return ans;
}

// hardcoded main function
int main()
{
    // considering tree as
    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6
    //     /
    //    7
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->left->right = new TreeNode<int>(5);
    root->left->right->left = new TreeNode<int>(7);
    root->right = new TreeNode<int>(3);
    root->right->right = new TreeNode<int>(6);
    root->left->left = new TreeNode<int>(4);

    vector<int> ans = traverseBoundary(root);
    cout << "Boundary order traversal of the tree is : ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    delete root;
    return 0;
}