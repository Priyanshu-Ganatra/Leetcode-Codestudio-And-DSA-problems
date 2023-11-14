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

int len(ListNode *head)
{
    int i = 0;
    while (head != NULL)
    {
        i++;
        head = head->next;
    }
    return i;
}

// tc: O(n), sc: O(n)
ListNode *reverseKGroup(ListNode *head, int k)
{
    // base cases
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }

    // 1 case
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = curr->next;
    int pos = 0;

    int length = len(head);
    if(length < k)
    {
        return head;
    }

    while (pos < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        pos++;
    }

    ListNode *recursionsAns = NULL;
    if (next != NULL)
    {
        recursionsAns = reverseKGroup(curr, k);
        head->next = recursionsAns;
    }
    return prev;
}

int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);

    cout << "Original LL: ";
    print(head);
    cout << endl;

    ListNode *newHead = reverseKGroup(head, 2);
    cout << "Reversed LL in k-groups: ";
    print(newHead);

    return 0;
}