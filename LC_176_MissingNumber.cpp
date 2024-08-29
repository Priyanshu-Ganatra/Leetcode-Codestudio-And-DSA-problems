#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Brute
        // int n= nums.size();
        // sort(nums.begin(), nums.end());

        // for(int i = 0; i<n; i++){
        //     if(i == nums[i]) continue;
        //     else return i;
        // }
        // return n;

        // Two Optimal Aprroaches
        // tc: O(n) & O(1) both
        
        // 1. Summation
        // int n = nums.size();
        // int idealSum = (n * (n + 1)) / 2;
        // int givenSum = 0;

        // for (int i = 0; i < n; i++) {
        //     givenSum += nums[i];
        // }
        // return idealSum - givenSum;

        // 2. XOR
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            ans ^= nums[i];
        }
        for(int i = 0; i <= n; i++){
            ans ^= i;
        }
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {3,0,1};
    cout<<obj.missingNumber(nums)<<endl;
    return 0;
}