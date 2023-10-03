#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    vector<string> zigzag(numRows);
    int i = 0, row = 0;
    bool direction = true; // T->B

    while(true){
        if (direction)
        {
            while(row < numRows && i < s.size())
            {
                zigzag[row++].push_back(s[i++]);
                
            }
            row = numRows - 2;
        }
        else
        {
            while(row>=0 && i<s.size()){
                zigzag[row--].push_back(s[i++]);
            }
            row = 1;
        }
        if(i >= s.size()) break;
        direction = !direction;    
    }

    string res = "";
    for(auto str: zigzag)
        res += str;
    return res;    
}

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << convert(s, numRows) << endl;
    return 0;
}