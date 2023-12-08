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

int getLength(ListNode *head)
{
    int len = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
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

    while (fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

ListNode *reverseList(ListNode *head)
{
    ListNode *nextNode, *prevNode = NULL, *curr = head;
    while (curr)
    {
        nextNode = curr->next; // store next node
        curr->next = prevNode; // reverse current node, it now points to previous node
        prevNode = curr;       // update previous node
        curr = nextNode;       // update current node
    }
    head = prevNode; // prevNode is the new head at the end
    return head;
}

// this function compares two lists and returns true if they are identical
bool compareLists(ListNode *head1, ListNode *head2)
{
    ListNode *temp1 = head1;
    ListNode *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->val != temp2->val)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

// By breaking list in 2 halves
// tc: O(n), sc: O(1)
// bool isPalindrome(ListNode *head)
// {
//     // break the LL into two halves
//     ListNode *mid = middleNode(head); // mid is the tail of first half
//     ListNode *head2 = mid->next; // head of second half
//     mid->next = NULL; // break the link between first and second half because we need to reverse the second half

//     // reverse the second half of LL
//     head2 = reverseList(head2);

//     // compare the two halves
//     bool ans = compareLists(head, head2);
//     return ans;
// }

// By using stack
// tc: O(n), sc: O(n)
bool isPalindrome(ListNode *head)
{
    // geting mid node, but in case of even length, we need to take the the previous node to the conventional mid node
    // eg: 1->2->3->4, by convention, we get mid node as 3, but we need 2 here as mid node
    ListNode *slow = NULL;
    ListNode *fast = NULL;
    if (getLength(head) & 1) // odd length
    { 
        slow = head;
        fast = head;
    }
    // even length, here we need to take the previous node to the conventional mid node that why we are initializing fast with head->next
    else 
    {
        slow = head;
        fast = head->next;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    ListNode *mid = slow;
    ListNode *temp = mid->next;
    stack<int> st;
    while (temp)
    {
        st.push(temp->val);
        temp = temp->next;
    }
    ListNode *it = head;
    while (!st.empty())
    {
        if (it->val != st.top())
        {
            return false;
        }
        st.pop();
        it = it->next;
    }
    return true;
}

int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);

    cout << "Printing the LL:" << endl;
    print(head);
    if (isPalindrome(head))
        cout << "\nLL is Palindrome" << endl;
    else
        cout << "\nLL is not Palindrome" << endl;

    return 0;
}