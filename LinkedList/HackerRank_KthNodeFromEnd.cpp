#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

void fun(SinglyLinkedListNode *head, int &positionFromTail, int &ans)
{
    if (head == 0)
        return;
    fun(head->next, positionFromTail, ans);
    if (positionFromTail == 0)
    {
        ans = head->data;
    }
    positionFromTail--;
}

int getNode(SinglyLinkedListNode *llist, int positionFromTail)
{
    int ans = -1;
    fun(llist, positionFromTail, ans);
    return ans;
}

int main()
{
    SinglyLinkedListNode *head = new SinglyLinkedListNode(1);
    head->next = new SinglyLinkedListNode(2);
    head->next->next = new SinglyLinkedListNode(3);
    head->next->next->next = new SinglyLinkedListNode(4);
    int ans = getNode(head, 2);
    cout << "ans: " << ans << "\n"; 
    return 0;
}