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

bool solve(TreeNode *&root, int &targetSum, int sum)
{
    // base case
    if (root == NULL)
    {
        return false;
    }

    sum += root->val;
    if (root->left == NULL && root->right == NULL)
    {
        // currently at leaf node
        // verify
        if (sum == targetSum)
            return true;
        else
            return false;
    }

    bool leftAns = solve(root->left, targetSum, sum);
    bool rightAns = solve(root->right, targetSum, sum);
    return leftAns || rightAns;
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    int sum = 0;
    bool ans = solve(root, targetSum, sum);
    return ans;
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