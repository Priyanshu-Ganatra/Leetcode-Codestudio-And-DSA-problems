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

// tc : O(n) and sc : O(1)
ListNode *oddEvenList(ListNode *head)
{
    if (!head || head->next == 0)
        return head;
    ListNode *h1 = head, *h2 = head->next; // h1 = odd idx list, h2 = even idx list
    ListNode *evenHead = h2;
    while (h2 && h2->next)
    {
        h1->next = h2->next;
        h2->next = h2->next->next;
        h1 = h1->next;
        h2 = h2->next;
    }
    h1->next = evenHead; // join odd list with even list i.e. odd list -> even list
    return head;
}

int main()
{
    ListNode *head = NULL, *tail = NULL;
    insertAtHead(head, tail, 6);
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    print(head);
    cout << endl;
    ListNode *newHead = oddEvenList(head);
    print(newHead);
    return 0;
}