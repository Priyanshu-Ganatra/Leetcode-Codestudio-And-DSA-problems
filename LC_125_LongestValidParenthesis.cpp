#include <bits/stdc++.h>
using namespace std;

// tc: O(n) sc: O(n)
int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1); // push -1 to handle edge case: ()()
    int maxLen = 0; 

    // the intuition behind this approach is that whenever we encounter a closing bracket, we pop the top element. And if the 
    // stack is empty, we push the index of the closing bracket. This way, we can keep track of the length of the valid
    // parenthesis. the top represents the index of the last encountered opening bracket. So, the length of the valid 
    // parenthesis is the difference between the current index and the top of the stack.
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(') // push index of opening bracket so that we can keep track of the length of the valid parenthesis
        {
            st.push(i); 
        }
        else 
        {
            st.pop(); // pop the top element
            // this means that the current closing bracket is not part of a valid parenthesis so we push the index of the closing bracket to
            if (st.empty()) 
            {
                st.push(i);
            }
            // if the stack is not empty, then the top of the stack represents the index of the last encountered opening bracket. So, the length of the valid parenthesis is the difference between the current index and the top of the stack.
            else
            {
                int len = i - st.top();
                maxLen = max(len, maxLen);
            }
        }
    }
    return maxLen;
}

int main()
{
    string s = ")()())";
    cout << "Longest valid parenthesis length:" << endl;
    cout << longestValidParentheses(s);
    return 0;
}