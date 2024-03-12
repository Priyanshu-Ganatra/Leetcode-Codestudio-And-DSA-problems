#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int solveUsingRec(vector<int>& arr, map<pair<int, int>, int> &maxi, int s, int e){
    //     if(s>e) return 0;
    //     // if there's a single node
    //     if(s==e) return 0;

    //     int ans = INT_MAX;
    //     for(int i = s; i<e; i++){
    //         // i is used for partitioning
    //         ans = min(ans, (maxi[{s, i}] * maxi[{i+1, e}]) 
    //                         + solveUsingRec(arr, maxi, s, i)
    //                         + solveUsingRec(arr, maxi, i+1, e));
    //     }
    //     return ans;
    // }   
    
    int solveUsingMemo(vector<int>& arr, map<pair<int, int>, int> &maxi, int s, int e, 
    vector<vector<int>> &dp){
        if(s>e) return 0;
        // if there's a single node
        if(s==e) return 0;
        if(dp[s][e] != -1) return dp[s][e];

        int ans = INT_MAX;
        for(int i = s; i<e; i++){
            // i is used for partitioning
            ans = min(ans, (maxi[{s, i}] * maxi[{i+1, e}]) 
                            + solveUsingMemo(arr, maxi, s, i, dp)
                            + solveUsingMemo(arr, maxi, i+1, e, dp));
        }
        dp[s][e] = ans;
        return ans;
    }   

    int mctFromLeafValues(vector<int>& arr) {
        // pre computation of max elem in each range
        map<pair<int, int>, int> maxi;
        for(int i = 0; i<arr.size(); i++){
            maxi[{i,i}] = arr[i];
            for(int j = i+1; j<arr.size(); j++){
                maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }   
        int n = arr.size();
        int s = 0, e = n-1;
        // return solveUsingRec(arr, maxi, s, e);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solveUsingMemo(arr, maxi, s, e, dp);
    }
};

int main() {
    vector<int> arr = {6, 2, 4};
    Solution sol;
    cout << sol.mctFromLeafValues(arr);
    return 0;
}