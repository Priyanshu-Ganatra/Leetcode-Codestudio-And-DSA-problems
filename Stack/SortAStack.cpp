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

void insertSorted(stack<int> &st, int &elem)
{
    if (st.empty() || elem >= st.top())
    {
        st.push(elem);
        return;
    }
    int top = st.top();
    st.pop();
    insertSorted(st, elem);
    st.push(top); // backtrack
}

// tc : O(n^2) sc : O(n)
void sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int top = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, top); // backtrack
}

int main()
{
    stack<int> st;
    st.push(50);
    st.push(40);
    st.push(30);
    st.push(20);
    st.push(10);
    cout << "Before sorting stack: " << endl;
    printStack(st);
    cout << endl;
    sortStack(st);
    cout << "Before sorting stack: " << endl;
    printStack(st);
    return 0;
}
