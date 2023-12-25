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

void rightView(TreeNode *root, vector<int> &view, int level)
{
    if (!root)
    {
        return;
    }
    if (view.size() == level)
    {
        view.push_back(root->val);
    }
    rightView(root->right, view, level + 1);
    rightView(root->left, view, level + 1);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> view;
    rightView(root, view, 0);
    return view;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    vector<int> view = rightSideView(root);
    cout << "Right side view of the tree is : ";
    for (int i = 0; i < view.size(); i++)
    {
        cout << view[i] << " ";
    }
    cout << endl;
    return 0;
}