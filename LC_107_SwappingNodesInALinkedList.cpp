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

int findLength(ListNode *&head)
{
    ListNode *temp = head;
    int len = 0;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// swap nodes without swapping data i.e. only swapping pointers
// tc: O(n), sc: O(1)
ListNode *swapNodes(ListNode *head, int k)
{
    // case 1
    if (!head || !head->next)
        return head;
    int n = findLength(head);

    int lpos = k, rpos = n - k + 1;
    if (lpos > rpos)
        swap(lpos, rpos);

    // case 2
    if (lpos == rpos)
        return head;

    // case 3
    if (n == 2)
    {
        ListNode *second = head->next;
        head->next = NULL;
        second->next = head;
        return second; // new head
    }

    // case 4
    if (lpos == 1)
    {
        ListNode *lp = 0, *ln = head, *rp = head;
        for (int i = 0; i < rpos - 2; i++)
            rp = rp->next;
        ;
        ListNode *rn = rp->next;
        ListNode *rSave = rn->next;

        // swappping
        rn->next = ln->next;
        rp->next = ln;
        ln->next = rSave;

        return rn; // new head
    }

    // case 5
    int intermediateNodes = rpos - lpos - 1;
    if (intermediateNodes == 0)
    {
        // ln and rn are adjacent
        ListNode *lp = head;
        for (int i = 0; i < lpos - 2; i++)
            lp = lp->next;
        ListNode *ln = lp->next;

        ListNode *rp = ln;
        ListNode *rn = rp->next;
        ListNode *rSave = rn->next;

        // swapping
        lp->next = rp->next;
        rn->next = rp;
        rp->next = rSave;

        return head; // new head
    }
    else
    {
        // case 6
        // if intermediate nodes are present i.e. intermediateNodes >=1
        ListNode *lp = head;
        for (int i = 0; i < lpos - 2; i++)
            lp = lp->next;
        ListNode *ln = lp->next;

        ListNode *rp = head;
        for (int i = 0; i < rpos - 2; i++)
            rp = rp->next;
        ListNode *rn = rp->next;
        ListNode *rSave = rn->next;

        // swapping
        lp->next = rn;
        rn->next = ln->next;
        rp->next = ln;
        ln->next = rSave;

        return head; // new head
    }
}

int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    insertAtHead(head, tail, 7);
    insertAtHead(head, tail, 6);
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);

    cout << "Original LL: ";
    print(head);
    cout << endl;

    cout << "Swapped LL: ";
    ListNode *newHead = swapNodes(head, 2);
    print(newHead);
    cout << endl;

    return 0;
}