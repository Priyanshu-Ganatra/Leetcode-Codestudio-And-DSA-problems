#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Brute
        // int  n= nums.size();
        // sort(nums.begin(), nums.end());

        // for(int i = 0; i<n; i++){
        //     if(i == nums[i]) continue;
        //     else return i;
        // }
        // return n;

        // Optimal
        int n = nums.size();
        int idealSum = (n * (n+1))/2;      
        int givenSum = 0;

        for(int i = 0;i<n; i++){
            givenSum += nums[i];
        }
        return idealSum-givenSum;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {3,0,1};
    cout<<obj.missingNumber(nums)<<endl;
    return 0;
}