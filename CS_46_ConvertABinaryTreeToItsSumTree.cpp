#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

int sum(TreeNode<int> *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
    {
        // leaf node
        int leafVal = root->data;
        root->data = 0;
        return leafVal;
    }
    int lsum = sum(root->left);
    int rsum = sum(root->right);
    int currNodeVal = root->data;    // store the current node val as it'll be overwritten
    root->data = lsum + rsum;        // update current node val to its subtrees' sum
    return root->data + currNodeVal; // return previous val of curr node + new sum val of curr node
}

// tc: O(n) & sc: O(n)
TreeNode<int> *convertToSumTree(TreeNode<int> *root)
{
    sum(root);
    return root;
}

void printTree(TreeNode<int> *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(-2);
    root->right = new TreeNode<int>(6);
    root->left->left = new TreeNode<int>(8);
    root->left->right = new TreeNode<int>(-4);
    root->right->left = new TreeNode<int>(7);
    root->right->right = new TreeNode<int>(5);

    cout << "Original Tree (Preorder): ";
    printTree(root);
    cout << endl;

    cout << "Sum Tree: (Preorder): ";
    convertToSumTree(root);
    printTree(root);
    cout << endl;

    return 0;
}