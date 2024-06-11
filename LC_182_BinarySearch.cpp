#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};

int main() {
    vector<int> nums = {3,4,5,6,11,13,14,15,56,70};
    int target = 13;
    
    Solution obj_search;
    cout << obj_search.search(nums, target) << endl;
    
    return 0;
}