#include <bits/stdc++.h>
using namespace std;

bool isPossibleSol(vector<int> &stalls, int k, int mid)
{ // predicate function
    // can we place k cows with atleast mid distance between cows' stalls?
    int cnt = 1; // count of cows
    int pos = stalls[0];
    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - pos >= mid)
        { // if min. dist. is same is greater than mid, then place the cow
            cnt++;
            pos = stalls[i]; // 1 more cow has been placed
        }
        if (cnt == k)
        {
            return true;
        }
    }
    return false;
}

int solve(int n, int k, vector<int> &stalls)
{
    sort(stalls.begin(), stalls.end());
    int start = 0;
    int end = stalls[stalls.size() - 1] - stalls[0];

    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossibleSol(stalls, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cout << "Enter the number of stalls: ";
    cin >> n;
    cout << "Enter the number of cows: ";
    cin >> k;
    vector<int> stalls(n);
    cout << "Enter the stalls' positions: ";
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }
    cout << "The maximum min. distance between cows' stalls is: " << solve(n, k, stalls) << endl;
    return 0;
}