#include <bits/stdc++.h>
using namespace std;

void solveForATc()
{
    int col = 0;
    cin >> col;
    int row = 0;
    cin >> row;
    int towers = 0;
    cin >> towers;
    vector<pair<int, int>> loc;
    // coordinates of towers
    while (towers--)
    {
        int x = 0;
        cin >> x;
        int y = 0;
        cin >> y;
        loc.push_back(make_pair(x, y));
    }

    vector<int> xDim;
    // two dummy towers for calculation
    xDim.push_back(0);
    xDim.push_back(col + 1);
    for (int i = 0; i < loc.size(); i++)
    {
        xDim.push_back(loc[i].first);
    }
    sort(xDim.begin(), xDim.end());

    vector<int> yDim;
    // two dummy towers for calculation
    yDim.push_back(0);
    yDim.push_back(row + 1);
    for (int i = 0; i < loc.size(); i++)
    {
        yDim.push_back(loc[i].second);
    }
    sort(yDim.begin(), yDim.end());

    // difference between two towers in x and y direction
    vector<int> xAns;
    for (int i = 1; i < xDim.size(); i++)
    {
        xAns.push_back(xDim[i] - xDim[i - 1] - 1);
    }

    vector<int> yAns;
    for (int i = 1; i < yDim.size(); i++)
    {
        yAns.push_back(yDim[i] - yDim[i - 1] - 1);
    }

    int maxi = -1;
    for (int i = 0; i < xAns.size(); i++)
    {
        for (int j = 0; j < yAns.size(); j++)
        {
            maxi = max(maxi, xAns[i] * yAns[j]);
        }
    }
    cout << maxi << endl;
}

int main()
{
    int tcs = 0;
    cin >> tcs;
    while (tcs--)
    {
        solveForATc();
    }
    return 0;
}