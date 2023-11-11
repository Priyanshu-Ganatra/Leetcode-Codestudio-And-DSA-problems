#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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

// Two passes - tc : O(n + n/2)
// int getLength(ListNode* head){
//     int len = 0;
//     ListNode* temp = head;
//     while(temp != NULL){
//         len++;
//         temp = temp->next;
//     }
//     return len;
// }

// ListNode* middleNode(ListNode* head) {
//     int n = getLength(head);
//     int pos = n/2 + 1;

//     ListNode* temp = head;
//     while(pos != 1){
//         pos--;
//         temp = temp -> next;
//     }
//     return temp;
// }

// tortoise algo, one pass - tc: O(n)
ListNode *middleNode(ListNode *head)
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
    }
    return slow;
}

int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 5);
    cout << "Original LL: ";
    print(head);
    cout << endl;
    cout << "Middle Node: " << middleNode(head)->val << endl;
    return 0;
}
    