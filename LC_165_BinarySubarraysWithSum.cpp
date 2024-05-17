#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // tc : O(n) & sc : O(1)
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int s = 0, e = 0, sum = 0, prefixZeros = 0, count = 0;

        while(e < nums.size()){
            // include value in sum 
            sum = sum + nums[e];
            while(s < e && (sum>goal || nums[s] == 0)){
                // ans 
                if(nums[s] == 1){
                    prefixZeros = 0;
                }
                else{
                    prefixZeros++;
                }
                // sum
                sum = sum - nums[s];
                // start
                s++;
            }
            // verify ans
            if(sum == goal){
                count += prefixZeros + 1;
            }
            // explore
            e++;
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout << sol.numSubarraysWithSum(nums, goal) << endl;
    return 0;
}