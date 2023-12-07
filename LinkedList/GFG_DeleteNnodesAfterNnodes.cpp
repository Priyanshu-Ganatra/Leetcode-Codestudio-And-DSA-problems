#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void linkdelete(struct Node *head, int M, int N)
{
    if (!head)
        return;
    Node *it = head;
    for (int i = 0; i < M - 1; i++)
    {
        if (!it)
            return; // if M nodes aren't available
        it = it->next;
    }

    // 'it' would be Mth node
    if (!it)
        return;

    Node *MthNode = it;
    it = MthNode->next;
    for (int i = 0; i < N; i++)
    {
        if (!it)
            break;
        Node *next = it->next;
        delete it;
        it = next;
    }
    MthNode->next = it;
    linkdelete(it, M, N);
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    linkdelete(head, 1, 1);
    cout << "LL after deletion: ";
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    
    return 0;
}