#include <bits/stdc++.h>
using namespace std;

int minDiff(vector<int> &arr)
{
    int diff = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i + 1 < arr.size() && diff > arr[i + 1] - arr[i])
        {
            diff = arr[i + 1] - arr[i];
        }
    }
    return diff;
}

// tc: O(nlogn) + O(n) = O(nlogn), sc: O(n)
int findMinDifference(vector<string> &timePoints)
{
    int ans;
    vector<int> time;
    for (int i = 0; i < timePoints.size(); i++)
    {
        int hr = stoi(timePoints[i].substr(0, 2));
        int min = stoi(timePoints[i].substr(3, 2));
        time.push_back((hr * 60) + min);
    }
    sort(time.begin(), time.end());
    // this will handle the case when the min difference is between the first and last element
    return min(minDiff(time), ((1440) + time[0]) - time[time.size() - 1]); 
}

int main()
{
    vector<string> timePoints = {"23:59", "00:00"};
    cout << findMinDifference(timePoints) << endl;
    return 0;
}
