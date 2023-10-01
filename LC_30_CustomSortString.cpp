#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static string str; 
    // custom comparator
    static bool compare(char ch1, char ch2){
        // true when the position of ch1 in str < position of ch2 in str
        return (str.find(ch1) < str.find(ch2)); 
    }

    string customSortString(string order, string s) {
        str = order;
        sort(s.begin(), s.end(), compare);
        return s;
    }
};

string Solution::str;

int main() {
    Solution solution;
    string order = "cba";
    string s = "abcd";

    string sortedString = solution.customSortString(order, s);

    cout << "Original String: " << s << endl;
    cout << "Sorted String: " << sortedString << endl;

    return 0;
}
