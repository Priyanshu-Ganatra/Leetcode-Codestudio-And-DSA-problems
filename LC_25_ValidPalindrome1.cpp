#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.length()-1;
        while(i<j){
            while(i<j and !isalnum(s[i])) i++;
            while(j>i and !isalnum(s[j])) j--;

            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "aba";
    cout << sol.isPalindrome(s) << endl;
    return 0;
}