#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> st;
    string str = "abc";
    for (auto c : str)
    {
        st.push(c);
    }
    cout << "original: " << str << endl;
    cout << "reversed: ";
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}
