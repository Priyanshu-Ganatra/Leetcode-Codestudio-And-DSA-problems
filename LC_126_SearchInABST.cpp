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

// worst case: tc : O(n) & sc : O(n) 
// best case : O(logn) & sc : O(logn) when tree is balanced
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

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);
    cout << "Searching for 12 in BST:" << endl; 
    if (searchBST(root, 12) != NULL)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}