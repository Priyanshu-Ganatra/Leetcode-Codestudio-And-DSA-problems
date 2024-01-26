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

TreeNode *build(vector<int> &preorder, int &i, int min, int max)
{
    if (i >= preorder.size())
        return NULL;
    TreeNode *root = NULL;
    if (preorder[i] > min && preorder[i] < max)
    {
        root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, min, root->val);
        root->right = build(preorder, i, root->val, max);
    }
    return root;
}

// TC: O(n) & SC: O(n)
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int min = INT_MIN, max = INT_MAX;
    int i = 0;
    return build(preorder, i, min, max);
}

int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    cout << "BST from preorder: " << endl;
    TreeNode *root = bstFromPreorder(preorder);
    return 0;
}