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

// create a mapping of inorder elements with their indices for faster search
void createMapping(vector<int> &inorder, int &size, unordered_map<int, int> &mapping)
{
    for (int i = 0; i < size; i++)
    {
        mapping[inorder[i]] = i;
    }
}

TreeNode *solve(vector<int> &postorder, vector<int> &inorder, int &postIndex, int inStartIndex, int inEndIndex, int &size, unordered_map<int, int> &mapping)
{
    // base case
    if (postIndex < 0 || inStartIndex > inEndIndex)
    {
        return NULL;
    }

    // solving one case
    int elem = postorder[postIndex];
    postIndex--;
    TreeNode *root = new TreeNode(elem);
    // search this elem in in-order
    int pos = mapping[elem];

    // recursion
    // we call for the right subtree first as we are traversing the postorder array from the end
    // and the right subtree will be at the end of the postorder array
    // right subtree will be from pos + 1 to inEndIndex in inorder as pos is
    // the current root
    root->right = solve(postorder, inorder, postIndex, pos + 1, inEndIndex, size, mapping);
    // left subtree will be from inStartIndex to pos - 1 in inorder as pos is
    // the current root
    root->left = solve(postorder, inorder, postIndex, inStartIndex, pos - 1, size, mapping);
    return root;
}

// tc : O(n) + O(n) = O(n) for creating mapping and solving and sc : O(n) for mapping and O(h) for recursion stack = O(n)
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int size = postorder.size();
    // mapping of inorder elements with their indices
    unordered_map<int, int> mapping;
    createMapping(inorder, size, mapping); // create mapping
    int postIndex = postorder.size() - 1, inStartIndex = 0, inEndIndex = inorder.size() - 1;
    return solve(postorder, inorder, postIndex, inStartIndex, inEndIndex, size, mapping);
}

TreeNode *postOrderTraversal(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << " ";
} 

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    cout << "Given postorder traversal of a binary tree is: ";
    for (int i = 0; i < postorder.size(); i++)
    {
        cout << postorder[i] << " ";
    }
    cout << endl;
    TreeNode *root = buildTree(inorder, postorder);
    cout << "Postorder traversal of the constructed tree is: ";
    postOrderTraversal(root);
    return 0;
}