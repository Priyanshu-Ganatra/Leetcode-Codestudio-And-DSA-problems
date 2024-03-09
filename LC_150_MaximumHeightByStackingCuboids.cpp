#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &curr, vector<int> &prev)
    {
        // curr -> cuboid with bigger height
        // prev -> cuboid with smaller height
        // [0] && [1] can be width or length, we don't care
        // [2] is the height of the cuboid
        if (prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2])
        {
            return true;
        }
        return false;
    }

    // tc: O(n^2) & sc: O(2n)
    int solveUsingTabuSpaceOpti(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int inc = 0;
                if (prev == -1 || check(cuboids[curr], cuboids[prev]))
                {
                    int heightToAdd = cuboids[curr][2];
                    // curr + 1 = index shifting
                    inc += heightToAdd + nextRow[curr + 1];
                }
                // prev + 1 = index shifting
                int exc = 0 + nextRow[prev + 1];
                currRow[prev + 1] = max(inc, exc);
            }
            // shifting
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &cuboid : cuboids)
        {
            sort(cuboid.begin(), cuboid.end());
        }

        sort(cuboids.begin(), cuboids.end());
        // here the cuboid in ex. 1 looks like this:
        // [12 23 45]
        // [20 45 50]
        // [37 50 95]
        return solveUsingTabuSpaceOpti(cuboids);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> cuboids = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
    cout << s.maxHeight(cuboids) << endl;
    return 0;
}