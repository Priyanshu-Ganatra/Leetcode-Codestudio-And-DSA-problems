#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int countPairs(Node *root1, Node *root2, int x)
{
    int ans = 0;
    stack<Node*> s1, s2;
    Node *a = root1, *b = root2;
    while(1){
        while(a){
            // inorder traversal
            s1.push(a);
            a = a->left;
        }
        while(b){
            // reverse inorder traversal
            s2.push(b);
            b = b->right;
        }

        if(s1.empty() || s2.empty())
            break;

        auto atop = s1.top();
        auto btop = s2.top();

        int sum = atop->data + btop->data;

        if(sum == x){
            ans++;
            s1.pop();
            s2.pop();
            a = atop->right;
            b = btop->left;
        }
        else if(sum < x){
            s1.pop();
            a = atop->right;
        }
        else{
            s2.pop();
            b = btop->left;
        }
    }
    return ans;
}

int main()
{
    struct Node *root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    struct Node *root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);
    root2->right->left = new Node(11);
    root2->right->right = new Node(18);

    int x = 16;
    cout << "Count of pairs from two BSTs whose sum is equal to " << x << " is " << countPairs(root1, root2, x) << endl;

    return 0;
}