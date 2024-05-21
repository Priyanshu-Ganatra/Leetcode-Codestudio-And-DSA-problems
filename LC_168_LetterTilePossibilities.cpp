#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &freq){
        int ans = 0;
        // try to insert A-Z in each box
        for(int i=0; i<26; i++){
            // check if this ith char exists in the string then only it'll
            // contribute to a new permutation of ans
            if(freq[i] != 0){
                ans++;
                freq[i]--;
                int recursionAns = solve(freq);
                ans += recursionAns;
                // backtracking
                freq[i]++;
            }
        }
        return ans;
    }

    // Time: O(n!), Space: O(1)
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        // count freq of chars
        for(auto ch: tiles){
            freq[ch-'A']++;
        }
        int ans = solve(freq);
        return ans;
    }
};

int main(){
    Solution s;
    string tiles = "AAB";
    cout << s.numTilePossibilities(tiles) << "\n";
    return 0;
}