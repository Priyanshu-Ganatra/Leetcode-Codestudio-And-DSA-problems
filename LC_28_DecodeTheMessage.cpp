#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> m;
        int c = 0;

        for (int i = 0; i < key.size(); i++) {
            if (!isalpha(key[i])) continue; // Ignore non-alphabetic characters
            if (m.find(key[i]) != m.end()) continue; // Skip already mapped characters

            m[key[i]] = 'a' + c;
            c++;
            if (c == 26) break; // All letters are mapped
        }

        string ans = "";
        for (auto it : message) {
            if (isalpha(it)) {
                ans.push_back(m[it]);
            } else {
                ans.push_back(it); // Keep spaces and other non-alphabetic characters 
                // unchanged
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    string key = "abc";
    string message = "abc";
    cout << s.decodeMessage(key, message) << endl;
    return 0;
}