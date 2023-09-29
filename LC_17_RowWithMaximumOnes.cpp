#include <bits/stdc++.h>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    vector<int> ans;
    int row = -1;
    int maxOnesCount = INT_MIN;
    int n = mat.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 1)
                count++;
        }
        if (count > maxOnesCount)
        {
            maxOnesCount = count;
            row = i;
        }
    }
    ans.push_back(row);
    ans.push_back(maxOnesCount);
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 1, 1},
                               {0, 0, 1, 1},
                               {1, 1, 1, 1},
                               {0, 0, 0, 0}};
    vector<int> ans = rowAndMaximumOnes(mat);
    cout << "Row: " << ans[0] << "\n";
    cout << "Max Ones: " << ans[1] << "\n";
    return 0;
}
