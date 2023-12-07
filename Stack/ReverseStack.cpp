#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> &st)
{
    if (st.empty())
        return;

    int elem = st.top();
    cout << "Top: " << elem << endl;
    st.pop();
    printStack(st);
    st.push(elem); // backtrack
}

void insertAtBottom(stack<int> &st, int &elem)
{
    if (st.empty())
    {
        st.push(elem);
        return;
    }

    int top = st.top();
    st.pop();
    insertAtBottom(st, elem);
    st.push(top); // backtrack
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;
    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, temp); // backtrack
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout << "Before reversing: " << endl;
    printStack(st);
    cout << endl;
    cout << "After reversing: " << endl;
    reverseStack(st);
    printStack(st);
    return 0;
}
