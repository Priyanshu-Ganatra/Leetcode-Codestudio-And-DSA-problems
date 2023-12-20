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

// height using level order traversal
int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    queue<TreeNode *> q;
    q.push(root);
    int height = 0;
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        height++;
    }
    return height;
}

// brute force approach
int diameterOfBinaryTree(TreeNode *root)
{
    // base case
    if (root == NULL)
        return 0;
    // we have three options, either diameter lies in left subtree or right subtree or it passes through root
    int option1 = diameterOfBinaryTree(root->left);         // diameter of left subtree
    int option2 = diameterOfBinaryTree(root->right);        // diameter of right subtree
    int option3 = height(root->left) + height(root->right); // height of left subtree + height of right subtree

    int diameter = max(option1, max(option2, option3)); // max of all three options
    return diameter;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    cout << diameterOfBinaryTree(root) << endl;
    return 0;
}