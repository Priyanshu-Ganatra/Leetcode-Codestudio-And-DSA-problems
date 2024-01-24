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

void getInorder(TreeNode *&root, vector<int> &inorder)
{
    if (!root)
        return;
    // L
    getInorder(root->left, inorder);
    // N
    inorder.push_back(root->val);
    // R
    getInorder(root->right, inorder);
}

// O(n) time, O(n) space
bool findTarget(TreeNode *root, int k)
{
    vector<int> inorder;
    getInorder(root, inorder);

    // find if targetSum i.e. k can be made
    // 2 pointers
    int s = 0, e = inorder.size() - 1;

    while (s < e)
    {
        int sum = inorder[s] + inorder[e];
        if (sum == k)
            return true;
        else if (sum > k)
            e--;
        else
            s++;
    }
    return false;
}

int main(){
    TreeNode *root = new TreeNode(6);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(8);
    root->left = left;
    root->right = right;

    cout << "Is there a pair with sum 10 in BST: " << findTarget(root, 10) << endl; 
    return 0;
}