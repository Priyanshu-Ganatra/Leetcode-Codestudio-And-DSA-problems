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

// tc: O(n) and sc: O(n)
// vector<int> nextLargerNodes(ListNode *head)
// {   
//     vector<int> ll; // to store the linked list and the answer
//     while(head){
//         ll.push_back(head->val);
//         head = head->next;
//     }
//     stack<int> st;
        
//     for (int i = 0; i < ll.size(); i++)
//     {
//         while (!st.empty() && ll[i] > ll[st.top()])
//         {
//             // means ith element is next greater than the top element of stack
//             int kids = st.top();
//             st.pop();
//             // storing the answer
//             ll[kids] = ll[i]; // ith element is the next greater element (father) for these kids
//         }
//         st.push(i); // push the index of the element to compare with the next element
//     }
//     while (!st.empty()) // if stack is not empty then there is no next greater element for these elements
//     {
//         ll[st.top()] = 0;
//         st.pop();
//     }
//     ll[ll.size()-1] = 0; // last element will always be 0
//     return ll;
// }

// Alternative approach, using a stack of pairs - single pass
// tc: O(n) and sc: O(n)
vector<int> nextLargerNodes(ListNode *head)
{   
    // creating a stack of pairs to hold index-value pairs
    stack<pair<int, int>> st;

    // vector to store final ans
    vector<int> ans;

    // index variable 'i' to keep track of current index
    int i = 0;

    // iterate through the linkedlist until head becomes NULL
    while(head){
        // add a placeholder (0) to the answer vector for the current node
        ans.push_back(0);

        // check if the stack's not empty and the current node's value is greater
        // than the value at the top of the stack. If true, update the answer vector
        while (!st.empty() && st.top().second < head->val)
        {
            auto top = st.top();
            st.pop();
            ans[top.first] = head->val;
        }
        // push the current index-value pair on the stack
        st.push({i++, head->val});
        // move to the next node in LL
        head = head->next; 
    }
    return ans;
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
    print(head);
    cout << endl;
    vector<int> ans = nextLargerNodes(head);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}