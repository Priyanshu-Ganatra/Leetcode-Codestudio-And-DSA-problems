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

int ans = 0;
void pathFromARoot(TreeNode *root, long long sum)
{
    if (!root)
        return;
    if (sum == root->val)
    {
        ++ans;
    }
    pathFromARoot(root->left, sum - root->val);
    pathFromARoot(root->right, sum - root->val);
}

// tc: O(n^2) & sc: O(n)
int pathSum(TreeNode *root, long long targetSum)
{
    if (root)
    {
        pathFromARoot(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    root->right->right = new TreeNode(11);
    cout << "The total number of paths with sum 8 is:" << endl;
    cout << pathSum(root, 8) << endl;
    return 0;
}