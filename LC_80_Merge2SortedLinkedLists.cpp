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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->val >= l2->val)
        l2->next = mergeTwoLists(l1, l2->next);
    else
    {
        l1->next = mergeTwoLists(l1->next, l2);
        l2 = l1;
    }
    return l2;
}

int main()
{
    ListNode *head1 = NULL;
    ListNode *tail1 = NULL;
    insertAtHead(head1, tail1, 4);
    insertAtHead(head1, tail1, 2);
    insertAtHead(head1, tail1, 1);
    insertAtHead(head1, tail1, 1);
    insertAtHead(head1, tail1, 1);
    cout << "List 1: ";
    print(head1);
    cout << endl;

    ListNode *head2 = NULL;
    ListNode *tail2 = NULL;
    insertAtHead(head2, tail2, 4);
    insertAtHead(head2, tail2, 3);
    insertAtHead(head2, tail2, 1);
    cout << "List 2: ";
    print(head2);
    cout << endl;

    ListNode *head3 = mergeTwoLists(head1, head2);
    cout << "Merged List: ";
    print(head3);
    cout << endl;

    return 0;
}