#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // tc : O(n), sc : O(1)
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = 0, k = n - 1;

        // j <= k and not j < k because what if j & k are on the same index 
        // and I need to perform a swap to complete the sorting
        // try to dry run nums = [2, 0, 1] with the loop condition of j < k
        while (j <= k) {
            if(arr[j] == 0){
                swap(arr[j], arr[i]);
                i++;
                j++;
            }
            else if(arr[j] == 2){
                swap(arr[j], arr[k]);
                k--;
            }
            else
                j++;
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