#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0, e = 0, len = INT_MAX, sum = 0;

        while(e < nums.size()){
            // include value in sum 
            sum = sum + nums[e];
            // 3 possibilities
            // sum == target
            // sum > target
            // sum < target
            // equal or greater then minimize
            while(sum >= target){
                // minimize
                len = min(len, e-s+1);
                // current elem. pointed by "s" should be removed from sum
                sum = sum - nums[s];
                s++;
            }
            
            // out of loop means sum < target
            e++; // explore 
        }
        if(len == INT_MAX){
            return 0; 
        }
        else return len;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    cout << sol.minSubArrayLen(target, nums) << endl;
    return 0;
}