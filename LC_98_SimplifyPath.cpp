#include <bits/stdc++.h>
using namespace std;

// tc: O(n) and sc: O(n)
string simplifyPath(string path)
{
    stack<string> s;
    int i = 0;
    while(i < path.size()){
        int start = i; // start of the path
        int end = i + 1; // end of the path

        while (end < path.size() && path[end] != '/') // find the end of the path
        {
            end++;
        }
        string minPath = path.substr(start, end - start); // extract the path from start to end
        i = end; // update i to end as we have already processed the path between start and end
        if (minPath == "/" || minPath == "/.") // if path is / or /. then continue
        {
            continue;
        }
        if(minPath != "/.."){ // if path is not /.. then push it to the stack
            s.push(minPath);
        }        
        else if(!s.empty()){ // if path is /.. and stack is not empty then pop the top element
            s.pop();
        }
    }
    if(s.empty()){ // if stack is empty then return /
        return "/";
    }
    string result = "";
    while(!s.empty()){ // stack is LIFO
        result = s.top() + result; // append to the front
        s.pop(); // pop the top element
    }
    return result;
}

int main()
{
    string path = "/home//foo/";
    cout << "Given path: " << path << endl;
    cout << "Simplified path: ";
    cout << simplifyPath(path) << endl;
    return 0;
}