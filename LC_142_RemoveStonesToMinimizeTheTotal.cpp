#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(nlogn) + O(klogn) + O(n) = O(nlogn) and Space Complexity: O(n)
int minStoneSum(vector<int> &piles, int k)
{
    priority_queue<pair<int, int>> pq;
    // tc of below loop is O(nlogn)
    for (int i = 0; i < piles.size(); i++)
    {
        pq.push({piles[i], i});
    }
    // tc of below loop is O(klogn) as we are removing and adding element in pq k times
    while (k--)
    {
        auto top = pq.top();
        pq.pop();
        int val = top.first;
        int idx = top.second;
        piles[idx] = val - val / 2;
        pq.push({piles[idx], idx});
    }
    int sum;
    sum = accumulate(piles.begin(), piles.end(), 0);
    return sum;
}

int main()
{
    vector<int> piles = {5, 4, 9};
    int k = 2;
    cout << minStoneSum(piles, k) << endl;
    return 0;
}