#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, n = nums.size(), high = n - 1, ans = n;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,5,6};
    int target = 5;
    cout << sol.searchInsert(nums, target) << endl;
    return 0;
}