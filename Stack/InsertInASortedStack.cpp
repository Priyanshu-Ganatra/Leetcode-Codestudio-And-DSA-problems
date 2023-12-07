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

// tc : O(n) sc : O(n)
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

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    int elem = 5;
    cout << "Before inserting " << elem << " stack was: " << endl;
    printStack(st);
    cout << endl;
    insertSorted(st, elem);
    cout << "After inserting " << elem << " the stack is: " << endl;
    printStack(st);
    return 0;
}
