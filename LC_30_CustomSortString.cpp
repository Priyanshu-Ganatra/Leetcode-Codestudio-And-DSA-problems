#include <bits/stdc++.h>
using namespace std;

// // tc: O(n*log(n)) | sc: O(m), where m = size of order string
// class Solution
// {
// public:
//     static string str;
//     // custom comparator
//     static bool compare(char ch1, char ch2)
//     {
//         // true when position of ch1 in str < position of ch2 in given order string
//         return (str.find(ch1) < str.find(ch2));
//         // when true is returned, ch1 will be placed before ch2 in the o/p string else it'll be placed after ch2
//     }

//     string customSortString(string order, string s)
//     {
//         str = order;
//         sort(s.begin(), s.end(), compare);
//         return s;
//     }
// };

// string Solution::str;

class Solution {
public:
    // tc and sc: O(n)
    string customSortString(string order, string s) {
        string result = "";
        unordered_map<char, int> mp;  // Map to count occurrences of each character in s
        
        // Count the occurrences of each character in s
        for (auto &it : s) {
            mp[it]++;
        }
        
        // Append characters in the order specified by the order string
        for (auto &it : order) {
            if (mp.find(it) != mp.end()) {
                result.append(mp[it], it);
                mp.erase(it);  // Remove character from map after processing
            }
        }
        
        // Append remaining characters that were not in the order string
        for (auto &it : mp) {
            result.append(it.second, it.first);
        }
        
        return result;
    }
};

int main()
{
    Solution obj;
    string order = "cba";
    string s = "abcd";
    cout << obj.customSortString(order, s) << endl;
    return 0;
}