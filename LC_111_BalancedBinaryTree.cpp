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

// // brute force approach
// // tc : O(n^2) sc : O(n)
// bool isBalanced(TreeNode *root)
// {
//     // base case
//     if (root == NULL)
//     {
//         return true;
//     }

//     // solve for current node
//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);
//     int diff = abs(leftHeight - rightHeight);

//     bool currNodeAns = (diff <= 1);

//     // solve for left subtree
//     bool leftSubtreeAns = isBalanced(root->left);

//     // solve for right subtree
//     bool rightSubtreeAns = isBalanced(root->right);

//     // final answer
//     bool ans = currNodeAns && leftSubtreeAns && rightSubtreeAns;
//     return ans;
// }

bool balance = true;
int height(TreeNode *root)
{
    if (!root)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    // check current node, is it balanced?
    if (balance && abs(lh - rh) > 1)
    {
        balance = false;
    }

    // return current node height
    return max(lh, rh) + 1;
}

// Optimal, tc: O(n), sc: O(n)
bool isBalanced(TreeNode *root)
{
    height(root);
    return balance;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    if (isBalanced(root))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}