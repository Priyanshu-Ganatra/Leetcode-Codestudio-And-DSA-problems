#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>&curr, vector<int>&prev){
        // curr -> envelope with bigger height
        // prev -> envelope with smaller height
        // [0] is width of the envelope
        // [1] is the height of the envelope
        if(prev[0] < curr[0] && prev[1] < curr[1]){
            return true;
        }
        return false;
    }

    // TLE
    // tc: O(n^2) & sc: O(2n)
    int solveUsingTabuSpaceOpti(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int inc = 0;
                if ( prev == -1 || check(envelopes[curr], envelopes[prev]) ) {
                    // curr + 1 = index shifting
                    inc += 1 + nextRow[curr + 1];
                }
                // prev + 1 = index shifting
                int exc = 0 + nextRow[prev + 1];
                currRow[prev + 1] = max(inc, exc);
            }
            // shifting
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        return solveUsingTabuSpaceOpti(envelopes);
    }
};

int main() {
    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    Solution s;
    cout << s.maxEnvelopes(envelopes) << endl;
    return 0;
}