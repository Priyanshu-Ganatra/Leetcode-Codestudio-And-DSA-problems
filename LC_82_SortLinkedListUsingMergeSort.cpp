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

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// using dummy node approach - O(n) time, O(1) space
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    ListNode *ans = new ListNode(-1); // dummy node
    ListNode *mptr = ans;             // merge pointer

    while (l1 && l2) // while both lists are not empty
    {
        if (l1->val <= l2->val) // if l1's value is smaller
        {
            mptr->next = l1; // point merge pointer to l1
            mptr = l1;       // move merge pointer to l1
            l1 = l1->next;   // move l1 to next node
        }
        else // if l2's value is smaller
        {
            mptr->next = l2; // point merge pointer to l2
            mptr = l2;       // move merge pointer to l2
            l2 = l2->next;   // move l2 to next node
        }
    }

    if (l1) // if l1 is not empty but l2 is empty
    {
        mptr->next = l1; // point merge pointer to l1
    }

    if (l2) // if l2 is not empty but l1 is empty
    {
        mptr->next = l2; // point merge pointer to l2
    }
    return ans->next; // return the merged list
}

// merge sort - O(nlogn) time, O(logn) space
ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    // break the list into two halves
    ListNode *mid = middleNode(head);
    ListNode *left = head;
    ListNode *right = mid->next;
    mid->next = NULL;

    // sort the left and right halves recursively
    left = sortList(left);
    right = sortList(right);

    // merge the sorted halves
    ListNode *mergedLL = mergeTwoLists(left, right);
    return mergedLL;
}

int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 3);

    cout << "Before Sorting: ";
    print(head);

    cout << "\nAfter Sorting: ";
    sortList(head);
    print(head);
    return 0;
}