#include <bits/stdc++.h>
using namespace std;

// BinaryTreeNode with template argument
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    // constructor
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    // destructor
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

void solve(BinaryTreeNode<int> *root, vector<int> &ans, int level)
{
    if (!root)
        return;

    // entered new level
    if (level == ans.size())
        ans.push_back(root->data);

    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

// recursive solution, tc : O(n) and sc : O(n) for recursion stack
vector<int> printLeftView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    solve(root, ans, 0);
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
    //   /
    //  8
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->right = new BinaryTreeNode<int>(6);
    root->left->right->left = new BinaryTreeNode<int>(7);
    root->left->right->left->left = new BinaryTreeNode<int>(8);

    vector<int> ans = printLeftView(root);
    cout << "Left view of the binary tree is: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    delete root;
    return 0;
}
