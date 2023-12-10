#include <bits/stdc++.h>
using namespace std;

// // tc: O(n^2) and sc: O(n)
// bool isValid(string s)
// {
//     if (s.size() == 0) // if string is empty then return true
//     {
//         return true;
//     }

//     int fnd = s.find("abc"); // find abc in the string
//     if(fnd != string::npos){ // if abc is found then remove it and check for the remaining string
//         string tleft = s.substr(0, fnd); // left part of the string
//         string tright = s.substr(fnd + 3, s.size()); // right part of the string after abc
//         return isValid(tleft + tright); // check for the remaining string after removing abc
//     }
//     return false; // If the size of the string is not 0 and abc is not found then return false
// }

// tc: O(n) and sc: O(n)
bool isValid(string s)
{
    if (s[0] != 'a') // if first character is not a then return false as the string should start with a
        return false;

    stack<char> st; // stack to store the characters
    for (char ch : s) // traverse the string character by character
    {
        if (ch == 'a') // if character is a then push it to the stack
            st.push(ch);
        // to push b to the stack, a should be present at the top of the stack as the string should be in the form of abc    
        else if (ch == 'b') 
        {
            if (!st.empty() && st.top() == 'a')
            {
                st.push(ch);
            }
            else
            {
                return false;
            }
        }
        // to push c to the stack, b should be present at the top of the stack as the string should be in the form of abc
        else
        {
            // ch == 'c'
            // if top is b then pop it and now check for a at the top, if present then pop it thus popping the complete abc sequence
            if (!st.empty() && st.top() == 'b') 
            {
                st.pop();
                if (!st.empty() && st.top() == 'a')
                {
                    st.pop();
                }
                else // if a is not present at the top then return false
                {
                    return false;
                }
            }
            else // if b is not present at the top then return false
            {
                return false;
            }
        }
    }
    return st.empty(); // if stack is empty then return true else return false
}

int main()
{
    string s = "aabcbc";
    cout << "Given string: " << s << endl;
    cout << "Is valid: ";
    cout << (isValid(s) ? "true" : "false") << endl;
    return 0;
}