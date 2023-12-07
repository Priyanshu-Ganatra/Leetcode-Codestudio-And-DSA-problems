#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insertAtHead(ListNode *&head, ListNode *&tail, int data)
{
    // check for Empty LL
    if (head == NULL)
    {
        ListNode *newNode = new ListNode(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // step1:
        ListNode *newNode = new ListNode(data);
        // step2:
        newNode->next = head;
        // step3:
        head = newNode;
    }
}

void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

void solve(ListNode *head, int &carry){
    if(!head) return;
    solve(head->next, carry);

    // solve 1 case
    int prod = head->val * 2 + carry;
    head->val = prod % 10;
    carry = prod / 10;
}

// tc: O(n) and sc: O(n)
ListNode *doubleIt(ListNode *head)
{
    int carry = 0;
    solve(head, carry);
    // if carry is still left then add a new node at the head 
    if (carry)
    {
        ListNode* carryNode = new ListNode(carry);
        carryNode->next = head;
        head = carryNode;
    }
    return head;
}

int main()
{
    ListNode *head = NULL, *tail = NULL;
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    print(head);
    cout << endl;
    ListNode *newHead = doubleIt(head);
    print(newHead);
    return 0;
}