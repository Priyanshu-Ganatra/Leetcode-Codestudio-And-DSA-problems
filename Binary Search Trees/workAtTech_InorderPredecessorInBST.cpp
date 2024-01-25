#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

Node* findPredecessor(Node* root, Node* p) {
    Node *pred = 0;
    Node *curr = root;
    while (curr)
    {
        if (curr->data < p->data)
        {
            pred = curr;
            curr = curr->right;
        }
        else
            curr = curr->left;
    }
    return pred;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);

    root->left->left = new Node(4);
    root->left->right = new Node(12);

    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Node* x = root->left->right->left;

    Node* ans = findPredecessor(root, x);
    if (ans == NULL)
        cout << "No predecessor Found\n";
    else
        cout << "Predecessor is " << ans->data << "\n";
    return 0;
}