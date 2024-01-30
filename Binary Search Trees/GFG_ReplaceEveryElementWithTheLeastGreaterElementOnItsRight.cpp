#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *insert(Node *root, int val, int &succ)
{
    if (!root)
        return new Node(val);
    if (val >= root->data)
    {
        root->right = insert(root->right, val, succ);
    }
    else
    {
        succ = root->data;
        root->left = insert(root->left, val, succ);
    }
    return root;
}

// avg. case tc : O(nlogn) & worst case tc : O(n)
// sc : O(n)
vector<int> findLeastGreater(vector<int> &arr, int n)
{
    vector<int> ans(arr.size(), -1);
    Node *root = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int succ = -1;
        root = insert(root, arr[i], succ);
        ans[i] = succ;
    }
    return ans;
}

int main()
{
    vector<int> arr{8, 58, 71, 18, 31, 32, 63, 92,
                    43, 3, 91, 93, 25, 80, 28};
    vector<int> ans = findLeastGreater(arr, arr.size());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}