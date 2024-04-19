#include <bits/stdc++.h>
using namespace std;

void printDiff(vector<vector<int>> &diff)
{
    for (int i = 0; i < diff.size(); i++)
    {
        for (int j = 0; j < diff[0].size(); j++)
        {
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int newX, int newY, int rows, int cols, vector<vector<int>> &diff, int currX, int currY)
{
    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && diff[currX][currY] < diff[newX][newY])
    {
        return true;
    }
    return false;
}

int minimumEffortPath(vector<vector<int>> &heights)
{
    // min heap to store the path with minimum effort
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> mini;
    int rows = heights.size();
    int cols = heights[0].size();
    vector<vector<int>> diff(rows, vector<int>(cols, INT_MAX));

    // initial state
    diff[0][0] = 0;
    mini.push({0, {0, 0}});

    while (!mini.empty())
    {
        auto topPair = mini.top();
        mini.pop();
        int currDiff = topPair.first;
        pair<int, int> currNodeIndexPair = topPair.second;
        int currX = currNodeIndexPair.first;
        int currY = currNodeIndexPair.second;

        // now we traverse the neighbours of the current node i.e. top, right, bottom, left
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int newX = currX + dx[i];
            int newY = currY + dy[i];
            if (isSafe(newX, newY, rows, cols, diff, currX, currY))
            {
                int maxDiff = max(currDiff, abs(heights[newX][newY] - heights[currX][currY]));
                // check if we can update the diff array
                diff[newX][newY] = min(diff[newX][newY], maxDiff);
                // create a new pair and push it to the min heap
                if (newX != rows - 1 || newY != cols - 1)
                {
                    mini.push({diff[newX][newY], {newX, newY}});
                }
            }
        }
    }
    // printDiff(diff);
    return diff[rows - 1][cols - 1];
}

int main()
{
    vector<vector<int>> heights = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    cout << minimumEffortPath(heights) << endl;
    return 0;
}