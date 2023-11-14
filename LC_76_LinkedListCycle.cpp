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

// brute force approach using map, tc: O(n), sc: O(n)
// bool hasCycle(ListNode *head)
// {
//     unordered_map<ListNode*, bool> table;
//     ListNode* temp = head;
//     while (temp != NULL)
//     {
//         // if the element is already present in the map
//         if (table.find(temp) != table.end())
//         {
//             return true;
//         }
//         table[temp] = true; // insert the element in the map
//         temp = temp->next; // move to the next node
//     }
//     return false;
// }

// Two-pointers, tc: O(n), sc: O(1)
bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // check for loop
        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ListNode *head = NULL, *tail = NULL;
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 0);
    insertAtHead(head, tail, -4);
    tail->next = head->next;

    if (hasCycle(head))
    {
        cout << "Cycle is present in the LL";
    }
    else
    {
        cout << "Cycle is not present in the LL";
    }
    return 0;
}