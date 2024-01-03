#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            data = val;
            left = right = NULL;
        }
};

int minVal(Node* root){
	if (root == NULL)
        return -1;
    while (root->left)
    {
        root = root->left;
    }
    return root->data;	
}

// hardcoded main function
int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    cout << "Minimum value in BST:" << endl;
    cout << minVal(root);
    return 0;
}