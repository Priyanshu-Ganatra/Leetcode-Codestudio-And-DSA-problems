#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *searchBST(TreeNode *root, int val)
{
    // base case
    if (root == NULL)
        return NULL;
    // solve 1 case
    if (root->val == val)
        return root;
    // solve remaining cases using recursion
    if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

// worst case: tc : O(n) & sc : O(n)
// best case : O(logn) & sc : O(logn) when tree is balanced
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return new TreeNode(val);
    }

    if (val < root->val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);
    cout << "Inserting 13 in BST:" << endl;
    insertIntoBST(root, 13);
    cout << "Searching for 13 in BST:" << endl;
    if (searchBST(root, 13) != NULL)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}