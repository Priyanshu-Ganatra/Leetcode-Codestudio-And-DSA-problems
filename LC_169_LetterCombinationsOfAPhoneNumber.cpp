#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string mapping[], string output, int index, vector<string> &ans, string str){
        // bc
        if(index >= str.length()){
            // string would've become in output
            // store that string in ans array
            if(output.length() > 0)
                ans.push_back(output); 
            return;
        }

        string temp = mapping[str[index]-'0'];
        for(auto ch: temp){
            output.push_back(ch);
            solve(mapping, output, index+1, ans, str);
            // backtracking
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", 
        "wxyz"};
        string output = "";
        int index = 0;
        solve(mapping, output, index, ans, digits);
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> ans = s.letterCombinations("23");
    for(auto str: ans){
        cout << str << " ";
    }
    return 0;
}