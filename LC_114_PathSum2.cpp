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

void solve(TreeNode *root, int targetSum, vector<vector<int>> &paths, vector<int> &path, int sum)
{
    // base case
    if (root == nullptr)
    {
        return;
    }

    sum += root->val;
    path.push_back(root->val);

    // leaf node
    if (root->left == nullptr && root->right == nullptr && targetSum == sum)
    {
        paths.push_back(path);
    }

    solve(root->left, targetSum, paths, path, sum);
    solve(root->right, targetSum, paths, path, sum);

    // backtrack
    path.pop_back();
}

// tc : O(n) sc : O(n)
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> paths;
    vector<int> path;
    int sum = 0;
    solve(root, targetSum, paths, path, sum);
    return paths;
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
    TreeNode *rightRightLeft = new TreeNode(5);
    TreeNode *rightRightRight = new TreeNode(1);
    rightRight->left = rightRightLeft;
    rightRight->right = rightRightRight;

    vector<vector<int>> paths = pathSum(root, 22);
    cout << "Paths : \n";
    for (vector<int> path : paths)
    {
        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}