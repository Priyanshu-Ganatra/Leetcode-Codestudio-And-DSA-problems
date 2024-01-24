#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// O(n) time, O(n) space
int kthSmallest(TreeNode *root, int &k)
{
    if (!root)
        return -1;
    // left
    int left = kthSmallest(root->left, k);
    if (left != -1)
        return left;

    // current
    k--;
    if (k == 0)
        return root->val;

    // right
    int right = kthSmallest(root->right, k);
    return right;
}

int main()
{
    TreeNode *root = new TreeNode(6);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(8);
    root->left = left;
    root->right = right;
    TreeNode *leftLeft = new TreeNode(0);
    TreeNode *leftRight = new TreeNode(4);
    left->left = leftLeft;
    left->right = leftRight;
    TreeNode *rightLeft = new TreeNode(7);
    TreeNode *rightRight = new TreeNode(9);
    right->left = rightLeft;
    right->right = rightRight;
    TreeNode *leftRightLeft = new TreeNode(3);
    TreeNode *leftRightRight = new TreeNode(5);
    leftRight->left = leftRightLeft;
    leftRight->right = leftRightRight;

    int k = 3;
    cout << "kth smallest element in BST:" << endl;
    cout << kthSmallest(root, k) << endl;
    return 0;
}