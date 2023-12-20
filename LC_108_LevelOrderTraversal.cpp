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

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);      // push root node
        while (!q.empty()) // while queue is not empty
        {
            int s = q.size();           // size of queue
            vector<int> v;              // vector to store values of nodes at each level
            for (int i = 0; i < s; i++) // for each level store values of nodes in vector
            {
                TreeNode *node = q.front(); // get front node
                q.pop();                    // pop front node
                if (node->left != NULL)     // if left child exists
                    q.push(node->left);     // push left child
                if (node->right != NULL)    // if right child exists
                    q.push(node->right);    // push right child
                v.push_back(node->val);     // push value of node
            }
            ans.push_back(v); // push vector of values of nodes at each level
        }
        return ans; // return answer
    }
};

int main()
{
    Solution obj;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> ans = obj.levelOrder(root);
    for (auto it : ans)
    {
        for (auto ptr : it)
        {
            cout << ptr << " ";
        }
        cout << endl;
    }
    return 0;
}