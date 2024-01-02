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

vector<TreeNode *> ans;
unordered_map<string, int> subTreeMap;

string preOrder(TreeNode *root){
    if(!root) return "N";

    string curr = to_string(root->val); 
    string l = preOrder(root->left);
    string r = preOrder(root->right);
    string s = curr + "," + l + "," + r;
    if(subTreeMap.find(s) != subTreeMap.end()){
        if(subTreeMap[s] == 1) ans.push_back(root);
        subTreeMap[s]++;
    } 
    else subTreeMap[s] = 1;

    return s;
}

// Time Complexity: O(n) and Space Complexity: O(n)
vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    preOrder(root);
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);

    vector<TreeNode *> ans = findDuplicateSubtrees(root);
    cout << "Duplicate Subtrees:" << endl;
    for (auto node : ans)
        cout << node->val << " ";
    cout << endl;
    return 0;
}

