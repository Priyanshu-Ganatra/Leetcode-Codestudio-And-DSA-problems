#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> &st){
    if(st.empty()) return;

    int elem = st.top();
    cout << "Top: " << elem << endl;
    st.pop();
    printStack(st);
    st.push(elem); // backtrack
}

// tc : O(n^2) sc : O(n)
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

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    int elem = 69;
    cout << "Before inserting " << elem << " at bottom the stack was: " << endl;
    printStack(st);
    cout << endl;
    insertAtBottom(st, elem);
    cout << "After inserting " << elem << " at bottom the stack is: " << endl;
    printStack(st);
    return 0;
}
