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

int maxValue(TreeNode *root)
{
    if (root == NULL)
        return -1;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->val;
}

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

// worst case: tc : O(n) & sc : O(n)
// best case : O(logn) & sc : O(logn) when tree is balanced
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->val == key)
    {
        // delete node
        // 4 cases

        // 1. node is leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 2. node has right child
        else if (root->left == NULL)
        {
            TreeNode *rightChild = root->right;
            delete root;
            return rightChild;
        }
        // 3. node has left child
        else if (root->right == NULL)
        {
            TreeNode *leftChild = root->left;
            delete root;
            return leftChild;
        }
        // 4. node has both children
        else
        {
            // get max value from left subtree
            int leftMax = maxValue(root->left);
            // replace root value with leftMax
            root->val = leftMax;
            // delete leftMax from left subtree
            root->left = deleteNode(root->left, leftMax);
            return root;
        }
    }
    else if (root->val > key)
    {
        // go to left subtree
        root->left = deleteNode(root->left, key);
    }
    else
    {
        // go to right subtree
        root->right = deleteNode(root->right, key);
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
    cout << "Deleting 12 from BST:" << endl;
    deleteNode(root, 12);
    cout << "Searching for 12 in BST:" << endl;
    if (searchBST(root, 12) != NULL)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}