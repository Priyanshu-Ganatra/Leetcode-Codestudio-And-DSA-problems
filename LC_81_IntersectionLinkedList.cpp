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

// tc - O(n) | sc - O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // step 1 - equalize the 'a' and 'b' pointers
    ListNode *a = headA;
    ListNode *b = headB;

    while (a->next && b->next)
    {
        if (a == b)
            return a;
        a = a->next;
        b = b->next;
    }

    // if there's no intersection and the size is same of both LLs
    if (a->next == NULL && b->next == NULL && a != b)
        return NULL;

    // if 'b' is bigger/equal in size (as 'a' has reached its end already),
    // now we'll increment headB by the difference of sizes to equalize the pointers
    if (a->next == NULL)
    {
        int blen = 0;
        while (b->next)
        {
            blen++;
            b = b->next;
        }

        while (blen--)
        {
            headB = headB->next;
        }
    }
    // if 'a' is bigger/equal in size (as 'b' has reached its end already),
    // now we'll increment headA by the difference of sizes to equalize the pointers
    else
    {
        int alen = 0;
        while (a->next)
        {
            alen++;
            a = a->next;
        }

        while (alen--)
        {
            headA = headA->next;
        }
    }

    // step 2 - start traversing with the equalized pointers, and the return
    // the elem with the matching value
    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

int main()
{
    ListNode *head1 = NULL;
    ListNode *tail1 = NULL;
    ListNode *head2 = NULL;
    ListNode *tail2 = NULL;

    insertAtHead(head1, tail1, 8);
    insertAtHead(head1, tail1, 7);
    insertAtHead(head1, tail1, 5);
    insertAtHead(head1, tail1, 1);

    insertAtHead(head2, tail2, 4);
    insertAtHead(head2, tail2, 1);

    head2->next->next = head1->next->next;

    ListNode *ans = getIntersectionNode(head1, head2);
    cout << ans->val << endl;

    return 0;
}