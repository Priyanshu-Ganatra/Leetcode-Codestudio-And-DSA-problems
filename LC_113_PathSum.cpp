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

bool solve(TreeNode *root, int &targetSum, int sum)
{
    if (!root)
        return false;

    sum += root->val;
    if (!root->left && !root->right)
        return (sum == targetSum);
    return solve(root->left, targetSum, sum) || solve(root->right, targetSum, sum);
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    int sum = 0;
    return solve(root, targetSum, sum);
}

int main()
{
    TreeNode *root = new TreeNode(5);
    TreeNode *left = new TreeNode(4);
    TreeNode *right = new TreeNode(8);
    root->left = left;
    root->right = right;
    TreeNode *leftLeft = new TreeNode(11);
    left->left = leftLeft;
    TreeNode *rightLeft = new TreeNode(13);
    TreeNode *rightRight = new TreeNode(4);
    right->left = rightLeft;
    right->right = rightRight;
    TreeNode *leftLeftLeft = new TreeNode(7);
    TreeNode *leftLeftRight = new TreeNode(2);
    leftLeft->left = leftLeftLeft;
    leftLeft->right = leftLeftRight;
    TreeNode *rightRightRight = new TreeNode(1);
    rightRight->right = rightRightRight;

    int targetSum = 22;
    bool ans = hasPathSum(root, targetSum);
    cout << "Has path sum : " << ans << "\n";
    return 0;
}