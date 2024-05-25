#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // tc : O(n), sc : O(1)
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1)
                mid++;
            else
            {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    sol.sortColors(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}