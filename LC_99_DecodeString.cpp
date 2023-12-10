#include <bits/stdc++.h>
using namespace std;

// tc: O(n) and sc: O(n)
string decodeString(string s)
{
    stack<string> st;
    for (auto ch : s) // traverse the string character by character
    {
        if(ch == ']'){ // if closing bracket then pop the stack until we get opening bracket
            string strToRepeat = "";
            while (!st.empty() && st.top() != "[") // if top is not [ then append it to strToRepeat
            {
                string top = st.top(); 
                strToRepeat += top; // append to strToRepeat
                st.pop(); // pop the top element
            }
            st.pop(); // pop the opening bracket

            string numericTimes = ""; // get the number of times to repeat, as the number can be more than 1 digit
            while (!st.empty() && isdigit(st.top()[0])) // if it is a digit then append it to numericTimes
            {
                numericTimes += st.top();
                st.pop();
            }
            reverse(numericTimes.begin(), numericTimes.end()); // reverse the numericTimes as it is in reverse order while popping from stack
            int times = stoi(numericTimes); // convert string to int

            // final decoding
            string currentdecode = ""; // decode the string and push it to the stack
            while(times--){ // repeat the string 'times' number of times
                currentdecode += strToRepeat; // append to curretdecode
            }
            st.push(currentdecode); // push the decoded string to the stack
        }   
        else 
        {
            string temp(1, ch); // convert char to string
            st.push(temp); // push the string to the stack
        }        
    }
    string result = "";
    while (!st.empty()) // stack is LIFO
    {
        result += st.top(); // append    
        st.pop(); // pop the top element after appending
    }
    reverse(result.begin(), result.end()); // reverse the result as it is in reverse order while popping from stack
    return result;
}

int main()
{
    string s = "3[a]2[bc]";
    cout << "Given string: " << s << endl;
    cout << "Decoded string: ";
    cout << decodeString(s) << endl;
    return 0;
}