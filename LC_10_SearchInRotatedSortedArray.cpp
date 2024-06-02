#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bs(vector<int>& nums, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        vector<int>::iterator max_idx = max_element(nums.begin(), nums.end());
        int pivot = std::distance(nums.begin(), max_idx);

        if (nums[0] <= target && target <= nums[pivot]) {
            return bs(nums, 0, pivot, target);
        } else {
            return bs(nums, pivot + 1, nums.size() - 1, target);
        }
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    int target = 0;
    cout << s.search(nums, target) << endl;
    return 0;
}