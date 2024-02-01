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

// tc : O(m + n) sc : O(h1 + h2)
vector<int> merge(Node *root1, Node *root2)
{
    vector<int> ans; // stores sorted elements of both the trees
    stack<Node *> sa, sb;
    Node *a = root1, *b = root2;
    while (a || b || !sa.empty() || !sb.empty())
    {
        while (a)
        {
            sa.push(a);
            a = a->left;
        }
        while (b)
        {
            sb.push(b);
            b = b->left;
        }

        if (sb.empty() || (!sa.empty() && sa.top()->data <= sb.top()->data))
        {
            auto atop = sa.top();
            ans.push_back(atop->data);
            sa.pop();
            a = atop->right;
        }
        else
        {
            auto btop = sb.top();
            sb.pop();
            ans.push_back(btop->data);
            b = btop->right;
        }
    }
    return ans;
}

int main()
{
    // input
    // 1st bst
    Node *root1 = new Node(100);
    root1->left = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    // 2nd bst
    Node *root2 = new Node(80);
    root2->left = new Node(40);
    root2->right = new Node(120);

    // output
    auto ans = merge(root1, root2);
    cout << "Merged BST :" << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << "\n";

    return 0;
}
