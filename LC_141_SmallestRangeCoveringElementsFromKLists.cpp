#include <bits/stdc++.h>
using namespace std;

class Info
{
public:
    int data;
    int rowIdx;
    int colIdx;

    Info(int a, int b, int c)
    {
        this->data = a;
        this->rowIdx = b;
        this->colIdx = c;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->data > b->data;
    }
};

vector<int> smallestRange(vector<vector<int>> &nums)
{
    priority_queue<Info *, vector<Info *>, compare> pq;
    int maxi = INT_MIN;
    int mini = INT_MAX;

    // process first k elems
    for (int i = 0; i < nums.size(); i++)
    {
        int elem = nums[i][0];
        int row = i;
        int col = 0;
        Info *temp = new Info(elem, row, col);
        pq.push(temp);
        maxi = max(maxi, elem);
        mini = min(mini, elem);
    }

    int ansStart = mini;
    int ansEnd = maxi;

    while (!pq.empty())
    {
        Info *topNode = pq.top();
        pq.pop();
        int topData = topNode->data;
        int topCol = topNode->colIdx;
        int topRow = topNode->rowIdx;
        mini = topNode->data;
        if ((maxi - mini) < (ansEnd - ansStart))
        {
            // update ans
            ansStart = mini;
            ansEnd = maxi;
        }

        // insertion
        if (topCol + 1 < nums[topRow].size())
        {
            int newElem = nums[topRow][topCol + 1];
            maxi = max(maxi, newElem);
            Info *newInfo = new Info(newElem, topRow, topCol + 1);
            pq.push(newInfo);
        }
        else
            break;
    }

    return {ansStart, ansEnd};
}

int main()
{
    vector<vector<int>> nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    vector<int> ans = smallestRange(nums);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}