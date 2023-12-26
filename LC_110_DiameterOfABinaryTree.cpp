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

// // height using level order traversal
// int height(TreeNode *root)
// {
//     if (root == NULL)
//         return 0;
//     queue<TreeNode *> q;
//     q.push(root);
//     int height = 0;
//     while (!q.empty())
//     {
//         int s = q.size();
//         for (int i = 0; i < s; i++)
//         {
//             TreeNode *node = q.front();
//             q.pop();
//             if (node->left != NULL)
//                 q.push(node->left);
//             if (node->right != NULL)
//                 q.push(node->right);
//         }
//         height++;
//     }
//     return height;
// }

// // brute force approach - tc: O(n^2) - for each node we are calculating height of left subtree and right subtree and then
// // adding them up to get diameter of that node and then we are taking max of all nodes to get diameter of tree - sc: O(n) - recursion stack
// int diameterOfBinaryTree(TreeNode *root)
// {
//     // base case
//     if (root == NULL)
//         return 0;
//     // we have three options, either diameter lies in left subtree or right subtree or it passes through root
//     int option1 = diameterOfBinaryTree(root->left);         // diameter of left subtree
//     int option2 = diameterOfBinaryTree(root->right);        // diameter of right subtree
//     int option3 = height(root->left) + height(root->right); // height of left subtree + height of right subtree

//     int diameter = max(option1, max(option2, option3)); // max of all three options
//     return diameter;
// }

int D = 0; // global variable to store diameter
int height(TreeNode *&root)
{
    if (!root) // base case
        return 0;

    // height of left subtree and right subtree 
    int lh = height(root->left);
    int rh = height(root->right);
    // diameter of current node 
    int currD = lh + rh;
    // update diameter if required
    D = max(D, currD); 
    // return height of current node 
    return max(lh, rh) + 1;
}

// optimized approach - tc: O(n) - we are calculating height and diameter of each node in one go and updating diameter if required
// sc: O(n) - recursion stack
int diameterOfBinaryTree(TreeNode *root)
{
    height(root);
    return D;
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