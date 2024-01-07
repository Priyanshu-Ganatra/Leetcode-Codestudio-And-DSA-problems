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

bool solve(TreeNode *root, long long lb, long long ub)
{
    if (!root)
    {
        return true;
    }

    // 2 conditions
    bool cond1 = 0; // current node should be smaller than parent node (ub)
    bool cond2 = 0; // current node should be bigger than parent node (lb)

    if (root->val < ub)
        cond1 = true;
    else
        return false;
    if (root->val > lb)
        cond2 = true;
    else
        return false;

    // for left subtree lb remains same (i.e -∞) but the left node should be smaller
    // than its parent (i.e. ub) so we pass current node as ub for validating its
    // left subtree
    bool leftAns = solve(root->left, lb, root->val);
    // for right subtree ub remains same (i.e ∞) but the right node should be bigger
    // than its parent (i.e. lb) so we pass current node as lb for validating its
    // right subtree
    bool rightAns = solve(root->right, root->val, ub);

    if (cond1 && cond2 && leftAns && rightAns)
        return true;
    else
        return false;
}

// tc: O(n) sc: O(n)
bool isValidBST(TreeNode *root)
{
    // long long as root->val can be INT_MIN/INT_MAX
    long long lb = -2147483657;
    long long ub = 2147483657;
    return solve(root, lb, ub);
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    cout << "Is the given tree a valid BST? :" << endl;
    cout << isValidBST(root) << endl;

    return 0;
}