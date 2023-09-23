#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &nums, int target)
{
    int ans = -1;
    int s = 0;
    int e = nums.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int lastOccurence(vector<int> &nums, int target)
{
    int ans = -1;
    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int first = firstOccurence(nums, target);
    int last = lastOccurence(nums, target);
    return {first, last};
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int target;
    cout << "Enter the target element: ";
    cin >> target;
    vector<int> ans = searchRange(nums, target);
    cout << "The first and last occurence of the target element are: ";
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}